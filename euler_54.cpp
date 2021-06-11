#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct Card {
  Card (int in_val, char in_suit)
    : val(in_val), suit(in_suit) {}

  int val;
  char suit;
};

class PokerHand {
public:
  explicit PokerHand(const vector<Card>& cards);

  bool operator<(const PokerHand& other) const {
    if (m_rank < other.m_rank) return true;
    if (m_rank > other.m_rank) return false;
    return lexicographical_compare(rbegin(m_cards), rend(m_cards),
      rbegin(other.m_cards), rend(other.m_cards),
        [] (Card a, Card b) { return a.val < b.val; });
  }
  bool operator>(const PokerHand& other) const {
    return other < *this;
  }
  bool operator==(const PokerHand& other) const {
    return (m_rank == other.m_rank &&
      equal(begin(m_cards), end(m_cards),
        begin(other.m_cards), end(other.m_cards),
        [] (Card a, Card b) { return a.val == b.val; }));
  }

private:
  vector<Card> m_cards;
  int m_rank = 0;
};

int compute_count()
{
  ifstream ifs("poker.txt");
  string st;
  int count = 0;
  for (int i = 0; i < 1000; i++) {
    vector<Card> cards;
    for (int j = 0; j < 5; j++) {
      ifs >> st;
      char c = st[0];
      int val = static_cast<int>(c - '0');
      if (c == 'T') val = 10;
      else if (c == 'J') val = 11;
      else if (c == 'Q') val = 12;
      else if (c == 'K') val = 13;
      else if (c == 'A') val = 14;
      cards.emplace_back(val, st.back());
    }
    PokerHand left(cards);
    cards.clear();
    for (int j = 0; j < 5; j++) {
      ifs >> st;
      char c = st[0];
      int val = static_cast<int>(c - '0');
      if (c == 'T') val = 10;
      else if (c == 'J') val = 11;
      else if (c == 'Q') val = 12;
      else if (c == 'K') val = 13;
      else if (c == 'A') val = 14;
      cards.emplace_back(val, st.back());
    }
    PokerHand right(cards);
    if (left > right) ++count;
  }

  return count;
}

PokerHand::PokerHand(const vector<Card>& cards)
  : m_cards(cards)
{
  unordered_map<int, int> cnts;
  for (Card c : m_cards) {
    cnts[c.val]++;
  }

  sort(begin(m_cards), end(m_cards), [&] (Card a, Card b) {
    return pair(cnts.at(a.val), a.val) < pair(cnts.at(b.val), b.val);
  });

  bool is_flush = all_of(begin(m_cards), end(m_cards),
    [suit=m_cards.front().suit] (Card c) { return c.suit == suit; });
  vector<int> iv(5);
  iota(begin(iv), end(iv), m_cards.front().val);
  bool is_straight = equal(begin(m_cards), end(m_cards),
    begin(iv), end(iv), [] (Card c, int i) { return c.val == i; });

  if (is_flush && is_straight) {
    m_rank = (m_cards.front().val == 10) ? 9 : 8;
  } else if (is_flush) {
    m_rank = 5;
  } else if (is_straight) {
    m_rank = 4;
  } else {
    if (m_cards[1].val == m_cards.back().val) {
      m_rank = 7;
    } else if (m_cards[2].val == m_cards.back().val) {
      if (m_cards.front().val == m_cards[1].val) {
        m_rank = 6;
      } else {
        m_rank = 3;
      }
    } else if (m_cards[3].val == m_cards.back().val) {
     if (m_cards[1].val == m_cards[2].val) {
       m_rank = 2;
     } else {
       m_rank = 1;
     }
    }
  }
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
