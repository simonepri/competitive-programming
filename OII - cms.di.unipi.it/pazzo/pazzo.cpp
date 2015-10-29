 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N,M;
	vector<int> ord;
	int t1,t2,first = 0;
	in>>N>>M;
	for(int i = 0; i < N; i++) ord.push_back(i);
	
	for(int i = 0; i < M; i++) {
		in>>t1>>t2;
		
		swap(ord[t1],ord[t2]);
		if(ord[t1] == 0) first = t1;
		else if(ord[t2] == 0) first = t2;
	}
	out<<first;
	in.close();
	out.close();
	return 0;
}
