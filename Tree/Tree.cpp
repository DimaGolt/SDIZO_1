#include <iostream>
#include <Windows.h>
#include "Tree.h"

using namespace std;

Tree::Tree() {
    guardian = new TreeNode();
    guardian->color = Color::Black;
    guardian->parent = guardian;
    guardian->left = guardian;
    guardian->right = guardian;

    root = guardian;
}

Tree::~Tree() {
    deleteNodes(root);

    if(guardian != nullptr)
        delete guardian;
}

void Tree::add(int var) {
    TreeNode* newNode;
    TreeNode* helper;

    newNode = new TreeNode(var, root, guardian, guardian, Color::Red);

    if(newNode->parent == guardian)
        root = newNode;
    else {
        while (true){
            if(var < newNode->parent->value){
                if(newNode->parent->left == guardian){
                    newNode->parent->left = newNode;
                    break;
                }
                newNode->parent = newNode->parent->left;
            } else{
                if(newNode->parent->right == guardian){
                    newNode->parent->right = newNode;
                    break;
                }
                newNode->parent = newNode->parent->right;
            }
        }
    }

    while (newNode != root && newNode->parent->color == Color::Red){
        if (newNode->parent == newNode->parent->parent->left){
            helper = newNode->parent->parent->right;

            if(helper->color == Color::Red){
                newNode->parent->color = Color::Black;
                helper->color = Color::Black;
                newNode->parent->parent->color = Color::Red;
                newNode = newNode->parent->parent;
                continue;
            }

            if(newNode == newNode->parent->right){
                newNode = newNode->parent;
                leftRotation(newNode);
            }

            newNode->parent->color = Color::Black;
            newNode->parent->parent->color = Color::Red;
            rightRotation(newNode->parent->parent);
            break;
        } else {
            helper = newNode->parent->parent->left;

            if (helper->color == Color::Red){
                newNode->parent->color = Color::Black;
                helper->color = Color::Black;
                newNode->parent->parent->color = Color::Red;
                newNode = newNode->parent->parent;
                continue;
            }

            if(newNode == newNode->parent->left){
                newNode = newNode->parent;
                rightRotation(newNode);
            }

            newNode->parent->color = Color::Black;
            newNode->parent->parent->color = Color::Red;
            leftRotation(newNode->parent->parent);
            break;
        }
    }

    root->color = Color::Black;
}

void Tree::contains(int var) {
    if(root == guardian){
        cout << "Tree is empty" << endl;
    }

    TreeNode* helper = root;

    do
    {
        if (var == helper->value)
        {
            cout << "Found " << var << endl;
            break;
        }

        if (var < helper->value)
        {
            helper = helper->left;
        }

        if (var > helper->value)
        {
            helper = helper->right;
        }
    } while (helper != guardian);
}

void Tree::remove(int var) {
    TreeNode* nodeToRemove = findNode(var, root);

    if (nodeToRemove == nullptr){
        return;
    }

    TreeNode* helperOne;
    TreeNode* helperTwo;

    if (nodeToRemove->left == guardian
        || nodeToRemove->right == guardian)
    {
        helperOne = nodeToRemove;
    }
    else
    {
        helperOne = successor(nodeToRemove);
    }

    if (helperOne->left != guardian)
    {
        helperTwo = helperOne->left;
    }
    else
    {
        helperTwo = helperOne->right;
    }

    helperTwo->parent = helperOne->parent;

    if (helperOne->parent == guardian)
    {
        root = helperTwo;
    }
    else
    {
        if (helperOne == helperOne->parent->left)
        {
            helperOne->parent->left = helperTwo;
        }
        else
        {
            helperOne->parent->right = helperTwo;
        }
    }

    if (helperOne != nodeToRemove)
    {
        nodeToRemove->value = helperOne->value;
    }

    if (helperOne->color == Color::Black)
    {
        deleteFixUp(helperTwo);
    }
}

void Tree::printBT(const string& prefix, const TreeNode* node, bool isLeft)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(node == guardian)
        return;
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "L--" );

        // print the value of the node
        int color = node->color == Color::Red ? 12: 8;
        SetConsoleTextAttribute(hConsole, color);
        cout << node->value << std::endl;
        SetConsoleTextAttribute(hConsole, 15);

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void Tree::print()
{
    printBT("", root, false);
}

TreeNode* Tree::successor(TreeNode* node){
    if (node->right != guardian)
    {
        return this->minimum(node->right);
    }

    TreeNode* helper = node->parent;
    while (helper != guardian && node == helper->right)
    {
        node = helper;
        helper = helper->parent;
    }
    return helper;
}

TreeNode* Tree::minimum(TreeNode* node){
    while (node->left != guardian)
    {
        node = node->left;
    }
    return node;
}

TreeNode* Tree::findNode(int var, TreeNode* node) {
    if (node == guardian)
    {
        return nullptr;
    }

    if (var == node->value)
    {
        return node;
    }

    if (var > node->value)
    {
        return findNode(var, node->right);
    }

    return findNode(var, node->left);
}

void Tree::leftRotation(TreeNode* node)
{
    // Create two temporary pointers
    TreeNode* child;
    TreeNode* parent;

    child = node->right;

    // Check if right child exits
    if (child != guardian)
    {
        parent = node->parent;
        node->right = child->left;

        // Check if exists left child of right child
        if (node->right != guardian)
        {
            node->right->parent = node;
        }

        // Swap nodes
        child->left = node;
        child->parent = parent;
        node->parent = child;

        // Check if parent exists
        if (parent != guardian)
        {
            if (parent->left == node)
            {
                parent->left = child;
                return;
            }
            parent->right = child;
            return;
        }
        root = child;
    }
}

void Tree::rightRotation(TreeNode* node)
{
    TreeNode* child;
    TreeNode* parent;

    child = node->left;

    if (child != guardian)
    {
        parent = node->parent;
        node->left = child->right;

        if (node->left != guardian)
        {
            node->left->parent = node;
        }

        child->right = node;
        child->parent = parent;
        node->parent = child;

        if (parent != guardian)
        {
            if (parent->left == node)
            {
                parent->left = child;
                return;
            }
            parent->right = child;
            return;
        }
        root = child;
    }
}

void Tree::deleteFixUp(TreeNode* node)
{
    TreeNode* helper;

    while (node != root && node->color == Color::Black)
    {
        if (node == node->parent->left)
        {
            helper = node->parent->right;

            if (helper->color == Color::Red)
            {
                helper->color = Color::Black;
                node->parent->color = Color::Red;
                leftRotation(node->parent);
                helper = node->parent->right;
            }

            if (helper->left->color == Color::Black
                && helper->right->color == Color::Black)
            {
                helper->color = Color::Red;
                node = node->parent;
            }
            else
            {
                if (helper->right->color == Color::Black)
                {
                    helper->left->color = Color::Black;
                    helper->color = Color::Red;
                    rightRotation(helper);
                    helper = node->parent->right;
                }
                helper->color = helper->parent->color;
                node->parent->color = Color::Black;
                helper->right->color = Color::Black;
                this->leftRotation(node->parent);
                node = root;
            }
        }
        else
        {
            helper = node->parent->left;

            if (helper->color == Color::Red)
            {
                helper->color = Color::Black;
                node->parent->color = Color::Red;
                rightRotation(node->parent);
                helper = node->parent->left;
            }

            if (helper->right->color == Color::Black
                && helper->left->color == Color::Black)
            {
                helper->color = Color::Red;
                node = node->parent;
            }
            else
            {
                if (helper->left->color == Color::Black)
                {
                    helper->right->color = Color::Black;
                    helper->color = Color::Red;
                    leftRotation(helper);
                    helper = node->parent->left;
                }
                helper->color = helper->parent->color;
                node->parent->color = Color::Black;
                helper->left->color = Color::Black;
                rightRotation(node->parent);
                node = root;
            }
        }
    }
    node->color = Color::Black;
}

void Tree::deleteNodes(TreeNode* node)
{
    if (node != guardian)
    {
        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    }
}