/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

#include <algorithm>

using namespace std;

int freq[52];
string str;
string out;

void permutations(int &op) {
  if (op == out.size()) {
    cout << out << endl;
    return;
  }
  for (int i = 0; i < 52; i += 2) {
    if (freq[i] > 0) { // 'A'-'Z'
      freq[i]--;
      out[op] = 'A' + (i / 2);
      op++;
      permutations(op);
      op--;
      freq[i]++;
    }

    if (freq[i + 1] > 0) { // 'a'-'z'
      freq[i + 1]--;
      out[op] = 'a' + (i / 2);
      op++;
      permutations(op);
      op--;
      freq[i + 1]++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;

  cin >> T;
  while (T--) {
    cin >> str;
    int len = str.size();
    out.resize(len);

    // Compute letter frequency
    for (int i = 0; i < 52; i++) freq[i] = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] <= 'Z') freq[(str[i] - 'A') * 2]++; // 'A'-'Z' in even positions
      else freq[1 + (str[i] - 'a') * 2]++;           // 'a'-'z' in odd positions
    }

    int c = 0;       // Passing it as reference to consume less memory.
    permutations(c);
  }

  return 0;
}
