 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include<vector>
#include<queue>

using namespace std;

#define LINEARI 0
#define ANELLO 1
#define STELLA 2

int lineari, stella, anello;
vector<bool> Vi;
vector<int> Ti;
vector< vector<int> > Gr;

int find_component() {
    static int start = 0;
    int N = Vi.size();
    for(int i = start; i < N; i++) {
        if(Vi[i] == false) {
            start = i+1;
            return i;
        }
    }
    start = N;
    return -1;
}

void categorize_component(int start, int *T) {
    int c_size = 0, c_one = 0, c_two = 0, c_max = 0,actual;
    queue<int> Qu;
    Qu.push(start);
    Vi[start] = true;
    while(!Qu.empty()) {
        actual = Qu.front();
        Qu.pop();
        c_size++;

        if(Ti[actual] == 1) c_one++;
        else if(Ti[actual] == 2) c_two++;
        else if(Ti[actual] > c_max) c_max = Ti[actual];

        for(vector<int>::iterator it = Gr[actual].begin(); it != Gr[actual].end(); it++) {
            if(Vi[*it] == false) {
                Qu.push(*it);
                Vi[*it] = true;
            }
        }
    }

    if(c_two == c_size && c_size > 2) T[ANELLO]++;
    else if(c_one == 2 && c_two == c_size-2 && c_size > 1) T[LINEARI]++;
    else if(c_one == c_size-1 && c_max == c_size-1 && c_size > 3) T[STELLA]++;

    return;
}

void Analizza(int N, int M, int* A, int* B, int* T) {
    Gr.resize(N+1); Vi.resize(N+1); Ti.resize(N+1);
    for(int i = 0; i < M; i++) {
        Gr[A[i]].push_back(B[i]);
        Gr[B[i]].push_back(A[i]);
        Ti[A[i]]++;
        Ti[B[i]]++;
    }
    int node = 0;
    while((node = find_component()) != -1) {
        categorize_component(node,T);
    }
    return;
}
/*
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXM 100000

static FILE *fr, *fw;

static int n, m, i;
static int a[MAXM+1], b[MAXM+1], t[3];

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &n, &m));
    for(i=0; i<m; i++)
        assert(2 == fscanf(fr, "%d%d", a+i, b+i));

    Analizza(n, m, a, b, t);
    fprintf(fw, "%d %d %d\n", t[0], t[1], t[2]);

    fclose(fr);
    fclose(fw);
    return 0;
}
*/
