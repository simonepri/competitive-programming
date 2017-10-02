/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <iomanip>

#include <cmath>

using namespace std;

inline bool isNearZero(double x) {
  const double epsilon = 1e-6;
  return fabs(x) <= epsilon;
  // see Knuth section 4.2.2 pages 217-218
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int p, q, r, s, t, u;
  while (true) {
    cin >> p >> q >> r >> s >> t >> u;
    if (!cin) break;
    double precision = 1e-9;
    // The range in which we need to find x
    double range = 1.0 - 0.0;
    // We need at most this iterations to find x if available.
    int iterations = ceil(log2(range / precision));

    double x = -1;

    double lo = 0.0, hi = 1.0, mid = 0.0, ans = 0.0;
    for (int i = 0; i < iterations; i++) {
      mid = (lo + hi) / 2.0;

      double val = p * exp(-mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * pow(mid, 2) + u;

      if (isNearZero(val)) {
        x = mid;
        break;
      }
      else if (val < 0.0) hi = mid;
      else lo = mid;
    }
    if (x != -1.0) {
      cout << fixed << setprecision(4) << x << endl;
    } else {
      cout << "No solution" << endl;
    }
  }

  return 0;
}
