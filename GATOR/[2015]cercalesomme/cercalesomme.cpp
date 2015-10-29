 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

#include <iostream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

ifstream fin;
ofstream fout;
int N, B;
string C;


string _to_string(int &n)
{
    ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
int _stoi(string str) {
    return atoi(str.c_str());
}

bool valid(string &pos, int &len) {
	int last = 0, next, sum = 0;
	for(int i = 0; i < len; i++) {
	    next = pos[i] - '0';
		sum += _stoi(C.substr(last,next-last));
		last = next;
	}
    sum += _stoi(C.substr(last,N));
	if(sum == B) return true;
	return false;
}

void fact(string pos = "", int len = 0, int last = 0) {
	if(len > N || len < 0 || pos.length()+1 >= N || pos.length() < 0) return;
	if(valid(pos,len)) {
        for(int i = 0; i < len; i++) fout<<pos[i]<<" ";
        fout<<endl;
	}
	len++;
	for(int i = last+1; i < N; i++) {
		fact(pos+_to_string(i), len, i);
	}
}

int main()
{
	fin.open(FILE_INPUT);
	fout.open(FILE_OUTPUT);

	if(!fin || !fout) return 1;
	fin>>N;
	C.resize(N);
	for(int i = 0; i < N; i++) fin>>C[i];
	fin>>B;
	fact();
	fin.close();
	fout.close();
	return 0;
}
