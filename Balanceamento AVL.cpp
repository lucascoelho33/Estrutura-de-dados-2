#include <iostream>

using namespace std;

Struct Node {
	int data;
	Node* left;
	Node* right;
	
	explicit Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

void rot_dir(Node*&p) {
	Node* q = p->left;
	Node* tmp = q->right;
	q->right = p;
	p->left = tmp;
	p = q;
}

void rot_esq(Node*&p) {
	Node* q = p->right;
	Node* tmp = q->left;
	q->left = p;
	p->right = tmp;
	p = q;
}

void rot_esq_dir(Node*& p) {
    rot_esq(p->left);
    rot_dir(p);
}

void rot_dir_esq(Node*& p) {
    rot_dir(p->right);
    rot_esq(p);
}

void emOrdem(Node* root) {
    if (root != nullptr) {
        emOrdem(root->left);
        cout << root->data << " ";
        emOrdem(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Construção da árvore
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Realizar rotações
    rot_dir(root);
    rot_esq(root->right);
    rot_esq_dir(root->left);

    // Imprimir a árvore em ordem
    cout << "Em ordem da árvore: ";
    emOrdem(root);
    cout << endl;

    return 0;
}
