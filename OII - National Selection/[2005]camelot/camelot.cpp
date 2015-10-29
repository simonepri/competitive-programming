 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>	 //C Standard IO
#include <algorithm> //Per la funzione swap e find
#include <vector> 	 //Per la classe vector

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 4000

#define DEBUG 0

vector <int> Hamiltoniano;
vector < vector <int> > Grafo;

//Spiegazione Algoritmo => http://en.wikipedia.org/wiki/Ore%27s_theorem#Algorithm

int Hamiltonian_path(int N) {
	int Vi1,Vi2,Vj1,Vj2;
	int Vi2_idx,Vj1_idx,dist_Vi2_Vj1;
	for(int i = 0; i < N; i++) {
		Vi1 = Hamiltoniano[i];
		Vi2 = Hamiltoniano[(i+1) % N];
		if(find(Grafo[Vi1].begin(), Grafo[Vi1].end(), Vi2) == Grafo[Vi1].end()) { //Se Vi1 non è adiacente a Vi2
			for(int j = 0; j < N; j++) {
				if(j == i || j == (i+1) % N) continue; //Salto i vertici già presi in considerazione
				Vj1 = Hamiltoniano[j];
				Vj2 = Hamiltoniano[(j+1) % N];
				if(find(Grafo[Vi1].begin(), Grafo[Vi1].end(), Vj1) != Grafo[Vi1].end() && find(Grafo[Vj2].begin(), Grafo[Vj2].end(), Vi2) != Grafo[Vi1].end())  {//Se cè un arco da Vi1 a Vj1 e da Vj2 a Vi2
					Vi2_idx = (i+1) % N;
					Vj1_idx = j;
					dist_Vi2_Vj1 = (N-(Vi2_idx-Vj1_idx)) % N;
					#if DEBUG >=2
						printf(">> Vi2 = %d \t Vj1 = %d \t dist = %d \t k = %d\n",Vi2_idx, Vj1_idx, dist_Vi2_Vj1, dist_Vi2_Vj1/2);
					#endif
					for(int k = 0; k <= dist_Vi2_Vj1/2; k++) { //Inverto il ciclo tra Vi2 e Vj1 (compresi)
						#if DEBUG >= 3
							printf(">>> Scambio %d(%d) con %d(%d)\n",Hamiltoniano[(Vi2_idx+k) % N],(Vi2_idx+k) % N, Hamiltoniano[(N+Vj1_idx-k) % N],(N+Vj1_idx-k) % N);
						#endif
						swap(Hamiltoniano[(Vi2_idx+k) % N], Hamiltoniano[(N+Vj1_idx-k) % N]);
					}
					#if DEBUG >=3
						printf("\n");
					#endif
					return 1;
				}
			}
		}
	}
	return -1;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return 1;
	
	int N,temp;
    if(fscanf(in,"%d",&N) != 1) return 1;
	
	Hamiltoniano.resize(N);
	Grafo.resize(N+1);
	
	for(int i = 0; i < N; i++) {
		for(int j = 1; j < N+1; j++) {
			if(fscanf(in,"%d",&temp) != 1) return 1;
			if(temp) Grafo[i+1].push_back(j);
		}
		Hamiltoniano[i] = i+1;
	}
	
	int count = 0;
	while(Hamiltonian_path(N) != -1) {
		count++;
		if(count >= N) break;
	}
	#if DEBUG >= 1
		printf("> Operazioni Necessarie: %d\n",count);
	#endif
	
	for(int i = 0; i < N; i++) {
		#if DEBUG >= 1
			int Vi1 = Hamiltoniano[i];
			int Vi2 = Hamiltoniano[(i+1) % N];
			if(find(Grafo[Vi1].begin(), Grafo[Vi1].end(), Vi2) == Grafo[Vi1].end()) printf("> %d(%d) e %d(%d) NON sono amici\n",Vi1,i,Vi2,(i+1) % N);
		#endif
		fprintf(out,"%d ",Hamiltoniano[i]);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
