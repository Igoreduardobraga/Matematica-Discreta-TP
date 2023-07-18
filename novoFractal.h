#ifndef NOVO_FRACTAL
#define NOVO_FRACTAL

#include <stdio.h>
#include <stdlib.h>

extern FILE *arquivo_1, *arquivo_2, *arq_final;
extern char caractere;

void escreverAxioma(char axioma[],char regra[]);

void novoFractal(char axioma[], char regra1[], char regra2[], int angulo){
    
    // Escreve o axioma no arquivo auxiliar 1
    escreverAxioma(axioma,regra1);

    // Abre o arquivo_2 e arq_final em modo escrita
    arquivo_2 = fopen("arq_aux2.txt", "w");
    arq_final = fopen("saidas/novo_Fractal.txt", "w");

    // Escreve o axioma, angulo e regra no arquivo de final
    fprintf(arq_final, "NOVO FRACTAL\n\nAxioma: X+X+X+X+X+X\nÂngulo: 60\nRegra 1: -YF+X+FY-\nRegra 2: +XF-X-FX+");

    int i;
    // Roda o progama 4 vezes. Cada iteração do loop for gera um estágio do fractal
    for(i = 1 ; i<5 ; i++){
        while ((caractere = fgetc(arquivo_1)) != EOF) {
            // Troca o caractere "X" pela regra do fractal e escreve o conteúdo resultate no outro arquivo auxiliar
            if(caractere=='X'){
                fputs(regra1, arquivo_2);
            }
            // Troca o caractere "Y" pela regra do fractal e escreve o conteúdo resultate no outro arquivo auxiliar
            else if(caractere=='Y'){
                fputs(regra2, arquivo_2);
            }
            else{
                fputc(caractere, arquivo_2);
            }
        }

        // Determina qual arquivo TXT deve ser aberto em modo leitura para que seu conteúdo seja escrito no arquivo final
        if(i%2==1){
            fclose(arquivo_2);
            arquivo_2 = fopen("arq_aux2.txt", "r");
        }
        else if(i%2==0){
            fclose(arquivo_2);
            arquivo_2 = fopen("arq_aux1.txt", "r");
        }

        fprintf(arq_final, "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fprintf(arq_final, "ESTÁGIO %d:\n\n", i);

        // Escreve o estágio no arquivo final sem os símbolos "X" e "Y"
        while((caractere = fgetc(arquivo_2)) != EOF){
            if(caractere!='X' && caractere!='Y'){
                fputc(caractere, arq_final);
            }
        }

        fclose(arquivo_1);
        fclose(arquivo_2);

        // Determina qual arquivo deve ser aberto em modo leitura e qual deve ser aberto em modo escrita
        if(i%2==1){
            arquivo_1 = fopen("arq_aux2.txt", "r");
            arquivo_2 = fopen("arq_aux1.txt", "w");
        }
        else if(i%2==0){
            arquivo_1 = fopen("arq_aux1.txt", "r");
            arquivo_2 = fopen("arq_aux2.txt", "w");
        }
    }
    //Fecha o arquivo final e remove os arquivos auxiliares
    fclose(arq_final);
    remove("arq_aux2.txt");
    remove("arq_aux1.txt");
}

#endif