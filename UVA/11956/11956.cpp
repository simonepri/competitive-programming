/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include  <iomanip>

#include <string>

#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  char c;
  int T, D[100], pointer;
  string line;
  line.reserve(100000+1);

  cin >> T;

  cin.ignore();
  for (int i = 1; i <= T; i++) {
    pointer = 0;
    fill(D, D+100, 0);
    getline(cin, line);

    for (string::iterator it = line.begin(); it != line.end(); it++) {
      c = *it;
      switch (c) {
        case '+': D[pointer] = D[pointer] < 255 ? D[pointer] + 1 : 0; break;
        case '-': D[pointer] = D[pointer] > 0 ? D[pointer] - 1 : 255; break;
        case '>': pointer = pointer < 99 ? pointer + 1 : 0; break;
        case '<': pointer = pointer > 0 ? pointer - 1 : 99; break;
      }
    }

    cout << "Case " << dec << i << ": ";
    cout << setfill('0') << hex << uppercase;
    cout << setw(2) << D[0];
    for (int i = 1; i < 100; i++) {
      cout << " " << setw(2) << D[i];
    }
    cout << endl;
  }

  return 0;
}
