 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <algorithm>
#include <cmath>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define DIV 3
#define INC 1

int A, B;
vector< vector<int> > tree;
vector<int> lazy;

void build_tree(int node, int N) {
	tree[node].resize(DIV);
	tree[node].at(0) = N;
	if(N > 1) {
		int child = 2*node;
		build_tree(child+1, (N+1)/2);
		build_tree(child+2, N/2);
	}
	return;
}

int query_tree(int node, int i, int j) {
	if(i > j || i > B || j < A) return 0;
	int child = 2*node;
	if(lazy[node]) {
		rotate(tree[node].begin(), tree[node].begin()+(lazy[node] >= DIV ? lazy[node] % DIV : lazy[node]), tree[node].end());
		if(i != j) {
			lazy[child+1] += lazy[node];
			lazy[child+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(i >= A && j <= B) return tree[node].at(0);
	int k = (i+j)/2;
	return query_tree(child+1, i, k) + query_tree(child+2, k+1, j);
}

void update_tree(int node, int i, int j) {
	int child = 2*node;
	if(lazy[node]) {
		rotate(tree[node].begin(), tree[node].begin()+(lazy[node] >= DIV ? lazy[node] % DIV : lazy[node]), tree[node].end());
		if(i != j) {
			lazy[child+1] += lazy[node];
			lazy[child+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(i > j || i > B || j < A) return;
	if(i >= A && j <= B) {
		rotate(tree[node].begin(), tree[node].begin()+(INC >= DIV ? INC % DIV : INC), tree[node].end());
		if(i != j) {
			lazy[child+1] += INC;
			lazy[child+2] += INC;
		}
		return;
	}
	int k = (i+j)/2;
	update_tree(child+1, i, k);
	update_tree(child+2, k+1, j);
	for(int d = 0; d < DIV; d++) tree[node].at(d) = tree[child+1].at(d) + tree[child+2].at(d);
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, Q;
	in>>N>>Q;
	int size = (1 << ((int) ceil(log2(N)) + 1)) - 1;
	tree.resize(size);
	lazy.resize(size);
	
	build_tree(0, N);
	bool T;
	for(int i = 0; i < Q; i++) {
		in>>T>>A>>B;
		if(T) out<<query_tree(0, 0, N-1)<<endl;
		else update_tree(0, 0, N-1);
	}
	
	in.close();
	out.close();
	return 0;
}
