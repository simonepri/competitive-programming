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

  int T, N, s;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    cin >> N;

    int max = 0;
    for (int j = 0; j < N; j++) {
      cin >> s;
      if (s > max) max = s;
    }
    cout << "Case " << i << ": " << max << endl;
  }

  return 0;
}
