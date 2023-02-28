#<include.stdio.h>
#<include.stdlib.h>
#<include iostream>

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

int quantidade_folhas(Arv *raiz) {
	if(raiz == NULL){
		return 0;
	}else if(raiz->esquerda == NULL && raiz->direita == NULL){
		return 1;
	}else{
		return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
	}
}

int main() {
	cout << 'Quantidade de folhas: ' << quantidade_folhas(raiz) << endl;
}
