#include <iostream>

static int selecaoDificuldade() {
    int dificuldade{};
    int vidas{};
    bool selecao{false};
    std::cout << "**********************\n\nMenu Inicial Jogo adivinha\n\n**********************\n\n";
    std::cout << "Qual dificuldade: Dificil(3), Medio(2), Facil(1)\nDigite a letra que deseja em Capslock...\n";

    while (!selecao) {
        std::cout << "->";
        std::cin >> dificuldade;
        switch (dificuldade)
        {
        case 3:
            vidas = 3;
            selecao = true;
            break;
        case 2:
            vidas = 6;
            selecao = true;
            break;
        case 1:
            vidas = 10;
            selecao = true;
            break;
        default:
            std::cout << "*Numero invalido!*\n";
            selecao = false;
            break;
        }
    }
    
    std::cout << "Voce tem: " << vidas << " Chances\n";

    return vidas;
}

static void iniciarJogo(int vidasJogador) {
    srand((int)time(0));
    const int NUMEROALEATORIO = rand() % 100;
    int numeroJogador{};

    //std::cout << NUMEROALEATORIO << "\n";

    while (vidasJogador != 0) {
        std::cout << "Escolha um numero de 0 a 100...\n->";
        std::cin >> numeroJogador;

        if (numeroJogador > NUMEROALEATORIO)
        {
            std::cout << "*O numero secreto e menor que seu chute*\n\n";
            vidasJogador--;
        }
        else if (numeroJogador < NUMEROALEATORIO)
        {
            std::cout << "*O numero secreto e maior que seu chute*\n\n";
            vidasJogador--;
        }
        else if (numeroJogador == NUMEROALEATORIO)
        {
            std::cout << "VOCE GANHOU!!!!!!!!!!!\n\n";
            break;
        }
        std::cout << "Vidas restantes: " << vidasJogador << "\n\n";
    }
}

int main()
{
    iniciarJogo(selecaoDificuldade());

    char continuar{};
    std::cout << "Continuar? (S/n)\n";
    std::cin >> continuar;

    if (continuar == 'S') {
        system("cls");
        main();
    }

    return 0;
}
