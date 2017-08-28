/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <cmath>

#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, R, C;
  char piece;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> piece >> R >> C;
    switch (piece) {
      // Kings are placed orizzontally leaving one column and one row free near
      // them.
      case 'K': {
        if (R % 2 != 0) R++;
        if (C % 2 != 0) C++;
        cout << (R / 2) * (C / 2) << endl;
        break;
      }
      // Rooks should be placed on the diagonal.
      case 'r': cout << min(R, C) << endl; break;
      // Knight can be placed in different ways.
      // For checkboards 1xC or Rx1 place them orizzontally.
      // For checkboards 2xC or Rx2 place them them in groups of 2x2 separated by
      // a free space of 2x2.
      // For checkerboards >= than 3x3 put them all on white or all on black.
      // If they are all on the same color, no collision happens.
      case 'k': {
        int m = R, M = C;
        if (m > M) swap(m, M);
        if (m >= 3) {
          cout << ceil(M * m / 2.0) << endl;
        } else if (m == 2) {
          int r = M % 4;
          if (r == 3) r = 1;
          cout << M + r << endl;
        } else {
          cout << M << endl;
        }
        break;
      }
      // Queens are simple but tricky at the same time. Ahh ladies!
      case 'Q': {
        int m = R, M = C;
        if (m > M) swap(m, M);
        if (m == 2) cout << 1 << endl;
        else if (m == 3 && M == 3) cout << 2 << endl;
        else cout << m << endl;
        break;
      }
    }
  }

  return 0;
}
