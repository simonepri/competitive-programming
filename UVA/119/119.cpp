/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <cmath>

#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  bool first = true;
  int N, people, amount;
  string name;
  map<string, int> M;
  vector<string> L;

  while(cin >> N) {
    M.clear();
    L.clear();
    L.reserve(N);

    for (int i = 0; i < N; i++) {
      cin >> name;
      L.push_back(name);
      M[name] = 0;
    }
    for (int i = 0; i < N; i++) {
      cin >> name >> amount >> people;
      if (people < 1) continue;

      int gift = amount / people;
      M[name] -= gift * people;

      for (int j = 0; j < people; j++) {
        cin >> name;
        M[name] += gift;
      }
    }
    if (!first) cout << endl;
    for (vector<string>::iterator it = L.begin(); it != L.end(); it++) {
      name = *it;
      cout << name << " " << M[name] << endl;
    }
    first = false;
  }

  return 0;
}
