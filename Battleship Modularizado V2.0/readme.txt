Read-Me Referente a parte 1 do projeto de LP1 2018.2

Alunos:Vinicius Ribeiro & Thyall D'Greville.
Professor:Selan Rodrigues.

O projeto -> Nessa primeira parte foi requisitado um gerador de puzzles para o projeto de battleship, o mesmo foi desenvolvido mas infelizmente possuimos 2 restrições nessa versão 2.0, sendo a primeira só aceitar matriz quadraticas nesse instante e a segunda sendo colocando menos barcos que o desejado em puzzles menores que 10x10.

O que pretendemos melhorar -> Utilizar a totalidade dos barcos em matrizes menores que 10x10 e o upgrade para matrizes não quadraticas.

O que percebemos -> Que utilizar array unidimensional embora optimize muito o tempo de execução e memória alocada pelo programa nos colocou algumas restrições sobre o que desejavamos fazer inicialmente.

Para compilar estando na pasta do battleship ->
g++ -Wall -std=c++11 bp.cpp fun_bp.cpp -o bp 

Seguido de

./bp x y z

onde x é a quantidade de puzzles desejada devendo partir de 1 mas não passar de 100.
onde y é a quantidade de linhas desejadas devendo partir de 7 mas não ser maior que 15.
onde z é a quantidade de linhas desejadas devendo partir de 7 mas não ser maior que 15.

Para ver no terminal todos os puzzles criados ->
Basta descomentar a linha 108, 109 e 110 do arquivo fun_bp.cpp 

108 //std::cout << i << std::endl;
109 //Printar(map_battle, dimensoes, colunas);
110 //std::cout << std::endl;

Read-Me Referente a parte 2 do projeto de LP1 2018.2

O projeto -> Nessa segunda parte foi requisitado um meio do usuário jogar o battleship puzzle da parte 1.

O que pretendiamos melhorar -> Mostrar a quantidade de elementos por linha e coluna já que no estado atual praticamente só olhando o gabarito e convertendo o mesmo para coordenadas (digitando o numero do gabarito seguido do caractere A caso seja um jogo acima de 10x10/contando os indices e vendo as coordenadas que batem caso seja um jogo menor que 10x10) o usuario vai conseguir jogar e acertar e tambem criar um break point caso o usuario digite 3 coordenadas sem querer que as mesmas acabam criando um loop infinito.

Considerações finais -> Infelizmente na versão atual ainda não conseguimos atuar com matrizes não quadraticas e o nosso usuário é bastante punido por nossa imcopetência em mostrar a quantidade de elementos por linha e coluna.
