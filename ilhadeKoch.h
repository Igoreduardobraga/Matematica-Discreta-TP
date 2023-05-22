#ifndef ILHA_DE_KOCH
#define ILHA_DE_KOCH

#include <stdio.h>
#include <stdlib.h>

extern FILE *arq_axioma, *estagio1, *estagio2, *estagio3, *estagio4;
extern char caractere;

void escreverAxioma(char axioma[],char regra[]);

void ilhadeKoch(char axioma[], char regra[]){

    escreverAxioma(axioma,regra);

    estagio1 = fopen("estagio1.txt", "w");
    if (arq_axioma == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    while ((caractere = fgetc(arq_axioma)) != EOF) {
        if(caractere=='F'){
            fputs(regra, estagio1);
        }
        else{
            fputc(caractere, estagio1);
        }
    }

    fclose(arq_axioma);
    fclose(estagio1);

    estagio1 = fopen("estagio1.txt", "r");
    estagio2 = fopen("estagio2.txt", "w");

    while ((caractere = fgetc(estagio1)) != EOF) {
        if(caractere=='F'){
            fputs(regra, estagio2);
        }
        else{
            fputc(caractere, estagio2);
        }
    }

    fclose(estagio1);
    fclose(estagio2);
    estagio2 = fopen("estagio2.txt", "r");
    estagio3 = fopen("estagio3.txt", "w");

    while ((caractere = fgetc(estagio2)) != EOF) {
        if(caractere=='F'){
            fputs(regra, estagio3);
        }
        else{
            fputc(caractere, estagio3);
        }
    }

    fclose(estagio2);
    fclose(estagio3);
    estagio3 = fopen("estagio3.txt", "r");
    estagio4 = fopen("estagio4.txt", "w");

    while ((caractere = fgetc(estagio3)) != EOF) {
        if(caractere=='F'){
            fputs(regra, estagio4);
        }
        else{
            fputc(caractere, estagio4);
        }
    }

    fclose(estagio3);
    fclose(estagio4);
}

#endif