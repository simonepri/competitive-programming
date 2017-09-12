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

  int N, s, d, max, min;

  cin >> N;
  while (N-- > 0) {
    cin >> s >> d;
    if (s < d || s % 2 != d % 2) {
      cout << "impossible" << endl;
      continue;
    }

    // a >= b
    // s = a + b -> a = s - b -> s - b = d + b -> 2b = s - d -> b = (s - d) / 2
    // d = a - b -> a = d + b -> a = d + b     -> a = d + b  -> a = (s + d) / 2

    int max = (s + d) / 2;  // s + d is always an even number.
    int min = s - max;
    cout << max << " " << min << endl;
  }

  return 0;
}
