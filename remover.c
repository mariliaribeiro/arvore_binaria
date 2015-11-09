#include "remover.h"

Node* remover(Node* no, int valor){
   
    Node* noPai = NULL;
    Node* noRemover;
    
    if (no != NULL){
        if (no->valor == valor){    
			noRemover = no;
            //perdendo pai
            
            // é folha?
			if (no->sae == NULL && no->sad == NULL)
				return isFolha(no, noPai, noRemover, valor);
            
			//else if ((no->sae == NULL && no->sad != NULL) || (no->sad == NULL && no->sae != NULL)) // é sub folha?
				//return isSubFolha(no, noPai, noRemover, valor);	
						
			//else if (no->sae != NULL && no->sad != NULL) // é pai de dois filhos (maior dos menores)?
				//return isPaiDoisFilhos(no, noPai, noRemover, valor);
        }
        else if (no->valor > valor){
            noPai = no;
            printf("\npai: %d \nprox: %d\n", noPai->valor, no->sae->valor);
            return remover(no->sae, valor);
        }
        else{
            noPai = no;
            printf("\npai: %d \nprox: %d\n", noPai->valor, no->sae->valor);
            return remover(no->sad, valor);
        }
    }
    return no;
}

Node* isFolha(Node* no, Node* noPai, Node* noRemover, int valor){
	if(noPai->valor > valor)
		 noPai->sae = NULL;
	else
		 noPai->sad = NULL;
		 
	free(noRemover);	
	return no;		
}

/*Node* isSubFolha(Node* no, Node* noPai, Node* noRemover, int valor){
	if(noPai->valor > valor){
		//if ternário -> condição ? verdadeiro : falso
		noPai->sae = no->sad != NULL ? noRemover->sad : noRemover->sae;
	}else{
		noPai->sad = no->sad != NULL ? noRemover->sad : noRemover->sae;
	}
		
	free(noRemover);	
	return no;	
}

Node* isPaiDoisFilhos(Node* no, Node* noPaiSubstituto, int valor){	
    Node* noSubstituto;
    Node* noPaiSubstituto;
    
    //if (no != NULL)
	if(noPai->valor > valor){
		noPaiSubstituto = no;
		if(noRemover->sae->sad != NULL){
			if(no->sad != NULL)
				noSubstituto = remover(no->sad);
		}else{
			noSubstituto = no->sae->sad;
		}
		                   
		noPaiSubstituto->sad = noSubstituto->sae;
		noSubstituto->sae = noRemover->sae;
		noSubstituto->sad = noRemover->sad;
		noPai->sae = noSubstituto;
	}else{
		noPaiSubstituto = no;
		if(no->sae->sad != NULL){
			if(no->sad != NULL)
				noSubstituto = remover(no->sad);
		}else{
			noSubstituto = no->sae->sad;
		}
		noPaiSubstituto->sad = noSubstituto->sae;
		noSubstituto->sae = noRemover->sae;
		noSubstituto->sad = noRemover->sad;
		noPai->sad = noSubstituto;
	}
	free(noRemover);	
	return no;	
}
*/
