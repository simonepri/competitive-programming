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

char CB[8][8] = {};

int mark(char pos, int r, int c) {
  int changes = 0;
  switch (pos) {
    // Pawn ♙
    case 'p': {
      int br = r + 1;
      if (br > 7) break;
      char *row = CB[br];
      if (c < 7) {
        char *p = &row[c + 1];
        if (*p == ' ') {
          *p = 'x';
          changes++;
        }
      }
      if (c > 0) {
        char *p = &row[c - 1];
        if (*p == ' ') {
          *p = 'x';
          changes++;
        }
      }
      break;
    }
    case 'P': {
      int br = r - 1;
      if (br < 0) break;
      char *row = CB[br];
      if (c < 7) {
        char *p = &row[c + 1];
        if (*p == ' ') {
          *p = 'x';
          changes++;
        }
      }
      if (c > 0) {
        char *p = &row[c - 1];
        if (*p == ' ') {
          *p = 'x';
          changes++;
        }
      }
      break;
    }
    // Knigth ♘
    case 'n': case 'N': {
      int rb, rc;
      int moves[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
      for (int m = 0; m < 8; m++) {
        rb = r + moves[m][0], rc = c + moves[m][1];
        if (rb < 0 || rb > 7 || rc < 0 || rc > 7) continue;
        char *p = &CB[r + moves[m][0]][c + moves[m][1]];
        if (*p != ' ') continue;
        *p = 'x';
        changes++;
      }
      break;
    }
    // Bishop ♗
    case 'b': case 'B': {
      int br, bc;
      br = r, bc = c;
      while (br > 0 && bc > 0) {
        char *p = &CB[--br][--bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      br = r, bc = c;
      while (br > 0 && bc < 7) {
        char *p = &CB[--br][++bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      br = r, bc = c;
      while (br < 7 && bc < 7) {
        char *p = &CB[++br][++bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      br = r, bc = c;
      while (br < 7 && bc > 0) {
        char *p = &CB[++br][--bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      break;
    }
    // Rook ♖
    case 'r': case 'R': {
      int br, bc;
      br = r, bc = c;
      while (bc > 0) {
        char *p = &CB[br][--bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      bc = c;
      while (br > 0) {
        char *p = &CB[--br][bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      br = r;
      while (bc < 7) {
        char *p = &CB[br][++bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      bc = c;
      while (br < 7) {
        char *p = &CB[++br][bc];
        if (*p == 'x') continue;
        if (*p != ' ') break;
        *p = 'x';
        changes++;
      }
      break;
    }
    // Queen ♕
    case 'q': case 'Q': {
      changes += mark('r', r, c);
      changes += mark('b', r, c);
      break;
    }
    // King ♔
    case 'k': case 'K': {
      int rb, rc;
      int moves[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
      for (int m = 0; m < 8; m++) {
        rb = r + moves[m][0], rc = c + moves[m][1];
        if (rb < 0 || rb > 7 || rc < 0 || rc > 7) continue;
        char *p = &CB[rb][rc];
        if (*p != ' ') continue;
        *p = 'x';
        changes++;
      }
      break;
    }
  }
  return changes;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int r = 0, c = 0;
  string FEN;
  while (true) {
    int free = 8 * 8;
    cin >> FEN;
    if (!cin) break;

    r = 0, c = 0;
    for (string::iterator it = FEN.begin(); it != FEN.end(); it++) {
      switch (*it) {
        case '/': r++; c = 0; break;
        case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': {
          int i = *it - '0';
          while (i-- > 0) CB[r][c++] = ' ';
          break;
        }
        default: CB[r][c++] = *it;
      }
    }

    r = 0, c = 0;
    for (string::iterator it = FEN.begin(); it != FEN.end(); it++) {
      switch (*it) {
        case '/': r++; c = 0; break;
        case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': c += *it - '0'; break;
        default: free -= mark(*it, r, c) + 1; c++;
      }
    }
    cout << free << endl;
  }

  return 0;
}
