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

const int INF = numeric_limits<int>::max();

int N;
char COL[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int M[9][9];

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
    int min = INF;
    do {
      int total = 0;
      for (int k = 0; k < N; k++) {
        total += M[k][COL[k]];
      }
      if (total < min) min = total;
    } while (next_permutation(COL, COL + N));

    cout << min << endl;
  }

  return 0;
}
