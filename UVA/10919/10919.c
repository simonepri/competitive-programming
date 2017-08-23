/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <stdio.h>

int chosen[10000] = {0};

int main() {
  int K, M, C, R, course;
  int i, j;
  int test = 0;

  while (1) {
    test++; // Works only if there are less than 2^(sizeof(int)*8)-1 tests
    int pass = 1;
    if (scanf("%d %d", &K, &M) != 2) break;

    for (i = 0; i < K; i++) {
      scanf("%d", &course);
      chosen[course] = test;
    }
    for (i = 0; i < M; i++) {
      int r = 0;
      scanf("%d %d", &C, &R);

      for (j = 0; j < C; j++) {
        scanf("%d", &course);
        if (chosen[course] == test) r++;
      }
      if (r < R) pass = 0;
    }
    if (pass) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}
