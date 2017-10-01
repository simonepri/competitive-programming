/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

#include <cmath>

using namespace std;

int V, maxb;
vector< vector<int> > graph;
vector<int> colors;
vector<int> sol;

#define WHT 0
#define BLK 1

void getMaximalIndependentSet(int colored) {
  if (colored > maxb) {
    maxb = colored;
    for (int i = 0; i < V; i++) sol[i] = colors[i];
  }
  if (colored == V) return;

  for (int i = 0; i < V; i++) {
    if (colors[i] == BLK) continue;

    bool blackAdjs = false;
    for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
      if (colors[*it] == WHT) continue;
      blackAdjs = true;
      break;
    }
    if (blackAdjs) continue;

    colors[i] = BLK;
    getMaximalIndependentSet(colored + 1);
    colors[i] = WHT;
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, E;
  int a, b;
  cin >> T;
  while (T-- > 0) {
    cin >> V >> E;
    graph.clear();
    graph.resize(V);
    for (int i = 0; i < E; i++) {
      cin >> a >> b;
      a--, b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    maxb = 0;
    colors.assign(V, WHT);
    sol.resize(V);

    // All vertex that are alone are always black.
    int start = 0;
    for (int i = 0; i < V; i++) {
      if (graph[i].size() == 0) {
        start++;
        colors[i] = BLK;
      }
    }
    // Try to color them in a backtracking fashion
    getMaximalIndependentSet(start);

    cout << maxb << endl;
    bool first = true;
    for (int i = 0; i < V; i++) {
      if (sol[i] == BLK) {
        if (!first) cout << " ";
        cout << i + 1;
        first = false;
      }
    }
    cout << endl;
  }
  return 0;
}
