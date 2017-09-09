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

inline bool isAlphabet(char &c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

inline bool cie(char &c1, char &c2) {
  // (c ^ ' ') is a fast way to pass from lower to upper and vice versa.
  return c1 == c2 || (c1 ^ ' ') == c2;
}

bool isPalindrome(string &str) {
  int len = str.size();
  int i = 0, j = len - 1;
  while (i < j) {
    while (!isAlphabet(str[i])) i++; if(i >= j) return true;
    while (!isAlphabet(str[j])) j--; if(i >= j) return true;
    if (!cie(str[i], str[j])) return false;
    i++; j--;
  }
  return true;
}

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string line;

  while (true) {
    getline(cin, line);
    if (line.size() == 4 && line[0] == 'D' && line[1] == 'O' && line[2] == 'N' && line[3] == 'E') break;
    if (isPalindrome(line)) cout << "You won't be eaten!" << endl;
    else cout << "Uh oh.." << endl;
  }

  return 0;
}
