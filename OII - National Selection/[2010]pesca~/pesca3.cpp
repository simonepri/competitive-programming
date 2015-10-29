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
	bool operator() (const point &lhs, const point &rhs) {
		if(lhs.y != rhs.y) return lhs.y < rhs.y;
		else return lhs.x < rhs.x;
	}
};

point start,finish;
set<point, cmp> Fish;
vector<int> Move[2];

void fish_erase(point p_old, point p_new, int type) {
	if(type == RED) {
		set<point>::iterator it = Fish.lower_bound(p_old);
		if(it != Fish.begin()) {
			while(p_old.y <= it->y && it->y <= p_new.y) {
				cout<<"> point: "<<it->x<<" "<<it->y<<endl;
				if(it->x >= p_old.x) it--;
				else if(it->y > p_old.y){
					cout<<"> EE: "<<it->x<<" "<<it->y<<endl;
					Fish.erase(it++);
				}
				else it--;
			}
		}
	}
	else if(type == BLUE) {
		p_new.y -= 1;
		set<point>::iterator it = Fish.lower_bound(p_old);
		if(it != Fish.end()) {
			cout<<"> point: "<<it->x<<" "<<it->y<<endl;
			while(p_old.y <= it->y && it->y <= p_new.y) {
				if(it->x < p_old.x) it++;
				else {
					cout<<"> EE: "<<it->x<<" "<<it->y<<endl;
					Fish.erase(it++);
				}
			}
		}
	}
	return;
}

void boat_move(int move, int type) {
	static int last[2] = {0,0};
	static point pos_new[2], pos_old[2];
	if(last[type] == 0) {
		pos_new[type] = start;
		pos_old[type] = start;
		last[type] = move;
	}
	if(move > 0 && last[type] > 0) pos_new[type].y += move;
	else if(move < 0 && last[type] < 0) pos_new[type].x += -move;
	else {
		if(move > 0 && last[type] < 0) {
			pos_old[type] = pos_new[type];
			pos_new[type].y += move;
		}
		else if(move < 0 && last[type] > 0) {
			cout<<"> EM: "<<move<<endl;
			fish_erase(pos_old[type], pos_new[type], type);
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
	finish = start;
	
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
			Move[type].push_back(read);
			if(i == 0) {
				if(read > 0) finish.y += read;
				else if(read < 0) finish.x += -read;
			}
		}
		type = (type == BLUE) ? RED : BLUE;
	}

	set<point>::iterator it = Fish.end();
	while(it != Fish.begin()) {
		it--;
		if(it->x > finish.x || it->y > finish.y) Fish.erase(it++);
	}

	for(set<point>::iterator it = Fish.begin(); it != Fish.end(); it++) {
		cout<<it->x<<" "<<it->y<<endl;
	}
	cout<<endl;

	for(int i = 0; i < 2; i++) {
		for(vector<int>::iterator it = Move[i].begin(); it != Move[i].end(); it++) {
			boat_move(*it,i);
		}
		cout<<endl;
	}
	
	out<<Fish.size();
	
	in.close();
	out.close();
	return 0;
}
