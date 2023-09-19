#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct Veiculo
{
    string renavam, placaVeiculo, dataHoraRetirada, dataHoraEntrega, lojaRetirada;

    Veiculo(string stRenavam, string stPlacaVeiculo, string stDataHoraRetirada, string stDataHoraEntrega, string stLojaRetirada ) {
        this->renavam=stRenavam;
        this->placaVeiculo=stPlacaVeiculo;
        this->dataHoraRetirada=stDataHoraRetirada;
        this->dataHoraEntrega=stDataHoraEntrega;
        this->lojaRetirada=stLojaRetirada;

    }
};

vector<Veiculo> vetorVeiculo;

void incluir() 
{
    string renavam, placa, dtRetirada, dtEntrega, lojaRetirada;
    cout << "\nMenu Incluir\n";
    cout << "\n===================\n";
    cout << endl;
    cout << "Digite o Renavam(11 dígitos):";
    getline(cin >> ws, renavam);
    cout << "Digite a Placa(pkj-3d19):";
    getline(cin >> ws, placa);
    cout << "Digite a Data e Hora da Retirada(dd/mm/aa hh:mm):";
    getline(cin >> ws, dtRetirada );
    cout << "Digite a Data e Hora da Entrega(dd/mm/aa hh:mm):";
    getline(cin >> ws, dtEntrega);
    cout << "Digite o Endereço da Retirada:";
    getline(cin >> ws, lojaRetirada);
    vetorVeiculo.push_back(Veiculo(renavam,placa,dtRetirada,dtEntrega,lojaRetirada));
    system("clear");
}

void excluir() 
{
    string placa;
    int tam,nulo;
    tam=vetorVeiculo.size();
    cout << "\nMenu Excluir\n";
    cout << "\n===================\n";
    cout << "Informe a Placa do Veículo:";
    getline(cin >> ws, placa);
    for(int i=0; i < tam; i++) {
        if(placa == vetorVeiculo[i].placaVeiculo) {
            vetorVeiculo.erase(vetorVeiculo.begin()+i);
            cout << "\nVeículo excluído com Sucesso!\n";
        }
    }
    cout << "\n0- Sair\n";
    cin >> nulo;
    cout << endl;
    
}

void alterar() 
{
    system("clear");
    string renavam, placa, dtRetirada, dtEntrega, lojaRetirada;
    int tam, opcao;
    bool sairAlterar=true;
    tam=vetorVeiculo.size();
    cout << "\nMenu Alterar\n";
    cout << "\n===================\n";
    for(int i=0; i < tam; i++) {
        cout << "Digite a placa do Veículo:";
        getline(cin >> ws, placa);
        if(placa == vetorVeiculo[i].placaVeiculo) {
            while(sairAlterar) {
                cout << "1- Deseja alterar o Renavam?\n ";
                cout << "2- Deseja alterar a data e hora da Retirada?\n ";
                cout << "3- Deseja alterar a data e hora da Entrega?\n ";
                cout << "4- Deseja alterar a Loja de Retirada?\n ";
                cout << "0- Sair?\n ";
                cin >> opcao;
                sairAlterar = opcao == 0? false: true;
                
                switch (opcao)
                {
                case 1:
                    cout << "Informe o novo Renavam:";
                    getline(cin >> ws, renavam);
                    vetorVeiculo[i].renavam= renavam;
                    cout << "\nRenavam alterado com Sucesso!\n";
                    renavam=" ";
                    system("clear");
                    break;
                case 2:
                    cout << "Informe a nova Data e Hora:";
                    getline(cin >> ws, dtRetirada);
                    vetorVeiculo[i].dataHoraRetirada= dtRetirada;
                    cout << "\nData e hora alterada com Sucesso!\n";
                    dtRetirada=" ";
                    system("clear");
                    break;
                case 3:
                    cout << "Informe a nova Data e Hora:";
                    getline(cin >> ws, dtRetirada);
                    vetorVeiculo[i].dataHoraEntrega= dtEntrega;
                    cout << "\nData e hora alterada com Sucesso!\n";
                    dtEntrega=" ";
                    system("clear");
                    break;
                case 4:
                    cout << "Informe a nova Loja:";
                    getline(cin >> ws, lojaRetirada);
                    vetorVeiculo[i].lojaRetirada= lojaRetirada;
                    cout << "\nLoja para Retirada alterada com Sucesso!\n";
                    lojaRetirada=" ";
                    system("clear");
                    break;
                default:
                    break;
                }
            }
        }
    }
    system("clear");
    placa=" ";
}

void listar() 
{
    system("clear");
    string renavam, placa, dtRetirada, dtEntrega, lojaRetirada;
    int tam, nulo;
    tam=vetorVeiculo.size();
    cout << "\nMenu Listar\n";
    cout << "\n===================\n";
    cout << endl;
    cout << "RENAVAM\t\t" <<  "PLACA\t\t" << "Retirada\t\t" << "ENTREGA\t\t" << "\tENDEREÇO\t" << lojaRetirada <<  endl;
        cout << "===================================================================================================================\n";
        for(int i =0; i < tam; i++) {
           cout << vetorVeiculo[i].renavam << "\t" << vetorVeiculo[i].placaVeiculo << "\t " 
           << vetorVeiculo[i].dataHoraRetirada<< "\t" << vetorVeiculo[i].dataHoraEntrega << "\t"
           << vetorVeiculo[i].lojaRetirada << endl;
            
        }
        cout << "\n0 - Sair: ";
        cin >> nulo;
        system("clear");
        
}

void localizar() 
{
    system("clear");
    string renavam, placa, dtRetirada, dtEntrega, lojaRetirada;
    int tam, nulo;
    tam=vetorVeiculo.size();

    cout << "\nMenu Localizar\n";
    cout << "\n===================\n";
    cout << "\nDigite a Placa: ";
    getline(cin >> ws, placa);
    cout << endl;

    cout << "RENAVAM\t\t" <<  "PLACA\t\t" << "Retirada\t\t" << "ENTREGA\t\t" << "\tENDEREÇO" << lojaRetirada <<  endl;
        cout << "===================================================================================================================\n";
        for(int i =0; i < tam; i++) {
            if(placa == vetorVeiculo[i].placaVeiculo){
                cout << vetorVeiculo[i].renavam << "\t" << vetorVeiculo[i].placaVeiculo << "\t " 
                << vetorVeiculo[i].dataHoraRetirada<< "\t" << vetorVeiculo[i].dataHoraEntrega << "\t"
                << vetorVeiculo[i].lojaRetirada << endl;
            }
        }
        cout << "\n0 - Sair: ";
        cin >> nulo;
        system("clear");
}

void menu() {
    int opcao=1; 
    bool sair = true;
    string cpf;
    while(sair) {
        cout << "\n* Cadastro de Veículos *\n";
        cout << "\n=======================\n";
        cout << "1- Incluir " << endl;
        cout << "2- Excluir"  << endl;
        cout << "3- Alterar" << endl;
        cout << "4- Listar" << endl;
        cout << "5- Localizar" << endl;
        cout << "0- Sair" << endl;
        cin >> opcao;
        sair = opcao == 0? false : true;

        system("clear");

        if(opcao >= 0 && opcao <= 5) {

            switch (opcao)
            {
            
        case 1:
            incluir();
            break;
        case 2:
            excluir();
            break;
        case 3:
            alterar();
            break;
        case 4:
           listar();
            break;
        case 5:
            localizar();            
            break;
        default:
            break;;
        }
        }else {
            cout << "\nOpção Inválida!" << endl;
        }

    }
}

int main() {
    menu();

    cout << "\nBye... Até mais!\n";
    return 0;
}