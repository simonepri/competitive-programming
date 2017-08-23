/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <iomanip>

#include <cmath>

#include <string>

using namespace std;

int getValue(char c) {
  if ('a' <= c && c <= 'z') return c - '`';
  if ('A' <= c && c <= 'Z') return c - '@';
  return 0;
}

int single(int v) {
  int s = v;
  while(v > 9) {
    s = 0;
    while(v > 0) {
      s += v % 10;
      v /= 10;
    }
    if (s > 9) v = s;
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int sum[2];
  string names[2];
  names[0].reserve(25+1);
  names[1].reserve(25+1);

  std::cout << std::setprecision(2) << std::fixed; // print 2 decimal places

  while(getline(cin, names[0]) && getline(cin, names[1])) {
    for (int i = 0; i < 2; i++) {
      sum[i] = 0;
      for (string::iterator it = names[i].begin(); it != names[i].end(); it++) {
        sum[i] += getValue(*it);
      }
      sum[i] = single(sum[i]);
    }

    double score;
    if (sum[0] > sum[1]) score =  sum[1] / (double)sum[0] * 100.0;
    else score = sum[0] / (double)sum[1] * 100.0;
    cout << score << " %" << endl;
  }

  return 0;
}
