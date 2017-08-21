/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  string cmd;
  vector<int> list;
  int T, N, move;

  cin >> T;

  for (int i = 0; i < T; i++) {
    int pos = 0;
    cin >> N;
    list.clear();
    list.reserve(N);

    cin.ignore();
    for (int j = 0; j < N; j++) {
      getline(cin, cmd);

      switch (cmd[0]) {
        case 'L': move = -1;
          break;
        case 'R': move = 1;
          break;
        default: move = list[stoi(cmd.substr(8))-1];
      }
      list.push_back(move);
      pos += move;
    }
    cout << pos << endl;
  }

  return 0;
}
