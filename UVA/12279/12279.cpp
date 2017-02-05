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
  int N, e, balance, count = 1;
  
  while(true) {
    cin >> N;
    if(!N) break;
    
    balance = 0;
    for(int i = 0; i < N; i++) {
      cin >> e;
      if(!e) balance--;
      else if(e >= 1 && e <= 99) balance++;
    }
    
    cout << "Case " << count << ": " << balance << endl;
    count++;
  }
  return 0;
}
