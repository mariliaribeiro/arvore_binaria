#include "getTipoNo.h"

int isFolha(Node* no){
	if (no->sae == NULL && no->sad == NULL)			
		return 1;
	else
		return 0;
}

int isSubFolha(Node* no){
	if ((no->sae == NULL && no->sad != NULL) || (no->sad == NULL && no->sae != NULL)) 
		return 1;
	else
		return 0;
}

int isPaiDoisFilhos(Node* no){
	if (no->sae != NULL && no->sad != NULL)				
		return 1;
	else
		return 0;
}


int isRaiz(Arvore* arvore, Node* no){
	if(no->valor == arvore->raiz->valor)
		return 1;
	else
		return 0;
}
