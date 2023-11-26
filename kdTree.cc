#include "kdTree.hh"
#include <ctime>
kdTree::kdTree(int k) {
    this->k = k;
    this->n = 0;
    this->root = nullptr;
    this->visitedNodes = 0;
    cout << time(NULL) << endl;
    srand(time(NULL));
}

double kdTree::valori(int i) const{
    if (this->root == nullptr || this->root->x.empty() or i >= this->root->x.size())
        return -1;
    return this->root->x[i];
}

bool kdTree::empty() const{
    return !this->root;
}

shared_ptr<Node> kdTree::getRoot() const{
    return this->root;
}

shared_ptr<Node> kdTree::i_insert(shared_ptr<Node>& curr, const vector<double>& info, unsigned depth, TreeType tipo, BoundingBox& Bb) {
    if (curr == nullptr) {
        unsigned disc_axis;

        if (tipo == STANDARD)  disc_axis =  depth % k;
        else if (tipo == RELAXED) disc_axis = rand() % k;
        else if (tipo == SQUARISH) {
            double dist = 0; double dnt = disc_axis = 0;
            for (int i = 0; i < k; ++i) {
                //cout << "BBmin: " << Bb.minPoint[i] << ", BBmax: " << Bb.maxPoint[i] << endl;
                dist = Bb.maxPoint[i] - Bb.minPoint[i];
                if (dist > dnt) {
                    dnt = dist;
                    disc_axis = i;
                }
            }
        }
        curr = make_shared<Node>(info, nullptr, nullptr/*, nullptr*/);
        curr->discr = disc_axis;
        return curr;
    }

    if (info[curr->discr] < curr->x[curr->discr]) {
        Bb.maxPoint[curr->discr] = curr->x[curr->discr];
        curr->left = i_insert(curr->left, info, depth +1, tipo, Bb);
    } else {
        Bb.minPoint[curr->discr] = curr->x[curr->discr];
        curr->right = i_insert(curr->right, info, depth +1, tipo, Bb);
    }
    //cout << disc_axis << endl;
    return curr;
}

void kdTree::insert(const vector<double>& info, TreeType tipo) {
    ++n;

    BoundingBox Bb;
    Bb.minPoint = vector<double>(k, 0.0);
    Bb.maxPoint = vector<double>(k, 1.0);
    i_insert(root, info, 0, tipo, Bb);
}

int kdTree::getVisitedNodes() const {
    return this->visitedNodes;
}

void kdTree::printBT() {
    printBT("", root, false);
}

void kdTree::printBT(const string& prefix, const shared_ptr<Node> node, bool isLeft) {

    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << node->discr;
        for (int i : node->x) cout << ' ' << node->x[node->discr];
        cout << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}