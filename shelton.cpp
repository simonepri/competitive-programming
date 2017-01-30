 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

//#include <string>
//#include <vector>
//#include <set>
//#include <unordered_set>
//#include <map>
//#include <unordered_map>
//#include <deque>
//#include <queue>

//#include <algorithm>
//#include <limits>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main() {
  sync_with_stdio(false); // faster I/O
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
  
  //in >> N;
  //out << N;
	
	in.close();
	out.close();
	return 0;
}
