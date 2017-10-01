/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

vector<int> books;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int N, sum;
  while (true) {
    cin >> N;
    if (!cin) break;
    books.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> books[i];
    }
    cin >> sum;
    sort(books.begin(), books.end());

    int minb = 0;
    for (int i = 0; i < N; i++) {
      if (books[i] > sum) break;
      if (sum - books[i] > books[i]) {
        if (!binary_search(books.begin() + i + 1, books.end(), sum - books[i])) continue;
      } else {
        if (!binary_search(books.begin(), books.begin() + i, sum - books[i])) continue;
      }
      if (abs(books[i] - (sum - books[i])) < abs(minb - (sum - minb))) minb = books[i];
    }
    int a = minb;
    int b = sum - minb;
    cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl << endl;
  }

  return 0;
}
