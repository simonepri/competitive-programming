/**
* Competitive Programming - Collection of solved problems.
*
* @author        Simone Primarosa,(http://simoneprimarosa.com)
* @link          (https://github.com/simonepri/competitive-programming)
* @license       MIT License (https://opensource.org/licenses/MIT)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int T;
  vector<int> E(3);
  
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cin >> E[0] >> E[1] >> E[2];
    
    sort(E.begin(), E.end());
    cout << "Case " << i << ": " << E[1] << endl;
  }
  return 0;
}
