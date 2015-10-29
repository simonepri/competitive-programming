 /**
 * Competitive Programming - Collection of solved problems.
 *
 * @copyright     Copyright (c) 2014, Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */
 
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

#define MAX_N 12

vector<int> PASSATA[MAX_N];
vector<int> RICEVUTO[MAX_N];
vector<int> cancellato(MAX_N);
vector<int> rimovibile(MAX_N);

int remove(int fulcro) {
	int _removed_count = 1,_temp,_flag=0,_c=0;
	cancellato.push_back(fulcro);
	//printf("CANCELLATO -> %d\n",fulcro);
	for(int _i = 0; _i < PASSATA[fulcro].size(); _i++) {
		_temp = PASSATA[fulcro].at(_i);
		if(find(cancellato.begin(), cancellato.end(), _temp) == cancellato.end()) { //se non cancellato
			//printf("IL FULCRO PASSA A %d CHE NON E' ELIMINATO\n",_temp);
			for(int _j = 0; _j < RICEVUTO[_temp].size(); _j++) if(find(cancellato.begin(), cancellato.end(), RICEVUTO[_temp].at(_j)) == cancellato.end()) _c++;
			for(int _j = 0; _j < RICEVUTO[_temp].size(); _j++) {
				if(find(cancellato.begin(), cancellato.end(), RICEVUTO[_temp].at(_j)) == cancellato.end()) { //se non trovato
					if(find(rimovibile.begin(), rimovibile.end(), RICEVUTO[_temp].at(_j)) == rimovibile.end()) { //se non rimovibile
						if(_c == 1) {
							rimovibile.push_back(_temp);
							//printf("%d CHE NON E' ELIMINATO HA ALTRI GIOCATORI CHE PASSANO %d però ne ha solo uno\n",_temp,RICEVUTO[_temp].at(_j));
						}
						//else printf("%d CHE NON E' ELIMINATO HA ALTRI GIOCATORI CHE PASSANO %d\n",_temp,RICEVUTO[_temp].at(_j));
						_flag = 1;
						break;
					}
					//else printf("%d CHE NON E' ELIMINATO HA ALTRI GIOCATORI CHE PASSANO %d però sono rimobili quinid levo\n",_temp,RICEVUTO[_temp].at(_j));
				}
			}
			_c = 0;
			if(_flag == 0) _removed_count += remove(_temp);
			else _flag = 0;
		}
	}
	return _removed_count;
}

int main()
{
	FILE *in,*out;
	in = fopen(FILE_INPUT,"r");
	out = fopen(FILE_OUTPUT,"w");
	if(!in || !out) return -1;
	int M,first,second;
    if(fscanf(in,"%d\n",&M) != 1) return -1;
	for(int i = 0; i < M; i++) {
		if(fscanf(in,"%d %d\n",&first,&second) != 2) return -1;
		PASSATA[first].push_back(second);
		RICEVUTO[second].push_back(first);
	}
	int max = 0,tmax = 0,gmax=0;
	for(int i = 1; i < MAX_N; i++) {
		tmax = remove(i)-1;
		//printf("G:%d max: %d\n",i,tmax);
		if(tmax > max) {
			max = tmax;
			gmax = i;
		}
		cancellato.clear();
		rimovibile.clear();
	}
	fprintf(out,"%d",gmax);
	
	fclose(in);
	fclose(out);
	return 0;
}
