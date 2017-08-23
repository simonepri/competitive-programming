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

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int cases = 0;
  string req, name, maxName;
  double price, maxPrice;
  int N, P, R, maxScore;

  while (true) {
    maxScore = 0;
    maxPrice = 0;

    cin >> N >> P;
    if (N == 0 && P == 0) break;

    cin.ignore();
    for (int i = 0; i < N; i++) getline(cin, req);

    for (int i = 0; i < P; i++) {
      getline(cin, name);
      cin >> price >> R;

      if (R > maxScore || (R == maxScore && price < maxPrice)) {
        maxScore = R;
        maxPrice = price;
        maxName = name;
      }

      cin.ignore();
      for (int j = 0; j < R; j++) getline(cin, req);
    }
    if (cases) cout << endl;
    cout << "RFP #" << ++cases << endl;
    cout << maxName << endl;
  }

  return 0;
}
