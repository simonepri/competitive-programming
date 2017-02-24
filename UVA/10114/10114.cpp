 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <iostream>

#include <string>

using namespace std;

int simulate(double &loan, double &value, double &fee, int &month, double &percentage) {
  if(month > 0) loan -= fee;
  value *= percentage;
  
  if(loan < value) {
    if(month != 1) cout << month << " months" << endl;
    else cout << month << " month" << endl;
    return month;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int months, records;
  double payed, loan, fee, value;
  
  while(true) {
    cin >> months >> payed >> loan >> records;
    if(months < 0) break;
    
    fee = loan/months;
    value = loan+payed;
    
    int sol = -1;
    int m = 0, month;
    double p = 0.0, percentage;
    
    for(int i = 0; i < records; i++) {
      cin >> month >> percentage;
      percentage = 1 - percentage;
      
      if(sol != -1) continue;
      for(int j = m+1; j < month; j++) {
        sol = simulate(loan, value, fee, j, p);
        if(sol != -1) break;
      }
      m = month; p = percentage;
      if(sol != -1) continue;
      sol = simulate(loan, value, fee, month, percentage);
    }
    while(sol == -1) {
      sol = simulate(loan, value, fee, ++m, p);
    }
  }

	return 0;
}
