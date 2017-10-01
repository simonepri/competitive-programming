/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <algorithm>
#include <limits>

using namespace std;

const int INF_NEG = numeric_limits<int>::min();
const int INF_POS = numeric_limits<int>::max();

int N;
char I[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
char J[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int M[9][9];

inline int play() {
  int sum = 0;
  for (int k = 0; k < N; k++) {
    sum += M[I[k]][J[k]];
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int T;
  cin >> T;
  while (T-- > 0) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> M[i][j];
      }
    }

    // when next_permutation return false, it also rearranges the elements
    // according to the first permutation.
    int max = INF_NEG;
    do {
      int min = INF_POS;
      do {
        int answ = play();
        if (answ < min) min = answ;
      } while (next_permutation(J, J + N));
      if (min > max) max = min;
    } while (next_permutation(I, I + N));

    cout << max << endl;
  }

  return 0;
}
