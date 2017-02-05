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
  int N;
  long a, b;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    if(a < b) cout << "<" << endl;
    else if(a > b) cout << ">" << endl;
    else cout << "=" << endl;
  }
  return 0;
}
