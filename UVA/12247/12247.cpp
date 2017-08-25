/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  vector<int> C(5);
  vector<int> lower(2);
  int *princess;
  int *prince;

  while (true) {
    cin >> C[0] >> C[1] >> C[2] >> C[3] >> C[4];
    if (C[0] == 0 && C[1] == 0 && C[2] == 0 && C[3] == 0 && C[4] == 0) break;

    sort(C.begin(), C.begin() + 3); // Princess
    sort(C.begin() + 3, C.end());   // Prince

    princess = &C[0];
    prince = &C[3];

    for (int j = 0; j < 2; j++) {
      int i = 0;
      while (i < 3 && princess[i] < prince[j]) i++;
      lower[j] = 3 - i;
    }

    int minsol = 1;
    switch (lower[0] + lower[1]) {
      case 0: break;
      case 1: minsol += princess[1]; break;
      case 2: minsol += (lower[0] == lower[1] ? princess[1] : princess[2]); break;
      case 3: minsol += (lower[0] == 3 || lower[1] == 3 ? princess[2] : -2); break;
      default: minsol += -2; break;
    }

    if (minsol != -1) {
      sort(C.begin(), C.end()); // Sort everything so we can know if the solution can be chosen
      for (int i = 0; i < 3; i++) if (princess[i] == minsol) minsol++;
      for (int i = 0; i < 2; i++) if (prince[i] == minsol) minsol++;
      if (minsol > 52) minsol = -1;
    }
    cout << minsol << endl;
  }

  return 0;
}
