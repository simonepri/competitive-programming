/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int A, C, height, max = 0, last = 0, cut;

  while (true) {
    cin >> A;
    if (A == 0) break;
    cin >> C;

    cut = 0;
    last = A;
    for (int i = 0; i < C; i++) {
      cin >> height;
      if (height >= last) {
        last = height;
        continue;
      }
      cut += last - height;
      last = height;
    }
    cout << cut << endl;
  }
  return 0;
}
