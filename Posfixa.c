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
Fila *infixaParaPosfixa(Fila *infixa)
{
    Pilha *pilha = criaPilha();  //Crie uma pilha vazia para manter os operadores.
    Fila *fila = criaFila();     //Crie uma fila/lista vazia para a saída.
    Objeto *copia_objeto = NULL; //Variavel que recebe a copia do objeto
    Objeto *elemento_top_pilha = front(infixa);//elemento que pega o primeiro elemento da fila infixa
    Objeto *elemento = NULL;

    while(elemento_top_pilha) {
        if(elemento_top_pilha->categoria == 9 || elemento_top_pilha->categoria == 10 || elemento_top_pilha->categoria == 11 || elemento_top_pilha->categoria == 12){
            enqueue(fila, copiaObjeto(elemento_top_pilha));
        }else if (elemento_top_pilha->categoria == 7) {
            empilha(pilha, copiaObjeto(elemento_top_pilha));
        }else if (elemento_top_pilha->categoria == 8) {
            copia_objeto = topoPilha(pilha);
            while (topoPilha(pilha) && topoPilha(pilha)->categoria != 7) {
                enqueue(fila, copiaObjeto(topoPilha(pilha)));
                desempilha(pilha);
            }
            if(topoPilha(pilha)){
                desempilha(pilha);
            }
        }else {
            elemento = copiaObjeto(elemento_top_pilha);
            while (topoPilha(pilha) != NULL && topoPilha(pilha)->valor.vInt >= elemento_top_pilha->valor.vInt) {
                if((topoPilha(pilha)->categoria == 0 && elemento_top_pilha->categoria == 6) || (topoPilha(pilha)->categoria == 6 && elemento_top_pilha->categoria == 0)){
                    break;
                }else {
                    enqueue(fila, copiaObjeto(topoPilha(pilha)));
                    desempilha(pilha);
                }
            }
            empilha(pilha, elemento);
        }
        elemento_top_pilha = elemento_top_pilha->proximo;

    } while(topoPilha(pilha)) {
        enqueue(fila, copiaObjeto(topoPilha(pilha)));
        desempilha(pilha);
    }        

    liberaPilha(pilha);

    return fila;
}

void imprimePosFixa(Fila *posfixa){
    Fila *f = copiaFila(posfixa);
    while (!filaVazia(f)){
        Objeto *obj = front(f);
        imprimeObjeto(obj, POSFIXA);
        dequeue(f);
    }
    printf("\n");
    liberaFila(f);
}