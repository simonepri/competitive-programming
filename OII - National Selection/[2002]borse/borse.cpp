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

int N;
ifstream in;
ofstream out;
vector<int> arr;

void composition(unsigned short n, unsigned short s, unsigned short size = 0) {
	
	for(int k = 1; k <= s; k++) {
		arr[size] = k;
		if(n-k > 0) composition(n-k, k, size+1);
		else if(n-k == 0) {
			for(int j = 0; j < size+1; j++) out<<arr[j]<<" ";
			out<<endl;
		}
	}
}

int main()
{
	in.open(FILE_INPUT);
	out.open(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>N;
	arr.resize(N);
	
	composition(N,N);
	
	in.close();
	out.close();
	return 0;
}
