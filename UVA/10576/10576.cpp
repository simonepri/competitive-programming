/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

int s, d;
int status;

bool valid() {
  int chunk = 0;
  chunk += status & (1 << 0) ? s : -d;
  chunk += status & (1 << 1) ? s : -d;
  chunk += status & (1 << 2) ? s : -d;
  chunk += status & (1 << 3) ? s : -d;
  chunk += status & (1 << 4) ? s : -d;
  if (chunk > 0) return false;
  for (int i = 5; i < 12; i++) {
    chunk += status & (1 << (i - 5)) ? -s : d;
    chunk += status & (1 << i) ? s : -d;
    if (chunk > 0) return false;
  }
  return true;
}

int sum() {
  int sum = 0;
  for (int i = 0; i < 12; i++) {
    if (status & (1 << i)) sum += s;
    else sum -= d;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  while (cin >> s >> d) {
    int max = -1;

    // Just try them all.
    for (status = 0; status < (1 << 12); status++) {
      if (valid()) {
        int sm = sum();
        if (sm > max) max = sm;
      }
    }

    if (max == -1) {
      cout << "Deficit" << endl;
    } else {
      cout << max << endl;
    }
  }
  return 0;
}
