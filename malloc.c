#include "malloc.h"

Arvore* criaArvore() {
	Arvore* novaArvore = (Arvore*) malloc(sizeof(Arvore));
	novaArvore->raiz = NULL;
	return novaArvore;
}

Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->sae = NULL;
    novoNo->sad = NULL;
    //novoNo->altura = criaAltura();
	return novoNo;
}

/*Altura* criaAltura(){
	Altura* novaAltura = (Altura*) malloc(sizeof(Altura));
	novaAltura->alturaEsquerda = 0;
	novaAltura->alturaDireita = 0;
	return novaAltura;	
}*/
