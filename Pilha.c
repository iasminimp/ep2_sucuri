#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

typedef struct pilha {
    Objeto *inicio;
    int n;
} Pilha;


Pilha *criaPilha(){
    Pilha *p = mallocSafe(sizeof(Pilha));
    p->inicio  = NULL;
    p->n = 0;
    return p;
}

/* Faz a desalocação da pilha */
void liberaPilha(Pilha *p) {
    //AVISO(Pilha.c: ainda não completei a função 'liberaPilha');
    Objeto *auxiliar = p->inicio;
    while(auxiliar) {
        Objeto *tmp = auxiliar->proximo;
        free(auxiliar);
        auxiliar = tmp;
    }
    free(p);
    p = NULL;   
}

/* Insere um novo objeto a pilha */
void empilha(Pilha *p, Objeto *no) { /*push*/
    //AVISO(Pilha.c: ainda não completei a função 'empilha');

    if(!p||!no){
       return;
   } if(!filaVazia(p)){ /*ou (p->fim ==NULL)*/
        p->inicio = p->fim = no;
   }else{
        p->fim->proximo = no;
        p->inicio = no;
   }
    p->n++;
}

/* Remove (apaga) o último elemento da pilha */
void desempilha(Pilha *p){ /*pop*/
    //AVISO(Pilha.c: ainda não completei a função 'desempilha');
    if (pilhaVazia(p)) {
        printf("ERRO: Pilha Vazia!");
    }
    else{
        Objeto *tmp = p->inicio;
        p->inicio = p->inicio->proximo;
        p->n--;//atualiza e em seguida libera, desempilha
        free(tmp);
    }
    
}

/* Retorna o objeto do topo da pilha */
Objeto *topoPilha(Pilha *p){
    //AVISO(Pilha.c: ainda não completei a função 'top');
    if(pilhaVazia(p)) {
        printf("ERRO: Pilha Vazia!");
        return NULL;
    }
    return p->inicio;//acessa o primeiro elemento(que esta no TOPO)

}

/* Verifica se a pilha está vazia */
bool pilhaVazia(Pilha *p){
    return (p->n == 0||p==NULL);
}

/* Retorna o número de elementos na pilha */
int tamanhoPilha(Pilha *p) {
    if (pilhaVazia(p)) return 0;
    return p->n;
}

/* Fução que imprime os elementos da pilha 
 * Essa função pode ajudar a detectar problemas nos objetos da pilha
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimePilha(Pilha *pilha, int tipo) {
    Objeto *elem = pilha->inicio;
    while (elem!= NULL){
        if(pilha!=NULL){
            imprimeObjeto(elem,tipo);//chamando a função: itemParaValor
        }
        printf("%d -> ", elem->valor);
        elem = elem->proximo;
    }
    printf("NULL\n");   
}