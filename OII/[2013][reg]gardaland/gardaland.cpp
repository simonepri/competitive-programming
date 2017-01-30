 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,L;
	map<int,int> PARTECIPANTI;
	fscanf(in,"%d %d",&N,&L);
	for(int i = 0; i < N;i++) {
		int temp;
		fscanf(in,"%d",&temp);
		PARTECIPANTI[i] = temp;
	}
	map<int,int> NELPULMAN;
	for(int i = 0; i < L; i++) {
		int nazione,atleti;
		fscanf(in,"%d %d",&nazione,&atleti);
		NELPULMAN[nazione] += atleti;
	}
	
	int count=0;
	for(int i = 0; i < N; i++) {
		if(PARTECIPANTI[i] > NELPULMAN[i]) count++;
	}
	fprintf(out,"%d\n",count);
	if(count != 0) {
		for(int i = 0; i < N; i++) {
			if(PARTECIPANTI[i] > NELPULMAN[i]) {
				fprintf(out,"%d %d\n",i,PARTECIPANTI[i]-NELPULMAN[i]);
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
