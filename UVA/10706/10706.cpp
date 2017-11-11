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
#include <cmath>
#include <algorithm>

using namespace std;

// Found printing i when tot < 0 (overflow happen) in compute_prv func
#define MAX_K 31269

string offset;
vector<int> prv(MAX_K);
vector<int> len(MAX_K);

// Computes the length of all Sk.
void compute_len() {
  len[0] = 0;
  for (int i = 1; i < MAX_K; i++) {
    len[i] = len[i - 1] + (int)log10(i) + 1;
  }
}

// Computes the start index of each Sk that will be used to do a binary search
// on the given input index to find.
void compute_prv() {
  int tot = 0;
  prv[0] = 0;
  for (int i = 1; i < MAX_K; i++) {
    prv[i] = tot;
    tot = prv[i] + len[i];
  }
}


// This generates a string containing the concatenation of numbers from 1 to MAX_K.
// Does not work for big MAX_K (too much memory).
void compute_offset() {
  offset.reserve(MAX_K);
  offset = "";
  for (int i = 1; i < MAX_K; i++) {
    offset += to_string(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T, N;
  cin >> T;

  compute_len();
  compute_prv();

  compute_offset();

  while (T-- > 0) {
    cin >> N;

    int idx = lower_bound(prv.begin(), prv.end(), N) - prv.begin() - 1;
    cout << offset[N - prv[idx] - 1] << endl;
  }

  return 0;
}
