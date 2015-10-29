 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <vector>

using namespace std;

vector<int> heap;

void create_tree(int pre[], int post[], int l, int h, int size, int root = 0) {
	static int pre_i = 0;
	
    if (pre_i >= size || l > h) return;
    
	heap[root] = pre[pre_i];
    pre_i++;
    
    if (l == h) return;
        
    for (int i = l; i <= h; i++) {
        if (pre[pre_i] == post[i])  {
        	if(2*root+1 < heap.size()) create_tree(pre, post, l, i, size, 2*root+1);
        	if(2*root+2 < heap.size()) create_tree(pre, post, i+1, h, size, 2*root+2);
            break;
        }
	}
    return;
}

void inorder_visit(int *SIMM, int root = 0) {
	static int simm_i = 0;
	if(2*root+1 < heap.size() && heap[2*root+1] != 0) inorder_visit(SIMM, 2*root+1);
	SIMM[simm_i] = heap[root];
	simm_i++;
	if(2*root+2 < heap.size() && heap[2*root+2] != 0) inorder_visit(SIMM, 2*root+2);
	return;
}

void visita(int N, int *PRE, int *POST, int *SIMM) {
	heap.resize(2*N);
	create_tree(PRE, POST, 0, N-1, N);
	inorder_visit(SIMM);
	return;
}
/*
#include <fstream>


#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N;
	in>>N;
	int PRE[N], POST[N], SIMM[N];
	
	for(int i = 0; i < N; i++) in>>PRE[i];
	for(int i = 0; i < N; i++) in>>POST[i];
	
	visita(N, PRE, POST, SIMM);
	
	for(int i = 0; i < N; i++) out<<SIMM[i]<<" ";
	
	in.close();
	out.close();
	return 0;
}*/
