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
	int ord;
	char I;
};

int order_num;
char ing_ava;
int ing_num[8];
list<order> Q;

void Bake(int K);

char to_bin(int N, int *A) {
	char temp = 0;
	for(int i = 0; i < N; i++) temp |= (1 << A[i]);
	return temp;
}

bool is_cookable(char I) {
	return ((ing_ava & I) == I);
}

void cook_it(char I) {
	for(int i = 0; i < 8; i++) {
		if((I & 1 << i) != 0) {
			ing_num[i]--;
			if(ing_num[i] == 0) ing_ava &= ~(1 << i);
		}
	}
	return;
}

void add_queue(int ord, int I) {
	order temp;
	temp.ord = ord;
	temp.I = I;
	Q.push_back(temp);
	return;
}

void elaborate_queue() {
	for(list<order>::iterator it = Q.begin(); it != Q.end(); it++) {
		if(is_cookable(it->I)) {
			cook_it(it->I);
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
	char I = to_bin(N, A);
	if(is_cookable(I)) {
		cook_it(I);
		Bake(order_num);
	}
	else {
		add_queue(order_num, I);
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
	cout<<K;
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
