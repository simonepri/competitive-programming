 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
//#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct point {
	long long x, y;
		bool operator <(const point &p) const {
			return x < p.x || (x == p.x && y < p.y);
		}
};

vector<point> P;
vector<point> H;

long long cross(const point &O, const point &A, const point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

void convex_hull()
{
	int N = P.size(), k = 0;
	H.resize(2*N);

	sort(P.begin(), P.end());

	for (int i = 0; i < N; ++i) {
		while (k >= 2 && (long long)cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	
	for (int i = N-2, t = k+1; i >= 0; i--) {
		while (k >= t && (long long)cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N;
	in>>N;
	
	if(N <= 3) {
		out<<N;
		in.close();
		out.close();
		return 0;
	}
	
	P.resize(N);
	
	for(int i = 0; i < N; i++) {
		in>>P[i].x>>P[i].y;
	}
	convex_hull();
	
	out<<H.size()-1;
	
	in.close();
	out.close();
	return 0;
}
