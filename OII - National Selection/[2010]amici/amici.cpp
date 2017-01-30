 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <cmath>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int K, N, T;
vector <int> Pos_Friend;
vector <bool> Is_Friend;
vector <int> Permutation;

vector <int> Pos_temp;
vector <int> Perm_temp;


void apply_perm(vector<int> &pos) {
	for(int i = 0; i < N; i++) {
		Perm_temp[ Permutation[i]-1 ] = pos[i];	
	}
	pos.swap(Perm_temp);
	return;
}

void new_perm() {
    apply_perm(Pos_temp);
	for(int i = 0; i < N; i++) {
		Permutation[ Pos_temp[i]-1 ] = i+1;
	}
	return;
}

int first_K() {
	int i; 
	for(i = 0; i < N; i++) if(Is_Friend[Pos_Friend[i]-1]) break;
	if(i != 0) return i+1;
	
	i = N;
	while(Is_Friend[Pos_Friend[i-1]-1]) i--;
	if(i == N) return 1;
	return i+1;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>N>>K>>T;
	
	Is_Friend.resize(N); Pos_Friend.resize(N); Permutation.resize(N); Pos_temp.resize(N); Perm_temp.resize(N);
	
	for(int i = 0; i < N; i++) {
		Pos_Friend[i] = i+1;
		Pos_temp[i] = i+1;
		in >> Permutation[i];
	}
	int read;
	for(int i = 0; i < K; i++) {
		in >> read;
		Is_Friend[read-1] = true;
	}

	int bits = ceil(log2(T));
	for(int i = 0; i <= bits; i++) {
		if((T & 1 << i) != 0) {
			apply_perm(Pos_Friend);
		}
		if(i+1 <= bits) {
			if(i == 0) apply_perm(Pos_temp);
			new_perm();
		}
	}
	out << first_K();
	
	in.close();
	out.close();
	return 0;
}

