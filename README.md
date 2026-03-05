# Gerador de Ticket com-Painel
## Estrutura utilizada: Vetor circular de inteiros
  - Inicio: indica qual índice o vetor começa.

  - Fim: indica o índice que o vetor termina.

  - Tamanho: indica quantos elementos o vetor possui no momento.

## Organização do código e separação de responsabilidades:

  - inicializaHistorico: inicializa a estrutura do vetor circular.

  - gerarTicket: gera um ticket, armazena ele no vetor circular e gerencia a
    circularidade.

  - formataTicket: formata o ticket no padrão correto e armazena o resultado no
    vetor char temporário auxFormatacao.

  - mostraHistorico: percorre o vetor circular, formata o ticket através da
    função formataTicket, armazena no vetor temporário auxFormatacao, imprime o
    resultado e o ciclo continua.

  - main: inicialização do histórico, loop do painel e chamada de gerarTicket na
    escolha 1 e chamada de mostrarHistorico na escolha 2.

Observação 1: o vetor char temporário auxFormatacao foi utilizado para armazenar
a string formatada temporariamente, isso permite que o vetor tickets fique
intocado na hora da formatação e impressão. Dessa forma, podemos mudar a
CAPACIDADE do vetor tickets sem afetar o restante do código.

Observação 2: foi utilizado um TAMANHO_BUFFER maior do que o normal para
permitir mudanças de formatos no futuro. Caso a nova formatação ultrapasse o
TAMANHO_BUFFER, é necessário apenas aumentar o seu valor e alterar o sprintf da
função formataTicket.
