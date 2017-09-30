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

typedef pair<int, int> pii;

int dist(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int M;
  char C;
  while (true) {
    cin >> M;
    if (!cin) break;
    vector<pii> one;
    vector<pii> three;
    for (int y = 0; y < M; y++) {
      for (int x = 0; x < M; x++) {
        cin >> C;
        if (C == '1') one.push_back(make_pair(x, y));
        else if (C == '3') three.push_back(make_pair(x, y));
      }
    }

    int max = 0;
    for (int i = 0; i < one.size(); i++) {
      int min = -1;
      for (int j = 0; j < three.size(); j++) {
        int d = dist(one[i], three[j]);
        // cout << d << endl;
        if (min == -1 || d < min) min = d;
      }
      if (max < min) max = min;
    }
    cout << max << endl;
  }

  return 0;
}
