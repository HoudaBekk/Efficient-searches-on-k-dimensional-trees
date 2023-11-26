#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <random>

#include "kdTree.hh"
using namespace std;

typedef vector<double> Coord;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Uso: ./programa T k n q" << endl;
        return 1;
    }

    random_device myRandomDevice;
    unsigned seed = myRandomDevice(); // para generar la "semilla"
    uniform_real_distribution<double> Uniforme(0.0, 1.0);
    default_random_engine RNG(seed);

    int T = atoi(argv[1]);
    int k = atoi(argv[2]);
    int n = atoi(argv[3]);
    int q = atoi(argv[4]);
    string result = "";

    result.append(to_string(T) + "\n");
    srand(time(NULL));

    for(int i = 1; i <= T; ++i) {
        result.append(to_string(n) + " " + to_string(k) +  " " + to_string(q) + "\n" );
        vector<vector<double>> info(n, vector<double>(k));
        kdTree tree(k);
        for(int j = 0; j < n; ++j) {
            for(int l = 0; l < k; ++l) {
                double val = Uniforme(RNG); //double(rand())/double(RAND_MAX);
                info[j][l] = val;
                result.append(to_string(val) + " ");
            }
            tree.insert(info[j], STANDARD);
            result.append("\n");
        }
        //tree.printBT();
        result.append("\n");
        vector<Coord> searches(q, Coord(k));

        for(int j = 0; j < q; ++j) {
            for(int l = 0; l < k; ++l) {
                double val = Uniforme(RNG);//double(rand())/double(RAND_MAX);
                searches[j][l] = val;
                result.append(to_string(val) + " ");
            }
            result.append("\n");
        }

    }
    cout << result;
    return 0;
}
