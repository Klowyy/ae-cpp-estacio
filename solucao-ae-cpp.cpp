// solucao-ae-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int escolha;
    float valorCarro;
    char resposta = 's';
    int trio = 0;
    int ar = 0;
    int direcao = 0;
    int completo = 0;
    float taxa1 = 0;
    float taxa2 = 0;
    float taxa3 = 0;
    float taxa4 = 0;
    float desconto = 0;
    float IPI;



    // usuário insere valor do carro
    cout << "Olá, você irá comprar um carro 0km! Parabéns. Digite o valor do carro: \n";
    cin >> valorCarro;
    IPI = valorCarro * 0.08; // IPI é 8% do valor do carro




    while (resposta == 's') {

        cout << "Escolha uma das opções abaixo: \n";
        cout << "0 - Nenhum adicional \n 1- Trio elétrico (alarme, vidro elétrico e tranca elétrica \n 2- Ar condicionado \n 3- Direção hidráulica \n 4- Completo (trio elétrico, ar condicionado e direção hidráulica) \n";

        cin >> escolha;

        if (escolha == 0) {
            resposta = 'n';
        };

        if (escolha == 1) {
            taxa1 = (valorCarro * 1.08) * 0.02; // 2% do valor do carro com IPI
            trio++;
            /*if (trio > 1) {
                trio = 1;
            }*/ //maneira de fixar em 1 (uma) escolha caso o usuário escolha a opção mais de uma vez; aplicar a todas as opções
        };

        if (escolha == 2) {
            taxa2 = valorCarro * 0.02; // 2% do valor do carro (sem o IPI)
            ar++;
        };

        if (escolha == 3) {
            taxa3 = valorCarro * 0.02; // 2% do valor do carro (sem o IPI)
            direcao++;
        };


        if (escolha == 4) {
            taxa4 = (((valorCarro * 1.08) * 0.02) + (valorCarro * 0.02 * 2)); // a soma dos acréscimos isolados
            desconto = (valorCarro + taxa4) * 0.035; // 3,5% de desconto do valor total
            completo++;
            resposta = 'n'; // ao escolher a opção "completo", não permite adicionar mais opções
        }

        if (escolha > 4) {
            cout << "Não existe essa opção \n";
        }

        // enquanto o usuário responder 's' para adicionar mais opções, retorna ao menu
        if (resposta != 'n') {
            cout << "Deseja adicionar mais opções? [s/n] ";
            cin >> resposta;
        }


    };
    // se o usuário escolher 1, 2 e 3
    // o '!= 0' foi usado para caso o usuário escolha a mesma opção mais de uma vez
    if (desconto == 0 && trio != 0 && ar != 0 && direcao != 0) {
        cout << "Você escolheu as opções 1, 2 e 3. Essas escolhas são similares ao modelo completo (opção 4). Porém dessa forma escolhida não será aplicado o desconto que você tem direito. Favor reiniciar e escolher a opção 4.";
    }
    // se o usuário escolher 1, 2 ou 3 e também escolher o modelo completo
    //o '!= 0' foi usado para caso o usuário escolha a mesma opção mais de uma vez
    else if ((trio != 0 || ar != 0 || direcao != 0) && completo == 1) {

        cout << "Você escolheu a opção 4 com o carro completo. Porém escolheu também alguma outra opção. Favor reiniciar e escolher somente o carro completo ou somente as outras opções desejadas";
    }
    else {
        // resultados
        cout << "Valor original do automóvel: R$" << setprecision(2) << fixed << valorCarro << "\n";
        cout << "Você escolheu Trio Elétrico: " << trio << " vezes" << "\n";
        cout << "Você escolheu Ar Condicionado: " << ar << " vezes" << "\n";
        cout << "Você escolheu Direção Hidráulica: " << direcao << " vezes" << "\n";
        cout << "Você escolheu Completo: " << completo << " vezes" << "\n";
        cout << "O valor do IPI é de R$" << IPI << "\n";
        cout << "O desconto é de R$" << setprecision(2) << fixed << desconto << "\n";
        cout << "O valor total de taxas R$" << setprecision(2) << fixed << IPI + taxa1 + taxa2 + taxa3 + taxa4 << "\n";
        cout << "O valor total do carro é de R$" << setprecision(2) << fixed << valorCarro + IPI + taxa1 + taxa2 + taxa3 + taxa4 - desconto << "\n";

        system("pause");
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
