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
  int N, count;
  string num;
  char one[] = {'o', 'n', 'e'};
  
  cin >> N;
  
  for(int i = 0; i < N; i++) {
    cin >> num;
    if(num.length() == 5) {
      cout << 3 << endl;
    }
    else {
      count = 0;
      for(int j = 0; j < 3; j++) {
        if(num[j] == one[j]) count++;
      }
      if(count >= 2) cout << 1 << endl;
      else cout << 2 << endl;
    }
  }
  return 0;
}
