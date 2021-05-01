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
    Objeto *tmp = NULL;
    while(auxiliar) {
        tmp = auxiliar;
        auxiliar = auxiliar->proximo;
        free(tmp);
    }
    free(p);
}

/* Insere um novo objeto a pilha */
void empilha(Pilha *p, Objeto *no) { /*push*/
    //AVISO(Pilha.c: ainda não completei a função 'empilha');
    no->proximo = p->inicio;
    p->inicio = no;
    p->n++;
}

/* Remove (apaga) o último elemento da pilha */
void desempilha(Pilha *p){ /*pop*/
    //AVISO(Pilha.c: ainda não completei a função 'desempilha');
    if (!p) {// ou (pilhaVazia(p))
        printf("ERRO: Pilha Vazia!");
        return;
    }
else{
        Objeto *tmp = p->inicio;
        p->inicio = p->inicio->proximo;
        free(tmp);
        p->n--;//atualiza e em seguida libera, desempilha        
    }
    
}

/* Retorna o objeto do topo da pilha */
Objeto *topoPilha(Pilha *p){
    //AVISO(Pilha.c: ainda não completei a função 'top');
    if(!p) { //ou (pilhaVazia(p))
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
    if (pilhaVazia(p)){
        return 0;     
    }else{
        return p->n;    
    }
    
}

/* Fução que imprime os elementos da pilha 
 * Essa função pode ajudar a detectar problemas nos objetos da pilha
 * Para imprimir um objeto, use a função imprimeObjeto.
 */

void imprimePilha(Pilha *pilha, int tipo) {
    /*if (pilha!=NULL){
		printf("Pilha Vazia!\n");
	    return;
    }    */
    Objeto *elem=NULL;
    for((elem=pilha->inicio);(elem->proximo!=NULL);(elem=elem->proximo)){
        imprimeObjeto(elem,tipo);
    }
    imprimeObjeto(elem,tipo);
}