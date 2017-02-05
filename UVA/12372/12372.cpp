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
  int T, L, W, H;
  
  cin >> T;
  
  for(int i = 1; i <= T; i++) {
    cin >> L >> W >> H;
    if(L > 20 || W > 20 || H > 20) cout << "Case " << i << ": bad" << endl;
    else cout << "Case " << i << ": good" << endl;
  }
  return 0;
}
