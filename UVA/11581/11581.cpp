/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <algorithm>

using namespace std;

inline void f(short i[3][3], short o[3][3]) {
  o[0][0] = (i[0+1][0] + i[0][0+1]) & 1;
  o[0][1] = (i[0+1][1] + i[0][1+1] + i[0][1-1]) & 1;
  o[0][2] = (i[0+1][2] + i[0][2-1]) & 1;
  o[1][0] = (i[1-1][0] + i[1+1][0] + i[1][0+1]) & 1;
  o[1][1] = (i[1-1][1] + i[1+1][1] + i[1][1+1] + i[1][1-1]) & 1;
  o[1][2] = (i[1-1][2] + i[1+1][2] + i[1][2-1]) & 1;
  o[2][0] = (i[2-1][0] + i[2][0+1]) & 1;
  o[2][1] = (i[2-1][1] + i[2][1+1] + i[2][1-1]) & 1;
  o[2][2] = (i[2-1][2] + i[2][2-1]) & 1;
}

inline bool empty(short i[3][3]) {
  return !(i[0][0] | i[0][1] | i[0][2] | i[1][0] | i[1][1] | i[1][2] | i[2][0] | i[2][1] | i[2][2]);
}

inline void print(short m[3][3]) {
  for (int i = 0; i < 3; i++) {for (int j = 0; j < 3; j++) {cout << m[i][j];} cout << endl;}
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  short g[2][3][3];

  int T;
  cin >> T; cin.ignore();
  while (T--) {
    cin.ignore();

    char chr;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> chr;
        g[0][i][j] = chr - '0';
      }
    }

    bool c = 0;
    int count = -1;
    while (!empty(g[c])) {
      f(g[c], g[!c]);
      c = !c;
      count++;
    }
    cout << count << endl;

  }

  return 0;
}
