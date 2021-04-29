#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"


struct fila {
    Objeto *inicio;
    Objeto *fim;
    int n; //quantidade de elementos na fila
};

Fila *criaFila() {
    Fila *f = mallocSafe(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->n = 0;
    return f;
}

/* Faz a desalocação da fila */
void liberaFila(Fila *f) {
    //AVISO(Fila.c: ainda não completei a função 'liberaFila');   
    Objeto *auxiliar = f->inicio; 
    while(auxiliar) {
        Objeto *tmp = auxiliar->proximo;
        free(auxiliar);
        auxiliar = tmp;
    }
    free(f);
    f = NULL;  
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o) {
    //AVISO(Fila.c: ainda não completei a função 'enqueue');
    
   if(!f||!o){
       return;
   } if(!filaVazia(f)){ /*ou (f->fim ==NULL)*/
        f->inicio = f->fim = o;
   }else{
        f->fim->proximo = o;
        f->inicio = o;
   }

    f->n++;
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f) {
    //AVISO(Fila.c: ainda não completei a função 'dequeue');   
   if (!filaVazia(f)) {
        Objeto *tmp = f->inicio;//fazer uma "copia"
        f->inicio = f->inicio->proximo;
        f->n--;
        free(tmp);
    }
    else
        printf("ERRO: Fila vazia!\n");  
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f) {
    //AVISO(Fila.c: ainda não completei a função 'front');
    if(filaVazia(f)){
        printf("ERRO: Fila vazia!");
       return NULL;    
    }else{
        return f->inicio;
    }
}

/* Verifica se a fila está vazia */
bool filaVazia(Fila *f) {
    return (f->n == 0||f==NULL);
}

/* Retorna o número de elementos na fila */
int tamanhoFila(Fila *f) {
    if (filaVazia(f)){
        return 0;
    } else {
        return f->n;
    }
}

/* Retorna uma cópia da fila passada como parâmetro */
Fila *copiaFila(Fila *f) {
    //AVISO(Fila.c: ainda não completei a função 'copiaFila');
    if (filaVazia(f)){
        return NULL;
    }
    Fila *copia_fila =NULL;
    copia_fila = mallocSafe(sizeof(Fila));
        
    copia_fila -> inicio = f->inicio;
    copia_fila -> fim = f->fim;
    copia_fila -> n = f->n;
    
    return copia_fila;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo) {
    Objeto *elem = f->inicio;
    while (elem!= NULL){
        if(f!=NULL){
            imprimeObjeto(elem, tipo);
        }
        printf("%d -> ", elem->valor);
        elem = elem->proximo;
    }
    printf("NULL\n"); 
}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */

/*faz a conversao de string para o numero inteiro, by IMP*/

void converteElementosFila(Fila *f, void (*cb)(Objeto *)) {
    //AVISO(Fila.c: ainda não completei a função 'converteElementosFila');
    Objeto *elem = f-> inicio;
    while (elem!= NULL){
        if(f!=NULL){
            cb(elem);//chamando a função: itemParaValor
        }
    }   
}
