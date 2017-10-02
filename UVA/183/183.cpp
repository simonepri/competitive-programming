/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int R, C;
int deep;
string imm, type, line;

string encoded;
vector< vector<char> > decoded;

string padding[] = {
  "",
  " ",
  "  ",
  "   "
};

void decode(int r1, int c1, int r2, int c2) {
  if (r1 == r2 || c1 == c2) return;

  int ones = 0;
  for (int r = r1; r < r2; r++) {
    for (int c = c1; c < c2; c++) {
      if (imm[r * C + c] == '1') ones++;
    }
  }

  // All zero
  if (ones == 0) {
    encoded += '0';
    return;
  }
  // All one
  if (ones == (r2 - r1) * (c2 - c1)) {
    encoded += '1';
    return;
  }
  encoded += 'D';

  int rh = (r2 + r1 + 1) / 2;
  int ch = (c2 + c1 + 1) / 2;
  // Top Left
  decode(r1, c1, rh, ch);
  // Top Right
  decode(r1, ch, rh, c2);
  // Bottom Left
  decode(rh, c1, r2, ch);
  // Bottom Right
  decode(rh, ch, r2, c2);
}

void encode(int r1, int c1, int r2, int c2) {
  if (r1 == r2 || c1 == c2) return;
  if (deep >= imm.size()) return;

  if (imm[deep] != 'D') {
    for (int r = r1; r < r2; r++) {
      for (int c = c1; c < c2; c++) {
        decoded[r][c] = imm[deep];
      }
    }
    deep++;
    return;
  }
  deep++;

  int rh = (r2 + r1 + 1) / 2;
  int ch = (c2 + c1 + 1) / 2;
  // Top Left
  encode(r1, c1, rh, ch);
  // Top Right
  encode(r1, ch, rh, c2);
  // Bottom Left
  encode(rh, c1, r2, ch);
  // Bottom Right
  encode(rh, ch, r2, c2);
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while (true) {
    getline(cin, line);
    stringstream ss(line);
    ss >> type;

    if (type[0] == '#') break;
    ss >> R >> C;
    imm.reserve(R * C);

    // Read all lines for this images
    char chr;
    imm = "";
    while (true) {
      getline(cin, line);
      // Put again in the stream the line read if it's not part of the image.
      if (line[0] == '#' || line[1] == ' ') {
        cin.putback('\n');
        for (int i = line.size() - 1; i >= 0; i--) {
          cin.putback(line[i]);
        }
        break;
      }
      imm += line;
    }

    if (type[0] == 'B') {
      // Start encoding
      encoded.reserve(2 * R * C);
      encoded = "";
      decode(0, 0, R, C);

      // Print the solution
      string rs = to_string(R);
      string cs = to_string(C);
      cout << "D" << padding[4 - rs.size()] << rs << padding[4 - cs.size()] << cs << endl;

      int printed = 0;
      for (int i = 0; i < encoded.size(); i++) {
        // The output should be splitted each 50 chars.
        if (printed > 0 && printed % 50 == 0) cout << endl;
        cout << encoded[i];
        printed++;
      }
      cout << endl;
    } else {
      // Start decoding
      decoded.resize(R);
      for (int r = 0; r < R; r++) decoded[r].resize(C);
      deep = 0;
      encode(0, 0, R, C);

      // Print the solution
      string rs = to_string(R);
      string cs = to_string(C);
      cout << "B" << padding[4 - rs.size()] << rs << padding[4 - cs.size()] << cs << endl;

      int printed = 0;
      for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
          // The output should be splitted each 50 chars.
          if (printed > 0 && printed % 50 == 0) cout << endl;
          cout << decoded[r][c];
          printed++;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
