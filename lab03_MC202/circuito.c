#include <stdio.h>
#include <stdlib.h>
#include "circuito.h"

circuito circuito_leitura (int n_participantes) {

    /**
     * A função recebe como argumento o número de participantes para
     * atribuir esse dado ao campo da struct dos circuitos.
     * Lê o número de identificação do circuito e as jogadas, armazenadas no vetor jogadas.
     * Devolve os dados que serão manipulados ao longo de cada partida á função de leitura.
    */
    circuito dados_circuitos;
    dados_circuitos.jogadores = n_participantes;
    int i;
    scanf("%d", &dados_circuitos.id_circuito);
    dados_circuitos.jogadas = malloc((dados_circuitos.jogadores)*sizeof(int));
    for (i=0; i<dados_circuitos.jogadores; i++) {
        scanf("%d", &dados_circuitos.jogadas[i]);
    }
    return dados_circuitos;
}
