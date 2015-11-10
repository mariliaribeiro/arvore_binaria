#include "mallocNode.h"

Parentesco* criaParente(){
	Parentesco* novoNo = (Parentesco*) malloc(sizeof(Parentesco));
	novoNo->sae = NULL;
    novoNo->sad = NULL;
	return novoNo;
}

