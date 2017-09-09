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

#define IS_NP 0
#define IS_PA 1
#define IS_MI 2
#define IS_MP 3

char reverse(char a) {
  switch (a) {
    case 'A': return 'A';
    case 'E': return '3';
    case 'H': return 'H';
    case 'I': return 'I';
    case 'J': return 'L';
    case 'L': return 'J';
    case 'M': return 'M';
    case 'O': return 'O';
    case 'S': return '2';
    case 'T': return 'T';
    case 'U': return 'U';
    case 'V': return 'V';
    case 'W': return 'W';
    case 'X': return 'X';
    case 'Y': return 'Y';
    case 'Z': return '5';
    case '0': return '0';
    case '1': return '1';
    case '2': return 'S';
    case '3': return 'E';
    case '5': return 'Z';
    case '8': return '8';
  }
  return 0;
}

int getType(string &str) {
  bool pali = true;
  bool mirr = true;
  int len = str.size();
  int last = str.size() - 1;
  for (int i = 0; i < len; i++) {
    if (str[i] != str[last - i]) {
      pali = false;
    }
    if (str[i] != reverse(str[last - i])) {
      mirr = false;
    }
    if (!pali && ! mirr) return IS_NP;
  }
  if (mirr && pali) return IS_MP;
  if (mirr) return IS_MI;
  return IS_PA;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string line;

  while (true) {
    cin >> line;
    if (!cin) break;
    switch (getType(line)) {
      case IS_NP: cout << line << " -- is not a palindrome." << endl << endl; break;
      case IS_PA: cout << line << " -- is a regular palindrome." << endl << endl; break;
      case IS_MI: cout << line << " -- is a mirrored string." << endl << endl; break;
      case IS_MP: cout << line << " -- is a mirrored palindrome." << endl << endl; break;
    }
  }

  return 0;
}
