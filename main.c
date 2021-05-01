#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilha.h"
#include "Fila.h"
#include "Lexer.h"
#include "Posfixa.h"
#include "Avalia.h"

/* Número máximo de caracteres em uma linha */
#define MAX_TAMANHO 128

void itemParaValor(Objeto *);

int main(int argc, char *argv[]) {

    char linha[MAX_TAMANHO];
    FILE *fEntrada = stdin;
    char *nomeArqScript = NULL;

    /* Opções de execução */
    bool modoInterativo = true;
    bool exibirNotacaoPosFixa = false;

    /* Lê os valores passados como argumento para o programa */
    for(int i = 1; i < argc; ++i) {
        if (!strncmp(argv[i], "-e", 2)) {
            exibirNotacaoPosFixa = true;
        }
        else if (!strncmp(argv[i], "-s", 2)){
            modoInterativo = false;
            nomeArqScript = argv[i + 1];
        }
    }

    if (!modoInterativo) {
        fEntrada = fopen(nomeArqScript, "r");
        if (fEntrada == NULL) {
            printf("Arquivo '%s' não encontrado\n", nomeArqScript);
            exit(1);
        }
    }

    printf("Estrutura de Dados 1 (2020/2) - EP2\n");
    printf("Sucuri - 1.0.0 (%s, %s)\n", __DATE__, __TIME__); // tirei o emoji, por que estava dando erro no compilador :/
    printf("[GCC %s] on %s\n", __VERSION__, SYSTEM);

    if (modoInterativo)
        printf(">>> ");

    /* Analisa cada linha do arquivo ou da entrada padrão */
    while (fgets(linha, MAX_TAMANHO, fEntrada) != NULL) {
        
        //Substitui o '\n' por '\0'
        if (linha[strlen(linha) - 1] == '\n')
            linha[strlen(linha) - 1] = '\0';

        if (!modoInterativo)
            printf("Analisando a expressão: '%s'\n", linha);

        /* TAREFA 1: implemente as função associadas a fila (Fila.c)*/
        /* Para verificar se deu tudo certo, você pode utilizar a função imprimeFila(filaObjetos, ITENS) */
        Fila *filaObjetos = criaFilaObjetos(linha);
        
        if(filaObjetos) {
            /* TAREFA 2: caso não tenha implementado, implemente a função 'converteElementosFila' (Fila.c) */
            /* Para verificar se deu tudo certo, você pode utilizar a função imprimeFila(filaObjetos, VALORES) */
            /* Quanto tudo estiver implementado, descomente a linha abaixo */
            converteElementosFila(filaObjetos, itemParaValor);

            /* TAREFA 3: implemente a função 'infixaParaPosfixa' (Posfixa.c) */
            /* A função converte a expressão em notação infix para notação pos-fixa */
            /* Para verificar se deu tudo certo, passando como argumento a opção '-e' */
            /* Quanto tudo estiver implementado, descomente as linhas abaixo */
            Fila *posfixa = infixaParaPosfixa(filaObjetos);
             if (exibirNotacaoPosFixa) {
                 printf("Expressão pós-fixa: ");
                 imprimePosFixa(posfixa);
            }

            /* TAREFA 4: implemente a função 'avalia' (Avalia.c) */
            /* A função recebe uma fila de objetos em notação pós-fixa e retorna o resultado da expressão */
            /* Quanto tudo estiver implementado, descomente as linhas abaixo */
             Objeto *resultado = avalia(posfixa);
             if (resultado){
                 imprimeValor(resultado);
                 liberaObjeto(resultado);
             }

            liberaFila(posfixa);
            liberaFila(filaObjetos);
        }

        if (modoInterativo)
            printf(">>> ");
    }
    fclose(fEntrada);
    return 0;
}

/* Faz a conversão do campo valor de um objeto para o seu valor correto */
/* Note que no caso de operador, o campo recebe o valor da precedencia do operador */
void itemParaValor(Objeto *obj) {
    char *c = obj->valor.pStr;
    if (obj->categoria >= 0 && obj->categoria <= 6) {
        obj->valor.vInt = getPrecedenciaOperadores(obj->categoria); 
    }
    else if(obj->categoria == FLOAT_STR || obj->categoria == INT_STR){
        if(obj->categoria == FLOAT_STR){
            obj->valor.vFloat = atof(obj->valor.pStr);  
            obj->categoria = FLOAT;
        }
        else {
            obj->valor.vInt = atoi(obj->valor.pStr);
            obj->categoria = INT;
        }
        if(c != NULL)
            free(c);
    }
    else if (obj->categoria == ABRE_PARENTESES || obj->categoria == FECHA_PARENTESES){
        obj->valor.vInt = 0;
    }
}