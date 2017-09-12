/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>
#include <cstring>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  string left, right, type;
  bool exist[12], safe[12];
  int weight[12];

  cin >> T;
  while (T-- > 0) {
    memset(safe, 0, sizeof(safe));
    memset(exist, 0, sizeof(exist));
    memset(weight, 0, sizeof(weight));

    for (int i = 0; i < 3; i++) {
      cin >> left >> right >> type;
      int len = left.size();
      bool down = type[0] == 'd';
      bool up = type[0] == 'u';

      for (int i = 0; i < len; i++) {
        int l = left[i] - 'A';
        int r = right[i] - 'A';

        exist[l] = true;
        exist[r] = true;

        if (up) {
          weight[l]++;
          weight[r]--;
        } else if (down) {
          weight[l]--;
          weight[r]++;
        } else {
          safe[l] = true;
          safe[r] = true;
        }
      }
    }

    int min = -1, max = -1;
    for (int i = 0; i < 12; i++) {
      if (!exist[i] || safe[i]) continue;
      if (min == -1 || weight[min] > weight[i]) min = i;
      if (max == -1 || weight[max] < weight[i]) max = i;
    }
    if (-weight[min] > weight[max]) {
      cout << (char)('A' + min) << " is the counterfeit coin and it is light." << endl;
    } else {
      cout << (char)('A' + max) << " is the counterfeit coin and it is heavy." << endl;
    }
  }

  return 0;
}
