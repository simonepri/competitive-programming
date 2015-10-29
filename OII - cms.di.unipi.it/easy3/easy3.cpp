 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int insert(int n, int var[]) {
	if(n > var[0]) {
		var[1] = var[0];
		var[0] = n;
		return 1;
	}
	else if(n > var[1]) {
		var[1] = n;
		return 1;
	}
	return 0;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N,temp,s1,s2;
	int odd[2] = {-1,-1}, even[2] = {-1,-1};
	in>>N;
	
	for(int i = 0; i < N; i++) {
		in>>temp;
		if(temp % 2 == 0) { //pari
			insert(temp,even);
		}
		else {
			insert(temp,odd);
		}
	}
	if(odd[1] != -1 || even[1] != -1) {
		s1 = odd[0]+odd[1];
		s2 = even[0]+even[1];
		out<< (s1 > s2 ? s1 : s2);
	}
	else {
		out<<-1;
	}
	in.close();
	out.close();
	return 0;
}
