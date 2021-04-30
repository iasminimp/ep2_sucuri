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
    Objeto *elemento2 = NULL;
    int precedencia =0;

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
        }else{ //operador => insira-o na pilha.
            precedencia = elemento->categoria;
            elemento2 = topoPilha(pilha); //recebe o primeiro elemento
            while (elemento2!=NULL){//percorrendo a pilha ate o final
                //getPrecedenciaOperadores(precedencia) => ATUAL  (elemento->categoria;)
                //getPrecedenciaOperadores(elemento2->categoria) => (sair da pilha ou não)

                if(getPrecedenciaOperadores(precedencia)<=getPrecedenciaOperadores(elemento2->categoria)){
                    copia_objeto = copiaObjeto(elemento2);
                    enqueue(fila, copia_objeto);
                    desempilha(pilha);//verificar: se estar removendo o elemento corretoh
                    //garante que o elemento é o primeiro ou é o elemento CERTO
                }
                //elemento2 = elemento2->proximo;//pra passar para o prximo elemento               
                copia_objeto = copiaObjeto(elemento2);
                empilha(pilha, elemento2);
            }
        }
        dequeue(infixa);//libera e prosegue para o proximo elemento da Fila (infixa)        
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