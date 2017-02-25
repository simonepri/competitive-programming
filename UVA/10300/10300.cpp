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
  int N, f;
  int space, animals, envgrade, sum;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    sum = 0;
    
    cin >> f;
    for(int j = 0; j < f; j++) {
      cin >> space >> animals >> envgrade;
      sum += space * envgrade;
    }
    cout << sum << endl;
  }
  return 0;
}
