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
  int t, n, num, ans;
  
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    
    num = 315*n + 36962;
    ans = abs((num - (num / 100)*100) / 10);
    
    cout << ans << endl;
  }
  return 0;
}
