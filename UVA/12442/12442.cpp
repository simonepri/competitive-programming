/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

using namespace std;

int dfs(vector<int> &G, vector<int> &sol, int cur, int deep) {
  int succ = G[cur];
  if (sol[succ] > 0) {
    sol[cur] = sol[succ] + 1;
    return -1;
  } else if (sol[succ] < 0) {
    sol[cur] = deep + sol[succ] + 1;
    return succ;
  } else {
    sol[cur] = -deep;
    int ca = dfs(G, sol, succ, deep + 1);
    if (ca == -1) sol[cur] = sol[succ] + 1;
    else sol[cur] = sol[succ];
    return ca == cur ? -1 : ca;
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    vector<int> G(N);
    for (int i = 0; i < N; i++) {
      int A, B;
      cin >> A >> B;
      G[A - 1] = B - 1;
    }

    vector<int> sol(N, 0);
    for (int i = 0; i < N; i++) {
      if (sol[i] > 0) continue;
      dfs(G, sol, i, 1);
    }

    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
      if (sol[i] > sol[maxIdx]) maxIdx = i;
    }

    cout << "Case " << t << ": " << maxIdx + 1 << endl;
  }

  return 0;
}
