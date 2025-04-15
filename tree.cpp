#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Settree {
public:
    TreeNode* root;
    Settree(int val) : root(new TreeNode(val)) {}

    void theone(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
        }
        else {
            insert(root, val);
        }
    }

    void insert(TreeNode* tree, int val) {
        if (tree->value > val) {
            if (tree->left == nullptr) {
                tree->left = new TreeNode(val);
            }
            else {
                insert(tree->left, val);
            }
        }
        else {
            if (tree->right == nullptr) {
                tree->right = new TreeNode(val);
            }
            else {
                insert(tree->right, val);
            }
        }
    }

    void output(TreeNode* tree) {/*中序*/ 
        if (tree != nullptr) {
            output(tree->left);
            cout << tree->value<<' ';
            output(tree->right);
        }
    }
    void output1(TreeNode* tree) {/*前序*/ 
        if (tree != nullptr) {
            cout << tree->value << ' ';
            output1(tree->left);
            output1(tree->right);
        }
    }
    void output2(TreeNode* tree) {/*后序*/ 
        if (tree != nullptr) {
            output2(tree->left);
            output2(tree->right);
            cout << tree->value << ' ';
        }
    }
    void print() {
        cout << "中序" << endl;
        output(root);
        cout << endl << "前序" << endl;
        output1(root);
        cout << endl << "后序" << endl;
        output2(root);
    }
};

int main() {
    Settree tree(11);
    tree.theone(10);
    tree.theone(9);
    tree.theone(15);
    tree.theone(7);
    tree.theone(12);

    tree.print();

    return 0;
}