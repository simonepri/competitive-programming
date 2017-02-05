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
  int K, N, M, x, y;
  
  while(true) {
    cin >> K;
    if(!K) break;
    
    cin >> N >> M;
    for(int i = 0; i < K; i++) {
      cin >> x >> y;
      if(x == N || y == M) cout << "divisa" << endl;
      else if(x > N && y > M) cout << "NE" << endl;
      else if(x > N && y < M) cout << "SE" << endl;
      else if(x < N && y < M) cout << "SO" << endl;
      else if(x < N && y > M) cout << "NO" << endl;
    }
  }
  return 0;
}
