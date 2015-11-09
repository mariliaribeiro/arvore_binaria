#include "buscar.h"

Node* buscar(Node* no, int valor){
    Node* encontrado;
    encontrado = NULL;
    
    if (no != NULL){
        if(no->valor == valor){
            encontrado =  no;
        }
        else if(no->valor > valor){
            if (no->sae != NULL){
                no = no->sae;
                encontrado = buscar(no, valor);
            }
        }
        else if(no->valor < valor){
            if (no->sad != NULL){
                no = no->sad;
                encontrado = buscar(no, valor);
            }
        }
    }
    return encontrado;
}

void imprimeBusca(Node* no, int valor){
    if(no != NULL){
        printf("Valor: %d --------> Endereço de memória: %p\n", valor, no);
    }else{
        printf("Valor: %d --------> Não encontrado!\n", valor);
    }
}
