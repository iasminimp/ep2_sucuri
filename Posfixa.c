#include <stdio.h>
#include <stdlib.h>

#include "Posfixa.h"
#include "Pilha.h"


Fila *infixaParaPosfixa(Fila *infixa) {
    //AVISO(Posfixa.c: ainda não completei a função 'infixaParaPosfixa');

    Pilha *pilha = criaPilha();//Crie uma pilha vazia para manter os operadores.
    Fila *fila = criaFila();//Crie uma fila/lista vazia para a saída.
    Objeto *copia_objeto = NULL; //Variavel que recebe a copia do objeto
    Objeto *elemento = NULL;
   // Objeto *elemento2 = NULL;
    
    int elemento_atual = 0;
    Objeto *elemento_top_pilha = NULL;
    //int precedencia =0;

   //Examine cada objeto da fila infixa e se o objeto for:
    while(!filaVazia(infixa)){ //ou  (filaVazia(infixa) == false
        elemento = front(infixa);//acessa o primeiro elemento  lista/fila

        if (elemento->categoria == FLOAT || elemento->categoria == INT){//FLOAT ou INT =>  coloque-o na fila de saída
            copia_objeto = copiaObjeto(elemento); //fazer a copia do objeto
            enqueue(fila, copia_objeto);//inserir na fila de saída
            //liberaObjeto(elemento);       
        }else if(elemento->categoria==ABRE_PARENTESES){ //ABRE_PARENTESES=> insira-o na pilha.
            copia_objeto = copiaObjeto(elemento); //fazer copia do objeto
            empilha(pilha, copia_objeto); //insira-o na pilha

        }else if(elemento->categoria==FECHA_PARENTESES){ //FECHA_PARENTESES =>remova os objetos da pilha até que o abre parêntese
            //remover os objetos da pilha até que o abre parêntese
            //correspondente seja removido. Coloque cada operador removido na la de saída
            for(int i=0; i<tamanhoPilha(pilha);i++){
                elemento_top_pilha = topoPilha(pilha);//referencia da Pilha
                if(elemento_top_pilha->categoria==ABRE_PARENTESES){
                    desempilha(pilha);
                    break;
                }else{//coloca na fila de saída (operadores)
                    copia_objeto = copiaObjeto(elemento_top_pilha);
                    enqueue(fila, copia_objeto);
                    desempilha(pilha);
                }
            }
        }else{ //operador
            elemento_atual = elemento->categoria;
            //elemento_top_pilha = topoPilha(pilha);
/*

+ e - = 1
* e / = 2
^ e _ = 3

*/
            //while (getPrecedenciaOperadores(elemento_atual)>=getPrecedenciaOperadores(elemento_top_pilha->categoria)){
            while (getPrecedenciaOperadores(elemento_atual)<=getPrecedenciaOperadores(elemento_top_pilha->categoria)){
                elemento_top_pilha = topoPilha(pilha);
                copia_objeto = copiaObjeto(elemento_top_pilha);
                enqueue(fila, copia_objeto);
                desempilha(pilha);//pilha fica vazia? o outro operador não é acrescentado?
            }
            copia_objeto = copiaObjeto(elemento_top_pilha);
            empilha(pilha, elemento_top_pilha);
        }

        dequeue(infixa);//libera e prosegue para o proximo elemento da Fila (infixa)    

        // verifique a pilha. Qualquer operador que ainda está na pilha deve ser removido e colocado na fila de saída.
    }
    //return NULL;


    return fila;
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