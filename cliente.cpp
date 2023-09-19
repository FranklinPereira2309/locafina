#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct Cliente
{
    string nome, cpf, cnh, dtNascimento;

    Cliente(string stNome, string stCpf, string stCnh, string stDtNascimento) {
        this->nome = stNome;
        this->cpf = stCpf;
        this->cnh = stCnh;
        this->dtNascimento = stDtNascimento;
    }

};

vector<Cliente> clienteVetor;

void incluir() {
        
    string nome, cpf,cnh, dtNascimento;
    

    cout << "Menu INCLUIR\n";
    cout << "===================\n\n";
    cout << "Digite o Primeiro Nome e Último Sobrenome: ";
    getline(cin >> ws, nome);
    cout << "Digite cpf(11 dígitos): ";
    getline(cin >> ws, cpf);
    cout << "Digite sua CNH(11 dígitos): ";
    getline(cin >> ws, cnh);
    cout << "Digite sua data de Nascimento(dd/mm/aaaa): ";
    getline(cin >> ws, dtNascimento);
    clienteVetor.push_back(Cliente(nome, cpf,cnh, dtNascimento));
    
   

    system("clear");
}

void excluir() 
{
    system("clear");
    cout << "Menu EXCLUIR\n";
    cout << "===================\n\n";
    int tam,nulo;
    tam = clienteVetor.size();
    string cpf;
    cout << "Informar o cpf para exlusão: ";
    getline(cin >> ws, cpf);
    for(int i =0; i < tam; i++) {
            
        if(cpf == clienteVetor[i].cpf) {
            clienteVetor.erase(clienteVetor.begin()+i);
            cout << "\nRegistro Excluído com Sucesso!\n";
            cout << endl;
            
        }
    }
    cout << "\n0- Sair\n";
    cin >> nulo;
    cout << endl;
    
                
}

void alterar(){ 
        system("clear");
        int tam;
        int opcao;
        int sairAlterar = true;
        string cpf, nome, cnh, dtNascimento;
        tam = clienteVetor.size();
        //Cliente novoCliente;        
        cout << "Menu ALTERAR\n";
        cout << "===================\n\n";
        cout << "Favor digitar o cpf: ";
        getline(cin >> ws, cpf);
        for(int i =0; i < tam; i++) {
            if(cpf == clienteVetor[i].cpf) {
                while(sairAlterar) {
                    cout << "1- Deseja alterar o nome?\n";
                    cout << "2- Deseja alterar o cnh?\n";
                    cout << "3- Deseja alterar a data de nascimento?\n";
                    cout << "0- Sair?\n";
                    cin >> opcao;
                    sairAlterar = opcao == 0? false: true;

                    switch (opcao)
                    {
                    case 1:
                        cout << "Digite o novo nome: ";
                        getline(cin >> ws, nome);
                        clienteVetor[i].nome = nome;
                        cout << "\nNome alterado com sucesso!\n";
                        nome=" ";
                        system("clear");
                        break;
                    case 2:
                        cout << "Digite a nova cnh: ";
                        getline(cin >> ws, cnh);
                        clienteVetor[i].cnh = cnh;
                        cout << "\nCnh alterada com sucesso!\n";
                        cnh=" ";
                        system("clear");
                        break;
                    case 3:
                        cout << "Digite a nova data de nascimento: ";
                        getline(cin >> ws, dtNascimento);
                        clienteVetor[i].dtNascimento = dtNascimento;
                        cout << "\nData de Nascimento alterada com sucesso!\n";
                        dtNascimento=" ";
                        system("clear");
                        break;
                    
                    default:
                        break;
                    }
                    

                }
            }
            
            


        }
        system("clear");
        
        
}



void listar() 
{
        
        system("clear");
        int tam, nulo;
        tam = clienteVetor.size();
        //Cliente novoCliente;        
        cout << "Menu LISTAR\n";
        cout << "===================\n\n";
        
        cout << "Nome\t\t\t" <<  "CPF\t\t" << "CNH\t\t" << "Data de Nascimento" << endl;
        cout << "=====================================================================================\n";
        for(int i =0; i < tam; i++) {
           cout << clienteVetor[i].nome << "\t" << clienteVetor[i].cpf << "\t " << clienteVetor[i].cnh << "\t" << clienteVetor[i].dtNascimento << endl;
        }
        cout << "\n0- Sair\n";
        cin >> nulo;
        cout << endl;
        system("clear");
}

void localizar() 
{
        string cpf;
        int tam, nulo;
        tam = clienteVetor.size();
        
        cout << "Menu LOCALIZAR\n";
        cout << "===================\n\n";
        cout << "Digite o cpf: ";
        getline(cin >> ws, cpf);
        cout << endl;
        
        cout << "\nNome\t\t\t" <<  "CPF\t\t" << "CNH\t\t" << "Data de Nascimento" << endl;
        cout << "=====================================================================================\n";
        for(int i =0; i < tam; i++) {
            if(cpf == clienteVetor[i].cpf) {
                cout << clienteVetor[i].nome << "\t" << clienteVetor[i].cpf << "\t " << clienteVetor[i].cnh << "\t" << clienteVetor[i].dtNascimento << endl;
                
            }
        }
        cout << "\n0- Sair\n";
        cin >> nulo;
        cout << endl;
        system("clear");
       
    }


void menu() {
    int opcao=1; 
    bool sair = true;
    string cpf;


    while(sair) {
        cout << "\n* Cadastro de Pessoas *\n";
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

    cout << "Obrigado... Volte sempre!" << endl;;

    return 0;
}