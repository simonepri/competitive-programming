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

vector<bool> coins;

int query(int A, int B) {
	int count = 0;
	for(int i = A; i <= B; i++) if(coins[i]) count++;
	return count;
}

void update(int A, int B) {
	for(int i = A; i <= B; i++) coins[i] = !coins[i];
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, Q;
	in>>N>>Q;
	coins.resize(N);
	
	int T, A, B;
	for(int i = 0; i < Q; i++) {
		in>>T>>A>>B;
		if(T) out<<query(A, B)<<endl;
		else update(A, B);
	}
	
	in.close();
	out.close();
	return 0;
}
