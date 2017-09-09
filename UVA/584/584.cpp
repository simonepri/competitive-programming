/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

inline void useBonus(int &pins, int &bonus) {
  if (bonus >= 3) {
    pins *= 3;
    bonus -= 2;
  } else if (bonus > 0) {
    pins *= 2;
    bonus--;
  }
}

inline void addScore(string &game, int &roll, int &frame, bool &half, int &bonus, int &score) {
  int pins;
  switch (game[roll]) {
    case 'X': {
      pins = 10;
      useBonus(pins, bonus);
      score += pins;

      if (frame < 10) bonus += 2;
      frame++;
      break;
    }
    case '/': {
      pins = 10 - (game[roll - 2] - '0');
      useBonus(pins, bonus);
      score += pins;

      if (frame < 10) bonus++;
      frame++;
      if (half) half = false;
      break;
    }
    default: {
      pins = game[roll] - '0';
      useBonus(pins, bonus);
      score += pins;

      if (half) {
        frame++;
        half = false;
      }
      else {
        half = true;
      }
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while (true) {
    string line;
    getline(cin, line);
    if (line[0] == 'G') break;

    bool half = false;
    int len = line.size();
    int score = 0, frame = 1, bonus = 0;
    
    for (int roll = 0; roll < len; roll += 2) {
      addScore(line, roll, frame, half, bonus, score);
    }
    cout << score << endl;
  }

  return 0;
}
