 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

string A;
struct entry {
    int nr[2], p;
};
vector<entry> L;
vector< vector<int> > P;

int cmp(struct entry a, struct entry b) {
    return (a.nr[0] == b.nr[0]) ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int stp, cnt, len, lg2;
	
    in >> A;
    len = A.size();
    lg2 = log2(len)+2;
    L.resize(len);
    P.resize(lg2);
    for(int i = 0; i < lg2; i++) {
    	P[i].resize(len);
    }
    
    for(int i = 0; i < len; i++) {
        P[0][i] = A[i] - 'a';
    }
    for(stp = 1, cnt = 1; cnt < len; stp++, cnt *=2 ) {
    	for(int i = 0; i < len; i++) {
    		L[i].nr[0] = P[stp - 1][i];
    		L[i].nr[1] = (i + cnt < len) ? (P[stp - 1][i + cnt]) : -1;
    		L[i].p = i;
   		}
    	sort(L.begin(), L.end(), cmp);
    	for(int i = 0; i < len; i++) {
    		P[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1]) ? P[stp][L[i-1].p] : i;
    	}
    }
    
    for(int i = 0; i < lg2; i++) {
    	for(int j = 0; j < len; j++) cout << P[i][j] << " ";
    	cout<<endl;
    }
    
	
	in.close();
	out.close();
	return 0;
}
