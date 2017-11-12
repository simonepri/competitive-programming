/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<bool> S;
vector< vector<pii> > G;

// Returns a pair<c1, c2> where:
// c1: is the cost to visit all friends in the subtree rooted by this node and then climb up.
// c2: is the cost to visit all friends in the subtree rooted by this node and then rest in one of his subnodes.
pii visit(const int &node, const int &weight) {
  if (G[node].size() == 0) {
    return make_pair(S[node] ? weight : 0, 0);
  }

  bool bf = false;
  pii energies = make_pair(0, 0), best;
  for (auto it = G[node].begin(); it != G[node].end(); it++) {
    pii temp = visit(it->first, it->second);

    energies.first += temp.first;
    if (!bf || best.first - best.second < temp.first - temp.second) {
      best = temp;
      bf = true;
    }
  }
  energies.second = energies.first;
  // Subtract the cost of climbing up and add the cost to rest in this subtree.
  energies.second -= best.first;
  energies.second += best.second;

  if (S[node] || energies.first > 0) energies.first += weight;
  return energies;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while (true) {
    int N, F, a, b, w;
    cin >> N >> F;
    if (!cin) break;

    G.clear();
    G.resize(N);
    S.assign(N, 0);

    for (int i = 0; i < N - 1; i++) {
      cin >> a >> b >> w;
      a--; b--;
      G[a].push_back(make_pair(b, w));
    }
    for (int i = 0; i < F; i++) {
      cin >> a;
      a--;
      S[a] = true;
    }
    cout << visit(0, 0).second << endl;
  }

  return 0;
}
