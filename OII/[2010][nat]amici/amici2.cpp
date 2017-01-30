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

vector <int> Pos;
vector <bool> Amici;
vector <int> Pi;
vector <int> temp;

void apply_pi(vector<int> &vec) {
	int N = temp.size();
	for(int i = 0; i < N; i++) {
		temp[ Pi[i]-1 ] = vec[i];	
	}
	vec.swap(temp);
	return;
}

int first_K() {
	int i; 
	for(i = 0; i < Pos.size(); i++) if(Amici[Pos[i]-1]) break;
	if(i != 0) return i+1;
	
	i = Pos.size();
	while(Amici[Pos[i-1]-1]) i--;
	if(i == Pos.size()) return 1;
	return i+1;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int K, N, T;
	
	in >> N >> K >> T;
	
	Amici.resize(N);
	Pos.resize(N); Pi.resize(N); temp.resize(N);
	
	for(int i = 0; i < N; i++) {
		Pos[i] = i+1;
		in >> Pi[i];
	}
	int read;
	for(int i = 0; i < K; i++) {
		in >> read;
		Amici[read-1] = true;
	}

	for(int i = 0; i < T; i++) {
		apply_pi(Pos);
	}
	out << first_K();
	
	in.close();
	out.close();
	return 0;
}

