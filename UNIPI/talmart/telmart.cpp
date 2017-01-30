 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
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
	
	int max;
	bool from;
	for(int i = 0; i < N; i++) {
		in>>People[i].floor;
		max = 0;
		from = true;
		for(int j = i-1; j > -1; j--) {
			if(People[j].sol < max) break;
			else if(People[j].from == (People[j].floor > People[i].floor)) {
				from = !People[j].from;
				max = People[j].sol;
			}
		}
		People[i].from = from;
		People[i].sol = max+1;
	}
	out<<People[N-1].sol;
	
	in.close();
	out.close();
	return 0;
}
