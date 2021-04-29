#include <stdio.h>
#include <stdlib.h>

#include "Posfixa.h"
#include "Pilha.h"

/* A função recebe uma fila de objetos em notação infixa e converte (retorna) 
 * a correspondente em notação pós-fixa.
 * Para evitar problemas de vazamento de memória e/ou falha de segmentação, faça 
 * cópia dos objetos. 
 * Lembre-se que a função 'desempilha' (Pilha.h) e 'dequeue' (Fila.h)
 * fazem a desalocação dos objetos(liberaObjeto)
 */

/*é chamada para converter a expressão em notação infixa para notação pós-fixa*/
Fila *infixaParaPosfixa(Fila *infixa) {
    AVISO(Posfixa.c: ainda não completei a função 'infixaParaPosfixa');
    
    return NULL;
}

void imprimePosFixa(Fila *posfixa) {
    Fila *f = copiaFila(posfixa);
    while(!filaVazia(f)) {
        Objeto *obj = front(f);
        imprimeObjeto(obj, POSFIXA);
        dequeue(f);
    }
    printf("\n");
    liberaFila(f);
}