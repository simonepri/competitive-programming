 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <cstdio>

using namespace std;

int main() {
  char c;
  bool state = 0;
  
  while(scanf("%c", &c) == 1) {
    if(c == '"') {
      if(state) printf("''");
      else printf("``");
      state = !state;
    }
    else printf("%c", c);
  }
return 0;
}
