 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 100000 //da 2 a 99999
#define MAX_M 100000 //da 2 a 99999
#define MAX_Q 100001 //da 1 a N

vector<int> GRAFO[MAX_N];
vector<bool> cache(MAX_N);

int remove(int Q) {
	int _removed_count = 1,_temp;
	for(int _i = 0; _i < GRAFO[Q].size(); _i++) {
		_temp = GRAFO[Q].at(_i);
		if(_temp >= 1 && _temp <= MAX_N && cache.at(_temp) != true) {
			GRAFO[Q].at(_i) = 0;
			cache.at(_temp) = true;
			printf("Rimosso: %d => Nodo Madre: %d\n",_temp,Q);
			_removed_count += remove(_temp);
		}
	}
	return _removed_count;
}
int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,M,Q,first,second;
	fscanf(in,"%d %d %d\n",&N,&M,&Q);
	for(int i = 0; i < M; i++) {
		fscanf(in,"%d %d\n",&first,&second);
		GRAFO[first].push_back(second);
	}
	
	fprintf(out,"%d",N-remove(Q));
	
	fclose(in);
	fclose(out);
	return 0;
}
