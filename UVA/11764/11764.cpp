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

  int T, N, h[2];
  cin >> T;

  for (int i = 1; i <= T; i++) {
    cin >> N;

    int l = 0, g = 0, k = 0;
    for (int j = 0; j < N; j++) {
      k = !k;
      cin >> h[k];

      if (j == 0 || h[0] == h[1]) continue;
      if (h[k] > h[!k]) g++;
      else l++;
    }
    cout << "Case " << i << ": " << g << " " << l << endl;
  }

  return 0;
}
