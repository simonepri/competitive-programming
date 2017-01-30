 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_A 4
#define MAX_D 4

#define MAX_X 85
#define MAX_Y 41


float pos_d_Y(int _d, float _y1, float _y2) {
	return ((_y2 - _y1)*(float(_d)/10))+_y1;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return -1;
	
	int d,A,D;
	int att_min = MAX_Y, dif_min = MAX_Y;
	float x1,x2,y1,y2,temp;
	float Attaccanti[MAX_A];
    if(!fscanf(in,"%d %d %d\n",&d, &A, &D)) return -1;
	for(int i = 0; i < A; i++) {
		if(!fscanf(in,"%f %f %f %f\n",&x1, &y1, &x2, &y2)) return -1;
		temp = pos_d_Y(d, y1, y2);
		if(att_min > temp) att_min = temp;
	}
	for(int i = 0; i < D; i++) {
		if(!fscanf(in,"%f %f %f %f\n",&x1, &y1, &x2, &y2)) return -1;
		temp = pos_d_Y(d, y1, y2);
		if(dif_min > temp) dif_min = temp;
	}
	if(att_min < dif_min) fprintf(out,"F");
	else fprintf(out,"R");
	
	fclose(in);
	fclose(out);
	return 0;
}
