#ifndef __remover_h
#define __remover_h

#include "definicoes.h"

Node* remover(Arvore*, Node*, int);
Node* removerFolha(Arvore*, Node*, Node*, int);
Node* removerSubFolha(Arvore*, Node*, Node*, int);
Node* removerPaiDoisFilhos(Arvore*, Node*, Node*, int);
Node* getMaiorMenores(Node*);
Node* getNoSubstituto(Node*);

#endif
