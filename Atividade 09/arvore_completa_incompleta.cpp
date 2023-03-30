

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
}Arv;

Arv *arvore(Arv *e, char x, Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;

}

void imprime(Arv *n){

	if (n!=NULL){

	cout<<"<"<<n->info;
	imprime(n->esq);
	imprime(n->dir);
	cout<<">";
   }
   else
     cout<<"<>";
}

int calculaQuantNos(Arv *no){
	if(no == NULL){
		return 0;
	}else {
		int nos = calculaQuantNos(no->esq) + 1;
		nos += calculaQuantNos(no->dir);
		return nos;
	}		
}

int alturaArvore(Arv *no){	        
	if(no == NULL){
		return 0;
	} else {
		int esquerda = alturaArvore(no->esq);
		int direita = alturaArvore(no->dir);

		if(esquerda > direita){
			return esquerda + 1;
		} else {
			return direita + 1;
		}
	}
}


bool ehArvoreBinariaCheia(Arv *no){
	int altura = alturaArvore(no);
	int totalNos = calculaQuantNos(no);
	return (pow(2, altura) - 1) == totalNos;
}

int calcularAlturaMinima(int totalNos){
	int alturaMinima = 0;

	if(totalNos % 2 != 0){
		totalNos++;
	}

	while(totalNos != 0){
		totalNos = totalNos / 2;
		alturaMinima++;
	}

	return alturaMinima;

}

bool ehArvoreCompleta(Arv *no){

	int totalNos = calculaQuantNos(no);
	int altura = alturaArvore(no);

	int alturaMinima = calcularAlturaMinima(totalNos);

	return alturaMinima == altura;	

}

main(){

	Arv *arv = arvore(arvore(arvore(NULL, 'd', NULL), 'b', arvore(NULL, 'e', NULL)) , 'a', arvore(NULL, 'c', arvore(NULL, 'f', NULL)));
	cout << "A arvore estah cheia? ";
	cout << std::boolalpha << ehArvoreCompleta(arv) << endl;

}
