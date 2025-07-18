#include "circuito.h"

typedef struct { // struct do tipo "partida" que corresponde aos requisitos do enunciado

    float valor_aluguel;
    int id_partida;
    int n_participantes;
    int n_circuitos;
    int n_alugados;
    circuito *circuito_pacote;

} partida;

partida partida_leitura ();

partida relatorio (int *somatorio_pontuacao, int id_dificil, partida dados_partida);
