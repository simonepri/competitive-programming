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
  int N, len;
  string S;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S;
    len = S.length();
    
    if((len == 1 && (S[0] == '1' || S[0] == '4')) || (len == 2 && S[0] == '7' && S[1] == '8')) {
      cout << '+' << endl;
    }
    else if((len >= 2 && S[len-2] == '3' && S[len-1] == '5')) {
      cout << '-' << endl;
    }
    else if((len >= 2 && S[0] == '9' && S[len-1] == '4')) {
      cout << '*' << endl;
    }
    else if((len >= 3 && S[0] == '1' && S[1] == '9' && S[2] == '0')) {
      cout << '?' << endl;
    }
  }
return 0;
}
