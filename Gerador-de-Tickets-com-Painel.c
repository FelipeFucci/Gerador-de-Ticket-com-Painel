/*
Estrutura utilizada: Vetor circular de inteiros
  - Inicio: indica qual índice o vetor começa.

  - Fim: indica o índice que o vetor termina.

  - Tamanho: indica quantos elementos o vetor possui no momento.

Organização do código e separação de responsabilidades:

  - inicializaHistorico: inicializa a estrutura do vetor circular.

  - adicionarTicket: recebe o valor do ticket, armazena ele no vetor circular e gerencia a
    circularidade.

  - formataTicketFormato1 e formataTicketFormato2: formatam o ticket no padrão
correto e armazenam o resultado no vetor char temporário auxFormatacao. Cada
função aplica um formato diferentemente.

  - mostraHistorico: percorre o vetor circular, utiliza o ponteiro de função
funcaoFormatacao para chamar a função de formatação escolhida, armazena o ticket
formatado no vetor temporário auxFormatacao, imprime o resultado e o ciclo
continua.

  - main: inicialização do histórico, loop do painel e chamada de adicionarTicket na
    escolha 1 e chamada de mostrarHistorico na escolha 2.

Observação 1: o vetor char temporário auxFormatacao foi utilizado para armazenar
a string formatada temporariamente, isso permite que o vetor tickets permaneça
inalterado na hora da formatação e impressão. Dessa forma, podemos mudar a
CAPACIDADE do vetor tickets sem afetar o restante do código.

Observação 2: O ponteiro funcaoFormatacao permite a troca do formato de
formatação sem alterar a lógica de nenhuma função, possibilitando que novas
funções de formatação possam ser adicionadas no futuro.

Observação 3: foi utilizado um TAMANHO_BUFFER maior do que o normal para
permitir mudanças de formatos no futuro. Caso a nova formatação ultrapasse o
TAMANHO_BUFFER, basta aumentar o valor da constante e criar uma nova
função de formatação.

*/

#include <stdio.h>

#define CAPACIDADE 5
#define TAMANHO_BUFFER 32

typedef struct {
  int tickets[CAPACIDADE];
  int inicio;
  int fim;
  int tamanho;

} HistoricoTickets;

void inicializaHistorico(HistoricoTickets *historico) {
  historico->inicio = 0;
  historico->fim = 0;
  historico->tamanho = 0;
}

void gerarTicket(HistoricoTickets *historico, int novoTicket) {
  historico->tickets[historico->fim] = novoTicket;
  historico->fim = (historico->fim + 1) % CAPACIDADE;

  if (historico->tamanho < CAPACIDADE) {
    historico->tamanho++;
  } else {
    historico->inicio = (historico->inicio + 1) % CAPACIDADE;
  }
}

void formataTicketFormato1(int numeroTicket, char *auxFormatacao) {
  sprintf(auxFormatacao, "Q-%04d", numeroTicket);
}

void formataTicketFormato2(int numeroTicket, char *auxFormatacao) {
  sprintf(auxFormatacao, "Q-%d", numeroTicket);
}

void mostraHistorico(const HistoricoTickets *historico,
                     void (*funcaoFormatacao)(int numeroTicket,
                                              char *auxFormatacao)) {
  if (historico->tamanho == 0) {
    printf("Histórico de tickets vazio\n\n");
    return;
  }

  char auxFormatacao[TAMANHO_BUFFER];
  int posicao = historico->inicio;

  for (int i = 0; i < historico->tamanho; i++) {
    funcaoFormatacao(historico->tickets[posicao], auxFormatacao);
    printf("%s | ", auxFormatacao);
    posicao = (posicao + 1) % CAPACIDADE;
  }
  printf("\n\n");
}

int main() {

  HistoricoTickets historico;
  int opcao;
  int resultado;
  int valorTicket = 1;

  inicializaHistorico(&historico);

  do {
    printf("\n----Sistema de Tickets----\n");
    printf("Gerar novo ticket (digite 1)\n");
    printf("Mostrar painel (digite 2)\n");
    printf("Sair (digite 3)\n");
    printf("\n\nEscolha: ");

    resultado = scanf("%d", &opcao);
    if (resultado != 1) {
      while (getchar() != '\n')
        ;
      opcao = 0;
    }

    printf("\n\n");

    switch (opcao) {

    case 1:
      gerarTicket(&historico, valorTicket);
      printf("Ticket gerado!\n\n");
      valorTicket++;
      break;

    case 2:
      mostraHistorico(&historico, formataTicketFormato1);
      break;

    case 3:
      printf("Saindo...\n\n");
      break;

    default:
      printf("Opção inválida!\n\n");
      break;
    }
  } while (opcao != 3);

  return 0;
}
