/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <algorithm>

using namespace std;

int roundMinDistance(int from, int to, int cycle) {
  if (from > to) {
    return min(from-to, (cycle-from)+to);
  }
  return min(to-from, (cycle-to)+from);
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int a, b;

  while(true) {
    cin >> a >> b;
    if (a == -1 && b == -1) break;
    cout << roundMinDistance(a, b, 100) << endl;
  }

  return 0;
}
