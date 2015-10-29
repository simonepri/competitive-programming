 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
/*#include <stdio.h>
#include <assert.h>
#define MAXN 1000000

static FILE *fr, *fw;

static int N;
static int C[MAXN];

void Diversifica(int, int[]);

void Vernicia(int i, int c) {
    fprintf(fw, "%d %d\n", i, c);
}

int main() {
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));

    int i;
    for (i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &(C[i])));

    Diversifica(N, C);

    fclose(fr);
    fclose(fw);
    return 0;
}
*/


#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void Vernicia(int i, int c);

void Diversifica(int N, int colore[]) {
	int read;
	int start = 1;
	vector<bool> used_color(N+1);
	queue<int> to_change;

	for(int i = 0; i < N; i++) {
		if(!used_color[colore[i]]) used_color[colore[i]] = true;
		else to_change.push(i);
	}
	while(!to_change.empty()) {
		read = to_change.front();
		to_change.pop();
		for(int i = start; i < N+1; i++) {
			if(!used_color[i]) {
				start = i+1;
				Vernicia(read, i);
				break;
			}
		}
	}
}
