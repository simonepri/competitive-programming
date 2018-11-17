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

bool dfs(vector< vector<char> > &M, int N, int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= N || M[x][y] == '.') return false;

  bool alive = M[x][y] == 'x';
  M[x][y] = '.';
  alive |= dfs(M, N, x, y - 1);
  alive |= dfs(M, N, x, y + 1);
  alive |= dfs(M, N, x + 1, y);
  alive |= dfs(M, N, x - 1, y);
  return alive;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  vector< vector<char> > M;
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    M.resize(N);
    for (int i = 0; i < N; i++) {
      M[i].resize(N);
      for (int j = 0; j < N; j++) {
        cin >> M[i][j];
      }
      cin.ignore();
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (M[i][j] == '.') continue;
        bool alive = dfs(M, N, i, j);
        if (alive) count++;
      }
    }
    cout << "Case " << t << ": " << count << endl;
  }

  return 0;
}
