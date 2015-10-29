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
#include <vector>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N,idx_1,idx_2,last = -1, now = -1,count = 0,temp[] = {-1,-1};
	
	in>>N;
	for(int i = 0; i < N; i++) {
		idx_1 = (i % 2);
		idx_2 = ((i-1) % 2);
		cout<<temp[idx_1]<<" "<<temp[idx_2]<<endl;
		in>>temp[idx_1];
		cout<<temp[idx_1]<<" "<<temp[idx_2]<<endl;
		
		if(idx_2 >= 0 && temp[idx_2] != -1) {
			now = (temp[idx_2] - temp[idx_1] < 0 ? 0 : 1);
			cout<<">last:"<<last<<" now:"<<now<<endl;
			if(last == -1 || last != now || temp[idx_2] == -1) {
				last = now;
				count++;
				cout<<">>inserito:"<<temp[idx_1]<<endl;
			}
			else {
				temp[idx_1] = (!last ? (temp[idx_1] > temp[idx_2] ? temp[idx_1] : temp[idx_2]) : (temp[idx_1] < temp[idx_2] ? temp[idx_1] : temp[idx_2]));
				cout<<">>scelgo:"<<temp[idx_1]<<endl<<endl;
			}
		}
		else {
			count++;
			cout<<">>>inserito:"<<temp[idx_1]<<endl;
		}
	}
	out<<count;
	in.close();
	out.close();
	return 0;
}
