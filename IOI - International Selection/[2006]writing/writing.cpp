 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

int main()
{
	ifstream in(FILE_INPUT);
	ofstream out(FILE_OUTPUT);
	
	if(!in || !out) return 1;
	
	int W,S,count = 0;
	string glyph,sequences;
	
	in>>W>>S;
	in>>glyph>>sequences;
	
	sort(glyph.begin(),glyph.end());
	
	do {
		int temp = 0;
		while(true) {
			temp = sequences.find(glyph, temp);
			if(temp != -1) {
				temp++;
				count++;
			}
			else break;
		}
	}
	while(next_permutation(glyph.begin(),glyph.end()));
	
	out<<count;
	
	in.close();
	out.close();
	return 0;
}
