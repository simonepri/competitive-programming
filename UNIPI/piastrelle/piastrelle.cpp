 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

unsigned short N;
ofstream out;
ifstream in;
vector<unsigned short> arr;
void compositions(unsigned short n = N, unsigned short size = 0)
{
	for(int k = 1; k <= 2; k++)
	{
		arr[size] = k;
		if(n-k > 0) compositions(n-k, size+1);
		else if(n-k == 0) {
			for(int i = 0; i < size+1; i++) {
				if(arr[i] == 1) out<<"[O]";
				else if(arr[i] == 2) out<<"[OOOO]";
			}
			out<<endl;
		}
	}
}

int main()
{
	in.open(FILE_INPUT);
	out.open(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>N;
	arr.resize(N);
	compositions();
	
	in.close();
	out.close();
	return 0;
}
