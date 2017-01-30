 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <cmath>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int A, B;
vector<int> tree;
vector<bool> lazy;

int query_tree(int node, int i, int j) {
	if(i > j || i > B || j < A) return 0;
	int child = 2*node;
	if(lazy[node]) {
		tree[node] = (j - (i - 1)) - tree[node];
		if(i != j) {
			lazy[child+1] = !lazy[child+1];
			lazy[child+2] = !lazy[child+2];
		}
		lazy[node] = 0;
	}
	if(i >= A && j <= B) return tree[node];
	int k = (i+j)/2;
	return query_tree(child+1, i, k) + query_tree(child+2, k+1, j);
}

void update_tree(int node, int i, int j) {
	int child = 2*node;
	if(lazy[node]) {
		tree[node] = (j - (i - 1)) - tree[node];
		if(i != j) {
			lazy[child+1] = !lazy[child+1];
			lazy[child+2] = !lazy[child+2];
		}
		lazy[node] = 0;
	}
	if(i > j || i > B || j < A) return;
	if(i >= A && j <= B) {
		tree[node] = (j - (i - 1)) - tree[node];
		if(i != j) {
			lazy[child+1] = !lazy[child+1];
			lazy[child+2] = !lazy[child+2];
		}
		return;
	}
	int k = (i+j)/2;
	update_tree(child+1, i, k);
	update_tree(child+2, k+1, j);
	tree[node] = tree[child+1] + tree[child+2];
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
	
	int T;
	for(int i = 0; i < Q; i++) {
		in>>T>>A>>B;
		if(T) out<<query_tree(0, 0, N-1)<<endl;
		else update_tree(0, 0, N-1);
	}
	
	in.close();
	out.close();
	return 0;
}
