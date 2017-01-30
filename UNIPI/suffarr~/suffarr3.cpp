 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <iostream>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int len;
string S;

bool sort_func(int a, int b) {
	return S.substr(a) < S.substr(b);
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
    
    in >> S;
    len = S.size();
    vector<int> V(len);
    
    for(unsigned short i = 0; i < len; i++) {
        V[i] = i;
    }
    sort(V.begin(), V.end(), sort_func);
    for(unsigned short i = 0; i < len; i++) out << V[i] << " ";
	
	in.close();
	out.close();
	return 0;
}
