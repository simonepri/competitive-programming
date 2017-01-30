 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
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
	
	int W, S;
	int count = 0, good = 0, maxgood = 0;
	char back,front;
	
	map<char, int> c_W, c_S;
	map<char, bool> check;
	queue<char> Q;
	
	in>>W>>S;
	
	for(int i = 0; i < W; i++) {
		in>>back;
		c_W[back]++;
	}
	
	maxgood = c_W.size();
	
	for(int i = 1; i <= S; i++) {
	
		in>>back;
		
		Q.push(back);
		if(c_W[back] > 0) {
			c_S[back]++;
			if(c_W[back] == c_S[back] && check[back] == false) {
				check[back] = true;
				good++;
			}
			else if(c_W[back] != c_S[back] && check[back] == true){
				check[back] = false;
				good--;
			}
		}
		
		if(good == maxgood) count++;
		
		if(i < W) continue;
		
		front = Q.front();
			
		if(c_W[front] > 0) {
			c_S[front]--;
			if(c_W[front] == c_S[front] && check[front] == false) {
				check[front] = true;
				good++;
			}
			else if(c_W[front] != c_S[front] && check[front] == true){
				check[front] = false;
				good--;
			}
		}
		Q.pop();
	}
	
	out<<count;
	
	in.close();
	out.close();
	return 0;
}