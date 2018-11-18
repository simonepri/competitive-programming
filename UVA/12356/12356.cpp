/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>
#include <set>

using namespace std;

#define pii pair<int, int>

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int S, B;
  while (true) {
    cin >> S >> B;
    if (S == 0 || B == 0) break;
    set<pii> ranges;

    int L, R;
    for (int i = 0; i < B; i++) {
      cin >> L >> R;

      pii lr = {L, R};

      auto it = ranges.insert(lr).first;
      auto pit = prev(it);
      auto nit = next(it);

      bool updated = false;
      if (pit != ranges.end() && pit->second + 1 == lr.first) {
        lr.first = pit->first;
        ranges.erase(pit);
        updated = true;
      }
      if (nit != ranges.end() && lr.second == nit->first - 1) {
        lr.second = nit->second;
        ranges.erase(nit);
        updated = true;
      }
      if (updated) {
        ranges.erase(it);
        ranges.insert(lr);
      }
      
      L = lr.first - 1;
      R = lr.second + 1;

      if (L == 0) cout << '*' << ' ';
      else cout << L << ' ';
      if (R == S + 1) cout << '*' << endl;
      else cout << R << endl;
    }
    cout << '-' << endl;
  }

  return 0;
}
