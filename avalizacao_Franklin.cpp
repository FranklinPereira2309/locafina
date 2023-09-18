#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct Cliente
{
    string cpf;
    string nome;
    string dataNascimento;
    string cnh;

};

void menu() {
    int opcao=1;

    vector<Cliente> dadosCliente;

    Cliente novoCliente;

    while(opcao !=0) {
        cout << "1- Incluir " << endl;
        cout << "2- Excluir"  << endl;
        cout << "3- Alterar(CPF)" << endl;
        cout << "4- Listar" << endl;
        cout << "5- Localizar(CPF)" << endl;
        cout << "0- Sair" << endl;
        cin >> opcao;

        system("clear");

        if(opcao >= 0 && opcao <= 5) {

        switch (opcao)
        {
            
        case 1:
            cout << "Menu INCLUIR...\n";
            cout << "===================...\n\n";

            cout << "Digite um Nome: ";
            getline(cin >> ws, novoCliente.nome);
            cout << "Digite cpf: ";
            getline(cin >> ws, novoCliente.cpf);
            cout << "Digite sua data de Nascimento: ";
            getline(cin >> ws, novoCliente.dataNascimento);
            cout << "Digite sua CNH: ";
            getline(cin >> ws, novoCliente.cnh);
            dadosCliente.push_back(novoCliente);
            system("clear");

            break;
        case 2:
            cout << "Exluindo...\n\n";
            break;
        case 3:
            cout << "Alterando...\n\n";
            break;
        case 4:
            cout << "Menu INCLUIR...\n";
            cout << "===================...\n\n";
            break;
        case 5:
            cout << "Localizando...\n\n";
            break;
        default:
            break;;
        }
        }else {
            cout << "\nOpção Inválida!" << endl;
        }

    }

    }
    void incluir() {
        
    }

    void excluir() {

    }

    void alterar() {

    }

    void listar() {

    }

    void localizar(int numero) {

    }


int main() {
    

    menu();


    return 0;
}