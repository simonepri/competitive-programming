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

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while(true) {
    int B, N;
    cin >> B >> N;
    if (B == 0 && N == 0) break;
    vector<int> R(B+1);

    for (int i = 1; i <= B; i++) {
      cin >> R[i];
    }
    for (int i = 0; i < N; i++) {
      int D, C, V;
      cin >> D >> C >> V;
      R[C] += V;
      R[D] -= V;
    }

    bool bailout = false;
    for (int i = 1; i <= B; i++) {
      if (R[i] < 0) {
        bailout = true;
        break;
      }
    }

    if (bailout) cout << 'N' << endl;
    else cout << 'S' << endl;
  }
  return 0;
}
