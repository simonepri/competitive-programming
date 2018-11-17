/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int R, C, M, N;
    cin >> R >> C >> M >> N;

    int MAP[R][C] = {0};
    unordered_map< int, unordered_map<int, bool> > water;
    int W;
    cin >> W;
    for (int i = 0; i < W; i++) {
      int r, c;
      cin >> r >> c;
      water[r][c] = true;
      MAP[r][c] = 1;
    }

    int ans[] = {0, 0};
    int ver[][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    int mov[] = {M, N};
    queue< pair<int, int> > Q;
    unordered_map< int, unordered_map<int, bool > > V;
    Q.push({0, 0});
    V[0][0] = true;
    while (!Q.empty()) {
      pair<int,int> top = Q.front();
      Q.pop();
      int row = top.first, col = top.second;

      int count = 0;
      for (int i = 0, l = mov[0]*mov[1] == 0 ? 2 : 4; i < l; i++) {
        for (int j = 0, s = M == N ? 1 : 2; j < s; j++) {
          int nrow = row + ver[i][0] * mov[j];
          int ncol = col + ver[i][1] * mov[(j + 1) % 2];

          // Check if we are out of bounds or there's water.
          if (nrow < 0 || ncol < 0 || nrow >= R || ncol >= C || water[nrow][ncol]) continue;

          // Count that we can reach that cell.
          count++;

          // Push a cell into the queue once.
          if (V[nrow][ncol]) continue;
          V[nrow][ncol] = true;
          Q.push({nrow, ncol});
        }
      }
      ans[count % 2]++;
    }
    cout << "Case " << t << ": " << ans[0] << " " << ans[1] << endl;
  }

  return 0;
}
