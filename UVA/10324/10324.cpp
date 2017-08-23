/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int cases = 0;
  int Q, from, to, len, dist;
  string str;
  vector<int> diff(1000000);

  while (cin >> str) {
    len = str.size();
    if (len == 0) break;
    diff.reserve(len);

    diff[0] = str[0] == '0' ? -1 : 1;
    for (int i = 1, j = 0; i < len; i++, j++) {
      diff[i] = diff[j] + (str[i] == '0' ? -1 : 1);
    }

    cin >> Q;

    cout << "Case " << ++cases << ":" << endl;
    for (int i = 0; i < Q; i++) {
      cin >> from >> to;

      if (from > to) swap(from, to);
      dist = to - from;
      if (str[from] == '0') dist *= -1;

      if (diff[from] + dist == diff[to]) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }

  return 0;
}
