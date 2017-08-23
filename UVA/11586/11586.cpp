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

int strToType(string piece) {
  if (piece[0] == piece[1]) {
    if (piece[0] == 'M') return 1;
    return 2;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string pieces;
  int T, type, c[3];
  cin >> T;

  cin.ignore();
  for (int i = 0; i < T; i++) {
    c[0] = 0, c[1] = 0, c[2] = 0;
    getline(cin, pieces);
    int len = pieces.size();

    for (int i = 0; i < len; i+=3) {
      while (pieces[i] == ' ') i++;
      type = strToType(&pieces[i]);  // pieces.substr(i)
      c[type]++;
    }
    if (c[1] != c[2] || (c[0] < 2 && c[1] == 0)) cout << "NO LOOP" << endl;
    else cout << "LOOP" << endl;
  }

  return 0;
}
