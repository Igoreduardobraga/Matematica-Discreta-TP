#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *estagio1, *estagio2;
    char axioma[10] = "F+F+F+F";
    char regra[20] = "F+F-F-FFF+F+F-F", caractere;

    estagio1 = fopen("estagio1.txt","w");
    if(estagio1 == NULL){
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }

    fputs(axioma,estagio1);

    fclose(estagio1);
    
    estagio1 = fopen("estagio1.txt","r");
    if(estagio1 == NULL){
        printf("Erro na abertura do arquivo!\n");
        return 1;
    }

    // scanf("%s",axioma);
    // scanf("%s",regra);

    // fputs(axioma, estagio1);

    // fclose(estagio1);

    // Abrir o arquivo novamente em modo de leitura e escrita
    estagio2 = fopen("estagio2.txt", "w");
    if (estagio1 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int i;
    // long posicao = ftell(estagio1);
    for(i = 0 ; i<2 ; i++){
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
        estagio1 = fopen("estagio1.txt","w");
        estagio2 = fopen("estagio2.txt","r");
        while((caractere = fgetc(estagio2)) != EOF) {
            fputc(caractere, estagio1);
        }
        fclose(estagio1);
        fclose(estagio2);
        estagio1 = fopen("estagio1.txt","r");
        estagio2 = fopen("estagio2.txt","w");
    }

    

    return 0;
}