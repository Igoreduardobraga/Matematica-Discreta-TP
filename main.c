#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ilhadeKoch.h"
#include "espacodePeano.h"
#include "novoFractal.h"

FILE *arq_axioma, *estagio1, *arq_final;
char caractere;

// void ilhadeKoch(char axioma[], char regra[]);
// void espacodePeano(char axioma[], char regra1[], char regra2[]);
// void fractalMisto(char axioma[], char regra[]);

void escreverAxioma(char axioma[], char regra[]);
void removerEspacos(char* string);

int main(){

    char *axioma = (char*)malloc((10 + 1) * sizeof(char));
    char *regra = (char*)malloc((40 + 1) * sizeof(char));
    int fractal;

    // strcpy(axioma,"Y");
    // strcpy(regra,"XFYFX+F+YFXFY-F-XFYFX");
    printf("Fractal: ");
    scanf("%d", &fractal);
    printf("Axioma: ");
    scanf("%s", axioma);

    if(fractal==5){
        printf("Regra: ");
        scanf("%s", regra);
        ilhadeKoch(axioma,regra);
    }
    else if(fractal==7){
        char *regra2 = (char*)malloc((40 + 1) * sizeof(char));
        printf("Regra 1: ");
        scanf("%s", regra);
        printf("Regra 2: ");
        scanf("%s", regra2);
        removerEspacos(regra);
        removerEspacos(regra2);
        espacodePeano(axioma,regra, regra2);
        free(regra2);
    }
    else{
        // strcpy(regra2,"-YF+XFX+FY");
        novoFractal("YY","-YF+XFX+FY", "YFXFY-F-XFYFX+F+YFXFY");    //angulo de 120
    }

    free(axioma);
    free(regra);

    return 0;
}

void removerEspacos(char* string) {
    int tamanho = strlen(string);
    int i, j;

    // Percorre a string original
    for (i = 0, j = 0; i < tamanho; i++) {
        // Verifica se o caractere atual não é um espaço
        if (string[i] != ' ') {
            // Copia o caractere para a nova posição na string
            string[j] = string[i];
            j++;
        }
    }

    // Adiciona o caractere nulo para indicar o fim da nova string
    string[j] = '\0';
}

void escreverAxioma(char axioma[],char regra[]){
    arq_axioma = fopen("arq_axioma.txt","w");
    if(arq_axioma == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(0);
    }

    fputs(axioma,arq_axioma);

    fclose(arq_axioma);
    
    arq_axioma = fopen("arq_axioma.txt","r");
    if(arq_axioma == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(0);
    }
}