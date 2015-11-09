#include "remover.h"

Node* remover(Node* no, int valor){
    Node* noPai;
    Node* noRemover;
    Node* noSubstituto;
    Node* noPaiSubstituto;
    
    
    if (no != NULL){
        if (no->valor == valor){
            noRemover = no;

            if(noPai->valor > valor){
                // verificar se é folha
                if (no->sae == NULL && no->sad == NULL)
                    noPai->sae = NULL;

                //verificar se é sub folha
                else if (no->sae == NULL && no->sad != NULL)
                    noPai->sae = noRemover->sad;
                else if (no->sad == NULL && no->sae != NULL)
                    noPai->sae = noRemover->sae;

                //verificar se tem dois filhos (maior dos menores)
                else if (no->sae != NULL && no->sad != NULL){
                    noPaiSubstituto = no;
                    if(no->sae->sad != NULL){
                        if(no->sad != NULL)
                            noSubstituto = remover(no->sad);
                    }else{
                        noSubstituto = no->sae->sad;
                    }
                    //if (noSubstituto->sae != NULL)                        
                    noPaiSubstituto->sad = noSubstituto->sae;
                    noSubstituto->sae = noRemover->sae;
                    noSubstituto->sad = noRemover->sad;
                    noPai->sae = noSubstituto;
                }   
            }else{
                // verificar se é folha
                if (no->sae == NULL && no->sad == NULL)
                    noPai->sad = NULL;

                //verificar se é sub folha
                else if (no->sae == NULL && no->sad != NULL)
                    noPai->sad = noRemover->sad;
                else if (no->sad == NULL && no->sae != NULL)
                    noPai->sad = noRemover->sae;

                //verificar se tem dois filhos
                else if (no->sae != NULL && no->sad != NULL){
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
            }
            free(noRemover);
            return no;
        }
        else if (no->valor > valor){
            noPai = no;
            return remover(no->sae, valor);
        }
        else{
            noPai = no;
            return remover(no->sad, valor);
        }
    }
    return no;
}
