/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <cmath>

using namespace std;

inline bool isAlphabet(char &c) {
  return ('a' <= c && c <= 'z');
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  char line[10001];

  cin >> T;
  cin.ignore();
  for (int t = 1; t <= T; t++) {
    int len = 0;
    while (true) {
      cin.get(line[len]);
      if (line[len] == '\n') break;
      if (!isAlphabet(line[len])) continue;
      len++;
    }
    line[len] = '\0';

    bool nomagic = true;
    int K = sqrt(len);
    int K2 = K * K;
    if (K2 == len) {
      nomagic = false;
      int r = K2 - 1;
      int l = 0;
      int b = K2 - 1;
      for (int i = 0; i < K; i++) {
        if (line[i] != line[r] || line[i] != line[l] || line[i] != line[b]) {
          nomagic = true;
          break;
        }
        r -= K;
        l += K;
        b--;
      }
    }

    cout << "Case #" << t << ":" << endl;
    if (nomagic) {
      cout << "No magic :(" << endl;
    } else {
      cout << K << endl;
    }
  }

  return 0;
}
