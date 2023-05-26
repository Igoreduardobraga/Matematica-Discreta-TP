#ifndef ILHA_DE_KOCH
#define ILHA_DE_KOCH

#include <stdio.h>
#include <stdlib.h>

extern FILE *arq_axioma, *estagio1, *arq_final;
extern char caractere;

void escreverAxioma(char axioma[], char regra[]);

void ilhadeKoch(char axioma[], char regra[]){

    escreverAxioma(axioma, regra);

    estagio1 = fopen("estagio1.txt", "w");
    arq_final = fopen("saidas/ilha_de_Koch.txt", "w");

    fprintf(arq_final, "ILHA DE KOCH\n\nAxioma: F+F+F+F\nÂngulo: 90\nRegra: F+F-F-FFF+F+F-F");
    fprintf(arq_final, "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    fprintf(arq_final, "ESTÁGIO 1: %s", axioma);
    int i;
    for(i = 2 ; i<5 ; i++){
        while ((caractere = fgetc(arq_axioma)) != EOF) {
            if(caractere=='F'){
                fputs(regra, estagio1);
            }
            else{
                fputc(caractere, estagio1);
            }
        }

        if(i%2==0){
            fclose(estagio1);
            estagio1 = fopen("estagio1.txt", "r");
        }
        else if(i%2==1){
            fclose(estagio1);
            estagio1 = fopen("arq_axioma.txt", "r");
        }

        fprintf(arq_final, "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fprintf(arq_final, "ESTÁGIO %d: ", i);
        while ((caractere = fgetc(estagio1)) != EOF) {
            fputc(caractere, arq_final);
        }

        fclose(arq_axioma);
        fclose(estagio1);

        if(i%2==0){
            arq_axioma = fopen("estagio1.txt", "r");
            estagio1 = fopen("arq_axioma.txt", "w");
        }
        else if(i%2==1){
            arq_axioma = fopen("arq_axioma.txt", "r");
            estagio1 = fopen("estagio1.txt", "w");
        }
    }
    fclose(arq_final);
    remove("estagio1.txt");
    remove("arq_axioma.txt");
}

#endif