#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *Left, *Right;

    Node(int value) {
        data = value;
        Left = NULL;
        Right = NULL;
    }
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }

    void insertNode(int value) {
        root = insertNodeRecursive(root, value);
    }

    Node* insertNodeRecursive(Node *node, int value) {
        if (node == NULL) {
            node = new Node(value);
        } else if (node->data > value) {
            node->Left = insertNodeRecursive(node->Left, value);
        } else {
            node->Right = insertNodeRecursive(node->Right, value);
        }
        return node;
    }

    bool deleteNode(int value) {
        return deleteNodeRecursive(root, value);
    }
    bool deleteNodeRecursive(Node *&node, int value){
        if (node == NULL) {
            return false;
        } else if (node->data > value) {
            return deleteNodeRecursive(node->Left, value);
        } else if (node->data < value) {
            return deleteNodeRecursive(node->Right, value);
        } else {
            Node *node1 = node;
            if (node->Left == NULL) {
                node = node->Right;
            } else if (node->Right == NULL) {
                node = node->Left;
            } else {
                Node *node2 = node->Right;
                searchStandFor(node1, node2);
            }
            delete node1;
            return true;
        }
    }
    void searchStandFor(Node *p, Node *&q) {
        if (q->Left) {
            searchStandFor(p, q->Left);
        } else {
            p->data = q->data;
            p = q;
            q = q->Right;
        }
    }

    Node* searchNode(int value) {
        return searchNodeRecursive(root, value);
    }

    Node* searchNodeRecursive(Node *node, int value) {
        if (node == NULL) {
            return NULL;
        } else if (node->data == value) {
            return node;
        } else if (node->data > value) {
            return searchNodeRecursive(node->Left, value);
        } else {
            return searchNodeRecursive(node->Right, value);
        }
    }

    void Preorder() {
        PreorderRecursive(root);
    }

    void PreorderRecursive(Node *node) {
        if (node != NULL) {
            cout << node->data << " ";
            PreorderRecursive(node->Left);
            PreorderRecursive(node->Right);
        }
    }

    void Inorder() {
        InorderRecursive(root);
    }

    void InorderRecursive(Node *node) {
        if (node != NULL) {
            InorderRecursive(node->Left);
            cout << node->data << " ";
            InorderRecursive(node->Right);
        }
    }

    void PostOrder() {
        PostOrderRecursive(root);
    }

    void PostOrderRecursive(Node *node) {
        if (node != NULL) {
            PostOrderRecursive(node->Left);
            PostOrderRecursive(node->Right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        tree.insertNode(u);
    }

    int val;
    cout << "Enter the value to delete: ";
    cin >> val;
    if (tree.deleteNode(val)) {
        cout << "Deleted value: " << val << endl;
    } else {
        cout << "Value not found." << endl;
    }

    int val2;
    cout << "Enter the value to search: ";
    cin >> val2;
    Node *result = tree.searchNode(val2);
    if (result != NULL) {
        cout << "Found value: " << result->data << endl;
    } else {
        cout << "Value not found." << endl;
    }

    cout << "Preorder traversal: ";
    tree.Preorder();
    cout << endl;

    cout << "Inorder traversal: ";
    tree.Inorder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.PostOrder();
    cout << endl;

    return 0;
}
