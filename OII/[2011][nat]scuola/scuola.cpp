 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <deque>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

ifstream in;
ofstream out;

void P_1(int N) {
	int start = 1;
	for(int i = 0; i < N; i++) {
		int pos = start;
		for(int j = 1; j <= N; j++) {
			out<<j<<" "<<pos<<" ";
			pos++;
			if(pos > N) pos = 1;
		}
		start--;
		if(start == 0) start = N;
		out<<endl;
	}
	return;
}

void P_2(int N) {
	deque<int> hero1;
	deque<int> hero2;
	for(int i = 0; i < N/2; i++) {
		hero1.push_back(i+1);
		hero2.push_back(N-i);
	}
	for(int i = 0; i < N-1; i++)
	{
		for(int j = 0; j < N/2; j++) out<<hero1[j]<<" "<<hero2[j]<<" ";
		out<<endl;
		hero1.pop_front();
		hero2.push_back(hero1.back());
		hero1.pop_back();
		hero1.push_front(hero2.front());
		hero2.pop_front();
		hero1.push_front(1);
	}
	return;
}

int main()
{
	in.open(FILE_INPUT);
	out.open(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, P;
	in>>N>>P;
	if(P == 1) P_1(N);
	else P_2(N);
	in.close();
	out.close();
	return 0;
}
