/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <cstring>

using namespace std;

int GOTO[101];
char POS[100000];

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int a, b, c, p, from, to, die, tests;
  bool over;
  cin >> tests;
  while (tests-- > 0) {
    cin >> a >> b >> c;

    memset(GOTO, 0, sizeof(GOTO));
    memset(POS, 1, a);

    for (int i = 0; i < b; i++) {
      cin >> from >> to;
      if (a == 0) continue;
      GOTO[from] = to;
    }
    over = false;
    p = 0;
    for (int i = 0; i < c; i++) {
      cin >> die;
      if (a == 0) continue;
      if (over) continue;
      POS[p] += die;
      if (POS[p] >= 100) {
        POS[p] = 100;
        over = true;
        continue;
      }
      if (GOTO[POS[p]] != 0) POS[p] = GOTO[POS[p]];
      if (POS[p] >= 100) {
        POS[p] = 100;
        over = true;
        continue;
      }
      p = (p + 1) % a;
    }
    for (int i = 0; i < a; i++) {
      cout << "Position of player " << i + 1 << " is " << (int)POS[i] << "." << endl;
    }
  }

  return 0;
}
