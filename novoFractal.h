#ifndef NOVO_FRACTAL
#define NOVO_FRACTAL

#include <stdio.h>
#include <stdlib.h>

extern FILE *arq_axioma, *estagio1, *arq_final;
extern char caractere;

void escreverAxioma(char axioma[],char regra[]);

void novoFractal(char axioma[], char regra1[], char regra2[]){
    
    escreverAxioma(axioma,regra1);

    estagio1 = fopen("estagio1.txt", "w");
    arq_final = fopen("saidas/novo_Fractal.txt", "w");

    fprintf(arq_final, "NOVO FRACTAL\n\n");
    int i;
    for(i = 1 ; i<5 ; i++){
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

        if(i%2==1){
            fclose(estagio1);
            estagio1 = fopen("estagio1.txt", "r");
        }
        else if(i%2==0){
            fclose(estagio1);
            estagio1 = fopen("arq_axioma.txt", "r");
        }

        fprintf(arq_final, "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fprintf(arq_final, "ESTÁGIO %d: ", i);
        while((caractere = fgetc(estagio1)) != EOF){
            if(caractere!='X' && caractere!='Y'){
                fputc(caractere, arq_final);
            }
        }

        fclose(arq_axioma);
        fclose(estagio1);

        if(i%2==1){
            arq_axioma = fopen("estagio1.txt", "r");
            estagio1 = fopen("arq_axioma.txt", "w");
        }
        else if(i%2==0){
            arq_axioma = fopen("arq_axioma.txt", "r");
            estagio1 = fopen("estagio1.txt", "w");
        }
    }
    fclose(arq_final);
    remove("estagio1.txt");
    remove("arq_axioma.txt");
}

#endif