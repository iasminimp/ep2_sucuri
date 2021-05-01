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
    Objeto *tmp;
    while(auxiliar) {
        tmp = auxiliar;
        auxiliar = auxiliar->proximo;
        free(tmp);
    }
    free(f);
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o) {
    //AVISO(Fila.c: ainda não completei a função 'enqueue');
    if(f->inicio==NULL){// ou (filaVazia(f))
       f->inicio =o; //ou (f->inicio=f->fim =o;)
       f->fim = o;
       f->n++;
       return;
   }
   f->fim->proximo =o;
   f->fim = f->fim->proximo;
   f->n++;
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f) {
    //AVISO(Fila.c: ainda não completei a função 'dequeue');   
    if (!filaVazia(f)){
        Objeto *tmp = f->inicio;
        f->inicio = f->inicio->proximo;
        free(tmp);
        f->n--;
    }
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f) {
    //AVISO(Fila.c: ainda não completei a função 'front');
    return f->inicio;
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

    Fila *copia_fila =criaFila();
    Objeto *auxiliar = f->inicio;
    while (auxiliar){
        //chama a função enqueue para adicionar
        //e a copiaObjeto para fazer a copia do objeto, nesse caso: auxiliar
        enqueue (copia_fila, copiaObjeto(auxiliar)); 
        auxiliar = auxiliar->proximo;
    }
    return copia_fila;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo) {
    Objeto *elem;
    for((elem = f->inicio); (elem->proximo != NULL); (elem = elem->proximo)){
        imprimeObjeto(elem,tipo);
    }
    imprimeObjeto(elem,tipo);
}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */

/*faz a conversao de string para o numero inteiro, by IMP*/

void converteElementosFila(Fila *f, void (*cb)(Objeto *)) {
    //AVISO(Fila.c: ainda não completei a função 'converteElementosFila');
    /*Objeto *elem = f-> inicio;
    while (elem!= NULL){
        if(f!=NULL){
            cb(elem);//chamando a função: itemParaValor
        }
    }   
    */
    Objeto *elem;
    for((elem = f->inicio); (elem->proximo != NULL); (elem = elem->proximo)){
        cb(elem);
    }
    cb(elem); 
    
}
