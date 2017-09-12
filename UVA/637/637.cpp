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

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int pages;
  while (true) {
    cin >> pages;
    if (!pages) break;

    cout << "Printing order for " << pages << " pages:" << endl;

    int sheet = 1;
    bool side = true;
    bool reverse = false;
    int top = 1; int bot = pages;

    if (pages == 1) {
      cout << "Sheet " << sheet << ", front: Blank, " << top++ << endl;
      continue;
    }

    switch (pages % 4) {
      case 1: {
        cout << "Sheet " << sheet << ", front: Blank, " << top++ << endl;
        cout << "Sheet " << sheet++ << ", back : " << top++ << ", " << "Blank" << endl;
        cout << "Sheet " << sheet << ", front: Blank, " << top++ << endl;
        reverse = true;
        side = !side;
        break;
      }
      case 2: {
        cout << "Sheet " << sheet << ", front: Blank, " << top++ << endl;
        cout << "Sheet " << sheet++ << ", back : " << top++ << ", " << "Blank" << endl;
        break;
      }
      case 3: {
        cout << "Sheet " << sheet << ", front: Blank, " << top++ << endl;
        cout << "Sheet " << sheet++ << ", back : " << top++ << ", " << bot-- << endl;
        break;
      }
    }

    while (bot - top >= 1) {
      if (side) {
        cout << "Sheet " << sheet << ", front: ";
      }
      else {
        cout << "Sheet " << sheet++ << ", back : ";
      }
      if (reverse) {
        cout << top++ << ", " << bot-- << endl;
      }
      else {
        cout << bot-- << ", " << top++ << endl;
      }
      reverse = !reverse;
      side = !side;
    }
  }

  return 0;
}
