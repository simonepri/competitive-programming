/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int test = 0;
  int N, M, query;
  int mdiff;
  vector<int> nums;

  while (true) {
    test++;
    cin >> N;
    if (N == 0) break;
    nums.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
    }
    // Sort them to be able to use binary search.
    sort(nums.begin(), nums.end());

    cout << "Case " << test << ":" << endl;

    cin >> M;
    for (int i = 0; i < M; i++ ) {
      cin >> query;

      if (N - 2 >= 0) {
        mdiff = (nums[N - 1] + nums[N - 2]) - query;
      } else {
        mdiff = nums[N - 1] - query;
      }

      // For each number search another number that minimize the difference
      // between the the sum of them and the query.
      for (int i = 0; i < N; i++) {
        int a = nums[i];

        int d = lower_bound(nums.begin(), nums.end(), query - a) - nums.begin();
        int l = d - 1, g = d;
        if (g == i) g++;
        if (l == i) l--;
        // l = the index of the first valid number >= query - a
        // g = the index of the first valid number < query - a

        if (l >= 0) {
          int b = nums[l];
          int diff = (a + b) - query;
          if (abs(diff) < abs(mdiff)) {
            mdiff = diff;
          }
        }
        if (g <= N - 1) {
          int b = nums[g];
          int diff = (a + b) - query;
          if (abs(diff) < abs(mdiff)) {
            mdiff = diff;
          }
        }
      }
      cout << "Closest sum to " << query << " is " << (query + mdiff) << "." << endl;
    }
  }

  return 0;
}
