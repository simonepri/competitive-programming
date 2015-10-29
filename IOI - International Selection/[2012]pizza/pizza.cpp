 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <deque>
#include <vector>

#include "pizza.h"

using namespace std;

struct order {
	int ord, N;
	vector<int> A;
};

int order_num;
vector<int> ing(8);
deque<order> Q;

bool is_cookable(int N, int *A) {
	for(int i = 0; i < N; i++) {
		if(ing[A[i]] == 0) return false;
	}
	return true;
}

void cook_it(int N, int *A) {
	for(int i = 0; i < N; i++) ing[A[i]]--;
	return;
}

bool is_cookable(int N, vector<int> &A) {
	for(int i = 0; i < N; i++) {
		if(ing[A[i]] == 0) return false;
	}
	return true;
}

void cook_it(int N, vector<int> &A) {
	for(int i = 0; i < N; i++) ing[A[i]]--;
	return;
}

void add_queue(int ord, int N, int *A) {
	order temp;
	temp.ord = ord;
	temp.N = N;
	temp.A.insert(temp.A.end(), &A[0], &A[N]);
	
	Q.push_back(temp);
	return;
}

void elaborate_queue() {
	int size = Q.size();
	for(int i = 0; i < size; i++) {
		if(is_cookable(Q[i].N, Q[i].A)) {
			cook_it(Q[i].N, Q[i].A);
			Bake(Q[i].ord);
			Q.erase(Q.begin()+i);
			break;
		}
	}
	return;
}

void Init() {
	return;
}

void Order(int N, int *A) {
	if(is_cookable(N, A)) {
		cook_it(N, A);
		Bake(order_num);
	}
	else {
		add_queue(order_num, N, A);
	}
	order_num++;
	return;
}

void Delivery(int I) {
	ing[I]++;
	elaborate_queue();
}
