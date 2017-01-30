 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <stdio.h>

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main() {
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
  //fscanf(in,"%d", &N);
	//fprintf(out,"%d", N);
	
	fclose(in);
	fclose(out);
	return 0;
}