/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

char L[102][102];
char T[102][102] = {};

inline void match(char &p1, char &p2, char &sp1, char &sp2) {
  switch (p1 - p2) {
    case 'R'-'S': case 'S'-'P': case 'P'-'R': sp2 = p1; break;
    case 'R'-'P': case 'S'-'R': case 'P'-'S': sp1 = p2; break;
  }
}

inline void war(int R, int C) {
  R--; C--;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      match(L[r][c], L[r][c + 1], T[r][c], T[r][c + 1]);
      match(L[r][c], L[r + 1][c], T[r][c], T[r + 1][c]);
    }
    match(L[r][C], L[r + 1][C], T[r][C], T[r + 1][C]);
  }
  for (int c = 0; c < C; c++) {
    match(L[R][c], L[R][c + 1], T[R][c], T[R][c + 1]);
  }

  R++; C++;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (!T[r][c]) continue;
      L[r][c] = T[r][c];
      T[r][c] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, R, C, N;
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> R >> C >> N;
    for (int r = 0; r < R; r++) {
      cin >> L[r];
    }

    while (N-- > 0) {
      war(R, C);
    }

    if (t != 0) cout << endl;
    for (int r = 0; r < R; r++) {
      cout << L[r] << endl;
    }
  }

  return 0;
}
