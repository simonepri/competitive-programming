 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <vector>
#include <deque>
#include <cmath>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int sqrtN;
vector< deque<int> > blocks;

int sqrt_search(int i) {
	return blocks[i / sqrtN][i % sqrtN];
}

void sqrt_update(int i, int j) {
	if(i == j) return;
	int v_i = sqrt_search(i);
	int b_i = i / sqrtN;
	blocks[b_i].erase(blocks[b_i].begin() + (i % sqrtN));
	if(i < j) {
		int b_j = j / sqrtN;
		while(b_i < b_j) {
			blocks[b_i].push_back(blocks[b_i + 1].front());
			blocks[++b_i].pop_front();
		}
		blocks[b_i].insert(blocks[b_i].begin() + (j % sqrtN), v_i);
	}
	else {
		int b_j = j / sqrtN;
		while(b_i > b_j) {
			blocks[b_i].push_front(blocks[b_i - 1].back());
			blocks[--b_i].pop_back();
		}
		blocks[b_i].insert(blocks[b_i].begin() + (j % sqrtN), v_i);
	}
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M;
	in>>N>>M;
	sqrtN = (int) sqrt(N) + 1;
	blocks.resize(sqrtN);
	for(int i = 0; i < sqrtN; i++) {
		blocks[i].resize(sqrtN);
		int k = i * sqrtN;
		for(int j = 0; j < sqrtN; j++) {
			blocks[i][j] = k+j;
		}
	}
	for(int k = 0; k < M; k++) {
		char c;
		in>>c;
		if(c == 'c') {
			int i;
			in>>i;
			out<<sqrt_search(i)<<" ";
		}
		else {
			int i, j;
			in>>i>>j;
			sqrt_update(i, j);
		}
	}
	in.close();
	out.close();
	return 0;
}
