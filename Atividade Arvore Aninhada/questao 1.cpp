// 1 - INCLUIR NÓS EM UMA ARVORE ALINHADA
// -----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct arv {
	int info;
	struct arv *prox;
}Arv;

void incluir(Arv **raiz, int valor) {
	Arv *n = (Arv *)malloc(sizeof(Arv));
    n->info = valor;
    n->prox = NULL;

    if (*raiz == NULL) {
        *raiz = n;
    } else {
        Arv *atual = *raiz;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = n;
    }
}

// FAZER PERCURSO IN-ORDER EM UMA ARVORE ALINHADA
void inorder(Arv *no) {
	if(no != NULL) {
		inorder(no->prox);
		printf("%d", no->prox);
	}
}

// FAZER PERCURSO PRE-ORDER EM UMA ARVORE ALINHADA
void preorder(Arv *no) {
	if(no != NULL) {
		preorder(no->info);
		printf("%d", no->info);
	}
}

int main() {
	Arv *arvore = NULL;
	
	incluir(&arvore, 4);
	incluir(&arvore, 1);
	incluir(&arvore, 5);
	incluir(&arvore, 7);
	incluir(&arvore, 2);
	incluir(&arvore, 6);
	incluir(&arvore, 3);
	
	printf("Percurso In-Order: ");
	inorder(arvore);
	
	printf("Percurso Pre-Order: ");
	preorder(arvore);
	
	return 0;
}
