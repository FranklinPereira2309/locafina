#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){

    //declarando variáveis para cadastro de clientes
    int opcaoSelecionada;
    string nomeCliente;
    string cpf;
    string DtNascimento;
    int cnh;

    // criando menu de opcao e armazenando a opcao selecionada no variavel opcao selecionada
    cout << "Selecione a opcao do que deseja fazer:\n\n ";
    cout << "1 - Incluir\n 2 - Excluir\n 3 - Alterar\n 4 - Listar\n 5 - Localizar\n 6 - Sair\n\n";
    
    cin >> opcaoSelecionada;

    switch(opcaoSelecionada){
        case 1:
            system("clear");
            cout << "Voce escolheu a opcao 1 - Inserir \n\n";

            cout << "Digite o nome completo do cliente: ";
            getline(cin >> ws, nomeCliente);

            cout << "Digite o cpf, apenas numeros: ";
            getline(cin >> ws, cpf);

            cout << "Digite a data de nascimento no formato DD/MM/YYYY: ";
            getline(cin >> ws, DtNascimento);

            cout << "Digite o numero da CNH: ";
            cin >> cnh;

            break;
        case 2:
            cout << "Voce escolheu a opcao 2\n";
            break;
        case 3:
            cout << "Voce escolheu a opcao 3\n";
            break;
        case 4: 
            cout << "Voce escolheu a opcao 4\n";
            break;
        case 5:
            cout << "Voce escolheu a opcao 5\n";
            break;
        case 6:
            cout << "Voce escolheu a opcao 6\n";
            break;
        case 0:
            cout << "Voce escolheu a opcao 0\n";
            break;
        default:
            cout << "Opcao invalida\n";
            break;
    }
    return 0;
}