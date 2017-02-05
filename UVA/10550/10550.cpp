/**
* Competitive Programming - Collection of solved problems.
*
* @author        Simone Primarosa,(http://simoneprimarosa.com)
* @link          (https://github.com/simonepri/competitive-programming)
* @license       MIT License (https://opensource.org/licenses/MIT)
*/

#include <iostream>

using namespace std;

int getDist(int from, int to) {
  return (40 + from - to) % 40;
}

int toDegree(int dist) {
  return dist*9;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int pos, c1, c2, c3, count;
  
  while(true) {
    cin >> pos >> c1 >> c2 >> c3;
    if(!pos && !c1 && !c2 && !c3) break;
    
    count = 1080 + toDegree(getDist(pos, c1) + getDist(c2, c1) + getDist(c2, c3));
    
    cout << count << endl;
  }
  return 0;
}
