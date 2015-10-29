 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"
ifstream in(FILE_INPUT);
ofstream out(FILE_OUTPUT);
bool isprime(int N) {
    float froot = sqrt(N);
    int root = int(froot);
    if(froot == 2) return false;
    for(int i = 2; i < root; i++) if(N % i == 0) return false;
    return true;
}

int main(){
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	if(!in || !out) return 1;
	int N;
	in>>N;
    bool flag = false;
    int f1, f2, root = sqrt(N);
    for(int i = 2; i <= root; i++) {
        if(N % i == 0) {
            f1 = i;
            f2 = N/f1;
            flag  = true;
            break;
        }
    }
    if(!flag || !isprime(f1) || !isprime(f2)) out<<-1<<endl;
    else out<<f1<<" "<<f2;
	in.close();
	out.close();
	return 0;
}