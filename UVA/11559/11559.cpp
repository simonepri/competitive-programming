/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int N, B, H, W;
  while(cin >> N >> B >> H >> W) {
    int minc = -1;
    for (int i = 0; i < H; i++) {
      int price;
      cin >> price;
      int cost = price * N;
      for (int j = 0; j < W; j++) {
        int beds;
        cin >> beds;
        if (cost > B) continue;
        if (beds < N) continue;
        if (cost < minc || minc == -1) minc = cost;
      }
    }
    if (minc == -1) {
      cout << "stay home" << endl;
    } else {
      cout << minc << endl;
    }
  }

  return 0;
}
