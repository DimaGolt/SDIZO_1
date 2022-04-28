#ifndef SDIZO_1_TREE_H
#define SDIZO_1_TREE_H

enum Color {
    Red,
    Black
};

struct TreeNode {
    int value{0};

    TreeNode *parent{nullptr};
    TreeNode *left{nullptr};
    TreeNode *right{nullptr};
    Color color{Color::Red};

    TreeNode(int value, TreeNode* parent, TreeNode* left, TreeNode* right, Color color)
    : value(value), parent(parent), left(left), right(right), color(color) {};

    TreeNode() = default;
};

class Tree {
public:
    Tree();
    ~Tree();
    void add(int var);
    void contains(int var);
    void remove(int var);
    void print();

    void fromFile(std::string fileName);

private:
    TreeNode* root;
    TreeNode* guardian;
    TreeNode *successor(TreeNode *node);
    TreeNode *minimum(TreeNode *node);
    TreeNode *findNode(int var, TreeNode *node);
    void leftRotation(TreeNode *node);
    void rightRotation(TreeNode *node);
    void deleteNodes(TreeNode *node);
    void deleteFixUp(TreeNode *node);
    void printBT(const std::string &prefix, const TreeNode *node, bool isLeft);

};


#endif //SDIZO_1_TREE_H
