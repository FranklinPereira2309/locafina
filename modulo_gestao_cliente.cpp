#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct Cliente {
    string CPF;
    string Nome;
    string DtNascimento;
    string CNH;

    Cliente(string CPF, string Nome, string DtNascimento, string CNH) {
        this->CPF = CPF;
        this->Nome = Nome;
        this->DtNascimento = DtNascimento;
        this->CNH = CNH;
    }
};

vector<Cliente> clientes;

void incluir_cliente() {
    string CPF, Nome, DtNascimento, CNH;

    cout << "Incluir Cliente:" << endl;
    cout << " " << endl;
    
    cout << "Digite o CPF do cliente: ";
    cin >> CPF;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, Nome);
    cout << "Digite a data de nascimento do cliente: ";
    cin >> DtNascimento;
    cout << "Digite o numero da CNH do cliente: ";
    cin >> CNH;

    Cliente cliente(CPF, Nome, DtNascimento, CNH);
    clientes.push_back(cliente);

    cout << "Cliente adicionado com sucesso!" << endl;
    cout << " " << endl;

}

void excluir_cliente() {
    string CPF;

    cout << "Excluir Cliente:" << endl;
    cout << " " << endl;

    cout << "Digite o CPF do cliente a ser excluído: ";
    cin >> CPF;
    cout << " " << endl;

    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].CPF == CPF) {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente removido com sucesso!" << endl;
            cout << " " << endl;

            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
    cout << " " << endl;
}

void alterar_cliente() {
    string CPF;

    cout << "Alterar Cliente:" << endl;
    cout << " " << endl;

    cout << "Digite o CPF do cliente a ser alterado: ";
    cin >> CPF;
    cout << " " << endl;

    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].CPF == CPF) {
            
            cout << "Dados do cliente:" << endl;
            cout << " " << endl;

            cout << "CPF: " << clientes[i].CPF << endl;
            cout << "Nome: " << clientes[i].Nome << endl;
            cout << "Data de Nascimento: " << clientes[i].DtNascimento << endl;
            cout << "Numero CNH: " << clientes[i].CNH << endl;
            cout << " " << endl;

            cout << "Deseja alterar o Nome? (S/N): ";
            char opcao;
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, clientes[i].Nome);
            }

            cout << "Deseja alterar o Telefone? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite a nova Data de Nascimento: ";
                cin >> clientes[i].DtNascimento;
            }

            cout << "Deseja alterar o número da CNF? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo email: ";
                cin >> clientes[i].CNH;
            }

            cout << "Cliente alterado com sucesso!" << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
    cout << " " << endl;

}

void listar_clientes() {

    cout << "Lista de Clientes:" << endl;
    cout << " " << endl;

    for (const Cliente& cliente : clientes) {
        cout << "CPF: " << cliente.CPF << endl; 
        cout << ". Nome: " << cliente.Nome << endl; 
        cout << ". Data de Nascimento: " << cliente.DtNascimento << endl; 
        cout << ". CNH: " << cliente.CNH << endl;
        cout << " " << endl;
    }
}
 
void localizar_cliente() {
    string CPF;

    cout << "Localizar Cliente:" << endl;
    cout << " " << endl;

    cout << "Digite o CPF do cliente a ser localizado: ";
    cin >> CPF;
    cout << " " << endl;

    for (const Cliente& cliente : clientes) {
        if (cliente.CPF == CPF) {
            cout << "Dados do cliente encontrado:" << endl;
            cout << " " << endl;

            cout << "CPF: " << cliente.CPF << endl; 
            cout << ". Nome: " << cliente.Nome << endl; 
            cout << ". Data de Nascimento: " << cliente.DtNascimento << endl; 
            cout << ". CNH: " << cliente.CNH << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Cliente não encontrado." << endl;
    cout << " " << endl;

}

int main() {
    int opcao;

    while (true) {
        cout << "Menu de Opções:" << endl;
        cout << " " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << " " << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cout << " " << endl;
 
        system ("clear");

        switch (opcao) {
            case 1:
                incluir_cliente();
                break;
            case 2:
                excluir_cliente();
                break;
            case 3:
                alterar_cliente();
                break;
            case 4:
                listar_clientes();
                break;
            case 5:
                localizar_cliente();
                break;
            case 0:
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                cout << " " << endl;
        }
    }

    return 0;
}
