 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <queue>
#include <vector>

using namespace std;

int order_num;
int ing_ava;
int ing_num[8];
queue<int> Q[256];

void Bake(int K);

int to_bin(int N, int *A) {
	int T = 0;
	for(int i = 0; i < N; i++) T |= (1 << A[i]);
	return T;
}

bool is_cookable(int T) {
	return ((ing_ava & T) == T);
}

void cook_it(int T) {
	for(int i = 0; i < 8; i++) {
		if((T & 1 << i) != 0) {
			ing_num[i]--;
			if(ing_num[i] == 0) ing_ava &= ~(1 << i);
		}
	}
	return;
}

void add_queue(int ord, int T) {
	Q[T].push(ord);
	return;
}

void elaborate_queue() {
	int min_T = 0;
	for(int T = 1; T < 256; T++) {
		if(!Q[T].empty() && is_cookable(T) && (min_T == 0 || Q[T].front() < Q[min_T].front())) min_T = T;
	}
	if(min_T != 0) {
		cook_it(min_T);
		Bake(Q[min_T].front());
		Q[min_T].pop();
	}
	return;
}

void Init() {
	return;
}

void Order(int N, int *A) {
	int T = to_bin(N, A);
	if(is_cookable(T)) {
		cook_it(T);
		Bake(order_num);
	}
	else {
		add_queue(order_num, T);
	}
	order_num++;
	return;
}

void Delivery(int I) {
	ing_num[I]++;
	ing_ava |= (1 << I);
	elaborate_queue();
}

/*
#include <iostream>

void Bake(int K) {
	cout<<K<<endl;
	return;
}

int main() {
	Delivery(1);
	Delivery(1);
	Delivery(1);
	
	Delivery(2);
	Delivery(2);
	
	int A[] = {1,2,3};
	Order(3, A);
	
	Delivery(4);
	Delivery(4);
	
	int B[] = {1,2,4};
	Order(3, B);
	
	Delivery(3);

	int C[] = {1,2,3,4};
	Order(4, C);
	
	Delivery(2);
	
	return 0;
}

*/
