/**
* Competitive Programming - Collection of solved problems.
*
* @author        Simone Primarosa,(http://simoneprimarosa.com)
* @link          (https://github.com/simonepri/competitive-programming)
* @license       MIT License (https://opensource.org/licenses/MIT)
*/

#include <iostream>
#include <limits>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int t, N, s, min, max;
  
  cin >> t;
  for(int i = 0; i < t; i++) {
    min = numeric_limits<int>::max();
    max = 0;
    
    cin >> N;
    for(int j = 0; j < N; j++) {
      cin >> s;
      if(s > max) max = s;
      if(s < min) min = s;
    }
    cout << (max - min) * 2 << endl;
  }
  return 0;
}
