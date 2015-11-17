#include "getPai.h"

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
