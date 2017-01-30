 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>
#include <fstream>
#include <cmath>

#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N

struct punto {
	int x,y;
};

struct retta {
	punto p1,p2;
	retta(punto a, punto b) : p1(a),p2(b) {}
};

double angolo(retta R);
bool stessaparte(retta R, punto P, punto Q);
bool sort_compare(punto a, punto b);

int N, p1 = 0;
vector<punto> Piano;

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	in>>N;
	Piano.resize(N);
	
	for(int i = 0; i < N; i++) {
		in>>Piano[i].x>>Piano[i].y;
		if(Piano[p1].y > Piano[i].y || Piano[p1].y == Piano[i].y && Piano[p1].x < Piano[i].x) swap(Piano[p1],Piano[i]);
	}
	cout<<Piano[p1].x<<" "<<Piano[p1].y<<endl<<endl;
	
	sort(Piano.begin()+1, Piano.end(), sort_compare);
	
	for(int i = 0; i < N; i++) {
		cout<<Piano[i].x<<" "<<Piano[i].y<<endl;
	}
	
	
	in.close();
	out.close();
	return 0;
}

double angolo(retta R) {
	return atan2(R.p2.x - R.p1.x, R.p2.y - R.p1.y);
}

bool stessaparte(retta R, punto P, punto Q) {
	int dRx = R.p2.x - R.p1.x;
	int dRy = R.p2.y - R.p1.y;
	int dPx = P.x - R.p1.x;
	int dPy = P.y - R.p1.y;
	int dQx = Q.x - R.p2.x;
	int dQy = Q.y - R.p2.y;
	return ((((dRx * dPy) - (dRy * dPx)) * ((dRx * dQy) - (dRy * dQx))) >= 0);
}

bool sort_compare(punto a, punto b) {
	retta Ra(Piano[p1],a);
	retta Rb(Piano[p1],b);
	return angolo(Ra) > angolo(Rb);
}
