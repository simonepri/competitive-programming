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

/*
    | +y | +z | -y | -z | <- rotation applied
 +x | +y | +z | -y | -z |
 +y | -x | +y | +x | +y |
 +z | +z | -x | +z | +x |
 -x | -y | -z | +y | +z |
 -y | +x | -y | -x | -y |
 -z | -z | +x | -z | -x |
 ^- actual state
*/

#define ND -1 // Not Possible
#define PX 0  // +x
#define PY 1  // +y
#define PZ 2  // +z
#define MX 3  // -x
#define MY 4  // -y
#define MZ 5  // -z

const int transition[6][6] = {
  /*   actual state -^  ^-rotation applied */
  /*    |    +x | +y | +z | -x | -y | -z | <- rotation applied */
  /* +x |*/ {ND,  PY,  PZ,  ND,  MY,  MZ},
  /* +y |*/ {ND,  MX,  PY,  ND,  PX,  PY},
  /* +z |*/ {ND,  PZ,  MX,  ND,  PZ,  PX},
  /* -x |*/ {ND,  MY,  MZ,  ND,  PY,  PZ},
  /* -y |*/ {ND,  PX,  MY,  ND,  MX,  MY},
  /* -z |*/ {ND,  MZ,  PX,  ND,  MZ,  MX}
  /* ^- actual state */
};

const string states[6] = {"+x", "+y", "+z", "-x", "-y", "-z"};

int strToCode(string str) {
  int state;
  if (str[0] == '-') state = 3;
  else state = 0;
  return state + str[1] - 'x';
}

string codeToStr(int state) {
  return states[state];
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int L;
  string decision;

  while (true) {
    cin >> L;
    if (L == 0) break;

    int state = PX;
    for (int i = 1; i < L; i++) {
      cin >> decision;
      if (decision[0] == 'N') continue;

      state = transition[state][strToCode(decision)];
    }
    cout << codeToStr(state) << endl;
  }

  return 0;
}
