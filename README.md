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



<table>
  <tr>
    <td><img src="https://github.com/nojirilucas/casamento_caracteres/assets/103136574/a66e1995-32f9-4498-97a5-8346a64f64e8" style="width: 300px; height: 200px;"></td>
    <td><img src="https://github.com/nojirilucas/casamento_caracteres/assets/103136574/2e010751-3c65-48ec-a989-083c7704e9ad" style="width: 300px; height: 200px;"></td>
  </tr>
  <tr>
    <td><img src="https://github.com/nojirilucas/casamento_caracteres/assets/103136574/71042acb-fe4c-40a3-a31e-ada9230b9158" style="width: 300px; height: 200px;"></td>
    <td><img src="https://github.com/nojirilucas/casamento_caracteres/assets/103136574/cd877f8c-2ab4-45be-aa23-9fc6985a657f" style="width: 300px; height: 200px;"></td>
  </tr>
</table>
