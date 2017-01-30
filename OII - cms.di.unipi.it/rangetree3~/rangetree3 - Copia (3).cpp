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
vector<int> flag_sx;
vector<int> flag_dx;

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
		if(Y >= 0) {
			tree[node] = Y;
			flag_sx[node] = 0;
			flag_dx[node] = 0;
		}
		else {
			tree[node] = 0;
			flag_sx[node] = 0;
			flag_dx[node] = Y;
		}
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

int query_tree(int node, int i, int j, int &f_sx, int &f_dx) {
	if(i > j || i > Y || j < X) return -INFINITE;
	if(X <= i && j <= Y) {
		f_sx = flag_sx[node];
		f_dx = flag_dx[node];
		return tree[node];
	}
	int k = (i+j)/2;
	int child = node*2;
	bool f1_sx, f1_dx, f2_dx, f2_sx;
	cout<<f1<<f2<<endl;
	int q1 = query_tree(child+1, i, k, f1_sx, f1_dx);
	int q2 = query_tree(child+2, k+1, j, f2_sx, f2_dx);

	if(q1 == -INFINITE) {
		if(q2 == -INFINITE) {
			return -INFINITE;
		}
		else {
			f_sx = f2_sx;
			f_dx = f2_dx;
			return q2;
		}
	}
	else if(q2 == -INFINITE) {
		f_sx = f1_sx;
		f_dx = f1_dx;
		return q1;
	}
	else if(q1 - f1_dx + f2_sx > 0) {
		f_sx = f1_sx;
		f_dx = f2_dx;
		return q1 + f1_dx + f2_sx + q2;
	}
	else if(q1 >= q2){
		f_sx = f1_sx;
		f_dx = f1_dx + f2_sx + q2 + f2_dx;
		return q1;
	}
	else if(q2 > q1) {
		f_sx = f1_sx + q1 + f1_dx + f2_sx;
		f_dx = f2_dx;
		return q2;
	}
	return -INFINITE;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M, f;
	bool T;
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
