#include <stdio.h>
// Necessário para utilizar as funções fgets e strcspn.
#include <string.h>

int main() {
    // Declaração de variáveis para armazenar os dados das cartas
    char estado1[2], estado2[2]; 
    char codigo_da_carta1[4], codigo_da_carta2[4];
    char nome_da_cidade1[30], nome_da_cidade2[30];
    unsigned int populacao1, populacao2;
    int pontos_turisticos1, pontos_turisticos2, opcao;
    float area1, area2, pib1, pib2, SuperPoder1, SuperPoder2;
    double densidade_populacional1, densidade_populacional2, pib_capita1, pib_capita2, inversoDensidadePopulacional1, inversoDensidadePopulacional2;

    // Variaveis de comparação (Declaradas como int para garantir a saída correta das comparações).
    int populacaoComparacao, areaComparacao, pibComparacao, pontosTuristicosComparacao, densidadeComparacao, pibCapitaComparacao, superPoderComparacao;    

    // Mensagem de boas-vindas e breve explicação do jogo
    printf("Olá, seja bem vindo ao jogo Super Trunfo!\n\n");
    printf("Super Trunfo é um jogo de cartas no qual cada carta contém informações sobre um determinado tema. \n");
    printf("O tema deste Super Trunfo é 'Países', onde você comparará os atributos numéricos das cidades como, população, área, pib e quantidade de pontos turísticos.");
    printf("Os jogadores se revezam escolhendo um atributo para comparar com a carta do oponente, e aquele com o valor mais alto vence a rodada e fica com a carta do adversário.\n\n");
        
    printf("Para começar, vamos cadastrar nossas cartas. Siga, conforme instruções.\n\n");

    // Cadastro da Primeira Carta--------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Carta 1: \n\n");

    // Obtendo o valor para variável estado1
    printf("Informe uma letra de 'A' a 'H'. Essa letra será a identificação para o estado: ");
    scanf(" %s", &estado1);

    // Consome o caractere de nova linha deixado no buffer
    getchar();

    // Obtendo o valor para variável codigo_da_carta1
    printf("Com base na letra que digitou na opção anterior. Agora vamos criar uma identificação para essa carta (Ex: 01): ");
    fgets(codigo_da_carta1, 4 , stdin);
    codigo_da_carta1[strcspn(codigo_da_carta1, "\n")] = 0;

    // Obtendo o valor para variável nome_da_cidade1
    printf("Agora, informe o nome dessa cidade: ");
    // fgets foi utilizado para ler a entrada do usuário, incluindo espaços em branco.
    fgets(nome_da_cidade1, 30, stdin);
    // strcspn foi utilizado para encontrar a posição do caracter de nova linha '\n' e substituí-lo por '0'. 
    nome_da_cidade1[strcspn(nome_da_cidade1, "\n")] = 0;

    // Obtendo o valor para variável populacao1
    printf("Agora, informe a população dessa cidade: ");
    scanf("%lu", &populacao1);

    // Obtendo o valor para variável area1
    printf("Agora, informe a área dessa cidade: ");
    scanf("%f", &area1);

    // Obtendo o valor para variável pib1
    printf("Muito bem, agora informe o PIB dessa cidade: ");
    scanf("%f", &pib1);

    // Obtendo o valor para variável pontos_turisticos1
    printf("E por último, informe a quantidade de pontos turísticos dessa cidade: ");
    scanf("%d", &pontos_turisticos1);

    printf("\n");

    printf("Muito bem! Você cadastrou a primeira carta. Agora, vamos cadastrar os dados da segunda.\n\n");

    // Cadastro da Segunda Carta--------------------------------------------------------------------------------------------------------------------------------------------------

    printf("Carta 2: \n\n");

    // Obtendo o valor para variável estado2
    printf("Informe uma letra de 'A' a 'H'. Essa letra será a identificação para o estado: ");
    scanf(" %s", &estado2);

    // Consome o caractere de nova linha deixado no buffer
    getchar();    
    
    // Obtendo o valor para variável codigo_da_carta2    
    printf("Com base na letra que digitou na opção anterior. Agora vamos criar uma identificação para essa carta (Ex: 02): ");
    // fgets foi utilizado para ler a entrada do usuário, incluindo espaços em branco.
    fgets(codigo_da_carta2, 4 , stdin);
    // strcspn foi utilizado para encontrar a posição do caracter de nova linha '\n' e substituí-lo por '0'. 
    codigo_da_carta2[strcspn(codigo_da_carta2, "\n")] = 0;

    // Obtendo o valor para variável nome_da_cidade2
    printf("Agora, informe o nome dessa cidade: ");
    fgets(nome_da_cidade2, 30, stdin);
    nome_da_cidade2[strcspn(nome_da_cidade2, "\n")] = 0;

    // Obtendo o valor para variável populacao2
    printf("Agora, informe a população dessa cidade: ");
    scanf("%lu", &populacao2);

    // Obtendo o valor para variável area2
    printf("Agora, informe a área dessa cidade: ");
    scanf("%f", &area2);

    // Obtendo o valor para variável pib2
    printf("Muito bem, agora informe o PIB dessa cidade: ");
    scanf("%f", &pib2);

    // Obtendo o valor para variável pontos_turisticos2
    printf("E por último, informe a quantidade de pontos turísticos dessa cidade: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculo densidade populacional
    // Utilizado conversão explicita (casting) para correção na saída de dados.
    densidade_populacional1 = (double) populacao1 / area1;
    densidade_populacional2 = (double) populacao2 / area2;

    // Calculo pib per capita das castas
    // Utilizado conversão explicita (casting) para correção na saída de dados.
    // O valor exibido na descrição está em bilhões, para a saída deseja, foi necessário multiplicar por 1b para depois dividir.
    pib_capita1 = (double) (pib1 * 1000000000) / populacao1;
    pib_capita2 = (double) (pib2 * 1000000000)  / populacao2;

    // Cácula o inverso da densidade populacional das cartas. Realizado conversão explicita para exibição correta dos valores.
    inversoDensidadePopulacional1 = (double) 1 / densidade_populacional1;    
    inversoDensidadePopulacional2 = (double) 1 / densidade_populacional2;    

    // Cálculo do super poder das cartas (calcula todos os atributos númericos das cartas).
    SuperPoder1 = (float) populacao1 + (float) area1 + (float) pib1 + (float) pontos_turisticos1 + (float) pib_capita1 + (float) inversoDensidadePopulacional1;
    SuperPoder2 = (float) populacao2 + (float) area2 + (float) pib2 + (float) pontos_turisticos2 + (float) pib_capita2 + (float) inversoDensidadePopulacional2;    

    printf("\n");

    // Exibição dos dados cadastrados
    printf("Muito bem, você finalizou a inserção de dados para nossas cartas. Calculamos automaticamente a densidade populacional e PIB per Capita. E também um novo atributo\n");
    printf("que chamamos de 'Super Poder', este atributo é a soma de todos os outros atributos números da nossa carta.\n\n");
    printf("Confira abaixo: \n\n");

    printf("Carta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s%s\n", estado1, codigo_da_carta1);
    printf("Nome da Cidade: %s\n", nome_da_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_capita1);
    printf("Poder total da carta (Super Poder): %.2f\n\n", SuperPoder1);

    printf("Carta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s%s\n", estado2, codigo_da_carta2);
    printf("Nome da Cidade: %s\n", nome_da_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_capita2);
    printf("Poder total da carta (Super Poder): %.2f\n\n", SuperPoder2);

    // Exibição do menu interativo. Mostrando os atributos disponíveis para que o usuário escolha qual quer comparar.
    printf("Agora você escolhe! Qual atributo deseja usar para comparar? \n\n");
    printf(" [1] - POPULAÇÃO\n");
    printf(" [2] - ÁREA\n");
    printf(" [3] - PIB\n");
    printf(" [4] - NÚMERO DE PONTOS TURÍSTICOS\n");
    printf(" [5] - DENSIDADE POPULACIONAL\n\n");

    // Registrando a escolha do usuário, e guardando na variável "opcao".
    printf("Digite o número correspondente ao atributo que deseja realizar a comparação: ");
    scanf("%d", &opcao);
    printf("\n");

    // Início do switch, com base no atributo escolhido pelo usuário, o switch irá tratar cada opção.
    switch (opcao)
    {
    case 1:
    // Comparação das cartas, caso o atributo escolhido tenha sido POPULAÇÃO.
        if (populacao1 == populacao2){
            printf("O atributo escolhido para comparação foi 'POPULAÇÃO'\n\n");
            printf("Carta 1: %s | População: %lu\n", nome_da_cidade1, populacao1);
            printf("Carta 2: %s | População: %lu\n\n", nome_da_cidade2, populacao2);
            printf("Opa! Tivemos um empate!\n\n");

        } else if (populacao1 > populacao2){
            printf("O atributo escolhido para comparação foi 'POPULAÇÃO'\n\n");
            printf("Carta 1: %s | População: %lu\n", nome_da_cidade1, populacao1);
            printf("Carta 2: %s | População: %lu\n\n", nome_da_cidade2, populacao2);
            printf("A carta 1: %s venceu!\n\n", nome_da_cidade1);

        }   else {
            printf("O atributo escolhido para comparação foi 'POPULAÇÃO'\n\n");
            printf("Carta 1: %s | População: %lu\n", nome_da_cidade1, populacao1);
            printf("Carta 2: %s | População: %lu\n\n", nome_da_cidade2, populacao2);
            printf("A carta 2: %s venceu!\n\n", nome_da_cidade2);
        }

        break;
    
    case 2:
    // Comparação das cartas, caso o atributo escolhido tenha sido AREA.
    if (area1 == area2){
        printf("O atributo escolhido para comparação foi 'ÁREA'\n\n");
        printf("Carta 1: %s | Área: %.2f\n", nome_da_cidade1, area1);
        printf("Carta 2: %s | Área: %.2f\n\n", nome_da_cidade2, area2);
        printf("Opa! Tivemos um empate!\n\n");

    } else if (area1 > area2){
        printf("O atributo escolhido para comparação foi 'ÁREA'\n\n");
        printf("Carta 1: %s | Área: %.2f\n", nome_da_cidade1, area1);
        printf("Carta 2: %s | Área: %.2f\n\n", nome_da_cidade2, area2);
        printf("A carta 1: %s venceu!\n\n", nome_da_cidade1);

    }   else {
        printf("O atributo escolhido para comparação foi 'ÁREA'\n\n");
        printf("Carta 1: %s | Área: %.2f\n", nome_da_cidade1, area1);
        printf("Carta 2: %s | Área: %.2f\n\n", nome_da_cidade2, area2);
        printf("A carta 2: %s venceu!\n\n", nome_da_cidade2);
    }
        break;

    case 3:
    // Comparação das cartas, caso o atributo escolhido tenha sido PIB.
    if (pib1 == pib2){
        printf("O atributo escolhido para comparação foi 'PIB'\n\n");
        printf("Carta 1: %s | PIB: %.2f\n", nome_da_cidade1, pib1);
        printf("Carta 2: %s | PIB: %.2f\n\n", nome_da_cidade2, pib2);
        printf("Opa! Tivemos um empate!\n\n");

    } else if (pib1 > pib2){
        printf("O atributo escolhido para comparação foi 'PIB'\n\n");
        printf("Carta 1: %s | PIB: %.2f\n", nome_da_cidade1, pib1);
        printf("Carta 2: %s | PIB: %.2f\n\n", nome_da_cidade2, pib2);
        printf("A carta 1: %s venceu!\n\n", nome_da_cidade1);

    }   else {
        printf("O atributo escolhido para comparação foi 'PIB'\n\n");
        printf("Carta 1: %s | PIB: %.2f\n", nome_da_cidade1, pib1);
        printf("Carta 2: %s | PIB: %.2f\n\n", nome_da_cidade2, pib2);
        printf("A carta 2: %s venceu!\n\n", nome_da_cidade2);
    }
        break;

    case 4:
    // Comparação das cartas, caso o atributo escolhido tenha sido NÚMERO DE PONTOS TURISTICOS.
    if (pontos_turisticos1 == pontos_turisticos2){
        printf("O atributo escolhido para comparação foi 'NÚMERO DE PONTOS TURÍSTICOS'\n\n");
        printf("Carta 1: %s | Número de pontos turísticos: %d\n", nome_da_cidade1, pontos_turisticos1);
        printf("Carta 2: %s | Número de pontos turísticos: %d\n\n", nome_da_cidade2, pontos_turisticos2);
        printf("Opa! Tivemos um empate!\n\n");

    } else if (pontos_turisticos1 > pontos_turisticos2){
        printf("O atributo escolhido para comparação foi 'NÚMERO DE PONTOS TURÍSTICOS'\n\n");
        printf("Carta 1: %s | Número de pontos turísticos: %d\n", nome_da_cidade1, pontos_turisticos1);
        printf("Carta 2: %s | Número de pontos turísticos: %d\n\n", nome_da_cidade2, pontos_turisticos2);
        printf("A carta 1: %s venceu!\n\n", nome_da_cidade1);

    }   else {
        printf("O atributo escolhido para comparação foi 'NÚMERO DE PONTOS TURÍSTICOS'\n\n");
        printf("Carta 1: %s | Número de pontos turísticos: %d\n", nome_da_cidade1, pontos_turisticos1);
        printf("Carta 2: %s | Número de pontos turísticos: %d\n\n", nome_da_cidade2, pontos_turisticos2);
        printf("A carta 2: %s venceu!\n\n", nome_da_cidade2);
    }
        break;

    case 5:
    // Comparação das cartas, caso o atributo escolhido tenha sido DENSIDADE POPULACIONAL.
    if (densidade_populacional1 == densidade_populacional2){
        printf("O atributo escolhido para comparação foi 'DENSIDADE POPULACIONAL'\n\n");
        printf("Observação: Neste atributo, o menor valor ganha!\n");
        printf("Carta 1: %s | Densidade Populacional: %.2f\n", nome_da_cidade1, densidade_populacional1);
        printf("Carta 2: %s | Densidade Populacional:: %.2f\n\n", nome_da_cidade2, densidade_populacional2);
        printf("Opa! Tivemos um empate!\n\n");

    } else if (densidade_populacional1 < densidade_populacional2){
        printf("O atributo escolhido para comparação foi 'DENSIDADE POPULACIONAL'\n\n");
        printf("Observação: Neste atributo, o menor valor ganha!\n");
        printf("Carta 1: %s | Densidade Populacional: %.2f\n", nome_da_cidade1, densidade_populacional1);
        printf("Carta 2: %s | Densidade Populacional:: %.2f\n\n", nome_da_cidade2, densidade_populacional2);
        printf("A carta 1: %s venceu!\n\n", nome_da_cidade1);

    }   else {
        printf("O atributo escolhido para comparação foi 'DENSIDADE POPULACIONAL'\n\n");
        printf("Observação: Neste atributo, o menor valor ganha!\n");
        printf("Carta 1: %s | Densidade Populacional: %.2f\n", nome_da_cidade1, densidade_populacional1);
        printf("Carta 2: %s | Densidade Populacional: %.2f\n\n", nome_da_cidade2, densidade_populacional2);
        printf("A carta 2: %s venceu!\n\n", nome_da_cidade2);
    }
        break;

    // Caso o usuário tenha digitado uma opção inválida, será exibido esta mensagem.
    default:
        printf("Você escolheu uma opção inválida.\n");
        break;
    }

    return 0;
}