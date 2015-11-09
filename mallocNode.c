#include "mallocNode.h"

Node* criaNode(){
	Node* novoNo = (Node*) malloc(sizeof(Node));
	novoNo->sae = NULL;
    novoNo->sad = NULL;
	return novoNo;
}

