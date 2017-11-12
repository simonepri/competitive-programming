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

int lag(int a, int b) {
  int diff = abs(a - b);
  return min(diff, 24 - diff);
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int N;
  vector<int> peoples;

  while (true) {
    cin >> N;
    if (!cin) break;
    peoples.resize(N);

    for (int i = 0; i < N; i++) {
      cin >> peoples[i];
    }
    sort(peoples.begin(), peoples.end());

    int sol1 = 0;
    for (int i = 0; i < peoples.size() - 1; i += 2) {
      sol1 += lag(peoples[i], peoples[i + 1]);
    }
    int sol2 = lag(peoples[peoples.size() - 1], peoples[0]);
    for (int i = 1; i < peoples.size() - 1; i += 2) {
      sol2 += lag(peoples[i], peoples[i + 1]);
    }

    cout << min(sol1, sol2) << endl;
  }

  return 0;
}
