#ifndef __definicoes_h
#define __definicoes_h

#include<stdio.h>
#include<stdlib.h>

typedef struct node Node; 
typedef struct arvoreBinaria Arvore;
typedef struct parentesco Parentesco;

struct node {
	int valor; //element
	Node *sae; //sub árvore a esquerda
	Node *sad; //sub árvore a direita
};

struct arvoreBinaria {
	Node* raiz;
};

struct parentesco{
    Node* noPai = NULL;
    Node* noPaiSubstituto = NULL;
}
#endif
