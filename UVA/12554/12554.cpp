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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  const string song[] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };
  const int len = sizeof(song) / sizeof(song[0]);

  int N, idx = 0;
  string name;
  cin >> N;

  vector<string> peoples;
  peoples.reserve(N);

  int carry = len % N;

  for (int i = 0; i < N; i++) {
    cin >> name;
    if (i < carry) {
      peoples.push_back(name);
    }
    cout << name << ": " << song[idx] << endl;
    idx = (idx + 1) % len;
  }
  int p = 0;
  while (idx != len) {
    cout << peoples[p] << ": " << song[idx] << endl;
    p = (p + 1) % peoples.size();
    idx++;
  }

  return 0;
}
