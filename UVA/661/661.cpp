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

  int N, M, C, test = 1;
  vector<int> devices;

  while (true) {
    int ampere = 0, maxamp = 0;
    devices.clear();

    cin >> N >> M >> C;
    if (N == 0 && M == 0 && C == 0) break;

    devices.resize(N);

    for (int i = 0; i < N; i++) {
      cin >> devices[i];
    }

    for (int i = 0; i < M; i++) {
      int idx;
      cin >> idx;
      if (ampere > C) continue;
      idx--;
      ampere += devices[idx];
      if (ampere > maxamp) maxamp = ampere;
      devices[idx] *= -1;
    }
    cout << "Sequence " << test++ << endl;
    if (ampere > C) cout << "Fuse was blown." << endl;
    else {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << maxamp << " amperes." << endl;
    }
    cout << endl;
  }

  return 0;
}
