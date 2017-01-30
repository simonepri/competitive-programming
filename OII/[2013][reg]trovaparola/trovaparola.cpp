 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_R 100
#define MAX_C 100

int STOP=0;
char TABELLA[MAX_R][MAX_C];
char RISULTATO[100];

int ricorsioneparola(char parola[], char mosse[] = "", int x=0, int y=0, int count=0)
{
	if(STOP == 0) {
		if(TABELLA[y][x] == parola[count]) {
			if(strlen(parola) == count+1) {
				STOP = 1;
				strcpy(RISULTATO,mosse);
				return 0;
			}
			else {
				if(x+1 < MAX_C) {
					if(TABELLA[y][x+1] == parola[count+1]) {
						char temp[100];
						strcpy(temp,mosse);
						strcat(temp,"D");
						return ricorsioneparola(parola, temp, x+1, y, count+1);
					}
				}
				if(y+1 < MAX_R) {
					if(TABELLA[y+1][x] == parola[count+1]) {
						char temp[100];
						strcpy(temp,mosse);
						strcat(temp,"B");
						return ricorsioneparola(parola, temp, x, y+1, count+1);
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int R,C;
	fscanf(in,"%d %d",&R,&C);
	char P[MAX_R+MAX_C];
	fscanf(in,"%s",P);
	for(int i = 0; i < R; i++) {
		fscanf(in,"%s",TABELLA[i]);
	}
	int ret = ricorsioneparola(P);
	if(ret == 0) fprintf(out,"%s","ASSENTE");
	else fprintf(out,"%s",RISULTATO);
	
	fclose(in);
	fclose(out);
	return 0;
}
