 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <limits>

#include <cmath>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define INFINITE numeric_limits<int>::max();

int X, Y;
vector<int> A;
vector<int> tree;
vector<bool> flag;

void create_tree(int node, int i, int j) {
	if(i > j) return;
	if(i == j) {
		tree[node] = A[i];
		return;
	}
	int child = 2*node;
	int k = (i+j)/2;
	create_tree(child+1, i, k);
	create_tree(child+2, k+1, j);
	tree[node] = (tree[child+1] >= 0 ? tree[child+1] : (tree[child+2] > tree[child+1] ? 0 : tree[child+1])) + (tree[child+2] >= 0 ? tree[child+2] : (tree[child+1] > tree[child+2] ? 0 : tree[child+2]));
	return;
}

int query_tree(int node, int i, int j) {
	if(i > j || i > Y || j < X) return -INFINITE;
	if(X <= i && j <= Y) return tree[node];
	int k = (i+j)/2;
	int child = node*2;
	int q1 = query_tree(child+1, i, k);
	int q2 = query_tree(child+2, k+1, j);
	return (q1 >= 0 ? q1 : (q2 > q1 ? 0 : q1)) + (q2 >= 0 ? q2 : (q1 > q2 ? 0 : q2));
}

void update_tree(int node, int i, int j) {
	if(i > j || i > X || X > j) return;
	if(i == j && i == X) {
		tree[node] = Y;
		return;
	}
	int child = 2*node;
	int k = (i+j)/2;
	update_tree(child+1, i, k);
	update_tree(child+2, k+1, j);
	tree[node] = (tree[child+1] >= 0 ? tree[child+1] : (tree[child+2] > tree[child+1] ? 0 : tree[child+1])) + (tree[child+2] >= 0 ? tree[child+2] : (tree[child+1] > tree[child+2] ? 0 : tree[child+2]));
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M;
	bool T;
	in>>N;
	A.resize(N+1);
	int size = (1 << ((int) ceil(log2(N)) + 1)) - 1;
	tree.resize(size);
	
	for(int i = 1; i <= N; i++) {
		in>>A[i];
	}
	create_tree(0, 1, N);
	
	in>>M;
	for(int i = 0; i < M; i++) {
		in>>T>>X>>Y;
		if(T) out<<query_tree(0, 1, N)<<endl;
		else update_tree(0, 1, N);
	}
	in.close();
	out.close();
	return 0;
}
