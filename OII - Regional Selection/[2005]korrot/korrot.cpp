 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_NM 210

#define STATE_VUOTO     0
#define STATE_OSTACOLO 1
#define STATE_PERCORSO  2

#define POS_R  0
#define POS_C  1

int N,M;
int scacchiera[MAX_NM][MAX_NM];
int KR,KC;
int PR,PC;
int downmode = 0;

char moveit() {
	if(KR == PR && KC == PC) return 'P';
	
	if(KR < N) {
		switch(scacchiera[KR+1][KC]) {
			case STATE_VUOTO: {
				scacchiera[KR][KC] = STATE_PERCORSO;
				KR++;
				downmode = 0;
				return 'A';
			}
			case STATE_OSTACOLO: {
				if(downmode == 1) {
					if(KC < PC) {
						switch(scacchiera[KR][KC+1]) {
							case STATE_VUOTO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KC++;
								return 'D';
							}
							case STATE_OSTACOLO: {
								return 'C';
							}
							case STATE_PERCORSO: {
								return 'C';
							}
						}	
					}
					else if(KC > PC) {
						switch(scacchiera[KR][KC-1]) {
							case STATE_VUOTO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KC--;
								return 'S';
							}
							case STATE_OSTACOLO: {
								return 'C';
							}
							case STATE_PERCORSO: {
								return 'C';
							}
						}
					}
				}
				else {
					if(KC < M) {
						switch(scacchiera[KR][KC+1]) {
							case STATE_VUOTO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KC++;
								return 'D';
							}
							case STATE_OSTACOLO: {
								return 'C';
							}
							case STATE_PERCORSO: {
								return 'C';
							}
						}
					}
					else {
						switch(scacchiera[KR][KC-1]) {
							case STATE_VUOTO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KC--;
								return 'S';
							}
							case STATE_OSTACOLO: {
								return 'C';
							}
							case STATE_PERCORSO: {
								return 'C';
							}
						}
					}
				}
			}
			case STATE_PERCORSO: {
				if(downmode == 1) {
					if(KC < PC) {
						switch(scacchiera[KR][KC+1]) {
							case STATE_VUOTO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KC++;
								return 'D';
							}
							case STATE_OSTACOLO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KR--;
								return 'B';
							}
							case STATE_PERCORSO: {
								return 'C';
							}
						}	
					}
					else if(KC > PC) {
						switch(scacchiera[KR][KC-1]) {
							case STATE_VUOTO: {
								scacchiera[KR][KC] = STATE_PERCORSO;
								KC--;
								return 'S';
							}
							case STATE_OSTACOLO: {
								return 'C';
							}
							case STATE_PERCORSO: {
								return 'C';
							}
						}
					}
				}
				return 'C';
			}
		}
	}
	else {
		if(KC < PC) {
			switch(scacchiera[KR][KC+1]) {
				case STATE_VUOTO: {
					scacchiera[KR][KC] = STATE_PERCORSO;
					KC++;
					return 'D';
				}
				case STATE_OSTACOLO: {
					scacchiera[KR][KC] = STATE_PERCORSO;
					KR--;
					downmode = 1;
					return 'B';
				}
				case STATE_PERCORSO: {
					return 'C';
				}
			}	
		}
		else if(KC > PC) {
			switch(scacchiera[KR][KC-1]) {
				case STATE_VUOTO: {
					scacchiera[KR][KC] = STATE_PERCORSO;
					KC--;
					return 'S';
				}
				case STATE_OSTACOLO: {
					scacchiera[KR][KC] = STATE_PERCORSO;
					KR--;
					downmode = 1;
					return 'B';
				}
				case STATE_PERCORSO: {
					return 'C';
				}
			}
		}
	}
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	int temp1,temp2;
    fscanf(in,"%d %d\n",&N, &M);
    fscanf(in,"%d %d\n",&temp1,&temp2);
    
    KR = 1, KC = temp1;
    PR = N, PC = temp2;
    
	while(fscanf(in,"%d %d\n",&temp1,&temp2) == 2) {
		scacchiera[temp1][temp2] = STATE_OSTACOLO;
	}
	int count = 0;
	char temp;
	while(1) {
		temp = moveit();
		if(temp != 'C' && temp != 'P') {
			fprintf(out,"%c",temp);
		}
		else {
			fprintf(out,"\n%c",temp);
			break;
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
