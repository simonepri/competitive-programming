 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>

#include <limits>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int nod,cap;
};

const int INFINITE = numeric_limits<int>::max();

vector< vector<node> > G;
vector<int> Cm;
vector<int> Dm;

int min(const int a, const int b) {
    return (a < b) ? a : b;
}

int BFS(int start, int end) {
    int actual,temp1,temp2;
    Cm.resize(G.size(),INFINITE);
    Dm.resize(G.size(),INFINITE);
    queue<int> Q;
    Q.push(start);
    Dm[start] = 0;
    while(!Q.empty()) {
        actual = Q.front();
        Q.pop();
        for(vector<node>::iterator it = G[actual].begin(); it != G[actual].end(); it++) {
            temp1 = Dm[actual] + 1;
            temp2 = min(Cm[actual], it->cap);
            if((Dm[it->nod] > temp1) || (Dm[it->nod] == temp1 && Cm[it->nod] > temp2)) {
                Dm[it->nod] = temp1;
                Cm[it->nod] = temp2;
                Q.push(it->nod);
            }
        }
    }
    return Cm[end];
}

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C) {
    G.resize(N+1);
    node temp;
    for(int i = 0; i < M; i++) {
        temp.cap = capacita[i];

        temp.nod = arco_a[i];
        G[arco_da[i]].push_back(temp);
        temp.nod = arco_da[i];
        G[arco_a[i]].push_back(temp);
    }
    return BFS(W, L);
}
/*
#include <stdio.h>
#include <assert.h>
#define MAXN 100000
#define MAXM 1000000

static FILE *fr, *fw;

static int N, M, W, L;
static int R, C;
static int arco_da[MAXM], arco_a[MAXM], capacita[MAXM];

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    int i;
    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &W, &L));
    assert(2 == fscanf(fr, "%d%d", &R, &C));
    for (i=0; i<M; i++)
        assert(3 == fscanf(fr, "%d%d%d", arco_da+i, arco_a+i, capacita+i));

    fprintf(fw, "%d\n", Analizza(N, M, W, L, arco_da, arco_a, capacita, R, C));

    fclose(fr);
    fclose(fw);
    return 0;
}
*/
