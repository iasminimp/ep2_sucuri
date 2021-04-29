#ifndef EP2_OBJETO_H
#define EP2_OBJETO_H

#include "Util.h"
#include "Categorias.h"

//valor = > variavel generica que pode armazenar int ou double ou char
typedef union valor {
    int    vInt;    
    double  vFloat;  
    String  pStr;    
} Valor;

typedef struct objeto {  
 /*
typedef struct no {
    int dado;
    struct no *proximo;
} No;

struct fila {
    int capacidade; //Tamanho do array F
    int ini;        //Posicao do "primeiro" elemento
    int fim;        //Posição livre onde um elemento deve ser inserido
    int n;          //Número de elementos na estrutura
    int *F;         //Array para armazenar os elementos
};

*/
    Categoria categoria;
    Valor valor;
    struct objeto *proximo;
} Objeto;

Objeto *criaObjeto();

void liberaObjeto(Objeto *);

void imprimeValor(Objeto *);

void imprimeObjeto(Objeto *, int);

Objeto *copiaObjeto(Objeto *);

#endif