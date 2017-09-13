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
  while (true) {
    cin >> line;
    double m = stoi(line.substr(line.size() - 2, line.size()));
    double h = stoi(line.substr(0, line.size() - 3));
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

    // cout << "a1 " << a1 << " a2 " << a2 << endl;
    cout << setprecision(3) << fixed << diff << endl;
  }

  return 0;
}
