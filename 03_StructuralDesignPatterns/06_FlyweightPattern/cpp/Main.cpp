#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// ============= TreeType Class ================
class TreeType {
private:
    // Properties that are common among all trees of this type
    string name;
    string color;
    string texture;

public:
    TreeType(string name, string color, string texture)
        : name(name), color(color), texture(texture) {}

    void draw(int x, int y) {
        cout << "Drawing " << name << " tree at (" << x << ", " << y << ")" << endl;
    }
};

// ================ Tree Class =================
class Tree {
private:
    // Attributes that keep on changing
    int x;
    int y;

    // Attributes that remain constant
    TreeType* treeType;

public:
    Tree(int x, int y, TreeType* treeType) 
        : x(x), y(y), treeType(treeType) {}

    void draw() {
        treeType->draw(x, y);
    }
};

// ============ TreeFactory Class ==============
class TreeFactory {
private:
    static map<string, TreeType*> treeTypeMap;

public:
    static TreeType* getTreeType(string name, string color, string texture) {
        string key = name + " - " + color + " - " + texture;

        if (treeTypeMap.find(key) == treeTypeMap.end()) {
            treeTypeMap[key] = new TreeType(name, color, texture);
        }
        return treeTypeMap[key];
    }

    static void cleanUp() {
        for (auto& pair : treeTypeMap) {
            delete pair.second;
        }
        treeTypeMap.clear();
    }
};

// Initialize the static map
map<string, TreeType*> TreeFactory::treeTypeMap;

// ================ Forest Class =================
class Forest {
private:
    vector<Tree*> trees;

public:
    void plantTree(int x, int y, string name, string color, string texture) {
        TreeType* type = TreeFactory::getTreeType(name, color, texture);
        Tree* tree = new Tree(x, y, type);
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

    // Planting 1 million trees (memory efficient due to flyweight)
    for (int i = 0; i < 1000000; i++) {
        forest.plantTree(i, i, "Oak", "Green", "Rough");
    }

    cout << "Planted 1 million trees." << endl;

    // Clean up the TreeFactory
    TreeFactory::cleanUp();

    return 0;
}