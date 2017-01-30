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
#include <cmath>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

struct point {
	int x,y;
	double angle;
};

vector<point> Points;

double angle(point p1, point p2) {
	return atan2(p2.x - p1.x, p2.y - p1.y);
}

bool sort_compare(point a, point b) {
	if(a.angle == b.angle) {
		if(a.y != b.y) return a.y < b.y;
		else return a.x > b.x;
	}
	return a.angle > b.angle;
}

int ccw(point p1, point p2, point p3) {
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	int N;
	in>>N;
	Points.resize(N+1);
	
	for(int i = 1; i <= N; i++) {
		in>>Points[i].x>>Points[i].y;
		if(Points[1].y > Points[i].y || Points[1].y == Points[i].y && Points[1].x < Points[i].x) swap(Points[1],Points[i]);
	}
	
	int count = 0;
	Points[1].angle = -1.0;
	for(int i = 2; i <= N; i++) {
		Points[i].angle = angle(Points[1], Points[i]);
		if(Points[i].angle == Points[i-1].angle) count++;
	}
	if(count == N-2) {
		out<<N;
		in.close();
		out.close();
		return 0;
	}
	
	sort(Points.begin()+2, Points.end(), sort_compare);
	
	Points[0] = Points[N];
	
	
	/*for(int i = 1; i <= N; i++) {
		cout<<Points[i].x<<" "<<Points[i].y<<endl;
	}
	cout<<endl;*/
	int M = 1;
	for(int i = 2; i <= N; i++) {
		while(ccw(Points[M-1], Points[M], Points[i]) <= 0) {
			if(M > 1) M--;
			else if(i == N) break;
			else i++;
		}
		M++;
		swap(Points[M], Points[i]);
	}
	
	/*for(int i = 1; i <= N; i++) {
		cout<<Points[i].x<<" "<<Points[i].y<<endl;
	}*/
	out<<M;
	in.close();
	out.close();
	return 0;
}
