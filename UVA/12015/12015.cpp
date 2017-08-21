/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string url;
  vector<string> rel;
  int T, rank;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    int max = 0;
    rel.clear();
    rel.reserve(10);
    for (int j = 0; j < 10; j++) {
      cin >> url >> rank;
      if (max > rank) continue;
      if (max < rank) {
        max = rank;
        rel.clear();
        rel.reserve(10);
      }
      rel.push_back(url);
    }

    cout << "Case #" << i << ":" << endl;
    for (vector<string>::iterator it = rel.begin(); it != rel.end(); it++) {
      cout << *it << endl;
    }
  }

  return 0;
}
