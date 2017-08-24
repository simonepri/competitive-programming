/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

struct suit {
  int aces = 0;
  int kings = 0;
  int queens = 0;
  int jacks = 0;
  int total = 0;
};

int suitToCode(char s) {
  switch (s) {
    case 'S': return 0;
    case 'H': return 1;
    case 'D': return 2;
    case 'C': return 3;
  }
  return -1;
}

char codeToSuit(int c) {
  switch (c) {
    case 0: return 'S';
    case 1: return 'H';
    case 2: return 'D';
    case 3: return 'C';
  }
  return ' ';
}

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string card;

  while (true) {
    suit hand[4];

    for (int i = 0; i < 13; i++) {
      cin >> card;
      if (!cin) return 0;

      suit* cs = &hand[suitToCode(card[1])];
      cs->total++;
      switch (card[0]) {
        case 'A': cs->aces++; break;
        case 'K': cs->kings++; break;
        case 'Q': cs->queens++; break;
        case 'J': cs->jacks++; break;
      }
    }

    int score = 0;
    for (int i = 0; i < 4; i++) {
      // Rule 1
      score += hand[i].aces * 4 + hand[i].kings * 3 + hand[i].queens * 2 + hand[i].jacks;
      // Rule 2
      if (hand[i].total <= 1) score -= hand[i].kings;
      // Rule 3
      if (hand[i].total <= 2) score -= hand[i].queens;
      // Rule 4
      if (hand[i].total <= 3) score -= hand[i].jacks;
    }

    // Checks for no-trump
    if (score >= 16) {
      int stopped = 0;
      for (int i = 0; i < 4; i++) {
        // Checks if the is not stopped
        if (hand[i].aces == 0 && (hand[i].kings == 0 || hand[i].total <= 1) && (hand[i].queens == 0 || hand[i].total <= 2)) break;
        stopped++;
      }
      if (stopped == 4) {
        cout << "BID NO-TRUMP" << endl;
        continue;
      }
    }

    for (int i = 0; i < 4; i++) {
      // Rule 5
      if (hand[i].total == 2) score++;
      // Rule 6 - 7
      else if (hand[i].total <= 1) score+=2;
    }

    // Checks for bid
    if (score >= 14) {
      int max = 0;
      for (int i = 1; i < 4; i++) {
        if (hand[i].total > hand[max].total) max = i;
      }
      cout << "BID " << codeToSuit(max) << endl;
    } else {
      cout << "PASS" << endl;
    }
  }

  return 0;
}
