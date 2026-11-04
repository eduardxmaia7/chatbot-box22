#include <stdio.h>

/* Descarta o que sobrou no teclado (evita loop infinito com letras) */
void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void) {
    int opcao = -1;          /* guarda a escolha do usuario */
    int leitura;             /* guarda o retorno do scanf */
    int total_consultas = 0; /* perguntas do FAQ respondidas (opcões 1 a 4) */
    int total_atendente = 0; /* vezes que o contato humano foi exibido */
    int total_invalidas = 0; /* entradas inválidas digitadas */

    /* Introducao */
    printf("==========================================\n");
    printf("     ASSISTENTE VIRTUAL - OFICINA BOX22\n");
    printf("==========================================\n");
    printf("Este sistema responde as dúvidas mais frequentes\n");
    printf("(FAQ) da oficina e, se necessário, indica o contato\n");
    printf("do atendimento humano.\n");
    printf("\nOlá! Seja bem-vindo(a), é um prazer ajudar você!\n");

    /* Laco do menu: repete ate o usuario digitar 0 */
    do {
        printf("\n------------- COMO POSSO AJUDAR? -------------\n");
        printf("1 - Horário de funcionamento\n");
        printf("2 - Formas de pagamento\n");
        printf("3 - Prazo de entrega\n");
        printf("4 - Trocas e devoluções\n");
        printf("5 - Falar com um atendente\n");
        printf("0 - Encerrar atendimento\n");
        printf("----------------------------------------------\n");
        printf("Digite o número da opcão: ");

        leitura = scanf("%d", &opcao);

        /* Tratamento de entrada inválida (letra ou simbolo) */
        if (leitura == EOF) {
            opcao = 0;              /* entrada encerrada: sai com seguranca */
        } else if (leitura != 1) {
            limpar_buffer();        /* descarta o que foi digitado */
            opcao = -1;             /* força a opcão a cair no default */
        } else {
            limpar_buffer();
        }

        /* Processamento da opção escolhida */
        switch (opcao) {
            case 1:
                printf("\n[HORÁRIO DE FUNCIONAMENTO]\n");
                printf("Segunda a sexta: 8h as 18h\n");
                printf("Sábado: 8h as 12h\n");
                printf("Domingos e feriados: fechado\n");
                total_consultas++;
                break;
            case 2:
                printf("\n[FORMAS DE PAGAMENTO]\n");
                printf("Aceitamos PIX, boleto, cartão de debito e\n");
                printf("cartão de crédito em ate 12x sem juros.\n");
                total_consultas++;
                break;
            case 3:
                printf("\n[PRAZO DE ENTREGA]\n");
                printf("Capital: 1 a 3 dias úteis\n");
                printf("Interior: 5 a 10 dias úteis\n");
                total_consultas++;
                break;
            case 4:
                printf("\n[TROCAS E DEVOLUCÕES]\n");
                printf("Arrependimento em compras online: até 7 dias\n");
                printf("corridos apos o recebimento.\n");
                printf("Defeito: até 30 dias, com nota fiscal.\n");
                total_consultas++;
                break;
            case 5:
                /* BONUS: redireciona para o atendimento humano */
                printf("\n[ATENDIMENTO HUMANO]\n");
                printf("Para dúvidas mais especificas, fale com a nossa equipe:\n");
                printf("Telefone/WhatsApp: (38) 4002-8922\n");
                printf("E-mail: atendimento@oficinabox22.com.br\n");
                printf("Atendimento: seg a sex, 9h as 18h\n");
                total_atendente++;
                break;
            case 0:
                /* a despedida é exibida após o laço */
                break;
            default:
                printf("\nOpcão inválida! Digite um número de 0 a 5.\n");
                printf("Se sua dúvida for outra, escolha 5 para falar\n");
                printf("com um atendente.\n");
                total_invalidas++;
        }
    } while (opcao != 0);

    /* Encerramento cortes com resumo do atendimento */
    printf("\n==========================================\n");
    printf("          RESUMO DO ATENDIMENTO\n");
    printf("==========================================\n");
    printf("Dúvidas respondidas: %d\n", total_consultas);
    printf("Contatos com atendente exibidos: %d\n", total_atendente);
    printf("Entradas invalidas: %d\n", total_invalidas);
    printf("------------------------------------------\n");
    printf("Atendimento encerrado. Obrigado pelo contato\n");
    printf("A Box22 está a disposição sempre que precisar!\n");

    return 0;
}
