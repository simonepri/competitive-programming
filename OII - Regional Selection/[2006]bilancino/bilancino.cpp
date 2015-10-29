 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <list>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 100  //da 2 a 99
#define MAX_M 4950 //da a a N(N-1)/2

list <int> relazioni[MAX_N];
int matrice[MAX_N][MAX_N];

void esplora_nodo(int n,int p) {
	if(relazioni[n].empty()) return;
	list<int>::iterator i;
	for( i = relazioni[n].begin(); i!= relazioni[n].end(); ++i)
	{
		matrice[p][*i] = matrice[*i][p] = 1;
		esplora_nodo(*i,p);
	}
}

int main(){
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	for(int i = 0; i < MAX_N ; i++) matrice[i][i] = 1;
	int N, M;
	
	fscanf(in,"%d %d\n",&N,&M);
	for(int i = 0; i < M ; i++)
	{
		int a, b;
		fscanf(in,"%d %d\n",&a,&b);
		matrice[a][b] = matrice[b][a] = 1;
		relazioni[a].push_back(b);
	}
	for(int i = 1; i <= N; ++i) {
		esplora_nodo(i,i);
	}
	int cont = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(matrice[i+1][j+1] == 0) cont++;
		}
	}
	if(cont == 0) fprintf(out,"0");
	else if(cont == 2) fprintf(out,"1");
	else fprintf(out,"2");
	
	return 0;
}