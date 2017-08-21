/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  const int MILE_COST  = 10, MILE_FRAME  = 30;
  const int JUICE_COST = 15, JUICE_FRAME = 60;

  int T, N, d;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    int mile = 0, juice = 0;
    cin >> N;
    for (int j = 0; j < N; j++) {
      cin >> d;
      mile  += MILE_COST  + (d / MILE_FRAME)  * MILE_COST;
      juice += JUICE_COST + (d / JUICE_FRAME) * JUICE_COST;
    }
    if (mile < juice) cout << "Case " << i << ": Mile " << mile << endl;
    else if(mile > juice) cout << "Case " << i << ": Juice " << juice << endl;
    else cout << "Case " << i << ": Mile Juice " << mile << endl;
  }

  return 0;
}
