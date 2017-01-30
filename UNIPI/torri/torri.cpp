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

void swap(int a, int b) {
	int c = a;
	a = b;
	b = c;
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N;
	vector<int> H,C;
	vector<int> solution;
	
	in>>N;
	H.resize(N);
	C.resize(N);
	solution.resize(N);
	
	for(int i = 0; i < N; i++) {
		in>>H[i]>>C[i];
		
		if(i > 0) {
			if(H[i-1] < H[i]) {
				int temp = 0;
				for(int j = i-1; j >= 0; j--) {
					if(H[j] <= H[i]) {
						temp += C[j];
					}
					else {
						temp += solution[j];
						break;
					}
				}
				if(temp <= C[i]) solution[i] = temp;
				else {
					solution[i] = solution[i-1] + C[i];
					H[i] = H[i-1];
					C[i] = C[i-1];
				}
			}
			else if(H[i-1] == H[i]) {
				if(C[i] > C[i-1]) {
					solution[i] = solution[i-1] + C[i-1];
				}
				else {
					solution[i] = solution[i-1] + C[i];
					swap(H[i],H[i-1]);
					swap(C[i],C[i-1]);
				}
			}
			else {
				solution[i] = solution[i-1];
			}
		}
		cout<<solution[i]<<endl;
	}
	
	out<<solution[N-1];
	in.close();
	out.close();
	return 0;
}
