 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>

#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

vector< vector<bool> > task_result;
vector<int> task_point;

void calculate_result(int player, int &point, int &passed) {
	int T = task_point.size();
	for(int t = 0; t < T; t++) {
		if(task_result[player][t] == true) {
			point += task_point[t];
			passed++;
		}
	}
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, T, P;
	bool read;
	int pos_p = 1, point_p = 0, passed_p = 0;
	
	in>>N>>T>>P;
	P--;
	task_result.resize(N);
	task_point.resize(T);
	
	for(int i = 0; i < N; i++) {
		task_result[i].resize(T);
		for(int j = 0; j < T; j++) {
			in>>read;
			if(read == false) task_point[j]++;
			task_result[i][j] = read;
		}
	}
	
	calculate_result(P, point_p, passed_p);
	
	for(int i = 0; i < N; i++) {
		if(i == P) continue;
		int point_i = 0, passed_i = 0;
		calculate_result(i, point_i, passed_i);
		
		if(point_i > point_p) pos_p++;
		else if(point_i == point_p && (passed_i > passed_p || passed_i == passed_p && i < P)) pos_p++;
	}
	
	out<<point_p<<" "<<pos_p;
	
	in.close();
	out.close();
	return 0;
}
