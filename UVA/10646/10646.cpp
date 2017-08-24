/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

using namespace std;

int getValue(string card) {
  switch (card[0]) {
    case 'A': case 'K': case 'Q': case 'J': case 'T':
      return 10;
  }
  return card[0] - '0';
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  string cards[52];

  cin >> T;

  for (int test = 1; test <= T; test++) {
    for (int i = 0; i < 52; i++) {
      cin >> cards[i];
    }

    int Y = 0;
    int pos = 27;
    for (int k = 0; k < 3; k++) {
      int val = getValue(cards[pos]);
      Y += val;
      pos -= 1 + (10 - val);
    }

    if (Y <= pos) cout << "Case " << test << ": " << cards[Y] << endl;
    else cout << "Case " << test << ": " << cards[Y + 27 - pos - 1] << endl;
  }

  return 0;
}
