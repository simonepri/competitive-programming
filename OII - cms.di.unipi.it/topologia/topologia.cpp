 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>

#include <vector>
#include <queue>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int lineari, anello, stella;
vector< vector<int> > Rete;
vector<bool> Visit;
vector<int> Times;

int find_component(int start = 0) {
	int N = Visit.size();
	for(int i = start; i < N; i++) if(Visit[i] == false) return i;
	return -1;
}

void categorize_component(int start) {
	int component_size = 0, component_one = 0, component_two = 0, component_max = 0;
	int actual;
	queue<int> Q;
	Q.push(start);
	Visit[start] = true;
	while(!Q.empty()) {
		actual = Q.front();
		Q.pop();
		
		if(Times[actual] == 1) component_one++;
		else if(Times[actual] == 2) component_two++;
		else if(Times[actual] > component_max ) component_max = Times[actual];
		component_size++;
		
		for(vector<int>::iterator it = Rete[actual].begin(); it != Rete[actual].end(); it++) {
			if(Visit[*it] == false) {
				Q.push(*it);
				Visit[*it] = true;
			}
		}
	}
	if(component_two == component_size && component_size > 2) anello++;
	else if(component_two == component_size-2 && component_one == 2 && component_size > 1) lineari++;
	else if(component_one == component_size-1 && component_max == component_size-1 && component_size > 3) stella++;
	
	return;
}

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int N, M, a, b;
	in>>N>>M;
	Rete.resize(N+1);
	Visit.resize(N+1);
	Times.resize(N+1);
	for(int i = 0; i < M; i++) {
		in>>a>>b;
		Rete[a].push_back(b);
		Rete[b].push_back(a);
		Times[a]++;
		Times[b]++;
	}
	int node = 0;
	while((node = find_component(node+1)) != -1) {
		categorize_component(node);
	}
	out<<lineari<<" "<<anello<<" "<<stella;
	
	in.close();
	out.close();
	return 0;
}
