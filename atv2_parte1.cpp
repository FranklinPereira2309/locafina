#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente {

public:
    string CPF;
    string Nome;
    string DtNascimento;
    string CNH;

    Cliente(const string& CPF, const string& Nome, const string& 
    DtNascimento, const string& CNH)

    : CPF(CPF), Nome(Nome), DtNascimento(DtNascimento), CNH(CNH) {}

};


void incluirCliente(vector<Cliente>& clientes) {

    string CPF, Nome, DtNascimento, CNH;
    
    cout << "Informe o CPF do cliente: ";
    cin >> CPF;
    
    cout << "Informe o Nome do cliente: ";
    cin.ignore();
    
    getline(cin, Nome);
    cout << "Informe a data de nascimento do cliente (dd/mm): ";
    cin >> DtNascimento;
    
    cout << "Informe o numero da CNH do cliente: ";
    cin >> CNH;

    clientes.push_back(Cliente(CPF, Nome, DtNascimento, CNH));
    cout << "Cliente adicionado com sucesso!" << endl;
}

void excluirCliente(vector<Cliente>& clientes, const string& CPF) {

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        
        if (it->CPF == CPF) {
            clientes.erase(it);
            
            cout << "Cliente com CPF " << CPF << " excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Cliente com CPF " << CPF << " nao encontrado." << endl;
}

void listarClientes(const vector<Cliente>& clientes) {
    cout << "Lista de Clientes:" << endl;

    for (const Cliente& cliente : clientes) {
        cout << "CPF: " << cliente.CPF << endl;
        cout << "Nome: " << cliente.Nome << endl;
        cout << "Data de Nascimento: " << cliente.DtNascimento << endl;
        cout << "CNH: " << cliente.CNH << endl;
        cout << endl;
    }
}

void localizarCliente(const vector<Cliente>& clientes, const string& CPF) {
    
    for (const Cliente& cliente : clientes) {
       
        if (cliente.CPF == CPF) {
            cout << "Cliente encontrado:" << endl;
            cout << "CPF: " << cliente.CPF << endl;
            cout << "Nome: " << cliente.Nome << endl;
            cout << "Data de Nascimento: " << cliente.DtNascimento << endl;
            cout << "CNH: " << cliente.CNH << endl;
           
            return;
        }
    }

    cout << "Cliente com CPF " << CPF << " não encontrado." << endl;
}

int main() {

    vector<Cliente> clientes;

    while (true) {
        
        cout << "Escolha uma das opcoes:" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (apenas por CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CPF)"<< endl;
        cout << "0. Sair" << endl;
        
        int opcoesIndice;
        cin >> opcoesIndice;


        switch (opcoesIndice) {
            case 1:
                incluirCliente(clientes);
                break;

            case 2: {
                string CPF;
                cout << "Informe o CPF do cliente a ser excluido: ";
                cin >> CPF;
                excluirCliente(clientes, CPF);
                break;
            }

            case 3: {
                string CPF;
                cout << "Informe o CPF do cliente a ser alterado: ";
                cin >> CPF;

                for (Cliente& cliente : clientes) {
                
                    if (cliente.CPF == CPF) {
                        cout << "CPF: " << cliente.CPF << endl;
                        cout << "Nome: " << cliente.Nome << endl;
                        cout << "Data de Nascimento: " << cliente.DtNascimento << endl;
                        cout << "CNH: " << cliente.CNH << endl;

                        cout << "Deseja alterar o Nome? (S/N): ";
                        char escolha;
                        cin >> escolha;
                
                        if (escolha == 'S' || escolha == 's') {
                            cout << "Novo Nome: ";
                            cin.ignore();
                            getline(cin, cliente.Nome);
                        }

                        cout << "Deseja alterar o CPF? (S/N): ";
                        cin >> escolha;
                
                        if (escolha == 'S' || escolha == 's') {
                            cout << "Novo CPF: ";
                            cin >> cliente.CPF;
                        }

                        cout << "Deseja alterar a data de nascimento? (S/N): ";
                        cin >> escolha;
                
                        if (escolha == 'S' || escolha == 's') {
                            cout << "Nova data de nascimento: ";
                            cin >> cliente.DtNascimento;
                        }

                        cout << "Deseja alterar a CNH? (S/N): ";
                        cin >> escolha;
                
                        if (escolha == 'S' || escolha == 's') {
                            cout << "Nova CNH: ";
                            cin >> cliente.CNH;
                        }

                        cout << "Cliente alterado!" << endl;
                        break;

                    }
                }

                break;
            }

            case 4:
                listarClientes(clientes);
                break;
            
            case 5: {
                string CPF;
                
                cout << "Informe o CPF do cliente a ser localizado: ";
                cin >> CPF;
                
                localizarCliente(clientes, CPF);
                break;

            }

            case 0:
            
                cout << "Cadastro finalizado." << endl;
                return 0;
            
            default:
            
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}