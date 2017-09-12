/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

using namespace std;

bool isGreen(const int &cycle, const int &elapsed) {
  int rem = elapsed % (cycle * 2);
  return (rem > 0 && rem <= cycle - 5);
}

string formatSec(int sec) {
  int hours = sec / 3600;
  sec = sec % 3600;
  int mins = sec / 60;
  sec = sec % 60;

  string out = "";
  if (hours < 10) out += '0';
  out += to_string(hours);
  out += ':';
  if (mins < 10) out += '0';
  out += to_string(mins);
  out += ':';
  if (sec < 10) out += '0';
  out += to_string(sec);
  return out;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int tl;
  vector<int> v(128);
  while (true) {
    int len = 0;
    while (true) {
      cin >> tl;
      if (tl == 0) break;
      if (v.size() == len) v.resize(len * 2);
      v[len++] = tl;
    }
    if (!len) break;

    int time = 0;
    int start = 0;

    // Exclude the initial portion while they are all still green.
    while (true) {
      time++;
      bool green = true;
      for (int i = 0; i < len; i++) {
        if (isGreen(v[i], time)) continue;
        green = false;
        break;
      }
      if (!green) break;
    }

    // Find an instant at witch they are all green again.
    while (time <= 5 * 60 * 60 + 1) {
      time++;
      bool green = true;
      for (int i = 0; i < len; i++) {
        if (isGreen(v[i], time)) continue;
        green = false;
        break;
      }
      if (green) break;
    }

    if (time - 1 > 5 * 60 * 60) {
      cout << "Signals fail to synchronise in 5 hours" << endl;
    } else {
      cout << formatSec(time - 1) << endl;
    }
  }

  return 0;
}
