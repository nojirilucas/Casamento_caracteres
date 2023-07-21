# casamento_caracteres
O objetivo do trabalho foi buscar casamentos de padrões em pedras mágicas usando diferentes algoritmos. Foram implementados e comparados três algoritmos: Força Bruta, KMP e Shift-And.

A estratégia 1 utilizou o algoritmo de Força Bruta para buscar casamentos de padrões.
Essa estratégia percorreu as sequências de caracteres e comparou as strings utilizando dois
índices. Foram realizadas iterações de ordem direta e reversa para verificar os casamentos.
A função Casamento_forca_bruta percorreu a lista de pares de strings e chamou a função
Forca_bruta para cada par, verificando se houve casamento ou não.

A estratégia 2 implementou o algoritmo KMP (Knuth-Morris-Pratt) para a busca de
padrões. Esse algoritmo utilizou o pré-processamento do padrão para construir o array
lps, que foi utilizado durante a busca para otimizar o processo. A função KMP_Busca
realizou a busca direta do padrão no texto, enquanto a função KMP_Reverso realizou a
busca reversa. A função Casamento_KMP percorreu a lista circular de nós e chamou as
funções KMP_Busca e KMP_Reverso para buscar o padrão em cada nó, registrando os
resultados.

A estratégia 3 utilizou o algoritmo Shift-And para buscar casamentos exatos do padrão
no texto. Essa estratégia fez uso de manipulação de bits e de uma tabela de caracteres,
chamada de "máscara", para realizar a busca de forma eficiente. Foram implementadas as
funções ShiftAnd e ShiftAnd_Reverso para buscar casamentos diretos e reversos, respec-
tivamente. A função Casamento_ShiftAnd percorreu a lista encadeada de nós e chamou
as funções ShiftAnd e ShiftAnd_Reverso para buscar o padrão em cada nó.

Exemplo de entrada:

4

ava av

patapon npatapatapatapo

isitfriday ohnoitisnt

haskell lleksah

Exemplo de saída:

S 1

S 10

N

S 7
