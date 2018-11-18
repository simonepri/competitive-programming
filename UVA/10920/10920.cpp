/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <cmath>

#define ll long long

using namespace std;

// See https://web.archive.org/web/20141202041502/https://danpearcymaths.wordpress.com/2012/09/30/infinity-programming-in-geogebra-and-failing-miserably/
// See https://math.stackexchange.com/questions/163080/on-a-two-dimensional-grid-is-there-a-formula-i-can-use-to-spiral-coordinates-in
pair<ll, ll> spiral(ll n) {
  ll k = ceil((sqrt(n) - 1) / 2);
  ll t = 2 * k;
  ll m = pow(t + 1, 2);

  if (n >= m - t) return {k-(m-n), -k};
  else m -= t;
  if (n >= m - t) return {-k, -k+(m-n)};
  else m -= t;
  if (n >= m - t) return {-k+(m-n), k};
  else return {k, k-(m-n-t)};
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int SZ;
  ll P;
  while (true) {
    cin >> SZ >> P;
    if (SZ == 0 || P == 0) break;

    int center = (SZ + 1) / 2;
    auto coord = spiral(P);

    cout << "Line = " << center + coord.first << ", column = " << center - coord.second << "." << endl;
  }

  return 0;
}
