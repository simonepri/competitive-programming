/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>

using namespace std;

int T, N, G;
int P, W, MW;
int knapsack[1000+1][30+1] = {0};
int weigth[1000+1] = {0};
int value[1000+1] = {0};

int max_value(int fW, int tW) {
  if(fW <= tW) {
    for(int e = 1; e <= N; e++) {
      for(int w = fW; w <= tW; w++) {
        if(weigth[e] <= w) {
          knapsack[e][w] = max(value[e]+knapsack[e-1][w-weigth[e]], knapsack[e-1][w]);
        }
        else knapsack[e][w] = knapsack[e-1][w];
      }
    }
  }
  return knapsack[N][tW];
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  
  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> N;
    for(int e = 1; e <= N; e++) {
      cin >> value[e] >> weigth[e];
    }
    
    int sol = 0;
    int last = 1;
    cin >> G;
    for(int g = 0; g < G; g++)
    {
      cin >> MW;
      int val = max_value(last, MW);
      sol += val;
      last = MW+1;
    }
    cout << sol << endl;
  }
  
  return 0;
}
