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

typedef pair<int, int> pii;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, a, b;
  vector<pii> intervals;
  cin >> T;

  while (T-- > 0) {
    intervals.clear();
    intervals.reserve(20);
    while (true) {
      cin >> a >> b;
      if (a == 0 && b == 0) break;
      if (a < 0 || b > 10 || a > b) continue;
      // We swap them to use the natural order of pairs.
      intervals.push_back(make_pair(b, a));
    }

    // Order by end increasing
    sort(intervals.begin(), intervals.end());

    int count = 0;
    int hour = 0;
    for(int i = 0; i < intervals.size(); i++) {
      if(hour > intervals[i].second) continue;
      hour = intervals[i].first;
      count++;
    }
    cout << count << endl;
  }

  return 0;
}
