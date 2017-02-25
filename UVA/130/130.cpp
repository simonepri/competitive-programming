 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>

#include <list>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

void circularNext(list<int> &L, list<int>::iterator &it, const int &pos) {
  int circ = pos % L.size();
  if(it == L.end()) it = L.begin(); // go to head
  for(int j = 0; j < pos; j++) {
    it++;
    if(it == L.end()) it = L.begin(); // go to head
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  
  int N, K;
  list<int>::iterator it, next;
  while(true) {
    cin >> N >> K;
    if(!N && !K) break;
    list<int> Q;
    for(int i = 1; i <= N; i++) {
      Q.push_back(i);
    }
    
    it = Q.begin();
    while(Q.size() != 1) {
      circularNext(Q, it, K-1);
      
      it = Q.erase(it);
      next = it, circularNext(Q, next, K-1);
      it = Q.insert(it, *next);
      Q.erase(next);
      
      circularNext(Q, it, 1);
    }
    cout << ((N - *it + 1) % N + 1) << endl;
  }
return 0;
}
