/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

using namespace std;

int fib[40];

string fib_base(int N) {
  string s;
  bool skip = false;

  // This is the last Fibonacci calculated.
  int start = sizeof(fib) / sizeof(int) - 1;
  // A binary search would be better here.
  while (fib[start] > N) start--;

  // We have to ignore fib(0) and fib(1)
  for (int i = start; i > 1; i--) {
    if (fib[i] > N || skip) {
      s += '0';
      skip = false;
    } else {
      s += '1';
      N -= fib[i];
      skip = true;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  fib[0] = 0;
  fib[1] = 1;

  // The 40th number of Fibonacci is 102,334,155 and since the problem asserts
  // that N is always lower than 100,000,000 we consider only Fibonacci's
  // numbers smaller than this value
  for (int i = 2; i < 40; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  int N, dec;
  string fff;
  cin >> N;

  while (N-- > 0) {
    cin >> dec;
    fff = fib_base(dec);
    cout << dec << " = " << fff <<  " (fib)" << endl;
  }

  return 0;
}
