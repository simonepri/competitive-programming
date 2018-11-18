/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <iomanip>

#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  cin >> T;

  while (T--) {
    int K;
    cin >> K;

    unordered_map<char, int> values;
    for (int i = 0; i < K; i++) {
      char c;
      cin >> c;
      cin >> values[c];
    }

    int M;
    cin >> M;
    cin.ignore();

    int pay = 0;
    string line;
    while (M--) {
      getline(cin, line);
      for (char c : line) {
        pay += values[c];
      }
    }

    cout << setprecision(2) << fixed << pay / 100.0 << "$" << endl;
  }

  return 0;
}
