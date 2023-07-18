#ifndef ILHA_DE_KOCH
#define ILHA_DE_KOCH

#include <stdio.h>
#include <stdlib.h>

extern FILE *arquivo_1, *arquivo_2, *arq_final;
extern char caractere;

void escreverAxioma(char axioma[], char regra[]);

void ilhadeKoch(char axioma[], char regra[], int angulo){

    // Escreve o axioma no auxiliar 1
    escreverAxioma(axioma, regra);

    // Abre o arquivo_2 e arq_final em modo escrita
    arquivo_2 = fopen("arq_aux2.txt", "w");
    arq_final = fopen("saidas/ilha_de_Koch.txt", "w");

    // Escreve o axioma, angulo e regra no arquivo de final
    fprintf(arq_final, "ILHA DE KOCH\n\nAxioma: F+F+F+F\nÂngulo: 90\nRegra: F+F-F-FFF+F+F-F");
    fprintf(arq_final, "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    
    // Escreve o estágio 1 do factal ilha de Koch, que corresponde ao seu axioma
    fprintf(arq_final, "ESTÁGIO 1:\n\n%s", axioma);

    int i;
    // Roda o progama 4 vezes. Cada iteração do loop for gera um estágio do fractal
    // Como o estágio 1 corresponde ao axioma no fractal de ilha de Koch, rodamos o for 3 vezes, de i=2 até i=5
    for(i = 2 ; i<5 ; i++){
        while ((caractere = fgetc(arquivo_1)) != EOF) {
            if(caractere=='F'){
                fputs(regra, arquivo_2);
            }
            else{
                fputc(caractere, arquivo_2);
            }
        }

        // Determina qual arquivo TXT deve ser aberto em modo leitura para que seu conteúdo seja escrito no arquivo final
        if(i%2==0){
            fclose(arquivo_2);
            arquivo_2 = fopen("arq_aux2.txt", "r");
        }
        else if(i%2==1){
            fclose(arquivo_2);
            arquivo_2 = fopen("arq_aux1.txt", "r");
        }

        fprintf(arq_final, "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fprintf(arq_final, "ESTÁGIO %d:\n\n", i);

        // Escreve o estágio no arquivo final
        while ((caractere = fgetc(arquivo_2)) != EOF) {
            fputc(caractere, arq_final);
        }

        fclose(arquivo_1);
        fclose(arquivo_2);

        // Determina qual arquivo deve ser aberto em modo leitura e qual deve ser aberto em modo escrita
        if(i%2==0){
            arquivo_1 = fopen("arq_aux2.txt", "r");
            arquivo_2 = fopen("arq_aux1.txt", "w");
        }
        else if(i%2==1){
            arquivo_1 = fopen("arq_aux1.txt", "r");
            arquivo_2 = fopen("arq_aux2.txt", "w");
        }
    }
    // Fecha o arquivo final e remove os arquivos auxiliares
    fclose(arq_final);
    remove("arq_aux2.txt");
    remove("arq_aux1.txt");
}

#endif