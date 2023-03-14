#include <stdio.h>
#include <string.h>
#include <iostream>
#include "../Atividade_Cap.13/arvore.cpp"

using namespace std;

int calcular(int esquerda, int direita, int operacao){
	if(operacao == '+'){
		return esquerda + direita;
	}elif(operacao == '-'){
		return esquerda - direita;
	}elif(operacao == '*'){
		return esquerda * direita;
	}else{
		return esquerda / direita;
	}
}

int valor(Arvore arvore) {
    if(arvore->esquerda == arvore->direita) {
        return arvore->item;
    } else {
        int esquerda = valor(arvore->esquerda);
        int direita = valor(arvore->direita);
        return calculate(esquerda, direita, char(arvore->item));
    }
}

int main() {
	int main() {
    Arvore arvore = criarArvore(criarArvore(criarArvore(criarArvore(NULL, 5, NULL), '+', criarArvore(NULL, 3, NULL)), '/', criarArvore(NULL, 4, NULL)), '*', criarArvore(criarArvore(NULL, 6, NULL), '-', criarArvore(NULL, 1, NULL)));

    int valor1 = valor(arvore);

    cout << "Valor: " << valor1 << endl;
}
}
