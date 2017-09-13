/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <iomanip>

#include <string>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string line;

  // Print always 3 decimal places.
  cout << setprecision(3) << fixed;

  while (true) {
    cin >> line;
    double m, h;
    if (line.size() == 5) {
      h = (line[0] - '0') * 10 + line[1] - '0';
      m = (line[3] - '0') * 10 + line[4] - '0';
    } else {
      h = line[0] - '0';
      m = (line[2] - '0') * 10 + line[3] - '0';
    }
    if (m == 0 && h == 0) break;
    if (m > 0) {
      h += m / 60.0;
      if (h > 12) h -= 12;
    }

    // 360 : 12 = ah : h
    double a1 = 360.0 * h / 12;

    // 360 : 60 = am : m
    double a2 = 360.0 * m / 60;

    double diff = abs(a1 - a2);
    if (diff > 180) diff = 360.0 - diff;

    cout << diff << endl;
  }

  return 0;
}
