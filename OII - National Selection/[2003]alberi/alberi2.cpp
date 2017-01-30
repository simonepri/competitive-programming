 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <vector>
#include <algorithm>

using namespace std;

void visita(int N, int *PRE, int *POST, int *SIMM) {
	int punt = 0;
	vector<unsigned int> dynamic_pre(PRE, PRE+N);
	vector<unsigned int> dynamic_post(POST, POST+N);
	while(1) {
		int post_node = dynamic_post[0];
		SIMM[punt++] = post_node;
		
		vector<unsigned int>::iterator pre_it = find(dynamic_pre.begin(),dynamic_pre.end(), post_node);
		if(pre_it == dynamic_pre.begin() || pre_it == dynamic_pre.end()) break;
		
		int pre_node = *(pre_it-1);
		SIMM[punt++] = pre_node;
		
		vector<unsigned int>::iterator post_it = find(dynamic_post.begin(), dynamic_post.end(), pre_node);
		
		dynamic_pre.erase(pre_it);
		dynamic_pre.erase(pre_it-1);
		dynamic_post.erase(dynamic_post.begin());
		dynamic_post.erase(post_it-1);
	}
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
