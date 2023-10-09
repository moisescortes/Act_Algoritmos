#include <iostream>
#include <vector>
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    void visit(int num) {
        std::cout << "Preorder traversal starting from BST object with data " << num << ":\n";
        preorder(root);
    }

private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        }

        return node;
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
};

int main() {
    BST tree;

    std::vector <int> vec = {5, 3, 2, 4, 7, 6, 8};
        for(int i = 0; i < vec.size(); i++){
            tree.insert(vec[i]);
        }

    // Llama a visit desde el objeto BST e imprime en preorden
    tree.visit(5);

    return 0;
}