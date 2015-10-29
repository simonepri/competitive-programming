 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <vector>

using namespace std;

void visita(int N, int *PRE, int *POST, int *SIMM) {
	int punt = 0;
	vector<int> used(N+1);
	vector<int> pre_pos(N+1);
	for(int i = 0; i < N; i++) pre_pos[PRE[i]] = i;
	for(int i = 0; i < N; i++) {
		if(used[POST[i]]) continue;
		SIMM[punt++] = POST[i];
		used[POST[i]] = true;
		for(int j = pre_pos[POST[i]]-1; j > -1; j--) {
			if(used[PRE[j]]) continue;
			SIMM[punt++] = PRE[j];
			used[PRE[j]] = true;
			break;
		}
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
