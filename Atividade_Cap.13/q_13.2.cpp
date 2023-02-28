#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct arv {
	int valor;
	struct arv *direita, *esquerda;
}Arv;

Arv insere(Arv *raiz, int num) {
	if(raiz == NULL) {
		Arv *aux = (Arv *)malloc(sizeof(Arv));
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		
		return aux;
	}
	else {
		if(num < raiz->valor){
			raiz->esquerda = insere(raiz->esquerda, num);
		}else{
			raiz->direita = insere(raiz->direita, num);
		}
		
		return raiz;
	}
}

// Questão 13.2
int qtd_nos(Arv *raiz){
	if(raiz == NULL){
		return 0;
	}else{
		return 1 + qtd_nos(raiz->esquerda) + qtd_nos(raiz->direita);
	}
}

int main() {
	printf('\nQuantidade de nós: d\n', qtd_nos(raiz));
}
