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

string sum(string str) {
  string s = "";
  int tmp = 0;
  for(int i = 0; i < str.length(); i++) {
    tmp += str[i] - '0';
  }
  return to_string(tmp);
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  string n;
  
  while(true) {
    cin >> n;
    if(n.length() == 1 && n[0] == '0') break;
    while(n.length() > 1) {
      n = sum(n);
    }
    cout << n << endl;
  }
  return 0;
}
