 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <iterator>
#include <iostream>

#include <vector>
#include <list>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

list<int> vases;

int query(int i) {
	list<int>::iterator it = vases.begin();
	advance(it, i);
	return *it;
}

void update(int i, int j) {
	if(i == j) return;
	int v_i = query(i);
	
	list<int>::iterator it = vases.begin();
	advance(it, i);
	
	vases.erase(it);
	
	it = vases.begin();
	advance(it, j);
	
	vases.insert(it, v_i);
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M;
	in>>N>>M;
	for(int i = 0; i < N; i++) vases.push_back(i);
	
	for(int k = 0; k < M; k++) {
		char c;
		in>>c;
		if(c == 'c') {
			int i;
			in>>i;
			out<<query(i)<<" ";
		}
		else {
			int i, j;
			in>>i>>j;
			update(i, j);
		}
	}
	in.close();
	out.close();
	return 0;
}
