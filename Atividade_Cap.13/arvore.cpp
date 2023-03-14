

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct arvoreS {
	struct arvoreS *direita;
	int item;
    struct arvoreS *esquerda;
} *Arvore;

Arvore criarArvore(Arvore e, int item, Arvore d){
	Arvore novo = (Arvore)malloc(sizeof(arvoreS));
	novo->esquerda = e;
	novo->item = item;
	novo->direita = d;
	return novo;	
}

void emOrdem(Arvore arvore) {
    if(arvore == NULL) return;
    emOrdem(arvore->esquerda);
    cout << arvore->item << endl;
    emOrdem(arvore->direita);
}
void preOrdem(Arvore arvore) {
    if(arvore == NULL) return;
    cout << arvore->item << endl;
    emOrdem(arvore->esquerda);
    emOrdem(arvore->direita);
}
void posOrdem(Arvore arvore) {
    if(arvore == NULL) return;
    emOrdem(arvore->esquerda);
    emOrdem(arvore->direita);
    cout << arvore->item << endl;
}

void destruirArvore(Arvore *arvore) {
    if(*arvore == NULL) return;
    destruirArvore(&(*arvore)->esquerda);
    destruirArvore(&(*arvore)->direita);
    free(*arvore);
    *arvore = NULL;
    
}
