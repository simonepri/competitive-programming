/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <algorithm>

using namespace std;

int getScore(string &game, int &roll) {
  if (game[roll] == 'X') {
    int pins = 10;
    if (game[roll + 4] == '/') pins += 10;
    else {
      pins += game[roll + 2] == 'X' ? 10 : (game[roll + 2] - '0');
      pins += game[roll + 4] == 'X' ? 10 : (game[roll + 4] - '0');
    }
    roll += 2;
    return pins;
  }
  if (game[roll + 2] == '/') {
    int pins = 10;
    pins += game[roll + 4] == 'X' ? 10 : (game[roll + 4] - '0');
    roll += 4;
    return pins;
  }
  int pins = (game[roll] - '0') + (game[roll + 2] - '0');
  roll += 4;
  return pins;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O


  while (true) {
    string line;
    getline(cin, line);
    if (line[0] == 'G') break;

    int len = line.size();
    int score = 0;

    int roll = 0;
    for (int i = 0; i < 10; i++) {
      score += getScore(line, roll);
    }
    cout << score << endl;
  }

  return 0;
}
