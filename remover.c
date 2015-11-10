#include "remover.h"

Node* remover(Node* no, int valor){
    Node* noPai;
    
    if (no != NULL){
        if (no->valor == valor){    
            // é folha?
			if (no->sae == NULL && no->sad == NULL)				
				return isFolha(no, noPai, valor);
            
            // é sub folha?
			else if ((no->sae == NULL && no->sad != NULL) || (no->sad == NULL && no->sae != NULL)) 
				return isSubFolha(no, noPai, valor);	
			
			// é pai de dois filhos (maior dos menores)?
			else if (no->sae != NULL && no->sad != NULL)				
				return isPaiDoisFilhos(no, noPai, valor);
        }
        else if (no->valor > valor){
			noPai = getPai(no, valor);
            return remover(no->sae, valor);
        }
        else{
			noPai = getPai(no, valor);
            return remover(no->sad, valor);
        }
    }
    return no;
}

Node* isFolha(Node* no, Node* noPai, int valor){
	Node* noRemover = no;
	
	if(noPai->valor > valor)
		 noPai->sae = NULL;
	else
		 noPai->sad = NULL;
		 
	printf("Removido: %d\n", noRemover->valor);
	free(noRemover);	
	return no;		
}


//if ternário -> condição ? verdadeiro : falso
Node* isSubFolha(Node* no, Node* noPai, int valor){
	Node* noRemover = no;
	if(noPai->valor > valor)		
		noPai->sae = no->sad != NULL ? noRemover->sad : noRemover->sae;
	else
		noPai->sad = no->sad != NULL ? noRemover->sad : noRemover->sae;
		
	printf("Removido: %d\n", noRemover->valor);
	free(noRemover);	
	return no;	
}

Node* isPaiDoisFilhos(Node* no, Node* noPai, int valor){	
	Node* noRemover = no;
    Node* noSubstituto = getNoSubstituto(no->sae);	 //filho esquerdo do nó que quero remover
    Node* noPaiSubstituto = getPai(no->sae, noSubstituto->valor);
    
    noPaiSubstituto = getPai(no, noSubstituto->valor);
    noPaiSubstituto->sad = noSubstituto->sae;
        
    noSubstituto->sae = noRemover->sae;
    noSubstituto->sad = noRemover->sad;
		
    if(noPai->valor > valor)		
        noPai->sae = noSubstituto;
    else
        noPai->sad = noSubstituto;
        
	printf("Removido: %d\n", noRemover->valor);
	free(noRemover);	
	return no;	
}

Node* getPai(Node* no, int valor){
    if(no != NULL){
        if (no->valor < valor){
            if (no->sad != NULL && no->sad->valor == valor)
                return no;
            else
                return getPai(no->sad, valor);
        }
        else if(no->valor > valor){
            if (no->sae != NULL && no->sae->valor == valor)
                return no;
            else
                return getPai(no->sae, valor);
        }        
    }else{
        return NULL;
    }
}

Node* getMaiorMenores(Node* no){
	if(no != NULL){
		if(no->sad == NULL)
			return no;
		else
			return getMaiorMenores(no->sad);
	}
}

Node* getNoSubstituto(Node* no){
	if(no->sad != NULL)	
		return getMaiorMenores(no->sad);
	else
		return no;
}
