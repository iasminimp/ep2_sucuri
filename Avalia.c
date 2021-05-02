#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"


/* Recebe uma fila de objetos em notação pós-fixa, avalia e retorna o resultado da expressação */
Objeto *avalia(Fila *posFixa) {
    //AVISO(Avalia.c: ainda não completei a função 'avalia');
    Pilha *pilha = criaPilha();
    Objeto *fila_auxiliar= front(posFixa);
    Objeto *tmp;
    Objeto *auxiliar_1;
    Objeto *auxiliar_2;
    Objeto *out;
    while(fila_auxiliar!= NULL){
        int num = fila_auxiliar->categoria;
        switch(num){
 /*----------------------------------------------------------------------*/ 
            case 11:
            case 12:
                empilha(pilha, copiaObjeto(fila_auxiliar));
                break;
/*----------------------------------------------------------------------*/                
            case 6:
            auxiliar_1 = copiaObjeto(topoPilha(pilha));
            desempilha(pilha); 
            tmp = criaObjeto();

            if(auxiliar_1->categoria == 12){
                tmp->valor.vInt = auxiliar_1->valor.vInt * (-1); 
                tmp->categoria = 12;
            }
            else if(auxiliar_1->categoria == 11){
                tmp->valor.vFloat = auxiliar_1->valor.vFloat * (-1); 
                tmp->categoria = 11;
            }
            empilha(pilha,tmp);
            liberaObjeto(auxiliar_1);
            break;
/*----------------------------------------------------------------------*/ 
            case 5:
                auxiliar_1 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                auxiliar_2 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                tmp = criaObjeto();

                if(auxiliar_1->categoria != 11 && auxiliar_2->categoria != 11){
                    tmp->valor.vInt = auxiliar_2->valor.vInt - auxiliar_1->valor.vInt;
                    tmp->categoria = 12;
                } else{
                    if (auxiliar_1->categoria == 12){
                        tmp->valor.vFloat = auxiliar_2->valor.vFloat - auxiliar_1->valor.vInt;
                    }else if(auxiliar_2->categoria == 12){
                        tmp->valor.vFloat = auxiliar_2->valor.vInt - auxiliar_1->valor.vFloat;
                    }else {
                        tmp->valor.vFloat = auxiliar_2->valor.vFloat - auxiliar_1->valor.vFloat;
                    }
                    tmp->categoria = 11;
                }
                empilha(pilha, tmp);
                liberaObjeto(auxiliar_1);
                liberaObjeto(auxiliar_2);
            break; 
/*----------------------------------------------------------------------*/ 
            case 4:
            auxiliar_1 = copiaObjeto(topoPilha(pilha));
            desempilha(pilha);
            auxiliar_2 = copiaObjeto(topoPilha(pilha));
            desempilha(pilha);
            tmp = criaObjeto();

            if(auxiliar_1->categoria != 11 && auxiliar_2->categoria != 11){
                tmp->valor.vInt = auxiliar_2->valor.vInt + auxiliar_1->valor.vInt;
                tmp->categoria = 12;
            } else{
                if (auxiliar_1->categoria == 12){
                    tmp->valor.vFloat = auxiliar_2->valor.vFloat + auxiliar_1->valor.vInt;
                }else if(auxiliar_2->categoria == 12){
                    tmp->valor.vFloat = auxiliar_2->valor.vInt + auxiliar_1->valor.vFloat;
                }else {
                    tmp->valor.vFloat = auxiliar_2->valor.vFloat + auxiliar_1->valor.vFloat;
                }
                tmp->categoria = 11;         
            }
            empilha(pilha,tmp);
            liberaObjeto(auxiliar_1);
            liberaObjeto(auxiliar_2);
            break;
/*----------------------------------------------------------------------*/          
            case 3:
                auxiliar_1 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                auxiliar_2 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                tmp = criaObjeto();

                if(auxiliar_1->categoria != 11 && auxiliar_2->categoria != 11){
                    tmp->valor.vInt= auxiliar_2->valor.vInt / auxiliar_1->valor.vInt;
                    tmp->categoria = 12;
                } else{
                    if (auxiliar_1->categoria == 12){
                        tmp->valor.vFloat = auxiliar_2->valor.vFloat / auxiliar_1->valor.vInt;
                    }else if(auxiliar_2->categoria == 12){
                        tmp->valor.vFloat = auxiliar_2->valor.vInt / auxiliar_1->valor.vFloat;
                    }else {
                        tmp->valor.vFloat = auxiliar_2->valor.vFloat / auxiliar_1->valor.vFloat;
                    }
                    tmp->categoria = 11;
                }
                empilha(pilha, tmp);
                liberaObjeto(auxiliar_1);
                liberaObjeto(auxiliar_2);
            break;           
/*----------------------------------------------------------------------*/ 
            case 2:
                auxiliar_1 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                auxiliar_2 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                tmp = criaObjeto();

                if(auxiliar_1->categoria != 11 && auxiliar_2->categoria != 11){
                    tmp->valor.vInt = auxiliar_2->valor.vInt * auxiliar_1->valor.vInt;
                    tmp->categoria = 12;
                } else{
                    if (auxiliar_1->categoria == 12){
                        tmp->valor.vFloat = auxiliar_2->valor.vFloat * auxiliar_1->valor.vInt;
                    }else if(auxiliar_2->categoria == 12){
                        tmp->valor.vFloat = auxiliar_2->valor.vInt * auxiliar_1->valor.vFloat;
                    }else {
                        tmp->valor.vFloat = auxiliar_2->valor.vFloat * auxiliar_1->valor.vFloat;
                    }
                    tmp->categoria = 11;
                }
                empilha(pilha, tmp);
                liberaObjeto(auxiliar_1);
                liberaObjeto(auxiliar_2);
            break;
/*----------------------------------------------------------------------*/            
            case 1:
                auxiliar_1 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                auxiliar_2 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                tmp = criaObjeto();

                if(auxiliar_1->categoria != 11 && auxiliar_2->categoria != 11){
                    tmp->valor.vInt = auxiliar_2->valor.vInt % auxiliar_1->valor.vInt;
                    tmp->categoria = 12;
                } else{
                    if (auxiliar_1->categoria == 12){
                        tmp->valor.vFloat = fmod(auxiliar_2->valor.vFloat , (float) auxiliar_1->valor.vInt);
                    }else if(auxiliar_2->categoria == 12){
                        tmp->valor.vFloat = fmod( (float) auxiliar_2->valor.vInt , auxiliar_1->valor.vFloat);
                    }else {
                        tmp->valor.vFloat = fmod(auxiliar_2->valor.vFloat , auxiliar_1->valor.vFloat);
                    }
                    tmp->categoria = 11;
                }

                empilha(pilha, tmp);
                liberaObjeto(auxiliar_1);
                liberaObjeto(auxiliar_2);
            break;
/*----------------------------------------------------------------------*/             
            case 0:
                auxiliar_1 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                auxiliar_2 = copiaObjeto(topoPilha(pilha));
                desempilha(pilha);
                tmp = criaObjeto();

                if(auxiliar_1->categoria != 11 && auxiliar_2->categoria != 11){
                    tmp->valor.vInt = pow(auxiliar_2->valor.vInt , auxiliar_1->valor.vInt);
                    tmp->categoria = 12;
                } else{
                    if (auxiliar_1->categoria == 12){
                        tmp->valor.vFloat = pow(auxiliar_2->valor.vFloat , auxiliar_1->valor.vInt);
                    }else if(auxiliar_2->categoria == 12){
                        tmp->valor.vFloat = pow(auxiliar_2->valor.vInt , auxiliar_1->valor.vFloat);
                    }else {
                        tmp->valor.vFloat = pow(auxiliar_2->valor.vFloat , auxiliar_1->valor.vFloat);
                    }
                    tmp->categoria = 11;
                }
                empilha(pilha, tmp);
                liberaObjeto(auxiliar_1);
                liberaObjeto(auxiliar_2);
            break;
        }
        
        fila_auxiliar= fila_auxiliar->proximo;
    }
/*---verificação da pilha ---*/ 
    out = copiaObjeto(topoPilha(pilha));
    liberaPilha(pilha);
    
    return out;

}

