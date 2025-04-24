#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaração das variáveis
    char estado1[3], estado2[3], codigo1[3], codigo2[3];
    char nomeCidade1[30], nomeCidade2[30];
    unsigned int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    float pibcapita1, pibcapita2, denspopulacional1, denspopulacional2;
    int pontosTur1, pontosTur2;
    int opcao1, opcao2;
    float valor1_atrib1 = 0, valor2_atrib1 = 0;
    float valor1_atrib2 = 0, valor2_atrib2 = 0;
    float soma1 = 0, soma2 = 0;

    // Entrada das cartas
    printf("Bem-vindo ao cadastrador de cartas Super Trunfo! Comece digitando uma letra de 'A' a 'H':\n");
    scanf("%s", estado1);
    printf("Ótimo! Agora digite um número de 01 a 04 que será o código da carta:\n");
    scanf("%s", codigo1);
    printf("Perfeito! Agora digite o nome da cidade:\n");
    getchar(); scanf(" %[^\n]", nomeCidade1);
    printf("Certo! Agora digite a população da cidade:\n");
    scanf("%d", &populacao1);
    printf("Agora digite a área em quilômetros quadrados:\n");
    scanf("%f", &area1);
    printf("Agora digite o PIB da cidade:\n");
    scanf("%f", &pib1);
    printf("Por fim, digite a quantidade de pontos turísticos:\n");
    scanf("%d", &pontosTur1);

    printf("Ótimo! Você terminou o cadastro da primeira cidade. Agora vamos cadastrar a segunda. Digite uma letra de 'A' a 'H':\n");
    scanf("%s", estado2);
    printf("Ótimo! Agora digite um número de 01 a 04 que será o código da carta:\n");
    scanf("%s", codigo2);
    printf("Perfeito! Agora digite o nome da cidade:\n");
    getchar(); scanf(" %[^\n]", nomeCidade2);
    printf("Certo! Agora digite a população da cidade:\n");
    scanf("%d", &populacao2);
    printf("Agora digite a área em quilômetros quadrados:\n");
    scanf("%f", &area2);
    printf("Agora digite o PIB da cidade:\n");
    scanf("%f", &pib2);
    printf("Por fim, digite a quantidade de pontos turísticos:\n");
    scanf("%d", &pontosTur2);

    // Cálculos
    denspopulacional1 = populacao1 / area1;
    denspopulacional2 = populacao2 / area2;
    pibcapita1 = pib1 / populacao1;
    pibcapita2 = pib2 / populacao2;

    // Menu de seleção
    printf("\nSelecione o primeiro atributo para comparação:\n");
    printf("1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    scanf("%d", &opcao1);

    do {
        printf("\nSelecione o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != opcao1) {
                switch(i) {
                    case 1: printf("%d. Populacao\n", i); break;
                    case 2: printf("%d. Area\n", i); break;
                    case 3: printf("%d. PIB\n", i); break;
                    case 4: printf("%d. Pontos Turisticos\n", i); break;
                    case 5: printf("%d. Densidade Populacional\n", i); break;
                    case 6: printf("%d. PIB per Capita\n", i); break;
                }
            }
        }
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) {
            printf("Você não pode escolher o mesmo atributo duas vezes!\n");
        }
    } while (opcao1 == opcao2);

    // Comparação dos dois atributos
    for (int i = 1; i <= 2; i++) {
        int escolha = (i == 1) ? opcao1 : opcao2;
        float v1 = 0, v2 = 0;
        char nomeAttr[30];

        switch(escolha) {
            case 1: v1 = populacao1; v2 = populacao2; strcpy(nomeAttr, "População"); break;
            case 2: v1 = area1; v2 = area2; strcpy(nomeAttr, "Área"); break;
            case 3: v1 = pib1; v2 = pib2; strcpy(nomeAttr, "PIB"); break;
            case 4: v1 = pontosTur1; v2 = pontosTur2; strcpy(nomeAttr, "Pontos Turísticos"); break;
            case 5: v1 = denspopulacional1; v2 = denspopulacional2; strcpy(nomeAttr, "Densidade Populacional"); break;
            case 6: v1 = pibcapita1; v2 = pibcapita2; strcpy(nomeAttr, "PIB per Capita"); break;
            default: printf("Atributo inválido.\n"); return 1;
        }

        printf("\nComparando %s:\n", nomeAttr);
        printf("%s: %.2f | %s: %.2f\n", nomeCidade1, v1, nomeCidade2, v2);

        // Regra especial para Densidade Populacional (menor vence)
        if (escolha == 5) {
            (v1 < v2) ? printf("Vencedor: %s\n", nomeCidade1) :
            (v2 < v1) ? printf("Vencedor: %s\n", nomeCidade2) :
            printf("Empate neste atributo!\n");
        } else {
            (v1 > v2) ? printf("Vencedor: %s\n", nomeCidade1) :
            (v2 > v1) ? printf("Vencedor: %s\n", nomeCidade2) :
            printf("Empate neste atributo!\n");
        }

        if (i == 1) { valor1_atrib1 = v1; valor2_atrib1 = v2; }
        else { valor1_atrib2 = v1; valor2_atrib2 = v2; }
    }

    // Soma dos dois atributos
    soma1 = valor1_atrib1 + valor1_atrib2;
    soma2 = valor2_atrib1 + valor2_atrib2;

    printf("\n==== RESULTADO FINAL ====\n");
    printf("Soma dos atributos:\n%s: %.2f\n%s: %.2f\n", nomeCidade1, soma1, nomeCidade2, soma2);

    if (soma1 > soma2)
        printf("VENCEDOR DA RODADA: %s\n", nomeCidade1);
    else if (soma2 > soma1)
        printf("VENCEDOR DA RODADA: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

    return 0;
}
