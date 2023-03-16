#include <iostream>
#include <stdlib.h>
#include "../Atividade_Cap.13/arvore.cpp"

using namespace std;

void exibe_dec(Arvore arv){
	if(arv == NULL){
		return 0;
	}
	exibe_dec(arv->direita);
	printf("%i \n", arv->item);
	exibe_dec(arv->esquerda);
}

int main() {
    Arvore arvore = criarArvore(criarArvore(criarArvore(criarArvore(NULL, 0, NULL), 1, criarArvore(NULL, 2, NULL)), 3, criarArvore(NULL, 4, NULL)), 5, criarArvore(criarArvore(NULL, 6, NULL), 7, criarArvore(criarArvore(NULL, 8, NULL), 9, NULL)));

    exibe_dec(arvore);
}
