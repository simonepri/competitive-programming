/**
* Competitive Programming - Collection of solved problems.
*
* @author        Simone Primarosa,(http://simoneprimarosa.com)
* @link          (https://github.com/simonepri/competitive-programming)
* @license       MIT License (https://opensource.org/licenses/MIT)
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // faster I/O
  int count = 1;
  string str;
  map<string,string>::iterator lng;
  map<string, string> dict = {
    {"HELLO", "ENGLISH"},
    {"HOLA", "SPANISH"},
    {"HALLO", "GERMAN"},
    {"BONJOUR", "FRENCH"},
    {"CIAO", "ITALIAN"},
    {"ZDRAVSTVUJTE", "RUSSIAN"}
  };
  
  while(true) {
    cin >> str;
    
    if(str[0] == '#' && str.length() == 1) break;
    lng = dict.find(str);
    if(lng != dict.end()) {
      cout << "Case " << count << ": " << lng->second << endl;
    }
    else {
      cout << "Case " << count << ": " << "UNKNOWN" << endl;
    }
    count++;
  }
  return 0;
}
