 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <string>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main() {
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);

	if(!in || !out) return 1;

	unsigned int len, first = 0, second = 0, max_len = 0, max_start = 0, temp;
	string S;
	in>>len;
	in>>S;
	//len = S.length();

	for(unsigned int start = 0; start < len-2; start++) {
		if(max_len > len-start) break;
		if(S[start] == S[start+1]) continue;
        first = second = 1;
		while(!S.compare(start, first, S, start+first+second, first)) {
			temp = first;
			first = first+second;
			second = temp;
		}
        temp = first+second;
		if(temp > max_len) {
            max_len = temp;
            max_start = start;
        }
		first = 0;
	}
	out<<max_start+1<<" "<<max_start+max_len<<endl;
	in.close();
	out.close();
	return 0;
}
