#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

int main () {

    /**
     * A função lê o número de partidas e usa essa informação para chamar a partida_leitura.
     * Cada chamada da partida_leitura corresponde a uma partida nova.
     * Retorna 0 para verificar que o código está funcionando. 
    */
    int n_partidas,i;
    scanf("%d", &n_partidas);

    for (i=0; i<n_partidas; i++) { // início de cada partida
        partida_leitura (i+1);
    }
    return 0;
}
