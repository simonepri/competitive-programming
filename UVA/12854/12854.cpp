/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <bitset>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while (true) {
    bitset<5> p[2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 5; j++) {
        bool c;
        cin >> c;
        if (!cin) break;
        p[i].set(j, c);
      }
      if (!cin) break;
    }
    if (!cin) break;

    if ((p[0] ^ p[1]).count() == 5) {
      cout << "Y" << endl;
    } else {
      cout << "N" << endl;
    }
  }

  return 0;
}
