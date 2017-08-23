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

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int i;
  string str, next;

  while (true) {
    i = 0;
    getline(cin, str);
    if (str[0] == 'E') break;

    while (true) {
      i++;
      next = to_string(str.size());
      if (next == str) break;
      str.swap(next);
    }
    cout << i << endl;
  }

  return 0;
}
