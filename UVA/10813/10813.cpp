/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

#define SKIP_POS 12

int COL[5] = {5, 5, 5, 5, 5};
int ROW[5] = {5, 5, 5, 5, 5};
int DIA[2] = {5, 5};
int CARD[25];
int POS[76] = {
  -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

inline bool mark(const int pos) {
  int col = pos % 5;
  COL[col]--;
  if (!COL[col]) return true;

  int row = pos / 5;
  ROW[row]--;
  if (!ROW[row]) return true;

  if (pos % 6 == 0) {
    DIA[0]--;
    if (!DIA[0]) return true;
  }
  if (pos >= 4 && pos <= 20 && pos % 4 == 0) {
    DIA[1]--;
    if (!DIA[1]) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, V, B;
  cin >> T;
  while (T-- > 0) {
    for (int i = 0; i < 25; i++) {
      cin >> V;
      CARD[i] = V;
      POS[V] = i;
      if (i == SKIP_POS - 1) {
        i++;
        CARD[i] = -1;
      }
    }
    mark(SKIP_POS);

    int win = 0;
    for (int i = 1; i <= 75; i++) {
      cin >> B;
      if (win) continue;
      if (POS[B] == -1) continue;
      if (mark(POS[B])) win = i;
    }
    cout << "BINGO after " << win << " numbers announced" << endl;

    if (T > 0) {
      for (int i = 0; i < 25; i++) {
        if (i == SKIP_POS) continue;
        POS[CARD[i]] = -1;
      }
      for (int i = 0; i < 5; i++) {
        COL[i] = ROW[i] = 5;
      }
      for (int i = 0; i < 2; i++) {
        DIA[i] = 5;
      }
    }
  }

  return 0;
}
