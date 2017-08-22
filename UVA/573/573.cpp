/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int H, U, D, F;
  while(true) {
    cin >> H >> U >> D >> F;
    if (H == 0) break;


    int day = 0;
    double heigth = 0;
    double L = (U * F / 100.0);
    while (true) {
      heigth += max(U - day * L, 0.0);
      if (heigth > H) {
        cout << "success on day " << day+1 << endl;
        break;
      }
      heigth -= D;
      if (heigth < 0) {
        cout << "failure on day " << day+1 << endl;
        break;
      }
      day++;
    }
  }

  return 0;
}
