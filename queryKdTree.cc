using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cmath> // For sqrt and pow

#include "kdTree.hh"

TreeType convertStringToTreeType(const char* s) {
    if (strcmp(s, "STANDARD") == 0) return STANDARD;
    if (strcmp(s, "RELAXED") == 0) return RELAXED;
    if (strcmp(s, "SQUARISH") == 0) return SQUARISH;
    exit(-1);

}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <TreeType> [checkSolution]\n";
        return 1;
    }
    bool checkSolution = (argc == 3 and strcmp("True", argv[2]) == 0);


    TreeType type = convertStringToTreeType(argv[1]);

    int nArboles;
    cin >> nArboles;
    string result = to_string(nArboles) +"\n";

    for (int i = 0; i < nArboles; ++i) {
        int n, k, q;
        cin >> n >> k >> q;
        result.append(to_string(k) + " " + to_string(q) +  + "\n");

        kdTree tree(k);
        for (int j = 0; j < n; ++j) {
            vector<double> info(k);

            for (int w = 0; w < k; ++w) // Leemos las k coordenadas.
                cin >> info[w];

            tree.insert(info, type);
        }
        for (int j = 0; j < q; ++j) {
            vector<double> info(k);

            for (int w = 0; w < k; ++w) // Leemos las k coordenadas.
                cin >> info[w];
            shared_ptr<Node> nearestNeighbor = tree.findNearestNeighbor(info);

            for (int w = 0; w < k; ++w)
                result.append(to_string(nearestNeighbor->x[w]) + " ");
            result.append(to_string(tree.getVisitedNodes()) + "\n");

            }



        }
        cout << result << endl;
        return 0;

}
