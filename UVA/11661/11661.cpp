/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int L;
  string S;

  while (true) {
    cin >> L;
    if (L == 0) break;
    cin >> S;

    int minDist = -1;
    int dist = 0;
    char last = 0;
    for (string::iterator it = S.begin(); it != S.end(); it++) {
      dist++;
      if (*it == '.') continue;
      if (*it == 'Z') {
        minDist = 0;
        break;
      }
      if (((last == 'R' && *it == 'D') || (last == 'D' && *it == 'R')) && (dist < minDist || minDist == -1)) {
        minDist = dist;
      }
      last = *it;
      dist = 0;
    }

    cout << minDist << endl;
  }

  return 0;
}
