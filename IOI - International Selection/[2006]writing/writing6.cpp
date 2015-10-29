 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <string>
using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int G, N;
	int count = 0, good = 0, maxgood = 0;
	int idx_read,idx_front;
	string S;
	int c_W[52] = {0}, c_S[52] = {0};
	
	in>>G>>N;
	
	in>>S;
	for(int i = 0; i < G; i++) {
		idx_read = ('A' <= S[i] && S[i] <= 'Z') ? (S[i]-'A') : (('a' <= S[i] && S[i] <= 'z') ? 26+(S[i]-'a') : -1);
		if(c_W[idx_read] == 0) maxgood++;
		c_W[idx_read]++;
	}
	
	in>>S;
	for(int i = 0; i < N; i++) {
		idx_read = ('A' <= S[i] && S[i] <= 'Z') ? (S[i]-'A') : (('a' <= S[i] && S[i] <= 'z') ? 26+(S[i]-'a') : -1);
		
		if(c_W[idx_read] > 0) {
			if(c_W[idx_read] == c_S[idx_read]) good--;
			c_S[idx_read]++;
			if(c_W[idx_read] == c_S[idx_read]) good++;
		}
		
		if(good == maxgood) count++;
		
		if(i+1 < G) continue;
		idx_front = ('A' <= S[i+1-G] && S[i+1-G] <= 'Z') ? (S[i+1-G]-'A') : (('a' <= S[i+1-G] && S[i+1-G] <= 'z') ? 26+(S[i+1-G]-'a') : -1);
		
		if(c_W[idx_front] > 0) {
			if(c_W[idx_front] == c_S[idx_front]) good--;
			c_S[idx_front]--;
			if(c_W[idx_front] == c_S[idx_front]) good++;
		}
	}
	
	out<<count;
	
	in.close();
	out.close();
	return 0;
}
