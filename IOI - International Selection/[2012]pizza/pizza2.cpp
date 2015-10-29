 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <list>
#include <vector>

#include "pizza.h"

using namespace std;

struct order {
	int ord, N;
	vector<int> A;
};

int order_num;
int ing[8];
list<order> Q;

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
	temp.A.insert(temp.A.end(), A, A+N);
	
	Q.push_back(temp);
	return;
}

void elaborate_queue() {
	int size = Q.size();
	for(list<order>::iterator it = Q.begin(); it != Q.end(); it++) {
		if(is_cookable(it->N, it->A)) {
			cook_it(it->N, it->A);
			Bake(it->ord);
			Q.erase(it);
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
