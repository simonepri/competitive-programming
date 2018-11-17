/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <sstream>

#include <string>
#include <unordered_set>

#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while(true) {
    int N;
    if (!(cin >> N)) break;

    unordered_set<int> S;
    int prev;
    cin >> prev;
    for (int i = 1; i < N; i++) {
      int num;
      cin >> num;
      S.insert(abs(num - prev));
      prev = num;
    }
    if (N == 1 || (S.size() == N - 1 && S.find(1) != S.end() && S.find(N - 1) != S.end())) cout << "Jolly" << endl;
    else cout << "Not jolly" << endl;
  }

  return 0;
}
