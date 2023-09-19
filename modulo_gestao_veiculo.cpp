#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct Veiculo {
    string Renavam;
    string Placa_do_Veiculo;
    string Data_Hora_Retirada;
    string Data_Hora_Entrega;
    string Loja_Retirada;

    Veiculo(string Renavam, string Placa_do_Veiculo, string Data_Hora_Retirada, string Data_Hora_Entrega, string Loja_Retirada) {
        this->Renavam = Renavam;
        this->Placa_do_Veiculo = Placa_do_Veiculo;
        this->Data_Hora_Retirada = Data_Hora_Retirada;
        this->Data_Hora_Entrega = Data_Hora_Entrega;
        this->Loja_Retirada = Loja_Retirada;
    }
};

vector<Veiculo> veiculos;

void incluir_Veiculo() {
    string Renavam, Placa_do_Veiculo, Data_Hora_Retirada, Data_Hora_Entrega, Loja_Retirada;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Incluir Veiculo:" << endl;
    cout << " " << endl;
    
    cout << "Digite o Renavam do veiculo: ";
    cin >> Renavam;
    cout << "Digite a Placa do veiculo: ";
    cin.ignore();
    getline(cin, Placa_do_Veiculo);
    cout << "Digite a Data e Hora para retirada do veiculo: ";
    cin >> Data_Hora_Retirada;
    cout << "Digite a Data e Hora para entrega do veiculo: ";
    cin >> Data_Hora_Entrega;
    cout << "Digite Loja de Retirada do veiculo: ";
    cin >> Loja_Retirada;

    Veiculo veiculo(Renavam, Placa_do_Veiculo, Data_Hora_Retirada, Data_Hora_Entrega, Loja_Retirada);
    veiculos.push_back(veiculo);

    cout << "Veiculo adicionado com sucesso!" << endl;
    cout << " " << endl;

}

void excluir_Veiculo() {
    string Placa_do_Veiculo;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Excluir Veiculo:" << endl;
    cout << " " << endl;

    cout << "Digite a Placa do veiculo a ser excluído: ";
    cin >> Placa_do_Veiculo;
    cout << " " << endl;

    for (int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].Placa_do_Veiculo == Placa_do_Veiculo) {
            veiculos.erase(veiculos.begin() + i);
            cout << "Veiculo removido com sucesso!" << endl;
            cout << " " << endl;

            return;
        }
    }

    cout << "Veiculo não encontrado." << endl;
    cout << " " << endl;
}

void alterar_Veiculo() {
    string Placa_do_Veiculo;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;
    
    cout << "Alterar Veiculo:" << endl;
    cout << " " << endl;

    cout << "Digite a Placa do veiculo a ser alterado: ";
    cin >> Placa_do_Veiculo;
    cout << " " << endl;

    for (int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].Placa_do_Veiculo == Placa_do_Veiculo) {
            
            cout << "Dados do veiculo:" << endl;
            cout << " " << endl;

            cout << "Renavam: " << veiculos[i].Renavam << endl;
            cout << "Placa do Veiculo: " << veiculos[i].Placa_do_Veiculo << endl;
            cout << "Data e Hora da Retirada: " << veiculos[i].Data_Hora_Retirada << endl;
            cout << "Data e Hora da Entrega: " << veiculos[i].Data_Hora_Entrega<< endl;
            cout << "Loja de Retirada: " << veiculos[i].Loja_Retirada << endl;
            cout << " " << endl;

            cout << "Deseja alterar o Renavam do Veiculo? (S/N): ";
            char opcao;
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo Renavam: ";
                cin.ignore();
                getline(cin, veiculos[i].Renavam);
            }

            cout << "Deseja alterar data e hora da retirada do veículo ? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite a nova data e hora da retirada: ";
                cin >> veiculos[i].Data_Hora_Retirada;
            }

            cout << "Deseja alterar a data e hora da entrega do veículo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o nova data e hora da entrega: ";
                cin >> veiculos[i].Data_Hora_Entrega;
            }

            cout << "Deseja alterar o local da retirada do veículo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Digite o novo local da retira: ";
                cin >> veiculos[i].Data_Hora_Entrega;
            }

            cout << " " << endl;
            cout << "Veiculo alterado com sucesso!" << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Veiculo não encontrado." << endl;
    cout << " " << endl;

}

void listar_Veiculos() {

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Lista de veiculos:" << endl;
    cout << " " << endl;

    for (const Veiculo& veiculo : veiculos) {
        
        cout << "Renavam: " << veiculo.Renavam << endl;
        cout << "Placa do Veiculo: " << veiculo.Placa_do_Veiculo << endl;
        cout << "Data e Hora da Retirada: " << veiculo.Data_Hora_Retirada << endl;
        cout << "Data e Hora da Entrega: " << veiculo.Data_Hora_Entrega<< endl;
        cout << "Loja de Retirada: " << veiculo.Loja_Retirada << endl;
        cout << " " << endl;
    }
}
 
void localizar_Veiculo() {
    string Placa_do_Veiculo;

    cout << "   GESTÃO DE VEÍCULO   " << endl;
    cout << "_______________________" << endl;
    cout << " " << endl;

    cout << "Localizar Veiculo:" << endl;
    cout << " " << endl;

    cout << "Digite a Placa do veiculo a ser localizado: ";
    cin >> Placa_do_Veiculo;
    cout << " " << endl;

    for (const Veiculo& veiculo : veiculos) {
        if (veiculo.Placa_do_Veiculo == Placa_do_Veiculo) {
            cout << "Dados do veiculo encontrado:" << endl;
            cout << " " << endl;

            cout << "Renavam: " << veiculo.Renavam << endl;
            cout << "Placa do Veiculo: " << veiculo.Placa_do_Veiculo << endl;
            cout << "Data e Hora da Retirada: " << veiculo.Data_Hora_Retirada << endl;
            cout << "Data e Hora da Entrega: " << veiculo.Data_Hora_Entrega<< endl;
            cout << "Loja de Retirada: " << veiculo.Loja_Retirada << endl;
            cout << " " << endl;
            
            return;
        }
    }

    cout << "Veiculo não encontrado." << endl;
    cout << " " << endl;

}

int main() {
    int opcao;

    while (true) {

        cout << "   GESTÃO DE VEÍCULO   " << endl;
        cout << "_______________________" << endl;
        cout << " " << endl;

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
                incluir_Veiculo();
                break;
            case 2:
                excluir_Veiculo();
                break;
            case 3:
                alterar_Veiculo();
                break;
            case 4:
                listar_Veiculos();
                break;
            case 5:
                localizar_Veiculo();
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
