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
vector<int> flag;

int max(int a, int b) {
	return (a < b) ? b : a;
}

void create_tree(int node, int i, int j) {
	if(i > j) return;
	if(i == j) {
		if(A[i] >= 0) {
			tree[node] = A[i];
			flag[node] = 0;
		}
		else {
			tree[node] = 0;
			flag[node] = A[i];
		}
		return;
	}
	int child = 2*node;
	int k = (i+j)/2;
	create_tree(child+1, i, k);
	create_tree(child+2, k+1, j);
	
	if(flag[child+1] < 0 && flag[child+2] && tree[child+1] == 0 && tree[child+2] == 0) {
		flag[node] = flag[child+1] + flag[child+2];
		tree[node] = 0;
	}
	else if(tree[child+1] + flag[child+1] + flag[child+2] >= 0 || flag[child+1] < 0 && flag[child+2] < 0) {
		flag[node] = flag[child+2];
		tree[node] = tree[child+1] + tree[child+2] + flag[child+1];
	}
	else if(tree[child+1] >= tree[child+2]) {
		flag[node] = flag[child+1] + flag[child+2] + tree[child+2];
		tree[node] = tree[child+1];
	}
	else if(tree[child+2] > tree[child+1]) {
		flag[node] = tree[child+1] + flag[child+1] + flag[child+2];
		tree[node] = tree[child+2];
	}
	return;
}

void update_tree(int node, int i, int j) {
	if(i > j || i > X || X > j) return;
	if(i == j && i == X) {
		if(Y >= 0) {
			tree[node] = Y;
			flag[node] = 0;
		}
		else {
			tree[node] = 0;
			flag[node] = Y;
		}
		return;
	}
	int child = 2*node;
	int k = (i+j)/2;
	update_tree(child+1, i, k);
	update_tree(child+2, k+1, j);
	
	if(flag[child+1] < 0 && flag[child+2] && tree[child+1] == 0 && tree[child+2] == 0) {
		flag[node] = flag[child+1] + flag[child+2];
		tree[node] = 0;
	}
	else if(tree[child+1] + flag[child+1] + flag[child+2] >= 0 || flag[child+1] < 0 && flag[child+2] < 0) {
		flag[node] = flag[child+2];
		tree[node] = tree[child+1] + tree[child+2] + flag[child+1];
	}
	else if(tree[child+1] >= tree[child+2]) {
		flag[node] = flag[child+1] + flag[child+2] + tree[child+2];
		tree[node] = tree[child+1];
	}
	else if(tree[child+2] > tree[child+1]) {
		flag[node] = tree[child+1] + flag[child+1] + flag[child+2];
		tree[node] = tree[child+2];
	}
	return;
}

int query_tree(int node, int i, int j, int &f) {
	if(i > j || i > Y || j < X) return -INFINITE;
	if(X <= i && j <= Y) {
		f = flag[node];
		return tree[node];
	}
	int k = (i+j)/2;
	int child = node*2;
	int f1, f2;
	int q1 = query_tree(child+1, i, k, f1);
	int q2 = query_tree(child+2, k+1, j, f2);

	if(q1 == -INFINITE) {
		if(q2 == -INFINITE) {
			f = 0;
			return -INFINITE;
		}
		else {
			f = f2;
			return q2;
		}
	}
	else if(q2 == -INFINITE) {
		f = f1;
		return q1;
	}
	else if(f1 < 0 && f2 < 0 && q1 == 0 && q2 == 0) {
		f = f1 + f2;
		return 0;
	}
	else if(q1 + f1 + f2 >= 0 || f1 < 0 && f2 < 0) {
		f = f2;
		return q1 + q2 + f1;
	}
	else if(q1 >= q2) {
		f = f1 + f2 + q2;
		return q1;
	}
	else if(q2 > q1) {
		f = q1 + f1 + f2;
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
	for(int i = 0; i < size; i++) cout<<tree[i]<<" ";
	cout<<endl;
	in>>M;
	for(int i = 0; i < M; i++) {
		in>>T>>X>>Y;
		if(T) {
			int q = query_tree(0, 1, N, f);
			
			out<<(q == 0 ? f : q)<<endl;
			}
		else {
			update_tree(0, 1, N);
			for(int i = 0; i < size; i++) cout<<tree[i]<<" ";
			cout<<endl;
		}
	}
	in.close();
	out.close();
	return 0;
}
