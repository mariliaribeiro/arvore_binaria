#include "definicoes.h"
#include "mallocArvore.h"
#include "inserir.h"
#include "ordenar.h"
#include "buscar.h"
#include "remover.h"

void popular(Arvore*);
void exibeOrdem(Arvore*);
void exibeBusca(Arvore*);
void exibeRemocao(Arvore*);

int main(){
	Arvore* minhaArvore;
	minhaArvore = criaArvore();
    popular(minhaArvore);
    exibeOrdem(minhaArvore);
    exibeBusca(minhaArvore);
    exibeRemocao(minhaArvore);
    exibeOrdem(minhaArvore);
 
	return 1;
}

void popular(Arvore* arvore){
    arvore->raiz = inserir(arvore->raiz, 20);
    arvore->raiz = inserir(arvore->raiz, 10);
    arvore->raiz = inserir(arvore->raiz, 15);
    arvore->raiz = inserir(arvore->raiz, 13);
    arvore->raiz = inserir(arvore->raiz, 18);
    arvore->raiz = inserir(arvore->raiz, 5);
    arvore->raiz = inserir(arvore->raiz, 2);
    arvore->raiz = inserir(arvore->raiz, 7);
    arvore->raiz = inserir(arvore->raiz, 30);
    arvore->raiz = inserir(arvore->raiz, 25);
    arvore->raiz = inserir(arvore->raiz, 45);
    arvore->raiz = inserir(arvore->raiz, 28);
    arvore->raiz = inserir(arvore->raiz, 27);
    arvore->raiz = inserir(arvore->raiz, 29);
    arvore->raiz = inserir(arvore->raiz, 40);
    arvore->raiz = inserir(arvore->raiz, 60);
    arvore->raiz = inserir(arvore->raiz, 6);
}

void exibeOrdem(Arvore* minhaArvore){
    printf("\n#----- Visualizando estrutura da árvore -----#\n");
    printf("Árvore pré-ordem: ");
    preOrdem(minhaArvore->raiz);
    printf("\nArvore pós-ordem: ");
    posOrdem(minhaArvore->raiz);
    printf("\nÁrvore em ordem: ");
    emOrdem(minhaArvore->raiz);
    printf("\n");
}

void exibeBusca(Arvore* minhaArvore){
    printf("\n#----- Buscando valores da árvore -----#\n");
    imprimeBusca(buscar(minhaArvore->raiz, 10), 10);
    imprimeBusca(buscar(minhaArvore->raiz, 20), 20);
    imprimeBusca(buscar(minhaArvore->raiz, 15), 15);
    imprimeBusca(buscar(minhaArvore->raiz, 31), 31);
}

void exibeRemocao(Arvore* minhaArvore){
    printf("\n#----- Removendo valores da árvore: -----#\n");
    remover(minhaArvore->raiz, 13);
    remover(minhaArvore->raiz, 25);
    remover(minhaArvore->raiz, 10);
}
