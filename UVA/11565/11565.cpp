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

  int N;
  int a, b, c;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;

    // Complete Search with simple pruning.
    int range = min(b, (int)ceil(sqrt(c)));
    bool stop = false;
    for (int x = -range; x <= range; x++) {
      for (int y = x + 1; y <= range; y++) {
        for (int z = y + 1; z <= range; z++) {
          if (x + y + z != a) continue;
          if (x * y * z != b) continue;
          if (x * x + y * y + z * z != c) continue;
          cout << x << " " << y << " " << z << endl;
          stop = true;
          break;
        }
        if (stop) break;
      }
      if (stop) break;
    }
    if (!stop) {
      cout << "No solution." << endl;
    }
  }
  return 0;
}
