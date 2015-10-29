 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 100000

bool check[MAX_N];

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, K, a, count = 0,max = 0;
	in>>N>>K;
	
	if(K == 1) {
		out<<0;
		in.close();
		out.close();
		return 0;
	}
	
	for(int i = 0; i < N; i++) {
		in>>a;
		if(a > max) max = a;
		check[a] = true;
	}
	for(int a = max; a > 0; a--) {
		if(check[a] == true) {
			if(a%K == 0) check[a/K] = false;
			count++;
		}
	}
	out<<count;
	
	in.close();
	out.close();
	return 0;
}
