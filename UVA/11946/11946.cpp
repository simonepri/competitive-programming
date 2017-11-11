/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

using namespace std;

int map[] = {
  'O',
  'I',
  'Z',
  'E',
  'A',
  'S',
  'G',
  'T',
  'B',
  'P'
};

char decode(char c) {
  int idx = c - '0';
  if (idx < 0 || idx > 9) return c;
  return map[idx];
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  string line;

  cin >> T;
  cin.ignore();

  while (T-- > 0) {
    while (true) {
      getline(cin, line);
      if (line.size() == 0) break;
      for (int i = 0; i < line.size(); i++) {
        cout << decode(line[i]);
      }
      cout << endl;
    }
    if (T == 1) cout << endl;
  }

  return 0;
}
