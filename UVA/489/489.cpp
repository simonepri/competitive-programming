/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <cstring>

#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int t, len, lifes, letters[26];
  string phrase, guesses;

  while (true) {
    cin >> t;
    if (t == -1) break;

    cout << "Round " << t << endl;
    cin >> phrase;
    cin >> guesses;

    memset(letters, 0, sizeof(letters));

    len = phrase.size();
    lifes = 7;
    for (string::iterator it = phrase.begin(); it != phrase.end(); it++) {
      letters[*it - 'a']++;
    }
    for (string::iterator it = guesses.begin(); it != guesses.end(); it++) {
      if (letters[*it - 'a'] == -1) continue;
      if (letters[*it - 'a'] == 0) {
        lifes--;
        if (lifes == 0) break;
        continue;
      }
      len -= letters[*it - 'a'];
      if (len == 0) break;
      letters[*it - 'a'] = -1;
    }
    
    if (len == 0) {
      cout << "You win." << endl;
    } else if (lifes == 0) {
      cout << "You lose." << endl;
    } else {
      cout << "You chickened out." << endl;
    }
  }

  return 0;
}
