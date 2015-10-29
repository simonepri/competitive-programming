 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <climits>

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 100  //da 2 a 99 

int VEC[MAX_N][MAX_N];

int dijkstra(int start, int finish, int N = MAX_N)
{
	int _dist[MAX_N],_prov[MAX_N],_visit[MAX_N],_act_node,_act_mindist;
	for(int _i = 0; _i < N; _i++) _dist[_i] = INT_MAX, _prov[_i] = -1,_visit[_i] = 0;
	_dist[start] = 0;
	_act_node = start;
	_act_mindist = 0;
	
	while(_act_node != finish && _act_mindist != INT_MAX) {
		_act_mindist = INT_MAX;
		for(int _i = 0; _i < N; _i++) {
			if(_visit[_i] == 0 && _dist[_i] < _act_mindist) {
				_act_mindist = _dist[_i];
				_act_node = _i;
			}
		}
		_visit[_act_node] = 1;
		for(int _i = 0; _i < N; _i++) {
			if(VEC[_act_node][_i] != INT_MAX && _dist[_i] > _dist[_act_node] + VEC[_act_node][_i]) {
				_dist[_i] = _dist[_act_node] + VEC[_act_node][_i];
				_prov[_i] = _act_node;
			}
		}
	}
	
	if(_visit[finish] == 0) return 1;
	return _dist[finish];
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,partecipanti[MAX_N] = {0},peso,costi[MAX_N] = {0},imin = -1;
    fscanf(in,"%d\n",&N);
	
    for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) VEC[i][j] = INT_MAX;
	}
    for(int i = 0; i < N; i++) {
    	fscanf(in,"%d\n",&peso);
		if(i < N-1) {
			VEC[i][i+1] = peso;
			VEC[i+1][i] = peso;
		}
		else {
			VEC[N-1][0] = peso;
			VEC[0][N-1] = peso;
		}
    }
    
	for(int i = 0; i < N; i++) {
    	fscanf(in,"%d\n",&partecipanti[i]); 
    }
    
    for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(j != i) {
				int dist = dijkstra(j,i,N);
				//printf("%d => %d == %d\n",j+1,i+1,dist);
				costi[i] += dist*partecipanti[j];
			}
		}
	}
	printf("\n");
	for(int i = 0; i < N; i++) {
		//printf("%d == %d\n",i+1,costi[i]);
    	if(imin == -1 || costi[i] < costi[imin]) imin = i;
    }
    
    fprintf(out,"%d",imin+1);
	
	fclose(in);
	fclose(out);
	return 0;
}
