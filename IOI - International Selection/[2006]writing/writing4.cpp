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

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	string S;
	char read;
	int G, N;
	int A[52] = {0}, B[52] = {0};
	int c = 0, d = 0, idx;
	in>>G>>N;
	
	for(int i = 0; i < G; i++) {
		in>>read;
		idx = ('A' <= read && read <= 'Z') ? (read-'A') : (('a' <= read && read <= 'z') ? 26+(read-'a') : -1);
		if(B[idx] == 0) c++;
		B[idx]++;
	}
	c = 52 - c;
	in>>S;
	
	for(int i = 0; i < N; i++) {
		if(A[S[i]] == B[S[i]]) c--;
		A[S[i]]++;
		if(A[S[i]] == B[S[i]]) c++;
		
		if(i+1 < G) continue;
		
		if(A[S[i-G]] == B[S[i-G]]) c--;
		A[S[i-G]]--;
		if(A[S[i-G]] == B[S[i-G]]) c++;
		
		if(c == 52) d++;
	}
	
	out<<d;
	
	in.close();
	out.close();
	return 0;
}
