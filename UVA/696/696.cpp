/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <cmath>

#include <iostream>

#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int R, C, m, M;
  while (true) {
    cin >> R >> C;
    if (R == 0 && C == 0) break;

    m = R, M = C;
    if (m > M) swap(m, M);

    // See UVa 278 for explaination.
    switch (m) {
      case 1: {
        cout << M << " knights may be placed on a " << R << " row " << C << " column board." << endl;
        break;
      }
      case 2: {
        int r = M % 4;
        if (r == 3) r = 1;
        cout << M + r << " knights may be placed on a " << R << " row " << C << " column board." << endl;
        break;
      }
      default: {
        cout << ceil(R * C / 2.0) << " knights may be placed on a " << R << " row " << C << " column board." << endl;
      }
    }
  }

  return 0;
}
