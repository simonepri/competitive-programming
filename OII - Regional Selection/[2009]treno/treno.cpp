 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

ifstream fin;
ofstream fout;

void spostamenti(int T) {
	fout<<(T-2)/2<<" "<<T-1<<endl;
	if(T == 10) return;
	fout<<T-3<<" "<<(T-2)/2<<endl;
	spostamenti(T-2);
}

int main()
{
	fin.open(FILE_INPUT);
	fout.open(FILE_OUTPUT);

	if(!fin || !fout) return 1;
    int N;
    fin>>N;
	if(N == 3) {
		fout<<"4 3\n2 7\n6 2\n4 6\n7 4"<<endl;
	}
	else {
		fout<<2*N-3<<" "<<N<<endl;
		spostamenti(N*2+2);
		fout<<"6 4\n2 6\n5 2"<<endl;
		fout<<2*N+1<<" 5"<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
