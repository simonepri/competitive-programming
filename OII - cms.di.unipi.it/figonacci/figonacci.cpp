 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#define F0	-1
#define F1 0

using namespace std;

int enumera(int N, int M) {
    int temp, Fn, sum;

    sum = M+(F0+F1);
	for(int i = 1; i < N; i++) {
        temp = Fn;
		Fn = (((((i % M) * (Fn % M)) % M) - sum) + M) % M;
		sum = (sum + temp) % M;
	}
    return Fn;
}

#include <stdio.h>
#include <assert.h>

int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));

    fprintf(fw, "%d\n", enumera(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}

