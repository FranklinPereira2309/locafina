#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cliente {
    string nome;
    string cpf;
    string dataNascimento;
    string numeroCNH;
};

struct Veiculo {
    string renavam;          
    string placa;            
    string horaRetirada;    
    string horaEntrega;      
    string lojaRetirada;  
};
// funcai para incuir clientes e adicionar em um vetor
void incluirCliente(vector<Cliente> &agendaClientes) {
    Cliente cliente;

    cout << "Digite o nome do cliente: ";
    getline(cin, cliente.nome);

    cout << "Digite o CPF: ";
    getline(cin, cliente.cpf);

    cout << "Digite a data de nascimento: ";
    getline(cin, cliente.dataNascimento);

    cout << "Digite o numero da CNH: ";
    getline(cin, cliente.numeroCNH);

    agendaClientes.push_back(cliente);
    cout << "Cliente adicionado com sucesso!" << endl;
}
// funcao para realizar a exclusao de cliente
void excluirCliente(vector<Cliente> &agendaClientes) {
    string cpf;
    cout << "Digite o CPF do Cliente a ser excluido: ";
    getline(cin, cpf);

    auto it = agendaClientes.begin();
    while (it != agendaClientes.end()) {
        if (it->cpf == cpf) {
            it = agendaClientes.erase(it);
            cout << "Cliente removido com sucesso!" << endl;
        } else {
            ++it;
        }
    }
}
// funcao para alterar os dados de um cliente
void alterarCliente(vector<Cliente> &agendaClientes) {
    string cpf;
    cout << "Digite o CPF do Cliente a ser alterado: ";
    getline(cin, cpf);

    for (auto &cliente : agendaClientes) {
        if (cliente.cpf == cpf) {
            cout << "Dados do Cliente:" << endl;
            cout << "Nome: " << cliente.nome << ", CPF: " << cliente.cpf << ", Data de Nascimento: " << cliente.dataNascimento << ", CNH: " << cliente.numeroCNH << endl;

            cout << "Deseja alterar o Nome? (S/N): ";
            char resposta;
            cin >> resposta;
            cin.ignore(); 

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite o novo nome: ";
                getline(cin, cliente.nome);
            }

            cout << "Deseja alterar a Data de Nascimento? (S/N): ";
            cin >> resposta;
            cin.ignore(); 

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite a nova data de nascimento: ";
                getline(cin, cliente.dataNascimento);
            }

            cout << "Deseja alterar o Numero da CNH? (S/N): ";
            cin >> resposta;
            cin.ignore(); 

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite o novo numero da CNH: ";
                getline(cin, cliente.numeroCNH);
            }

            cout << "Cliente alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "Cliente com CPF " << cpf << " nao encontrado na agenda." << endl;
}
// funcao para listar clientes cadastrados
void listarClientes(const vector<Cliente> &agendaClientes) {
    if (agendaClientes.empty()) {
        cout << "A agenda de clientes esta vazia." << endl;
    }

    cout << "Lista de Clientes na Agenda:" << endl;
    for (const auto &cliente : agendaClientes) {
        cout << "Nome: " << cliente.nome << ", CPF: " << cliente.cpf << ", Data de Nascimento: " << cliente.dataNascimento << ", CNH: " << cliente.numeroCNH << endl;
    }
}
/*
    A partir daqui é o modulo de veiculos
*/

// funcao para incluir veiculos em um vetor
void incluirVeiculo(vector<Veiculo> &veiculos) {
    Veiculo veiculo;

    cout << "Digite o Renavam: ";
    getline(cin, veiculo.renavam);

    cout << "Digite a placa: ";
    getline(cin, veiculo.placa);

    cout << "Digite a hora de retirada: ";
    getline(cin, veiculo.horaRetirada);

    cout << "Digite a hora da entrega: ";
    getline(cin, veiculo.horaEntrega);

    cout << "Digite a loja de retirada: ";
    getline(cin, veiculo.lojaRetirada);

    veiculos.push_back(veiculo);
    cout << "Veiculo adicionado com sucesso!" << endl;
}
// funcao para excluir veiculo
void excluirVeiculo(vector<Veiculo> &veiculos) {
    string placa;
    cout << "Digite a placa do veiculo a ser excluido: ";
    getline(cin, placa);

    auto it = veiculos.begin();
    while (it != veiculos.end()) {
        if (it->placa == placa) {
            it = veiculos.erase(it);
            cout << "Veiculo removido com sucesso!" << endl;
        } else {
            ++it;
        }
    }
}
// funcao para alterar veiculo
void alterarVeiculo(vector<Veiculo> &veiculos) {
    string placa;
    cout << "Digite a placa do veiculo a ser alterado: ";
    getline(cin, placa);

    for (auto &veiculo : veiculos) {
        if (veiculo.placa == placa) {
            cout << "Dados do Veiculo:" << endl;
            cout << "Renavam: " << veiculo.renavam << ", Placa: " << veiculo.placa << endl;
            cout << "Hora de Retirada: " << veiculo.horaRetirada << ", Hora da Entrega: " << veiculo.horaEntrega << ", Loja de Retirada: " << veiculo.lojaRetirada << endl;

            cout << "Deseja alterar a Placa? (S/N): ";
            char resposta;
            cin >> resposta;
            cin.ignore();

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite a nova placa: ";
                getline(cin, veiculo.placa);
            }

            cout << "Deseja alterar a hora de retirada? (S/N): ";
            cin >> resposta;
            cin.ignore();

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite a nova hora de retirada: ";
                getline(cin, veiculo.horaRetirada);
            }

            cout << "Deseja alterar a hora da entrega? (S/N): ";
            cin >> resposta;
            cin.ignore();

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite a nova hora da entrega: ";
                getline(cin, veiculo.horaEntrega);
            }

            cout << "Deseja alterar a loja de retirada? (S/N): ";
            cin >> resposta;
            cin.ignore();

            if (resposta == 'S' || resposta == 's') {
                cout << "Digite a nova loja de retirada: ";
                getline(cin, veiculo.lojaRetirada);
            }

            cout << "Veiculo alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "Veiculo com placa " << placa << " nao encontrado na colecao." << endl;
}
// funcao paa listar veiculos 
void listarVeiculos(const vector<Veiculo> &veiculos) {
    if (veiculos.empty()) {
        cout << "A lista de veiculos esta vazia." << endl;
    }

    cout << "Lista de Veiculos:" << endl;
    for (const auto &veiculo : veiculos) {
        cout << "Renavam: " << veiculo.renavam << ", Placa: " << veiculo.placa << endl;
        cout << "Hora de Retirada: " << veiculo.horaRetirada << ", Hora da Entrega: " << veiculo.horaEntrega << ", Loja de Retirada: " << veiculo.lojaRetirada << endl;
    }
}

int main() {
    vector<Cliente> agendaClientes;
    vector<Veiculo> veiculos;

    while (true) {
        cout << " ------------ Gestao de Clientes e Veiculos ------------";
        cout << "\nMenu:\n";
        cout << "1 - Cadastrar Cliente\n";
        cout << "2 - Excluir Cliente\n";
        cout << "3 - Alterar Cliente\n";
        cout << "4 - Listar Clientes\n";
        cout << "\n\n";
        cout << "5 - Cadastrar Veiculo\n";
        cout << "6 - Excluir Veiculo\n";
        cout << "7 - Alterar Veiculo\n";
        cout << "8 - Listar Veiculos\n";
        cout << "\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";

        int opcaoSelecionada;
        cin >> opcaoSelecionada;
        cin.ignore();

        switch (opcaoSelecionada) {
            case 1:
                incluirCliente(agendaClientes);
                break;
            case 2:
                excluirCliente(agendaClientes);
                break;
            case 3:
                alterarCliente(agendaClientes);
                break;
            case 4:
                listarClientes(agendaClientes);
                break;
            case 5:
                incluirVeiculo(veiculos);
                break;
            case 6:
                excluirVeiculo(veiculos);
                break;
            case 7:
                alterarVeiculo(veiculos);
                break;
            case 8:
                listarVeiculos(veiculos);
                break;
            case 0:
                cout << "Programa finalizado." << endl;
                return 0;
            default:
                cout << "Opcao invalida, por favor, tente novamente." << endl;
        }
    }
    return 0;
}
