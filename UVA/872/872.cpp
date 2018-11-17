/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <sstream>

#include <vector>
#include <set>

#define vi vector<int>
#define vb vector<bool>
#define vii vector< vi >
#define si set<int>

using namespace std;

inline char enc(int i) {
  return i + 'A';
}
inline int dec(char c) {
  return c - 'A';
}

int toposorts_rec(vii &G, vi &indeg, si &roots, int node, vi path, int len) {
  // Print the topological sort.
  if (path.size() == len) {
    cout << enc(*path.begin());
    for (auto it = next(path.begin()); it != path.end(); it++) {
      cout << " " << enc(*it);
    }
    cout << endl;
    return 1;
  }

  int count = 0;

  // Remove the node and its edges temporarly.
  for (int adj : G[node]) {
    indeg[adj]--;
    if (indeg[adj] == 0) roots.insert(adj);
  }

  auto it = roots.begin();
  while (it != roots.end()) {
    int root = *it;
    roots.erase(it);
    path.push_back(root);
    count += toposorts_rec(G, indeg, roots, root, path, len);
    path.pop_back();
    it = next(roots.insert(root).first);
    //if (count == 0) break;
  }

  // Add the node and its edges back.
  for (int adj : G[node]) {
    indeg[adj]++;
    if (indeg[adj] == 1) roots.erase(adj);
  }

  return count;
}

void toposorts(vii &G, vi &indeg, int &len) {
  si roots;

  // Find all the roots.
  for (int i = 0; i < 26; i++) {
    if (indeg[i] == 0) roots.insert(i);
  }

  vi path;
  path.reserve(26);
  int count = 0;
  auto it = roots.begin();
  while (it != roots.end()) {
    int root = *it;
    roots.erase(it);
    path.push_back(root);
    count += toposorts_rec(G, indeg, roots, root, path, len);
    path.pop_back();
    it = next(roots.insert(root).first);
    //if (count == 0) break;
  }
  if (count == 0) {
    cout << "NO" << endl;
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  cin >> T;
  cin.ignore();
  while(T-- > 0) {
    string str;
    getline(cin, str);  // Ignore the blank line.

    // Read the graph and compute indegree of all nodes.
    getline(cin, str);
    stringstream ss1(str);
    string lab;
    int len = 0;
    vi indeg(26, -1);
    while(ss1 >> lab) {
      indeg[dec(lab[0])] = 0;
      len++;
    }
    vii G(26);
    getline(cin, str);
    stringstream ss2(str);
    string rule;
    while (ss2 >> rule) {
      G[dec(rule[0])].push_back(dec(rule[2]));
      indeg[dec(rule[2])]++;
    }

    // Print all topological sorts.
    toposorts(G, indeg, len);
    if (T > 0) cout << endl;
  }

  return 0;
}
