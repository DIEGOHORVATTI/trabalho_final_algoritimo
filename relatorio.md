Percorrer cada Linha possível da matriz e procurar ocorrências sequidas de bases nitrogenadas.
<br />
<img src="./src/img/linhasColunas.png" width="100%" />
<br/>
Para responder à questão em si, eu desmembrei a matriz em string´s, e com 4 processos de verificação distintos['horizontal', 'vertical', 'Diagonal Principal', 'Diagonal Segundaria'], para percorrê-las verificando se existe uma sub string com a função "strstr(stringPercorrido, ocorrência)" se sim, retorna 1, Com está lógica eu verifico os vetores horizontais e caso ainda retorne 0  vai para a verificação vertical depois as diagonais principais e por último as diagonais segundarias. 

<br/>Horizontal<br />
<img src="./src/img/horizontal.png" width="100%" />
<br/>

<br/>Vertical<br />
<img src="./src/img/vertical.png" width="100%" />
<br/>

<br/>Diagonal principal<br />
<img src="./src/img/diagonalPrincipal.png" width="100%" />
<br/>

<br/>Diagonal Segundaria<br />
<img src="./src/img/diagonalSeundaria.png" width="100%" />
<hr/><br/>

Na parte estrutural do programa eu usei a arquitetura de projeto MVC, Com testes unitários TDD
<br />
<img src="./src/img/mvc.png" width="30%" />
<br/><hr/><br/>

Para fazer a configuração geral usei o consumo de API para leitura se arquivos de configuração ".conf" https://github.com/benhoyt/inih
<br />
<img src="./src/img/config.png" width="70%" />
<br/><hr/><br/>

Na compilação fiz de forma síncrona assim os arquivos de baixo receberam com perfeição os métodos e procedimentos dos arquivos de cima
<br />
<img src="./src/img/compilacao.png" width="70%" />
<br/><hr/><br/>

Já no front-end após eu 'penar' um pouquinho consegui fazer um front end até que agradável
<br />
<img src="./src/img/debug.png" width="100%" />
<br/>

<hr/>Debug das matrizes da sala de aula<hr/>
<br />
<img src="./src/img/debugSala.gif" width="100%" />
<br/>

<hr/>NOTAS DE PROGRAMAÇÃO<hr/>
Algo muito importante no trabalho é  a função do tipo de dado struct contido no "model" com ele foi bem legal ficar alterando os dados ao decorrer do programa.<br/> 
Outra coisa interessante é a possibilidade de o programa criar matrizes dinâmicas e randômicas caso for especificado no arquivo de configuração "ALEATORIO" como 'true' com isso ele criará uma matriz de DNA aleatória com as linhas e colunas do arquivo de configuração.
<br />
<img src="./src/img/exemplo.gif" width="100%" />
<br/>

Como no exemplo acima na verdade a verificão das diagonais principais e segundarias ele é repartido pela metade ['Diagonal principal Superior', 'Diagonal principal inferior'] assim na verdade temos 6 verificações e não 4 porem como está na mesma função englobando as duas é como se fosse uma.
<br/>
Outra coisa importante destacar é que só é passado a string para verificação se a mesma atender a alguns requisitos
* Ter o tamanho de caracteres igual ou maior que o setado em OCORRENCIAS no arquivo de configuração
* Não ter caracteres que não fazem parte das bases nitrogenadas['A', 'T', 'C', 'G']
* quando a primeira ocorrência for achada na ordem ['Horizontal', 'Vertical', 'Diagonal Principal', 'Diagonal segundaria'] o programa encerrará 
* caso não encontre nem uma ocorrência em, nem uma das verificações ele retornará humano
<br />
  <img src="./src/img/failLetra.gif" width="100%" />
<br/>