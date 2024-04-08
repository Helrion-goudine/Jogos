#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pergunta {
    char questao[200];
    char opcoes[4][50];
    int resposta;
};

int fazerPergunta(struct Pergunta *pergunta) {
    printf("%s\n", pergunta->questao);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, pergunta->opcoes[i]);
    }

    int resposta;
    printf("Escolha a opção correta (1-4): ");
    scanf("%d", &resposta);
    return resposta;
}

int main() {
    struct Pergunta perguntas[5]; // Alterado para 5 perguntas

    // Pergunta 1
    strcpy(perguntas[0].questao, "Qual é a capital do Brasil?");
    strcpy(perguntas[0].opcoes[0], "São Paulo");
    strcpy(perguntas[0].opcoes[1], "Brasília");
    strcpy(perguntas[0].opcoes[2], "Rio de Janeiro");
    strcpy(perguntas[0].opcoes[3], "Salvador");
    perguntas[0].resposta = 2;

    // Pergunta 2
    strcpy(perguntas[1].questao, "Quem escreveu Dom Quixote?");
    strcpy(perguntas[1].opcoes[0], "Miguel de Cervantes");
    strcpy(perguntas[1].opcoes[1], "William Shakespeare");
    strcpy(perguntas[1].opcoes[2], "Jorge Luis Borges");
    strcpy(perguntas[1].opcoes[3], "Machado de Assis");
    perguntas[1].resposta = 1;

    // Pergunta 3
    strcpy(perguntas[2].questao, "Qual é o maior planeta do Sistema Solar?");
    strcpy(perguntas[2].opcoes[0], "Terra");
    strcpy(perguntas[2].opcoes[1], "Júpiter");
    strcpy(perguntas[2].opcoes[2], "Saturno");
    strcpy(perguntas[2].opcoes[3], "Marte");
    perguntas[2].resposta = 2;

    // Pergunta 4
    strcpy(perguntas[3].questao, "Quem pintou a Mona Lisa?");
    strcpy(perguntas[3].opcoes[0], "Leonardo da Vinci");
    strcpy(perguntas[3].opcoes[1], "Pablo Picasso");
    strcpy(perguntas[3].opcoes[2], "Vincent van Gogh");
    strcpy(perguntas[3].opcoes[3], "Michelangelo");
    perguntas[3].resposta = 1;

    // Pergunta 5
    strcpy(perguntas[4].questao, "Qual é o rio mais longo do mundo?");
    strcpy(perguntas[4].opcoes[0], "Rio Amazonas");
    strcpy(perguntas[4].opcoes[1], "Rio Nilo");
    strcpy(perguntas[4].opcoes[2], "Rio Ganges");
    strcpy(perguntas[4].opcoes[3], "Rio Mississipi");
    perguntas[4].resposta = 1;

    int pontuacao = 0;

    for (int i = 0; i < 5; i++) {
        int resposta = fazerPergunta(&perguntas[i]);
        if (resposta == perguntas[i].resposta) {
            printf("Resposta correta!\n");
            pontuacao++;
        } else {
            printf("Resposta incorreta. A resposta correta era a opção %d.\n", perguntas[i].resposta);
        }
    }

    printf("Fim do jogo. Sua pontuação final é: %d\n", pontuacao);

    return 0;
}