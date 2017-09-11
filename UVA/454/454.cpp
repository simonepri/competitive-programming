/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <map>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  string line;
  string sorted;
  map<string, string> M;

  cin >> T;
  cin.ignore();
  getline(cin, line); // First empty line

  while(T-- > 0) {
    M.clear();

    while (true) {
      getline(cin, line);
      int lenl = line.size();
      if (!cin || lenl == 0) break;

      sorted.clear();
      sorted.reserve(lenl);
      for (int i = 0; i < lenl; i++) {
        if (line[i] == ' ') continue;
        sorted += line[i];
      }
      sort(sorted.begin(), sorted.end());

      M[line] = sorted;
    }

    for (map<string, string>::iterator it1 = M.begin(); it1 != M.end(); it1++) {
      for (map<string, string>::iterator it2 = next(it1); it2 != M.end(); it2++) {
        if (it1->second.compare(it2->second) != 0) continue;
        cout << it1->first << " = " << it2->first << endl;
      }
    }
    if (T > 0) cout << endl;
  }

  return 0;
}
