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
#include <set>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define NONE -1
#define RED 0
#define BLUE 1

struct point {
	int x, y;
};

struct cmp {
	bool operator() (const point& lhs, const point& rhs) const {
		if(lhs.x != rhs.x) return lhs.x < rhs.x;
		else return lhs.y < rhs.y;
	}
};

point start;
set<point, cmp> Fish;
int Fish_dx, Fish_sx;
point pos_new[2], pos_old[2];
int last[2] = {0,0};

void move(int move, int type) {
	if(last[type] == 0) {
		pos_new[type].x = start.x;
		pos_new[type].y = start.y;
		pos_old[type] = pos_new[type];
		last[type] = move;
	}
	if(move > 0 && last[type] > 0) {
		pos_new[type].y += move;
	}
	else if(move < 0 && last[type] < 0) {
		pos_new[type].x += -move;
	}
	else {
		if(type == RED) {
			for(set<point>::iterator it = Fish.begin(); it != Fish.end(); it++) {
				if(it->x < pos_new[type].x) {
					if(it->y > pos_old[type].y) Fish.erase(it);
				}
				else break;
			}
		}
		else {
			set<point>::iterator it = Fish.end();
			while(it != Fish.begin()) {
				it--;
				if(it->x > pos_new[type].x) {
					if(it->y < pos_old[type].y) Fish.erase(it++);
				}
				else break;
			}
		}
		if(move > 0 && last[type] < 0) {
			pos_old[type] = pos_new[type];
			pos_new[type].y += move;
		}
		else if(move < 0 && last[type] > 0){
			pos_old[type] = pos_new[type];
			pos_new[type].x += -move;
		}
	}
	last[type] = move;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int P;
	in>>P;
	in>>start.x>>start.y;
	
	for(int i = 0; i < P; i++) {
		point temp;
		in>>temp.x>>temp.y;
		if(temp.x < start.x || temp.y < start.y) continue;
		Fish.insert(temp);
	}
	int type = NONE;
	for(int i = 0; i < 2; i++) {
		while(true) {
			int read;
			in>>read;
			if(read == 0) break;
			if(type == NONE) type = read > 0 ? RED : BLUE;
			move(read, type);
		}
		type = type == BLUE ? RED : BLUE;
	}
	set<point>::iterator it = Fish.end();
	while(it != Fish.begin()) {
		it--;
		if(it->x > pos_new[type].x || it->y > pos_old[type].y) Fish.erase(it++);
	}
	/*
	for(set<point>::iterator it = Fish.begin(); it != Fish.end(); it++) {
		cout<<it->x<<" "<<it->y<<endl;
	}*/
	out<<Fish.size();
	
	in.close();
	out.close();
	return 0;
}
