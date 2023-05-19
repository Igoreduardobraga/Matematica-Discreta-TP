#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arq_axioma, *estagio1, *estagio2, *estagio3, *estagio4;
    char axioma[10] = "F+F+F+F";
    char regra[20] = "F+F-F-FFF+F+F-F";
    char caractere;

    arq_axioma = fopen("arq_axioma.txt","w");
    if(arq_axioma == NULL){
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }

    fputs(axioma,arq_axioma);

    fclose(arq_axioma);
    
    arq_axioma = fopen("arq_axioma.txt","r");
    if(arq_axioma == NULL){
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }

    // scanf("%s",arq_axioma);
    // scanf("%s",regra);

    // fputs(arq_axioma, arq_axioma);

    // fclose(arq_axioma);

    // Abrir o arquivo novamente em modo de leitura e escrita
    estagio1 = fopen("estagio1.txt", "w");
    if (arq_axioma == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int i;
    // long posicao = ftell(axioma);
    // for(i = 0 ; i<2 ; i++){
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

    return 0;
}