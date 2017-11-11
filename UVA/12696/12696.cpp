/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

using namespace std;

bool isValid(double length, double width, double depth, double weight) {
  bool valid = false;
  valid |= (length > 0 && width > 0 && depth > 0 &&
    length <= 56 && width <= 45 && depth <= 25);
  valid |= (length + width + depth <= 125);
  valid &= (weight <= 7);
  return valid;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int N;

  cin >> N;

  int count = 0;
  double x, y, z, w;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> z >> w;
    bool valid = isValid(x, y, z, w);
    count += valid;
    cout << valid << endl;
  }
  cout << count << endl;

  return 0;
}
