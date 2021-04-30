#include <stdio.h>
#include <stdlib.h>

#include "Categorias.h"
#include "Objeto.h"

Objeto *criaObjeto() {
    Objeto *obj = mallocSafe(sizeof(Objeto));
    obj->categoria  = INDEFINIDA;
    obj->valor.pStr = NULL;
    obj->proximo    = NULL;
    return obj;
}

/* Retorna uma cópia do objeto */
Objeto *copiaObjeto(Objeto *obj) {
    //AVISO(Objeto.c: ainda não completei a função 'copiaObjeto');
    if (obj == NULL){ //Objeto vazio
        return NULL;
    }
    Objeto *copia_obj = NULL; //copia do objeto, recebe o VALOR do OBJ
    copia_obj = mallocSafe(sizeof(Objeto));
 
    copia_obj->categoria = obj->categoria;
    copia_obj->proximo = obj->proximo;

    //verificacção da categoria
    if (obj->categoria == INT ){ //Inteiro (12)
       copia_obj->valor.vInt =  obj->valor.vInt;
    }else if (obj->categoria == FLOAT){ //Float (11)
        copia_obj->valor.vFloat = obj->valor.vFloat;
    }else{ //string
        copia_obj->valor.pStr = obj->valor.pStr;  
    }    
    return copia_obj;
}

void liberaObjeto(Objeto *o) {
/*   if (o->valor.pStr != NULL)
        free(o->valor.pStr);*/
//        free(o->categoria);
    free(o);   
/*
    while(o){
        Objeto *tmp = o->valor;
        if (o->valor.pStr != NULL){
            free(o->valor.pStr);
            o = tmp;
        }else{
            o = tmp;
        }
    }
    free(o);
    o = NULL;
*/
}

/*Imprime as informação do objeto de acordo com o 'tipo' (Util.h)*/
void imprimeObjeto(Objeto *obj, int tipo) {
    if (tipo == ITEM) {
        printf("  \"%s\" (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
    }
    else if(tipo == VALOR) {
        if (obj->categoria >= 0 && obj->categoria <= 8) {
            printf("  prec=%d (%s)\n", obj->valor.vInt, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria >= 9 && obj->categoria <= 10) {
            printf("  %s (%s)\n", obj->valor.pStr, getNomeCategoria(obj->categoria));
        }
        else if (obj->categoria == FLOAT) {
            /*VALOR FLOAT*/
            printf("  %lf (valor float)\n", obj->valor.vFloat);
        }
        else if (obj->categoria == INT) {
            /*VALOR INT*/
            printf("  %d (valor int)\n", obj->valor.vInt);
        }
    }
    else if (tipo == POSFIXA) {
        AVISO(Objeto.c: ainda não completei a função 'imprimeObjeto');
        //imprimeFila(posfixa, VALOR);
    }
}

void imprimeValor(Objeto * obj) {
    if(obj->categoria == FLOAT)
        printf("%lf\n", obj->valor.vFloat);
    else if(obj->categoria == INT)
        printf("%d\n", obj->valor.vInt);
}