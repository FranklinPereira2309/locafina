#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Veiculo {

    string Renavan;
    string Placa;
    string Nome;
    string DataRetirada;
    string HoraRetirada;
    string DataEntrega;
    string HoraEntrega;
    string LojaNome;
    string LojaEndereco;

};

string obterDataHoraAtual() {

    time_t agora = time(0);
    tm* tempoLocal = localtime(&agora);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d/%m", tempoLocal);

    return buffer;
}

string obterHoraAtual() {

    time_t agora = time(0);
    tm* tempoLocal = localtime(&agora);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M", tempoLocal);

    return buffer;
}

void incluirVeiculo(vector<Veiculo>& veiculos) {

    string Renavan, Placa, Nome, DataRetirada, HoraRetirada, DataEntrega, HoraEntrega, LojaNome, LojaEndereco;

    cout << "Informe o Renavan do veiculo: ";
    cin >> Renavan;

    cout << "Informe a Placa do veiculo: ";
    cin >> Placa;

    cout << "Informe o Nome do veiculo: ";
    cin.ignore();
    getline(cin, Nome);

    cout << "Informe a Data de Retirada (pre-vista) do veiculo (dd/mm): ";
    cin >> DataRetirada;

    cout << "Informe a Hora de Retirada (pre-vista) do veiculo (hh:mm): ";
    cin >> HoraRetirada;

    cout << "Informe a Data de Entrega (pre-vista) do veiculo (dd/mm): ";
    cin >> DataEntrega;

    cout << "Informe a Hora de Entrega (pre-vista) do veiculo (hh:mm): ";
    cin >> HoraEntrega;

    cout << "Informe o Nome da Loja de Retirada: ";
    cin.ignore();
    getline(cin, LojaNome);

    cout << "Informe o Endereco da Loja de Retirada: ";
    getline(cin, LojaEndereco);

    Veiculo novoVeiculo = {Renavan, Placa, Nome, DataRetirada, HoraRetirada, 
    DataEntrega, HoraEntrega, LojaNome, LojaEndereco};

    veiculos.push_back(novoVeiculo);
    cout << "Veiculo adicionado com sucesso!" << endl;

}

void excluirVeiculo(vector<Veiculo>& veiculos, const string& Placa) {

    for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {

        if (it->Placa == Placa) {

            veiculos.erase(it);
            cout << "Veiculo com Placa " << Placa << " excluido com sucesso!" << endl;

            return;
        }

    }

    cout << "Veiculo com Placa " << Placa << " nao encontrado." << endl;

}

void listarVeiculos(const vector<Veiculo>& veiculos) {

    cout << "Lista de Veiculos disponiveis:" << endl;

    for (const Veiculo& veiculo : veiculos) {

        cout << "Renavan: " << veiculo.Renavan << endl;
        cout << "Placa: " << veiculo.Placa << endl;
        cout << "Nome: " << veiculo.Nome << endl;
        cout << "Data de Retirada (pre-vista): " << veiculo.DataRetirada << endl;
        cout << "Hora de Retirada (pre-vista): " << veiculo.HoraRetirada << endl;
        cout << "Data de Entrega (pre-vista): " << veiculo.DataEntrega << endl;
        cout << "Hora de Entrega (pre-vista): " << veiculo.HoraEntrega << endl;
        cout << "Nome da Loja de Retirada: " << veiculo.LojaNome << endl;
        cout << "Endereco da Loja de Retirada: " << veiculo.LojaEndereco << endl;
        cout << endl;
    }
}

void localizarVeiculo(const vector<Veiculo>& veiculos, const string& Placa) {

    for (const Veiculo& veiculo : veiculos) {

        if (veiculo.Placa == Placa) {

            cout << "O veiculo " << veiculo.Nome << " com renavan " << veiculo.Renavan << " localizado na loja " 
                 << veiculo.LojaNome << " no endereco " << veiculo.LojaEndereco << ", estara disponivel para retirada no dia " 
                 << veiculo.DataRetirada << " as " << veiculo.HoraRetirada << ", com devolucao prevista no dia " 
                 << veiculo.DataEntrega << " as " << veiculo.HoraEntrega << "." << endl;

            return;

        }
    }

    cout << "Veiculo com Placa " << Placa << " nao encontrado." << endl;

}

int main() {

    vector<Veiculo> veiculos;

    while (true) {

        cout << "Digite o numero de uma das opcoes" << endl;
        cout << "1. Incluir Veiculo." << endl;
        cout << "2. Excluir Veiculo." << endl;
        cout << "3. Alterar Veiculo (apenas por Placa)." << endl;
        cout << "4. Listar Veiculos." << endl;
        cout << "5. Localizar Veiculo (por Placa)." << endl;
        cout << "0. Sair." << endl;

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluirVeiculo(veiculos);
                break;

            case 2: {
                string Placa;
                cout << "Informe a Placa do veiculo a ser excluido: ";
                cin >> Placa;
                excluirVeiculo(veiculos, Placa);
                break;

            }

            case 3: {

                string Placa;

                cout << "Informe a Placa do veiculo a ser alterado: ";
                cin >> Placa;

                for (Veiculo& veiculo : veiculos) {

                    if (veiculo.Placa == Placa) {

                        cout << "Renavan: " << veiculo.Renavan << endl;
                        cout << "Placa atual: " << veiculo.Placa << endl;
                        cout << "Nome atual: " << veiculo.Nome << endl;
                        cout << "Data de Retirada (pre-vista) atual: " << veiculo.DataRetirada << endl;
                        cout << "Hora de Retirada (pre-vista) atual: " << veiculo.HoraRetirada << endl;
                        cout << "Data de Entrega (pre-vista) atual: " << veiculo.DataEntrega << endl;
                        cout << "Hora de Entrega (pre-vista) atual: " << veiculo.HoraEntrega << endl;
                        cout << "Nome da Loja de Retirada atual: " << veiculo.LojaNome << endl;
                        cout << "Endereco da Loja de Retirada atual: " << veiculo.LojaEndereco << endl;

                        cout << "Deseja alterar a Placa? (S/N): ";
                        char escolha;
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Nova Placa: ";
                            cin >> veiculo.Placa;
                        }

                        cout << "Deseja alterar o Nome? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Novo Nome: ";
                            cin.ignore();
                            getline(cin, veiculo.Nome);
                        }

                        cout << "Deseja alterar a Data de Retirada (pre-vista)? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Nova Data de Retirada (pre-vista) (dd/mm): ";
                            cin >> veiculo.DataRetirada;
                        }

                        cout << "Deseja alterar a Hora de Retirada (pre-vista)? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Nova Hora de Retirada (pre-vista) (hh:mm): ";
                            cin >> veiculo.HoraRetirada;
                        }

                        cout << "Deseja alterar a Data de Entrega (pre-vista)? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Nova Data de Entrega (pre-vista) (dd/mm): ";
                            cin >> veiculo.DataEntrega;
                        }

                        cout << "Deseja alterar a Hora de Entrega (pre-vista)? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Nova Hora de Entrega (pre-vista) (hh:mm): ";
                            cin >> veiculo.HoraEntrega;
                        }

                        cout << "Deseja alterar o Nome da Loja de Retirada? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Novo Nome da Loja de Retirada: ";
                            cin.ignore();
                            getline(cin, veiculo.LojaNome);
                        }

                        cout << "Deseja alterar o Endereço da Loja de Retirada? (S/N): ";
                        cin >> escolha;

                        if (escolha == 'S' || escolha == 's') {

                            cout << "Novo Endereço da Loja de Retirada: ";
                            cin.ignore();
                            getline(cin, veiculo.LojaEndereco);
                        }

                        cout << "Veiculo alterado com sucesso!" << endl;

                        break;
                    }
                }

                break;
            }

            case 4:
                listarVeiculos(veiculos);

                break;

            case 5: {

                string Placa;

                cout << "Informe a Placa do veiulo a ser localizado: ";
                cin >> Placa;
                localizarVeiculo(veiculos, Placa);

                break;
            }

            case 0:

                cout << "Programa encerrado." << endl;

                return 0;

            default:

                cout << "Opcao inválida. Tente novamente." << endl;
        }
    }

return 0;

}