 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct person {
	unsigned int floor, sol;
	bool from;
};

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N, P;
	in>>N>>P;
	vector<person> People(N);
	
	in>>People[0].floor;
	People[0].from = true;
	People[0].sol = 1;
	for(int i = 1; i < N; i++) {
		int j = i-1;
		in>>People[i].floor;
		if(People[j].from == (People[j].floor > People[i].floor)) {
			People[i].from = !People[j].from;
			People[i].sol = People[j].sol+1;
		}
		else {
			People[i].from = People[j].from;
			People[i].sol = People[j].sol;
		}
	}
	out<<People[N-1].sol;
	
	in.close();
	out.close();
	return 0;
}
