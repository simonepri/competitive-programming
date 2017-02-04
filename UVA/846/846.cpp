 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int N, x, y, steps, diff, n, s, r, c;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> x >> y;
    steps = 0;
    diff = y - x;
    n = floor((sqrt(1+4*diff)-1)/2);
    s = n*(n+1);
    r = (diff - s);
    
    c = (r > 0) ? ((r <= n+1) ? 1 : 2) : (0);
    steps = 2*n + c;
    
    //cout << "diff: " << diff << endl;
    //cout << " sumn: " << n << endl;
    //cout << " sum: " << s << endl;
    //cout << "remain: " << r << endl;
    //cout << " additional: " << c << endl;
    //cout << "steps:" << steps << endl;
    
    cout << steps << endl;
  }
	
	return 0;
}
