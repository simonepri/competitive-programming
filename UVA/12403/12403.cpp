/**
* Competitive Programming - Collection of solved problems.
*
* @author        Simone Primarosa,(http://simoneprimarosa.com)
* @link          (https://github.com/simonepri/competitive-programming)
* @license       MIT License (https://opensource.org/licenses/MIT)
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int T;
  int balance = 0, k;
  string str;
  
  cin >> T;
  
  for(int i = 1; i <= T; i++) {
    cin >> str;
    if(str[0] == 'd') {
      cin >> k;
      balance += k;
    }
    else cout << balance << endl;
  }
  return 0;
}
