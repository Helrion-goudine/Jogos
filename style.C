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
    strcpy(perguntas[0].questao, "Quantos dígitos diferentes são usados no sistema binário?");
    strcpy(perguntas[0].opcoes[0], "Dois dígitos: 0 e 1");
    strcpy(perguntas[0].opcoes[1], "Quatro dígitos: 0, 1, 2, 3");
    strcpy(perguntas[0].opcoes[2], "Oito dígitos: 0, 1, 2, 3, 4, 5, 6, 7");
    strcpy(perguntas[0].opcoes[3], "Dezesseis dígitos: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F");
    perguntas[0].resposta = 2;

    // Pergunta 2
    strcpy(perguntas[1].questao, "Qual é a base do sistema octal?");
    strcpy(perguntas[1].opcoes[0], "Base 2");
    strcpy(perguntas[1].opcoes[1], "Base 8");
    strcpy(perguntas[1].opcoes[2], "Base 10");
    strcpy(perguntas[1].opcoes[3], "Base 16");
    perguntas[1].resposta = 1;

    // Pergunta 3
    strcpy(perguntas[2].questao, "O sistema decimal é baseado em quantos dígitos?");
    strcpy(perguntas[2].opcoes[0], "Quatro dígitos");
    strcpy(perguntas[2].opcoes[1], "Oito dígitos");
    strcpy(perguntas[2].opcoes[2], "Dez dígitos");
    strcpy(perguntas[2].opcoes[3], "Dezesseis dígitos");
    perguntas[2].resposta = 2;

    // Pergunta 4
    strcpy(perguntas[3].questao, "Quantos dígitos são usados no sistema hexadecimal?");
    strcpy(perguntas[3].opcoes[0], "Dez dígitos: 0 a 9");
    strcpy(perguntas[3].opcoes[1], "Doze dígitos: 0 a 9, A, B");
    strcpy(perguntas[3].opcoes[2], "Dezesseis dígitos: 0 a 9, A a F");
    strcpy(perguntas[3].opcoes[3], "Vinte dígitos: 0 a 9, A a J");
    perguntas[3].resposta = 3;

    // Pergunta 5
    strcpy(perguntas[4].questao, "Qual é o número decimal correspondente ao número binário '1010'?");
    strcpy(perguntas[4].opcoes[0], "2");
    strcpy(perguntas[4].opcoes[1], "5");
    strcpy(perguntas[4].opcoes[2], "8");
    strcpy(perguntas[4].opcoes[3], "10");
    perguntas[4].resposta = 4;

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
