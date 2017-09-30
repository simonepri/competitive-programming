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

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int C;
  double K, D;
  int degree;
  int coeff[21];

  cin >> C;

  while (C-- > 0) {
    cin >> degree;
    for (int i = 0; i <= degree; i++) {
      cin >> coeff[i];
    }

    cin >> D;
    cin >> K;

    // D is a common factor.
    K /= D;
    // Now K is the sum of n elements (Gauss sum)
    // K = n * (n + 1) / 2
    // n = 1/2 (sqrt(1 + 8 * K) - 1)
    int n = ceil(0.5 * (sqrt(1 + 8 * K) - 1));

    // Compute an as explained in the problem.
    double an = 0.0;
    for (int j = 0; j <= degree; j++) {
      an += coeff[j] * pow(n, j);
    }

    cout << fixed << setprecision(0) << an << endl;
  }

  return 0;
}
