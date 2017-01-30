 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct suffix {
	string sub;
	unsigned short idx;
};

bool sort_func(suffix a, suffix b) {
	return a.sub < b.sub;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	string S;
    
    in >> S;
    unsigned short len = S.size();
    vector<suffix> V(len);
    
    for(unsigned short i = 0; i < len; i++) {
    	V[i].sub = S.substr(i, len-i);
		cout<<V[i].sub<<endl;
        V[i].idx = i;
    }
    sort(V.begin(), V.end(), sort_func);
    for(unsigned short i = 0; i < len; i++) out << V[i].idx << " ";
	
	in.close();
	out.close();
	return 0;
}
