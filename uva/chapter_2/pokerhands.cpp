// Problem ID: 10315
// By Alexander Cai 2019-06-15
// ACCEPTED! Hoo boy this was a long one -- really it's just accounting
// for all the different hand combinations and checking for tiebreakers
// that poses the problem.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#define NVALUES 13
#define NSUITS 4
#define BLACK 0
#define WHITE 1
#define NEITHER 2
#define TIE 3
using namespace std;

const string values = "23456789TJQKA";
const string suits = "CDHS";

int rank_card(char value, char suit) {
  for (int i = 0; i < NVALUES; i++)
    if (values[i] == value)
      for (int j = 0; j < NSUITS; j++)
        if (suits[j] == suit)
          return i * NSUITS + j;

  cout << "Bad input card with value " << value << " and suit " << suit << endl;
  return -1;
}

char value(int rank) {
  return values[rank / NSUITS];
}

char suit(int rank) {
  return suits[rank % NSUITS];
}

int number_value(int rank) {
  int ind = values.find(value(rank));
  if (ind == string::npos) {
    cout << "Value " << value(rank) << suit(rank) << " not found" << endl;
    return 0;
  }
  return ind;
}

bool test_condition(bool black, bool white, int higher) {
  if (!black && !white) {
    return false;
  }
  
  if (black && !white) {
    cout << "Black wins." << endl;
  } else if (white && !black) {
    cout << "White wins." << endl;
  } else { // Both people have the combo
    if (higher == BLACK) {
      cout << "Black wins." << endl;
    } else if (higher == WHITE) {
      cout << "White wins." << endl;
    } else {
      cout << "Tie." << endl;
    }
  }

  return true;
}

int high_card(const vector<int> (&hands)[2]) {
  int i = 5;
  while (--i >= 0) {
    int a = number_value(hands[BLACK][i]);
    int b = number_value(hands[WHITE][i]);
    if (a > b) return BLACK;
    else if (b > a) return WHITE;
  }
  return TIE;
}

int main() {
  string s;

  while (getline(cin, s)) {
    vector<int> hands[2];
    vector<char> hand_values[2];
    set<int> hand_sets[2];
    stringstream ss;
    char card_value, card_suit;

    ss << s;
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j < 5; j++) {
        ss >> card_value;
        ss >> card_suit;
        int rank = rank_card(card_value, card_suit);
        hands[i].push_back(rank);
        hand_values[i].push_back(number_value(rank));
        hand_sets[i].insert(rank);
      }
    }

    int most_repeated_value[] = {0, 0};
    int second_most_repeated[] = {0, 0};
    int times_repeated[] = {0, 0};
    int second_most_times_repeated[] = {0, 0};
    bool straight[] = {true, true};
    bool flush[] = {true, true};

    sort(hands[BLACK].begin(), hands[BLACK].end());
    sort(hands[WHITE].begin(), hands[WHITE].end());
    sort(hand_values[BLACK].begin(), hand_values[BLACK].end());
    sort(hand_values[WHITE].begin(), hand_values[WHITE].end());

    // Straight flush
    for (int j = 1; j < 5; j++) {
      for (int i = 0; i <= 1; i++) {
        if (hand_values[i][j] != hand_values[i][j-1] + 1) { // If the cards are not consecutive
          straight[i] = false; // There is no straight flush
        } if (suit(hands[i][j]) != suit(hands[i][j-1]))
          flush[i] = false;
      }
    }

    // cout << endl << s << endl;
    // for (int i = 0; i <= 1; i++) {
    //   for (auto val : hands[i])
    //     cout << value(val) << suit(val) << " ";
    //   cout << endl;
    // }

    for (int i = 0; i <= 1; i++) {
      // For each unique value in the hand
      for (auto val : hand_sets[i]) {
        int c = count(hand_values[i].begin(), hand_values[i].end(), number_value(val));
        // If c is repeated more times, or if it is repeated the 
        // same number of times but the value is larger
        if (c > times_repeated[i]
        || (c == times_repeated[i] && number_value(val) > most_repeated_value[i])) {
          second_most_repeated[i] = most_repeated_value[i];
          second_most_times_repeated[i] = times_repeated[i];
          most_repeated_value[i] = number_value(val);
          times_repeated[i] = c;
        } else if (c < times_repeated[i] && c > second_most_times_repeated[i]) {
          second_most_repeated[i] = number_value(val);
          second_most_times_repeated[i] = c;
        }
      }
    }

    // cout << "most repeated black value: " << most_repeated_value[BLACK] << endl;
    // cout << "2nd most repeated black value: " << second_most_repeated[BLACK] << endl;
    // cout << "most repeated white value: " << most_repeated_value[WHITE] << endl;
    // cout << "2nd most repeated white value: " << second_most_repeated[WHITE] << endl;

    int higher = -1;
    if (hand_values[BLACK][4] > hand_values[WHITE][4]) higher = BLACK;
    if (hand_values[WHITE][4] > hand_values[BLACK][4]) higher = WHITE;

    // We go from highest priority downwards
    // Straight flush
    // for (auto c : hand_values[WHITE]) cout << c << " ";
    // cout << endl;
    // cout << straight[BLACK] << ", " << straight[WHITE] << endl;
    // cout << higher << endl;
    if (test_condition(straight[BLACK] && flush[BLACK], straight[WHITE] && flush[WHITE], higher)) continue;
    // cout << "tied straight flush" << endl;

    // Four of a kind
    higher = -1;
    if (most_repeated_value[BLACK] > most_repeated_value[WHITE]) higher = BLACK;
    if (most_repeated_value[WHITE] > most_repeated_value[BLACK]) higher = WHITE;
    if (test_condition(times_repeated[BLACK] == 4, times_repeated[WHITE] == 4, higher)) continue;
    // cout << "tied four of a kind" << endl;

    // Full house; we don't recheck higher since it's the same as above
    if (test_condition(
      times_repeated[BLACK] == 3 && second_most_times_repeated[BLACK] == 2,
      times_repeated[WHITE] == 3 && second_most_times_repeated[WHITE] == 2, higher
    )) continue;
    // cout << "tied full house" << endl;

    // Flush
    higher = high_card(hands);
    if (test_condition(flush[BLACK], flush[WHITE], higher)) continue;
    // cout << "tied flush" << endl;

    // Straight
    higher = -1;
    if (hand_values[BLACK][4] > hand_values[WHITE][4]) higher = BLACK;
    if (hand_values[WHITE][4] > hand_values[BLACK][4]) higher = WHITE;
    if (test_condition(straight[BLACK], straight[WHITE], higher)) continue;
    // cout << "tied straight" << endl;

    // Three of a kind
    higher = -1;
    if (most_repeated_value[BLACK] > most_repeated_value[WHITE]) higher = BLACK;
    if (most_repeated_value[WHITE] > most_repeated_value[BLACK]) higher = WHITE;
    if (test_condition(times_repeated[BLACK] == 3, times_repeated[WHITE] == 3, higher)) continue;
    // cout << "tied three of a kind" << endl;

    // Two pairs
    if (higher == -1) {
      if (second_most_repeated[BLACK] > second_most_repeated[WHITE]) higher = BLACK;
      if (second_most_repeated[WHITE] > second_most_repeated[BLACK]) higher = WHITE;
      if (higher == -1) {
        int extra[] = {0, 0};
        for (int i = 0; i <= 1; i++)
          for (auto j : hand_sets[i])
            if (number_value(j) != second_most_repeated[i] && j != most_repeated_value[i])
              extra[i] = number_value(j);
        if (extra[BLACK] > extra[WHITE]) higher = BLACK;
        if (extra[WHITE] > extra[BLACK]) higher = WHITE;
      }
    }
    if (test_condition(
      times_repeated[BLACK] == 2 && second_most_times_repeated[BLACK] == 2,
      times_repeated[WHITE] == 2 && second_most_times_repeated[WHITE] == 2,
      higher)
      ) continue;
    // cout << "tied two pairs" << endl;

    // Pairs
    higher = -1;
    if (most_repeated_value[BLACK] > most_repeated_value[WHITE]) higher = BLACK;
    else if (most_repeated_value[WHITE] > most_repeated_value[BLACK]) higher = WHITE;
    else for (int i = 4; i >= 0; i--) {
      if (hand_values[BLACK][i] > hand_values[WHITE][i]) {
        higher = BLACK;
        break;
      } else if (hand_values[WHITE][i] > hand_values[BLACK][i]) {
        higher = WHITE;
        break;
      }
    }
    if (test_condition(
      times_repeated[BLACK] == 2,
      times_repeated[WHITE] == 2,
      higher)
    ) continue;
    // cout << "tied pairs" << endl;

    // High card
    higher = high_card(hands);
    if (higher == BLACK) {
      cout << "Black wins." << endl;
    } else if (higher == WHITE) {
      cout << "White wins." << endl;
    } else {
      cout << "Tie." << endl;
    }
  }

  return 0;
}
