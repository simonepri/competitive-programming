 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include<vector>
#include<set>

using namespace std;
void Vernicia(int indice, int colore);

vector<int> Count;
set<int> Free;

void Diversifica(int N, int colore[]) {
    Count.resize(N+1);
    for(int i = 1; i <= N; i++) Free.insert(i);
    for(int i = 0; i < N; i++) {
        Count[colore[i]]++;
        if(Count[colore[i]] == 1) Free.erase(colore[i]);
    }
    set<int>::iterator it;
    for(int i = 0; i < N; i++) {
       if(Count[colore[i]] > 1) {
            Count[colore[i]]--;
            it = Free.begin();
            Vernicia(i, *it);
            Free.erase(it);
       }
    }
    return;
}
/*
#include <stdio.h>
#include <assert.h>
#define MAXN 10000

static FILE *fr, *fw;

static int N;
static int C[MAXN];

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
