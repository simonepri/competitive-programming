/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string word;
  map<string, pair<string, int>> dict;
  map<string, bool> out;
  while (true) {
    cin >> word;
    if (word.size() == 1 && word[0] == '#') break;

    string sword = word;
    transform(sword.begin(), sword.end(), sword.begin(), ::toupper);
    sort(sword.begin(), sword.end());
    dict[sword].first = word;
    dict[sword].second++;
  }

  for (map<string, pair<string, int>>::iterator it = dict.begin(); it != dict.end(); it++) {
    if (it->second.second == 1) {
      out[it->second.first] = true;
    }
  }
  for (map<string, bool>::iterator it = out.begin(); it != out.end(); it++) {
    cout << it->first << endl;
  }
  return 0;
}
