/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

int C[100][100] = {};
int offsets[8][2] = {{0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}};

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  char c;
  int n, m, t = 0;
  while (true) {
    t++;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c;
        if (c != '*') continue;
        for (int k = 0; k < 8; k++) {
          int *off = offsets[k];
          int I = i + off[0];
          if (I < 0 || I >= n) {
            k += 2;
            continue;
          }
          int J = j + off[1];
          if (J < 0 || J >= m) continue;
          if (C[I][J] == -1) continue;
          C[I][J]++;
        }
        C[i][j] = -1;
      }
    }
    if (t != 1) cout << endl;
    cout << "Field #" << t << ":" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v = C[i][j];
        if (v == -1) cout << '*';
        else cout << v;
        C[i][j] = 0;
      }
      cout << endl;
    }
  }

  return 0;
}
