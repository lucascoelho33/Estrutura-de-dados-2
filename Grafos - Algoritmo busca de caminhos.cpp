#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n� da �rvore
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Fun��o para criar um novo n�
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para encontrar o caminho em uma �rvore bin�ria
int findPath(struct Node* root, int target, int path[], int pathIndex) {
    if (root == NULL) {
        return 0;
    }

    // Adiciona o valor atual ao caminho
    path[pathIndex] = root->value;
    pathIndex++;

    // Caso base: o n� atual cont�m o valor de destino
    if (root->value == target) {
        return 1;
    }

    // Caso recursivo: procurar o valor de destino nos n�s filhos
    if (findPath(root->left, target, path, pathIndex) || findPath(root->right, target, path, pathIndex)) {
        return 1;
    }

    // Remove o valor atual do caminho
    pathIndex--;
    return 0;
}

int main() {
    // Construindo a �rvore bin�ria
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int target = 5;
    int path[100];  // Tamanho m�ximo do caminho
    int pathIndex = 0;

    // Encontrando o caminho at� o valor alvo
    if (findPath(root, target, path, pathIndex)) {
        printf("Caminho encontrado: ");
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Caminho n�o encontrado.\n");
    }

    return 0;
}
