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

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M, earn = 0;
	in>>N>>M;
	
	vector<int> R(N+1);
	vector<int> W(M+1);
	vector<int> F(M+1);
	priority_queue<int, vector<int>, greater<int> > P;
	queue<int> Q;
	
	for(int i = 1; i <= N; i++) {
		P.push(i);
		in>>R[i];
	}
	for(int i = 1; i <= M; i++) in>>W[i];
	for(int i = 1; i <= M*2; i++) {
		int r_car;
		in>>r_car;
		if(r_car > 0) {
			if(!P.empty() && Q.empty()) {
				int pos = P.top();
				P.pop();
				earn += R[pos]*W[r_car];
				F[r_car] = pos;
			}
			else {
				Q.push(r_car);
			}
		}
		else if(r_car < 0) {
			int pos = F[-r_car];
			P.push(pos);
			
			if(!Q.empty()) {
				int pos_2 = P.top();
				P.pop();
				int car = Q.front();
				Q.pop();
				earn += R[pos_2]*W[car];
				F[car] = pos_2;
			}
		}
	}
	out<<earn;
	in.close();
	out.close();
	return 0;
}
