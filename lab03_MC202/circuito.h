typedef struct { // struct do tipo "circuito" que corresponde aos requisitos do enunciado

   int id_circuito;
   int jogadores;
   int *jogadas;

} circuito;

circuito circuito_leitura (int n_participantes);
