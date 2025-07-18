#include <stdio.h>
#define MAX 300

int busca_palavras (char palavra_buscada[20], int tamanho, 
char matriz_letras[MAX][MAX], int linhas, int colunas) {

    int i,j;
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            if (matriz_letras[i][j] == palavra_buscada[0]) {
                int x=1;
                while (i-x>=0 && matriz_letras[i-x][j] == palavra_buscada[x]) { // linha acima
                    x++;
                    if (x == tamanho) {
                        x=1;
                        return 1;
                    }
                }
                x=1;
                while (i+x<=linhas && matriz_letras[i+x][j] == palavra_buscada[x]) { // linha abaixo
                    x++;
                    if (x == tamanho) {
                        x=1;
                        return 1;
                    }
                }
                x=1;
                while (j-x>=0 && matriz_letras[i][j-x] == palavra_buscada[x]) { // coluna a esquerda
                    x++;
                    if (x == tamanho) {
                        x=1;
                        return 1;
                    }
                }
                x=1;
                while (j+x<=colunas && matriz_letras[i][j+x] == palavra_buscada[x]) { // coluna a direita
                    x++;
                    if (x == tamanho) {
                        x=1;
                        return 1;
                    }
                }
            }
        }

    }
return 0;
}

int main () {

    int lcp[3], i; // lcp é o vetor que armazena os números da primeira entrada (linhas, colunas e palavras)
    for (i=0; i<3; i++)
        scanf("%d ", &lcp[i]);
    
    char matriz_letras[MAX][MAX]; 
    int j, k;
    int linhas = lcp[0], colunas = lcp[1], palavras = lcp[2];
    for (j=0; j<linhas; j++){
        for (k=0; k<colunas; k++)
            scanf(" %c", &matriz_letras[j][k]);
    }
    int m;
    char palavra_buscada[20];
    for (m=0; m<palavras; m++) {
        int tamanho = 0;
        scanf("%s ", palavra_buscada);
        while (palavra_buscada[tamanho]) {
            tamanho++;
        }
        int encontrou = busca_palavras(palavra_buscada, tamanho, 
        matriz_letras, linhas, colunas);
        if (encontrou) {
            printf("A palavra %s está no texto!\n", palavra_buscada);
        } 
        else {
            printf("A palavra %s não está no texto!\n", palavra_buscada);
        }
    }

    return 0;
}
