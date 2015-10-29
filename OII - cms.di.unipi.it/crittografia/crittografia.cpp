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

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 10
#define MAX_L 200000

bool isnum(char c) {return ( c-'0' >= 0 && c-'0' <= 9);}
int tonum(char c) {return c-'0';}

int decode(int N, int L, string &word, string &solution) {
	int temp;
	for(int i = 0; i < L/2; i++) {
		if(isnum(word[i])) {
			if(!isnum(word[L-i-1])) {
				temp = tonum(word[i]);
				if(solution[temp] == '*' || solution[temp] == word[L-i-1]) solution[temp] = word[L-i-1];
				else return 0;
			}
			else return 0;
		}
		else {
			if(isnum(word[L-i-1])) {
				temp = tonum(word[L-i-1]);
				if(solution[temp] == '*' || solution[temp] == word[i]) solution[temp] = word[i];
				else return 0;
			}
		}
	}
	return 1;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,L;
	string word;
	in>>N>>L>>word;
	string solution(N,'*');
	
	if(decode(N,L,word,solution)) out<<solution;
	else out<<"impossibile";
	
	in.close();
	out.close();
	return 0;
}
