#include <stdio.h>
#define MAX 10000

int contador (int i, int lista_pix[MAX], int tamanho, int quantidade) {

    /**
     * A função recebe como parâmetros o índice acessado no vetor,
     * o vetor, o tamanho do vetor e a variável que controla a quantidade de cada tamanho.
     * Ela serve basicamente para tornar o código menos repetitivo e mais sucinto.
     * O if verifica se há um match entre o tamanho e o elemento do vetor no indice acessado 
     * por uma busca linear.
     * Retona a quantidade de cada para a função quantidades_individuais,
     * que imprimirá a saída desejada com esses dados.
    */
    if (lista_pix[i] == tamanho)
        quantidade++;

    return quantidade;        
}

void quantidades_individuais (int n_saladas, int lista_pix[MAX]) {

    /**
     * A função conta quantas saladas de cada tamanho foram vendidas.
     * n_saladas e lista_pix, lidas na main, são utilizadas como parâmetros.
     * Isso porque a contagem ocorre no conteúdo desse vetor.
     * Ao final, a primeira linha da saída é impressa.
    */
    int quantidade_5 = 0, quantidade_7 = 0, quantidade_10 = 0, i;
   
    for (i = 0; i < n_saladas; i++) {
    
    // Esse for chama a função contador com os argumentos 
    // próprios de cada tamanho até que todo vetor seja percorrido.

    quantidade_5 = contador(i, lista_pix, 5, quantidade_5);
    quantidade_7 = contador(i, lista_pix, 7, quantidade_7);
    quantidade_10 = contador(i, lista_pix, 10, quantidade_10);
    }
    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais\n", quantidade_5, quantidade_7, quantidade_10);
}

void comprimento_consecutivo (int n_saladas, int lista_pix[MAX]) {

    /**
     * A função determina o maior número de saladas vendidas consecutivamente
     * por meio de dois fors aninhados.
     * Em seguida, imprime a segunda linha da saída esperada.
    */

    int contagem_consecutiva = 0, maior_atual = 1, posicao_maior_atual = 0, i, c;
 
    for (i = 0; i < n_saladas; i++) {
        for (c = i; c < n_saladas; c++) {
            if (lista_pix[i] == lista_pix[c]) 
                contagem_consecutiva++;
            else
                break; 
        }
        if (contagem_consecutiva > maior_atual) { // verifica se a contagem consecutiva superou o maior atual
            maior_atual = contagem_consecutiva; 
            posicao_maior_atual = i; 
        }
        contagem_consecutiva = 0; // reseta a variável de controle para o próximo for
        
    }
    printf("James vendeu %d %s de %d %s consecutivamente\n", maior_atual, "saladas", lista_pix[posicao_maior_atual], "reais");
}

int main () {

    /**
     * A função lê o número de saladas vendidas e usa esse número (tamanho) para 
     * preencher o vetor que armazena o pix de cada uma delas.
     * Em seguida, chama as funções quantidades_individuais e comprimento_consecutivo 
     * para desenvolver a lógica.
     * Retorna "0" para mostrar que o programa obteve sucesso.
     */
    int n_saladas, i, lista_pix[MAX]; 
    scanf("%d", &n_saladas);

    for (i = 0; i < n_saladas; i++)
        scanf("%d", &lista_pix[i]);
    
    quantidades_individuais(n_saladas, lista_pix);
    comprimento_consecutivo(n_saladas, lista_pix);

    return 0;
}
