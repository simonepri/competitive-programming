 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <cstring>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 101 //da 1 a 100
#define MAX_LEN 100
#define MAX_CHAR 10

bool isAnagram(char s1[], char s2[]) {
	int len = strlen(s1);
	if(len != strlen(s2)) return false;
	int _counter[MAX_CHAR] = {0};
	for(int i = 0; i < len; i++) {
		_counter[s1[i] - '0']++;
		_counter[s2[i] - '0']--;
	}
	for(int i = 0; i < MAX_CHAR; i++) {
		if(_counter[i] != 0) return false;
	}
	return true;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,aCount[MAX_N];
	char pizzini[MAX_N][MAX_LEN];
	fscanf(in,"%d\n",&N);
	
	for(int i = 0; i < N; i++) {
		aCount[i] = 1;
		fscanf(in,"%s\n",pizzini[i]);
	}
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++) {
			if(isAnagram(pizzini[i],pizzini[j])) {
				aCount[i]++;
				aCount[j]++;
			}
		}
	}
	
	for(int i = 0; i < N; i++) {
		if(aCount[i] == 0) aCount[i] = 1;
		fprintf(out,"%c",pizzini[i][aCount[i]-1]);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
