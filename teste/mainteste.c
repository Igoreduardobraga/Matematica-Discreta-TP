#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char frase[] = "F+F+F+F";
    char substituicao[] = "F+F-F-FFF+F+F-F";
    char* novaFrase = malloc(sizeof(char) * 1000); // Aloca memória para a nova frase
    int i, j;

    strcpy(novaFrase, frase); // Copia a frase original para a novaFrase

    for (j = 0; j < 10; j++) {
        char* temp = malloc(sizeof(char) * 1000); // Aloca memória para a string temporária
        temp[0] = '\0'; // Inicializa a string temporária como vazia

        for (i = 0; i < strlen(novaFrase); i++) {
            if (novaFrase[i] == 'F') {
                strcat(temp, substituicao); // Concatena a sequência de substituição na string temporária
            } else {
                strncat(temp, &novaFrase[i], 1); // Concatena o caractere original na string temporária
            }
        }

        free(novaFrase); // Libera a memória da iteração anterior
        novaFrase = temp; // Atribui a string temporária à novaFrase
    }
    free(novaFrase); // Libera a memória alocada para novaFrase

    FILE *arquivo;

    arquivo = fopen("teste2.txt", "w");

    fputs(novaFrase,arquivo);

    return 0;
}