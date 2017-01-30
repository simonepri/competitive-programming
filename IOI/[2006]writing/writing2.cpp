 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <queue>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int W, S, count = 0;
	bool flag = 0;
	char temp;
	map<char, int> c_W;
	map<char, int> c_S;
	queue<char> Q;
	in>>W>>S;
	
	for(int i = 0; i < W; i++) {
		in>>temp;
		c_W[temp]++;
	}
	for(int i = 1; i <= S; i++) {
	
		in>>temp;
		
		Q.push(temp);
		if(c_W[temp] > 0) c_S[temp]++;
		
		if(i < W) continue;
		
		for(map<char, int>::iterator it = c_W.begin(); it != c_W.end(); it++) {
			if(c_S[it->first] != c_W[it->first]) {
				flag = 1;
				break;
			}
		}
		if(!flag) count++;
		else flag = 0;
			
		if(c_W[Q.front()] > 0) c_S[Q.front()]--;
		Q.pop();
	}
	
	out<<count;
	
	in.close();
	out.close();
	return 0;
}
