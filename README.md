# Gerador de Ticket com Painel

Sistema que simula um histórico de gerador de tickets para atendimento em hospitais, desenvolvido em C.

## Funcionalidades
- Gera tickets sequencias automaticamente (começando em 1).
- Exibe e mantém apenas os 5 últimos tickets gerados em um painel.

## Estruturas utilizadas 
  - Vetor circular de inteiros.
    
  - Inicio: indica qual índice o vetor começa.

  - Fim: indica o índice que o vetor termina.

  - Tamanho: indica quantos elementos o vetor possui no momento.

## Organização do código e separação de responsabilidades:

  - inicializaHistorico: inicializa a estrutura do vetor circular.

  - gerarTicket: gera um ticket, armazena ele no vetor circular e gerencia a
    circularidade.

  - formataTicketFormato1 e formataTicketFormato2: formatam o ticket no padrão
correto e armazenam o resultado no vetor char temporário auxFormatacao. Cada
função aplica um formato diferentemente.

  - mostraHistorico: percorre o vetor circular, utiliza o ponteiro de função
funcaoFormatacao para chamar a função de formatação escolhida, armazena o ticket
formatado no vetor temporário auxFormatacao, imprime o resultado e o ciclo
continua.

  - main: inicialização do histórico, loop do painel e chamada de gerarTicket na
    escolha 1 e chamada de mostrarHistorico na escolha 2.

**Observação 1:** o vetor char temporário auxFormatacao foi utilizado para armazenar
a string formatada temporariamente, isso permite que o vetor tickets permaneça
inalterado na hora da formatação e impressão. Dessa forma, podemos mudar a
CAPACIDADE do vetor tickets sem afetar o restante do código.

**Observação 2:** O ponteiro funcaoFormatacao permite a troca do formato de
formatação sem alterar a lógica de nenhuma função, possibilitando que novas
funções de formatação possam ser adicionadas no futuro.

**Observação 3:** foi utilizado um TAMANHO_BUFFER maior do que o normal para
permitir mudanças de formatos no futuro. Caso a nova formatação ultrapasse o
TAMANHO_BUFFER, basta aumentar o valor da constante e criar uma nova
função de formatação.
    
  ## Como executar
    ```bash
    gcc Gerador-de-Ticket-com-Painel.c -o Gerador-de-Ticket-com-Painel
    ./Gerador-de-Ticket-com-Painel
