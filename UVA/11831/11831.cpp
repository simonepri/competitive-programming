/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

#define DIR_NORTH 'N'
#define DIR_EAST 'L'
#define DIR_SOUTH 'S'
#define DIR_WEST 'O'

#define ROT_NORTH 0
#define ROT_WEST 1
#define ROT_SOUTH 2
#define ROT_EAST 3

#define CELL_PILLAR '#'
#define CELL_STICKER '*'

#define CMD_FORWARD 'F'
#define CMD_RIGHT 'D'
#define CMD_LEFT 'E'

using namespace std;

inline void applyCmd(vector< vector<char> > &arena, int &R, int &C, int &row, int &col, int &rot, int &stickers, char &cmd) {
  switch (cmd) {
    case CMD_FORWARD: {
      int orow = row, ocol = col;
      switch (rot) {
        case ROT_NORTH: row--; break;
        case ROT_WEST: col--; break;
        case ROT_SOUTH: row++; break;
        case ROT_EAST: col++; break;
      }
      if (row < 0 || row >= R || col < 0 || col >= C || arena[row][col] == CELL_PILLAR) {
        row = orow;
        col = ocol;
      }
      if (arena[row][col] == CELL_STICKER) {
        stickers++;
        arena[row][col] = 0; // Get the sticker only once.
      }
      break;
    }
    case CMD_RIGHT: {
      rot = (rot + 4 - 1) % 4;
      break;
    }
    case CMD_LEFT: {
      rot = (rot + 1) % 4;
      break;
    }
  }
}

inline int dirToRot(char &c) {
  switch (c) {
    case DIR_NORTH: return ROT_NORTH;
    case DIR_WEST: return ROT_WEST;
    case DIR_SOUTH: return ROT_SOUTH;
    case DIR_EAST: return ROT_EAST;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while (true) {
    int N, M, S;
    cin >> N >> M >> S;
    if (N <= 0 || M <= 0 || S <= 0) break;

    // Read Arena and Start Point
    int row = -1, col = -1, rot = -1;
    vector< vector<char> > arena(N);
    for (int i = 0; i < N; i++) {
      arena[i].resize(M);
      for (int j = 0; j < M; j++) {
        cin >> arena[i][j];
        int enc = dirToRot(arena[i][j]);
        if (enc != -1) {
          row = i;
          col = j;
          rot = enc;
        }
      }
      cin.ignore();
    }

    // Apply Commands
    int stickers = 0;
    char cmd;
    for (int i = 0; i < S; i++) {
      cin >> cmd;
      applyCmd(arena, N, M, row, col, rot, stickers, cmd);
    }
    cin.ignore();
    cout << stickers << endl;
  }

  return 0;
}
