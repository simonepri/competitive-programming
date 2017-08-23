/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int K, M, C, R, course;
  unordered_map<int, bool> chosen;

  while (true) {
    bool pass = true;
    chosen.clear();
    if (!(cin >> K >> M)) break;
    chosen.reserve(K);

    for (int i = 0; i < K; i++) {
      cin >> course;
      chosen[course] = true;
    }
    for (int i = 0; i < M; i++) {
      int r = 0;
      cin >> C >> R;

      for (int j = 0; j < C; j++) {
        cin >> course;
        if (chosen[course]) r++;
      }
      if (r < R) pass = false;
    }
    if (pass) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
