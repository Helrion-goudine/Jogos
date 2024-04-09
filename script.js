const perguntas = [
    {
        questao: "Quantos dígitos diferentes são usados no sistema binário?",
        opcoes: ["Dois dígitos: 0 e 1", "Quatro dígitos: 0, 1, 2, 3", "Oito dígitos: 0, 1, 2, 3, 4, 5, 6, 7", "Dezesseis dígitos: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F"],
        resposta: 1
    },
    {
        questao: "Qual é a base do sistema octal?",
        opcoes: ["Base 2", "Base 8", "Base 10", "Base 16"],
        resposta: 2
    },
    {
        questao: "O sistema decimal é baseado em quantos dígitos?",
        opcoes: ["Quatro dígitos", "Oito dígitos", "Dez dígitos", "Dezesseis dígitos"],
        resposta: 3
    },
    {
        questao: "Quantos dígitos são usados no sistema hexadecimal?",
        opcoes: ["Dez dígitos: 0 a 9", "Doze dígitos: 0 a 9, A, B", "Dezesseis dígitos: 0 a 9, A a F", "Vinte dígitos: 0 a 9, A a J"],
        resposta: 3
    },
    {
        questao: "Qual é o número decimal correspondente ao número binário '1010'?",
        opcoes: ["2", "5", "8", "10"],
        resposta: 4
    }
];

let pontuacao = 0;
let perguntaAtual = 0;

const perguntaElemento = document.getElementById("pergunta");
const opcoesElementos = [
    document.getElementById("op1"),
    document.getElementById("op2"),
    document.getElementById("op3"),
    document.getElementById("op4")
];
const mensagemElemento = document.getElementById("mensagem");

function exibirPergunta() {
    const pergunta = perguntas[perguntaAtual];
    perguntaElemento.textContent = pergunta.questao;
    pergunta.opcoes.forEach((opcao, index) => {
        opcoesElementos[index].textContent = opcao;
    });
}

function verificarResposta() {
    const opcoes = document.getElementsByName("opcao");
    let resposta = null;
    opcoes.forEach(opcao => {
        if (opcao.checked) {
            resposta = parseInt(opcao.value);
        }
    });
    return resposta;
}

function proximaPergunta() {
    const resposta = verificarResposta();
    if (resposta !== null) {
        if (resposta === perguntas[perguntaAtual].resposta) {
            mensagemElemento.textContent = "Resposta correta!";
            pontuacao++;
        } else {
            mensagemElemento.textContent = `Resposta incorreta. A resposta correta era a opção ${perguntas[perguntaAtual].resposta}.`;
        }
        perguntaAtual++;
        if (perguntaAtual < perguntas.length) {
            exibirPergunta();
        } else {
            mensagemElemento.textContent = `Fim do jogo. Sua pontuação final é: ${pontuacao}`;
            document.getElementById("btnResponder").disabled = true;
        }
    } else {
        mensagemElemento.textContent = "Por favor, selecione uma opção.";
    }
}

document.getElementById("btnResponder").addEventListener("click", proximaPergunta);

exibirPergunta();
