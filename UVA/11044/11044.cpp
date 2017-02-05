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
  int t, n, m;
  
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n >> m;
    cout << int(ceil((n-2)/3.0) * ceil((m-2)/3.0)) << endl;
  }
  return 0;
}
