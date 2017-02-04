 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int N, r;
  int mid, sum;
  vector<int> houses;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> r;
    
    houses.clear();
    houses.resize(r);
    for(int j = 0; j < r; j++) {
      cin >> houses[j];
    }
    
    sum = 0;
    mid = r/2;
    nth_element(houses.begin(), houses.begin()+mid, houses.end());
    for(int k = 0; k < mid; k++) {
      if(houses[k] == houses[mid]) continue;
      sum += houses[mid]-houses[k];
    }
    for(int k = mid+1; k < houses.size(); k++) {
      if(houses[k] == houses[mid]) continue;
      sum += houses[k]-houses[mid];
    }
    
    cout << sum << endl;
  }
	return 0;
}
