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
    
/*
Dica: as funções dequeue e desempilha devem desalocar os objetos 
(chamando a função liberaObjeto) que estavam na fila e pilha,
respectivamente. Para evitar problemas de falha de segmentação, 
faça uma cópia de cada objeto (copiaObjeto) que será inserido na 
pilha e/ou fila de saída da função infixaParaPosfixa.
*/

    //Crie uma pilha vazia para manter os operadores.
    Pilha  *pilha = criaPilha();

    //Crie uma fila/lista vazia para a saída.
    Fila  *fila = criaFila();
    //Variavel que recebe a copia do objeto
    copia_objeto = NULL;

   //Examine cada objeto da fila infixa e se o objeto for:
    while(!filaVazia(infixa)){ /*ou  (filaVazia(infixa) == false*/
        //FLOAT ou INT =>  coloque-o na fila de saída
        elemento = front(infixa);//acessa o elemento    
        if (elemento->categoria == FLOAT || elemento->categoria == INT){
            copia_objeto = copiaObjeto(elemento); //fazer a copia do objeto
            enqueue(fila, copia_objeto);//inserir na fila de saída
            //liberaObjeto(elemento);       
        }else if(elemento->categoria==ABRE_PARENTESES){ //ABRE_PARENTESES=> insira-o na pilha.
            copia_objeto = copiaObjeto(elemento); //fazer copia do objeto
            empilha(pilha, copia_objeto); //insira-o na pilha

        }else if (){ //operador => insira-o na pilha.

        }else if (elemento->categoria==FECHA_PARENTESES){ //FECHA_PARENTESES =>remova os objetos da pilha até que o abre parêntese
            //remover os objetos da pilha até que o abre parêntese
            //correspondente seja removido. Coloque cada operador removido na la de saída
            for(int i=0; i<tamanhoPilha(pilha);i++){
                elemento2 = topoPilha(pilha);//referencia da Pilha
                if(elemento2->categoria==ABRE_PARENTESES){
                    desempilha(pilha);
                    break;
                }else{//coloca na fila de saída (operadores)
                    copia_objeto = copiaObjeto(elemento2);
                    enqueue(fila, copia_objeto);
                    desempilha(pilha);
                }
            }
        }
        dequeue(infixa);

    
    }

    //ABRE_PARENTESES=> insira-o na pilha.

    //FECHA_PARENTESES =>remova os objetos da pilha até que o abre parêntese
    //correspondente seja removido. Coloque cada operador removido na la de saída
    //operador => insira-o na pilha.

    /*Entretanto, remova antes os operadores que estão na pilha que
têm precedência maior ou igual ao operador encontrado e coloque-os na la de saída. Lembre-se
que o campo valor de um objeto que armazena um operador contém o valor da sua precedência
(quanto maior esse valor, maior é a precedência do operador).*/


/*• Quando a expressão tiver sido completamente examinada, verique a pilha. Qualquer operador que
ainda está na pilha deve ser removido e colocado na la de saída.*/


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