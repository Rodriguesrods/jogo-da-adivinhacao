#include <iostream>
#include <cmath> // Incluído para usar a função abs()
using namespace std;

int main() {
    cout << "*************************************" << endl;
    cout << "* Bem vindo ao jogo da adivinhacao! *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha a dificuldade:  " << endl; 
    cout << "Fácil (F), Médio (M) ou Difícil(D)" << endl; 

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    bool facil = dificuldade == 'F' || dificuldade == 'f'; // Aceita 'F' ou 'f'
    bool medio = dificuldade == 'M' || dificuldade == 'm'; // Aceita 'M' ou 'm'

    if (facil) {
        numero_de_tentativas = 15;
    }
    else if (medio) {
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    const int NUMERO_SECRETO = 42; // o numero aleatorio do jogo

    bool nao_acertou = true; // Saber que o loop pode parar
    int tentativas = 0; // soma de tentativas 

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {
        int chute; // variavel do numero de tentativas
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute?" << endl;
        cin >> chute; // recebe os chutes

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO; // organizou os if
        bool maior = chute > NUMERO_SECRETO;

        if (acertou) {
            cout << "Parabens! Voce acertou o numero secreto! " << endl;
            nao_acertou = false;
            break; // Sai do loop se o jogador acertar
        } 
        else if (maior) {
            cout << "Seu chute foi maior que o numero secreto! " << endl;
        } 
        else {
            cout << "Seu chute foi menor que o numero secreto! " << endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if (nao_acertou) {
        cout << "Você perdeu! Tente novamente!"  << endl;
    }
    else {
        cout << "Voce ganhou em " << tentativas << " tentativas! " << endl;
        cout.precision(2); // Define a precisão para 2 casas decimais
        cout << fixed; // Garante que a precisão seja aplicada corretamente
        cout << "Sua Pontuacao foi de " << pontos << " pontos." << endl;
    }

    return 0;
}
