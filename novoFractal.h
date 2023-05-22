#ifndef NOVO_FRACTAL
#define NOVO_FRACTAL

#include <stdio.h>
#include <stdlib.h>

extern FILE *arq_axioma, *estagio1, *estagio2, *estagio3, *estagio4, *final, *teste1, *teste2, *teste3;
extern char caractere;

void escreverAxioma(char axioma[],char regra[]);

void novoFractal(char axioma[], char regra1[], char regra2[]){
    
    escreverAxioma(axioma,regra1);

    estagio1 = fopen("estagio1.txt", "w");
    if (arq_axioma == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    //****************************************************************
    while ((caractere = fgetc(arq_axioma)) != EOF) {
        if(caractere=='X'){
            fputs(regra1, estagio1);
        }
        else if(caractere=='Y'){
            fputs(regra2, estagio1);
        }
        else{
            fputc(caractere, estagio1);
        }
    }
    
    fclose(estagio1);
    estagio1 = fopen("estagio1.txt", "r");
    teste1 = fopen("teste1.txt", "w");

    while((caractere = fgetc(estagio1)) != EOF){
        if(caractere!='X' && caractere!='Y'){
            fputc(caractere, teste1);
        }
    }

    fclose(teste1);
    fclose(arq_axioma);
    fclose(estagio1);
    estagio1 = fopen("estagio1.txt", "r");
    estagio2 = fopen("estagio2.txt", "w");

    //****************************************************************
    while ((caractere = fgetc(estagio1)) != EOF) {
        if(caractere=='X'){
            fputs(regra1, estagio2);
        }
        else if(caractere=='Y'){
            fputs(regra2, estagio2);
        }
        else{
            fputc(caractere, estagio2);
        }
    }

    fclose(estagio2);
    estagio2 = fopen("estagio2.txt", "r");
    teste2 = fopen("teste2.txt", "w");

    while((caractere = fgetc(estagio2)) != EOF){
        if(caractere!='X' && caractere!='Y'){
            fputc(caractere, teste2);
        }
    }

    fclose(teste2);
    fclose(estagio1);
    fclose(estagio2);
    estagio2 = fopen("estagio2.txt", "r");
    estagio3 = fopen("estagio3.txt", "w");

    //****************************************************************
    while ((caractere = fgetc(estagio2)) != EOF) {
        if(caractere=='X'){
            fputs(regra1, estagio3);
        }
        else if(caractere=='Y'){
            fputs(regra2, estagio3);
        }
        else{
            fputc(caractere, estagio3);
        }
    }

    fclose(estagio3);
    estagio3 = fopen("estagio3.txt", "r");
    teste3 = fopen("teste3.txt", "w");

    while((caractere = fgetc(estagio3)) != EOF){
        if(caractere!='X' && caractere!='Y'){
            fputc(caractere, teste3);
        }
    }

    fclose(teste3);
    fclose(estagio2);
    fclose(estagio3);
    estagio3 = fopen("estagio3.txt", "r");
    estagio4 = fopen("estagio4.txt", "w");

    //****************************************************************
    while ((caractere = fgetc(estagio3)) != EOF) {
        if(caractere=='X'){
            fputs(regra1, estagio4);
        }
        else if(caractere=='Y'){
            fputs(regra2, estagio4);
        }
        else{
            fputc(caractere, estagio4);
        }
    }

    fclose(estagio4);
    final = fopen("estagiofinal.txt", "w");
    estagio4 = fopen("estagio4.txt", "r");

    while((caractere = fgetc(estagio4)) != EOF){
        if(caractere!='X' && caractere!='Y'){
            fputc(caractere, final);
        }
    }

    fclose(final);
    fclose(estagio3);
    fclose(estagio4);
    remove("estagio1.txt");
    remove("estagio2.txt");
    remove("estagio3.txt");
    remove("estagio4.txt");
}

#endif