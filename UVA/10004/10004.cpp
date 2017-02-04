 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>

#include <vector>
#include <queue>

using namespace std;

bool isBicolorable(vector< vector<int> > &G) {
  vector<char> C(G.size());
  queue<int> Q;
  Q.push(0);
  C[0] = 'b';
  while(!Q.empty()) {
    int node = Q.front();
    Q.pop();
    char oldc = C[node];
    char newc = (oldc == 'a') ? ('b') : ('a');
    for(vector<int>::iterator it = G[node].begin(); it != G[node].end(); it++) {
      if(C[*it] == newc) continue;
      if(C[*it] == oldc) return false;
      C[*it] = newc;
      Q.push(*it);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int N, L, a, b;
  vector< vector<int> > G;
  
  while(true) {
    cin >> N;
    if(N == 0) break; 
    cin >> L;
    G.resize(N);
    
    for(int i = 0; i < L; i++) {
      cin >> a >> b;
      G[a].push_back(b);
    }
    
    cout << ((isBicolorable(G)) ? ("BICOLORABLE.") : ("NOT BICOLORABLE.")) << endl;
    G.clear();
  }
  return 0;
}
