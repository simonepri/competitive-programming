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

  int T;
  string str;
  cin >> T;
  while (T-- > 0) {
    cin >> str;
    int end = str.size() - 1;

    // Best solution found. Initially is the first char.
    int soli = 0, solj = 0;
    int idx = 0, subi = str.size() - 1, subj = str.size() - 1;

    while (subi >= 0 && idx <= end) {
      if (str[idx] == str[subi]) {
        // Update solution if is the actual sub is longer than the best found.
        if (idx > solj - soli) {
          soli = subi;
          solj = subj;
        }
        // Try to increase sub length.
        subi--;
        idx++;
      } else if (idx > 0) {
        // Increasing sub length failed. Restart from the last pos.
        idx = 0;
        subj = subi;
      } else {
        // No sub found.
        subi--;
        subj = subi;
      }
    }

    // Print the solution.
    for (int i = soli; i <= solj; i++) {
      cout << str[i];
    }
    cout << endl;
  }

  return 0;
}
