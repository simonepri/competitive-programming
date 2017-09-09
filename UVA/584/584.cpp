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

inline void addScore(char* shot, int &frame, bool &half, int &bonus, int &score) {
  int pins;
  switch (*shot) {
    case 'X': {
      pins = 10;
      useBonus(pins, bonus);
      score += pins;

      if (frame < 10) bonus += 2;
      frame++;
      break;
    }
    case '/': {
      pins = 10 - (*(shot - 2) - '0');
      useBonus(pins, bonus);
      score += pins;

      if (frame < 10) bonus++;
      frame++;
      if (half) half = false;
      break;
    }
    default: {
      pins = *shot - '0';
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
    char* shot = &(line[0]);
    char* end = &(line[len - 1]);
    while (shot <= end) {
      addScore(shot, frame, half, bonus, score);
      shot += 2;
    }
    cout << score << endl;
  }

  return 0;
}
