/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

//#include <string>
//#include <vector>
//#include <set>
//#include <unordered_set>
//#include <map>
//#include <unordered_map>
//#include <deque>
//#include <queue>

//#include <algorithm>
//#include <limits>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int N, tmp[2];
  cin >> N;

  cout << "Lumberjacks:" << endl;
  for (int i = 0; i < N; i++) {
    int k = 1;
    int state = -1;
    bool unordered = false;

    for (int j = 0; j < 10; j++) {
      k = !k;
      cin >> tmp[k];
      if (j == 0 || tmp[0] == tmp[1]|| unordered) continue;
      if (state == -1) {
        state = tmp[0] > tmp[1];
        continue;
      }
      if (tmp[k] > tmp[!k] == state) unordered = true;
    }

    if (unordered) cout << "Unordered" << endl;
    else cout << "Ordered" << endl;
  }

  return 0;
}
