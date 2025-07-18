#include <stdio.h>
#define MAX 10000

int contador (int i, int lista_pix[MAX], int tamanho, int quantidade) {

    if (lista_pix[i] == tamanho)
        quantidade++;

    return quantidade;        
}

void quantidades_individuais (int n_saladas, int lista_pix[MAX]) {

    int quantidade_5 = 0, quantidade_7 = 0, quantidade_10 = 0, i;
   
    for (i = 0; i < n_saladas; i++) {
        
    quantidade_5 = contador(i, lista_pix, 5, quantidade_5);
    quantidade_7 = contador(i, lista_pix, 7, quantidade_7);
    quantidade_10 = contador(i, lista_pix, 10, quantidade_10);

    }
    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais\n", quantidade_5, quantidade_7, quantidade_10);
    
}

void comprimento_consecutivo (int n_saladas, int lista_pix[MAX]) {

    int contagem_consecutiva = 0, maior_atual = 1, posicao_maior_atual = 0, i, c;
 
    for (i = 0; i < n_saladas; i++) {
        for (c = i; c < n_saladas; c++) {
            if (lista_pix[i] == lista_pix[c]) 
                contagem_consecutiva++;
            else
                break; 
        }
        if (contagem_consecutiva > maior_atual) {
            maior_atual = contagem_consecutiva;
            posicao_maior_atual = i; 
        }
        contagem_consecutiva = 0; 
        
    }
    printf("James vendeu %d %s de %d %s consecutivamente\n", maior_atual, "saladas", lista_pix[posicao_maior_atual], "reais");
}

int main () {

    int n_saladas, i, lista_pix[MAX];
    scanf("%d", &n_saladas);

    for (i = 0; i < n_saladas; i++)
        scanf("%d", &lista_pix[i]);
    
    quantidades_individuais(n_saladas, lista_pix);
    comprimento_consecutivo(n_saladas, lista_pix);

    return 0;
}









        


                    
                






    
    
