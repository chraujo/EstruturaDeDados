#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

partida partida_leitura (int id_partida) {

    /**
     * A função lê os dados da partida e utiliza eles para desenvolver a lógica necessária.
     * Após a leitura, ela chama a função que lê os circuitos e utiliza esses dados para 
     * calcular os dados requeridos pela saída.
     * Finalmente, chama a função de impressão dos dados obtidos (relatorio).
     * Recebe como argumento o id_partida, que é iniciado como i+1.
     * Retorna dados_partida.
    */
    int i,j,k,m;
    partida dados_partida;
    dados_partida.id_partida = id_partida;

    scanf("%d", &dados_partida.n_participantes);
    scanf("%d", &dados_partida.n_circuitos);
    scanf("%d", &dados_partida.n_alugados);

    int c = dados_partida.n_circuitos, e = dados_partida.n_alugados;
    dados_partida.valor_aluguel = (10*c + 17.50*e);
    
    int *soma_pontuacoes; // vetor que armazena a soma das pontuações de cada jogador
    soma_pontuacoes = malloc(dados_partida.n_participantes*sizeof(int));
    for (k=0; k<dados_partida.n_participantes; k++) {
        soma_pontuacoes[k] = 0;
    }

    dados_partida.circuito_pacote = malloc((dados_partida.n_participantes+2)*sizeof(circuito));
    int calculo = 0, mais_dificil = 0, id_dificil = 0;
    for (i=0; i<c; i++) { // início de cada circuito
        calculo = 0;
        dados_partida.circuito_pacote[i] = circuito_leitura (dados_partida.n_participantes);
        for (j=0; j<dados_partida.n_participantes; j++) {
            calculo = (calculo + dados_partida.circuito_pacote[i].jogadas[j]);
            // calculo é uma variável de controle, que só substitui o mais_dificil quando o supera
        }
        if (calculo > mais_dificil) {
            mais_dificil = calculo;
            id_dificil = dados_partida.circuito_pacote[i].id_circuito;
        }
        for (m=0; m<dados_partida.n_participantes; m++) {
            soma_pontuacoes[m] = (soma_pontuacoes[m] + 
            dados_partida.circuito_pacote[i].jogadas[m]);
        }  
    }
    relatorio (soma_pontuacoes, id_dificil, dados_partida);
    free(soma_pontuacoes); 
    free(dados_partida.circuito_pacote);
    return dados_partida;
}

partida relatorio (int *soma_pontuacoes, int id_dificil, partida dados_partida) {

    /**
     * A função imprime o relatório de cada partida. 
     * Recebe como argumentos o vetor soma_pontuacoes, o id do circuito mais difícil 
     * e os dados de partida.
     * Retorna dados_partida.
    */
    int i;
    printf("Partida %d\n", dados_partida.id_partida);
    printf("Num. de Jogadores: %d - Num. de Circuitos: %d - Num. de Equipamentos: %d\n",
           dados_partida.n_participantes, dados_partida.n_circuitos, dados_partida.n_alugados);
    printf("Valor do Aluguel: R$ %.2f\n", dados_partida.valor_aluguel);
    for (i = 0; i < dados_partida.n_participantes; i++) {
        printf("Jogador %d: %d\n", i + 1, soma_pontuacoes[i]);
    }
    printf("Circuito mais dificil: %d\n", id_dificil);
    printf("##########\n");

    return dados_partida;
}
