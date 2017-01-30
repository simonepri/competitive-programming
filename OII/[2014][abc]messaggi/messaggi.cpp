 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <string>

#include <vector>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

struct type {
	vector <string> S;
	vector <string> R;
};

map<string, type> LOG;

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,R;
	string temp1,temp2;
	
    in >> N >> R;
    
	for(int i = 0; i < N; i++) {
		in >> temp1 >> temp2;
		
		LOG[temp1].S.push_back(temp2);
		LOG[temp2].R.push_back(temp1);
	}
	
	for(int i = 0; i < R; i++) {
		in >> temp1 >> temp2;
		
		if(temp2.compare("INVIATI") == 0) {
			out << LOG[temp1].S.size();
			
			for(vector<string>::iterator it = LOG[temp1].S.begin(); it != LOG[temp1].S.end(); it++) {
				out << " " << *it;
			}
		}
		else {
			out << LOG[temp1].R.size();
			
			for(vector<string>::iterator it = LOG[temp1].R.begin(); it != LOG[temp1].R.end(); it++) {
				out << " " << *it;
			}
		}
		out << endl;
	}
	
	in.close();
	out.close();
	return 0;
}
