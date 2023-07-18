#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ilhadeKoch.h"
#include "espacodePeano.h"
#include "novoFractal.h"

FILE *arquivo_1, *arquivo_2, *arq_final;
char caractere;

void escreverAxioma(char axioma[], char regra[]);
void removerEspacos(char* string);

int main(){

    char *axioma = (char*)malloc((10 + 1) * sizeof(char));
    char *regra = (char*)malloc((40 + 1) * sizeof(char));
    int fractal, angulo;

    // strcpy(axioma,"Y");
    // strcpy(regra,"XFYFX+F+YFXFY-F-XFYFX");
    printf("Fractal: ");
    scanf("%d", &fractal);

    if(fractal==5){
        printf("Axioma: ");
        scanf("%s", axioma);
        //printf("Angulo: ");
        //scanf("%d", &angulo);
        printf("Regra: ");
        scanf("%s", regra);
        ilhadeKoch(axioma,regra,angulo);
    }
    else if(fractal==7){
        char *regra2 = (char*)malloc((40 + 1) * sizeof(char));
        printf("Axioma: ");
        scanf("%s", axioma);
        //printf("Angulo: ");
        //scanf("%d", &angulo);
        printf("Regra 1: ");
        scanf("%s", regra);
        printf("Regra 2: ");
        scanf("%s", regra2);
        removerEspacos(regra);
        removerEspacos(regra2);
        espacodePeano(axioma,regra, regra2, angulo);
        free(regra2);
    }
    else{
        // strcpy(regra2,"-YF+XFX+FY");
        novoFractal("X+X+X+X+X+X","-YF+X+FY-", "+XF-X-FX+", 60);    //angulo de 60º
    }

    free(axioma);
    free(regra);

    return 0;
}

// Remove os espacos da string de entrada
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

//Escreve o axioma no arquivo auxiliar 1
void escreverAxioma(char axioma[],char regra[]){
    arquivo_1 = fopen("arq_aux1.txt","w");
    if(arquivo_1 == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(0);
    }

    fputs(axioma,arquivo_1);

    fclose(arquivo_1);
    
    arquivo_1 = fopen("arq_aux1.txt","r");
    if(arquivo_1 == NULL){
        printf("Erro na abertura do arquivo!\n");
        exit(0);
    }
}