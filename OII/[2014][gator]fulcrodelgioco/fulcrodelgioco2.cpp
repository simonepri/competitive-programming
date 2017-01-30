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
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

vector<int> G[12];

int remove_try(int player) {
	vector<bool> v(12,false);
	queue<int> Q;
	int node,count = 0;
	Q.push(1);
	v[1] = true;
	v[player] = true;
	while(!Q.empty()) {
		node = Q.front();
		Q.pop();
		for(vector<int>::iterator it = G[node].begin(); it != G[node].end(); it++) {
			if(v[*it] == false) {
				v[*it] = true;
				Q.push(*it);
			}
		}
	}
	for(int j = 2; j < 12; j++) {
		if(v[j] == false) count++;
	}
	return count;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int M,A,B;
	in>>M;
	for(int i = 0; i < M; i++) {
		in>>A>>B;
		G[A].push_back(B);
	}
	int max = -1,id = 0, temp;
	for(int i = 2; i < 12; i++) {
		temp = remove_try(i);
		//cout<<i<<" "<<temp<<endl;
		if(temp > max) {
			max = temp;
			id = i;
		}
	}
	out<<id;
	in.close();
	out.close();
	return 0;
}
