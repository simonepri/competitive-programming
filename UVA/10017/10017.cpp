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

void printState(vector<int> *H) {
  char poles[] = "ABC";
  for(int i = 0; i < 3; i++) {
    cout << poles[i] << "=>";
    if(H[i].size() > 0) {
      cout << "  ";
      for(vector<int>::iterator it = H[i].begin(); it != H[i].end(); it++) {
        cout << " " << *it;
      }
    }
    cout << endl;
  }
  cout << endl;
}

void initState(vector<int> *H, const int &N, int &A, int &B, int &C) {
  H[0].clear();
  H[1].clear();
  H[2].clear();
  for(int i = N; i > 0; i--) {
    H[0].push_back(i);
  }
  if(N % 2 == 0) { // When even we should switch B and C
    A = 0; B = 2;  C = 1;
  }
  else {
    A = 0; B = 1; C = 2; 
  }
}

void nextState(vector<int> *H, const int &step, const int &A, const int &B, const int &C) {
  int from, to, pole1, pole2, top;
  int state = step % 3;
  
  switch(state) {
    case 1: {
      pole1 = A, pole2 = C; break;
    }
    case 2: {
      pole1 = A, pole2 = B; break;
    }
    case 0: {
      pole1 = B, pole2 = C; break;
    }
  }
  
  if(!H[pole1].size()) {
    from = pole2; to = pole1;
  }
  else if(!H[pole2].size()) {
    from = pole1; to = pole2;
  }
  else if(H[pole1].back() > H[pole2].back()) {
    from = pole2; to = pole1;
  }
  else {
    from = pole1; to = pole2;
  }
  
  top = H[from].back();
  H[from].pop_back();
  H[to].push_back(top);
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int n, m, count = 1;
  vector<int> H[3];
  while(true) {
    cin >> n >> m;
    if(!n && !m) return 0;
    
    cout << "Problem #" << count++ << endl << endl;
    int A, B, C;
    initState(H, n, A, B, C);
    printState(H);
    for(int i = 1; i <= m; i++) {
      nextState(H, i, A, B, C);
      printState(H);
    }
  }
	return 0;
}
