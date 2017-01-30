 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <queue>
#include <iostream>
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
	char read;
	int idx_read,idx_front;
	int c_W[52] = {0}, c_S[52] = {0};
	queue<int> Q;
	
	in>>G>>N;
	
	for(int i = 0; i < G; i++) {
		in>>read;
		idx_read = ('A' <= read && read <= 'Z') ? (read-'A') : (('a' <= read && read <= 'z') ? 26+(read-'a') : -1);
		if(c_W[idx_read] == 0) maxgood++;
		c_W[idx_read]++;
	}
	
	for(int i = 1; i <= N; i++) {
	
		in>>read;
		idx_read = ('A' <= read && read <= 'Z') ? (read-'A') : (('a' <= read && read <= 'z') ? 26+(read-'a') : -1);
		Q.push(idx_read);
		
		if(c_W[idx_read] > 0) {
			if(c_W[idx_read] == c_S[idx_read]) good--;
			c_S[idx_read]++;
			if(c_W[idx_read] == c_S[idx_read]) good++;
		}
		
		if(good == maxgood) count++;
		
		if(i < G) continue;
		
		idx_front = Q.front();
		Q.pop();
		
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
