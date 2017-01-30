 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <cmath>
#include <vector>
#include <limits>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define INFINITE numeric_limits<int>::max()

int X, Y;
vector<int> A;
vector<int> tree;
vector<bool> flag;

int max(int a, int b) {
	return (a < b) ? b : a;
}

void create_tree(int node, int i, int j) {
	if(i > j) return;
	if(i == j) {
		tree[node] = A[i];
		if(A[i] < 0) flag[node] = true;
		else flag[node] = false;
		return;
	}
	int child = 2*node;
	int k = (i+j)/2;
	create_tree(child+1, i, k);
	create_tree(child+2, k+1, j);
	
	if(flag[child+1] || flag[child+2]) {
		tree[node] = max(tree[child+1], tree[child+2]);
		flag[node] = true;
	}
	else {
		tree[node] = tree[child+1] + tree[child+2];
		flag[node] = false;
	}
	return;
}

void update_tree(int node, int i, int j) {
	if(i > j || i > X || X > j) return;
	if(i == j && i == X) {
		tree[node] = Y;
		if(tree[node] < 0) flag[node] = true;
		else flag[node] = false;
		return;
	}
	int child = 2*node;
	int k = (i+j)/2;
	update_tree(child+1, i, k);
	update_tree(child+2, k+1, j);
	
	if(flag[child+1] || flag[child+2]) {
		tree[node] = max(tree[child+1], tree[child+2]);
		flag[node] = true;
	}
	else {
		flag[node] = false;
		tree[node] = tree[child+1] + tree[child+2];
	}
	return;
}

int query_tree(int node, int i, int j, bool &flagged) {
	if(i > j || i > Y || j < X) return -INFINITE;
	if(X <= i && j <= Y) {
		if(flag[node]) flagged = true;
		return tree[node];
	}
	int k = (i+j)/2;
	int child = node*2;
	bool f1, f2;
	cout<<f1<<f2<<endl;
	int q1 = query_tree(child+1, i, k, f1);
	int q2 = query_tree(child+2, k+1, j, f2);
	cout<<q1<<" "<<q2<<endl;
	if(f1 || f2) {
		flagged = true;
		return max(q1, q2);
	}
	else if(q1 == -INFINITE || q2 == -INFINITE) return max(q1, q2);
	else return q1 + q2;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M;
	bool T, f;
	in>>N;
	A.resize(N+1);
	int size = (1 << ((int) ceil(log2(N)) + 1)) - 1;
	tree.resize(size);
	flag.resize(size);
	
	for(int i = 1; i <= N; i++) {
		in>>A[i];
	}
	create_tree(0, 1, N);
	
	in>>M;
	for(int i = 0; i < M; i++) {
		in>>T>>X>>Y;
		if(T) out<<query_tree(0, 1, N, f)<<endl;
		else update_tree(0, 1, N);
	}
	in.close();
	out.close();
	return 0;
}
