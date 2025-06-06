#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================ Tree Class =================
class Tree {
private:
    // Attributes that keep on changing
    int x;
    int y;

    // Attributes that remain constant
    string name;
    string color;
    string texture;

public:
    Tree(int x, int y, string name, string color, string texture) 
        : x(x), y(y), name(name), color(color), texture(texture) {}

    void draw() {
        cout << "Drawing tree at (" << x << ", " << y << ") with type " << name << endl;
    }
};

// ================ Forest Class =================
class Forest {
private:
    vector<Tree*> trees;

public:
    void plantTree(int x, int y, string name, string color, string texture) {
        Tree* tree = new Tree(x, y, name, color, texture);
        trees.push_back(tree);
    }

    void draw() {
        for (Tree* tree : trees) {
            tree->draw();
        }
    }

    ~Forest() {
        for (Tree* tree : trees) {
            delete tree;
        }
    }
};

// =============== Client Code ==================
int main() {
    Forest forest;

    // Planting 1 million trees (memory inefficient)
    for (int i = 0; i < 1000000; i++) {
        forest.plantTree(i, i, "Oak", "Green", "Rough");
    }

    cout << "Planted 1 million trees." << endl;

    return 0;
}