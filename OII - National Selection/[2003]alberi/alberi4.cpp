 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <list>
#include <algorithm>

using namespace std;

void visita(int N, int *PRE, int *POST, int *SIMM) {
	int punt = 0;
	list<int> dynamic_pre(PRE, PRE+N);
	list<int> dynamic_post(POST, POST+N);
	while(1) {
		int post_node = dynamic_post.front();
		SIMM[punt++] = post_node;
		dynamic_post.pop_front();
		
		list<int>::iterator pre_it = find(dynamic_pre.begin(),dynamic_pre.end(), post_node);
		if(pre_it == dynamic_pre.begin() || pre_it == dynamic_pre.end()) break;
		
		list<int>::iterator pre_it_prev = pre_it;
		pre_it_prev--;
		
		int pre_node = *(pre_it_prev);
		SIMM[punt++] = pre_node;
		dynamic_post.remove(pre_node);
		dynamic_pre.erase(pre_it);
		dynamic_pre.erase(pre_it_prev);
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
