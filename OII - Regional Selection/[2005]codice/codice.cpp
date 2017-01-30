 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <cstring>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_ROWLEN 80

char encode(char _row[]) {		   
	char NUM[] = "1234567890";
	char UPCASE[] = "ECDFIGHJOKLMNPUQRSTVYWXZAB";
	char LOWCASE[] = "ecdfighjoklmnpuqrstvywxzab";
	for(int i = 0; i < strlen(_row); i++) {
		if(_row[i] >= '0' && _row[i] <= '9') _row[i] = NUM[_row[i]-'0'];
		else if(_row[i] >= 'A' && _row[i] <= 'Z') _row[i] = UPCASE[_row[i]-'A'];
		else if(_row[i] >= 'a' && _row[i] <= 'z') _row[i] = LOWCASE[_row[i]-'a'];
	}
	return 0;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	int N;
	char row[MAX_ROWLEN];
    fscanf(in,"%d\n",&N);
	for(int i = 0; i < N; i++) {
		fgets(row,MAX_ROWLEN,in);
		encode(row);
		fprintf(out,"%s",row);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
