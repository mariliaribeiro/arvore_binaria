#include "ordenar.h"

void preOrdem(Node* no){
    if (no != NULL){
        printf("%d ", no->valor);
        preOrdem(no->sae);
        preOrdem(no->sad);
    }  
}

void posOrdem(Node* no){
    if (no != NULL){
        posOrdem(no->sae);
        posOrdem(no->sad);
        printf("%d ", no->valor); 
    }   
}

void emOrdem(Node* no){
    if (no != NULL){
        emOrdem(no->sae);
        printf("%d ", no->valor);        
        emOrdem(no->sad);
    }  
}
