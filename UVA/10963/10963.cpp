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
  int N, W, y0, y1;
  string s;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    getline(cin, s);
    cin >> W;
    
    int dif = -1, tmp;
    for(int i = 0; i < W; i++) {
      cin >> y0 >> y1;
      if(dif == -2) continue;
      tmp = abs(y0 - y1);
      if(dif == -1) dif = tmp;
      else if(tmp != dif) dif = -2;
    }
    if(dif == -2) cout << "no" << endl;
    else cout << "yes" << endl;
    if(i < N-1) cout << endl;
  }
  
  return 0;
}
