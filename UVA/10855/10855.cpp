/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

using namespace std;

#define vc vector<char>
#define vvc vector<vc>

int count_000(vvc big, int N, vvc small, int M) {
  int count = 0;
  for (int bi = 0; bi <= N - M; bi++) {
    for (int bj = 0; bj <=N - M; bj++) {

      bool stop = false;
      for (int si = 0, oi = 0; si < M; si++, oi++) {
        for (int sj = 0, oj = 0; sj < M; sj++, oj++) {
          if (big[bi + oi][bj + oj] == small[si][sj]) continue;
          stop = true;
          break;
        }
        if (stop) break;
      }
      if (!stop) count++;

    }
  }
  return count;
}

int count_090(vvc big, int N, vvc small, int M) {
  int count = 0;
  for (int bi = 0; bi <= N - M; bi++) {
    for (int bj = 0; bj <= N - M; bj++) {

      bool stop = false;
      for (int sj = 0, oi = 0; sj < M; sj++, oi++) {
        for (int si = M - 1, oj = 0; si >= 0; si--, oj++) {
          if (big[bi + oi][bj + oj] == small[si][sj]) continue;
          stop = true;
          break;
        }
        if (stop) break;
      }
      if (!stop) count++;

    }
  }
  return count;
}

int count_180(vvc big, int N, vvc small, int M) {
  int count = 0;
  for (int bi = 0; bi <= N - M; bi++) {
    for (int bj = 0; bj <=N - M; bj++) {

      bool stop = false;
      for (int si = M - 1, oi = 0; si >= 0; si--, oi++) {
        for (int sj = M - 1, oj = 0; sj >= 0; sj--, oj++) {
          if (big[bi + oi][bj + oj] == small[si][sj]) continue;
          stop = true;
          break;
        }
        if (stop) break;
      }
      if (!stop) count++;

    }
  }
  return count;
}

int count_270(vvc big, int N, vvc small, int M) {
  int count = 0;
  for (int bi = 0; bi <= N - M; bi++) {
    for (int bj = 0; bj <= N - M; bj++) {

      bool stop = false;
      for (int sj = M - 1, oi = 0; sj >= 0; sj--, oi++) {
        for (int si = 0, oj = 0; si < M; si++, oj++) {
          if (big[bi + oi][bj + oj] == small[si][sj]) continue;
          stop = true;
          break;
        }
        if (stop) break;
      }
      if (!stop) count++;

    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  vvc big;
  vvc small;
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 || M == 0) break;

    big.resize(N);
    for (int bi = 0; bi < N; bi++) {
      big[bi].resize(N);
      for (int bj = 0; bj < N; bj++) {
        cin >> big[bi][bj];
      }
    }

    small.resize(M);
    for (int si = 0; si < M; si++) {
      small[si].resize(M);
      for (int sj = 0; sj < M; sj++) {
        cin >> small[si][sj];
      }
    }

    cout << count_000(big, N, small, M) << " ";
    cout << count_090(big, N, small, M) << " ";
    cout << count_180(big, N, small, M) << " ";
    cout << count_270(big, N, small, M) << endl;
  }

  return 0;
}
