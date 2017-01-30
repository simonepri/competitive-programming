 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include<iostream>
#include<vector>

using namespace std;

vector<bool> Check;

int Trova(int N, int K, int insieme[]) {
    if(K == 1) return 0;
    int maxs = 0, counts = 0;
    for(int i = 0; i < N; i++) {
        if(insieme[i] > maxs) {
            maxs = insieme[i];
            Check.resize(maxs+1);
        }
        Check[insieme[i]] = true;
    }
    for(int a = 1; a <= maxs; a++) {
        if(Check[a] == true) {
            if(K*a <= maxs) Check[K*a] = false;
            counts++;
        }
    }
    return counts;
}
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXN 100000

static FILE *fr, *fw;

static int n, k, i;
static int insieme[MAXN+1];

int Trova(int n, int k, int* insieme);

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d %d", &n, &k));
    for(i=0; i<n; i++)
        assert(1 == fscanf(fr, "%d", insieme+i));

    fprintf(fw, "%d\n", Trova(n, k, insieme));

    fclose(fr);
    fclose(fw);
    return 0;
}*/
