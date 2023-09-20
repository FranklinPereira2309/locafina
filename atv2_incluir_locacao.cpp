#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cadastro {
    string CNH;
    string placa;
    string nome;
    string dataNascimento;
    string CPF;
    string renavan;
    string dataHoraRetirada;
    string dataHoraDevolucao;
};

struct RegistroLocacao {
    string CNH;
    string placa;
    string dataRetirada;
    char retiradaAconteceu;
};

vector<RegistroLocacao> registrosLocacao;
const int tamanhoCadastro = 5;
Cadastro cadastros[tamanhoCadastro];

bool checarDados(const Cadastro cadastro[], int tamanho, string CNH, string placa) {
    for (int i = 0; i < tamanho; i++) {
        if (cadastro[i].CNH == CNH && cadastro[i].placa == placa) {
            // Todos os dados estão corretos
            return true;
        }
    }
    // Dados não encontrados no cadastro
    return false;
}

void SolicitarInformacoesRetirada(RegistroLocacao& registro) {
    cout << "Digite a data real de retirada do veículo (dd/mm/aaaa): ";
    cin >> registro.dataRetirada;

    cout << "A retirada do carro já aconteceu? (S/s para sim, N/n para não): ";
    cin >> registro.retiradaAconteceu;
}

int main() {
    // Preencha o cadastro com dados exemplo
    cadastros[0] = {"12345678", "ABC1234", "João Silva", "01/01/1990", "123456789", "987654321", "01/01/2022 08:00", "01/01/2022 18:00"};
    cadastros[1] = {"87654321", "DEF5678", "Maria Santos", "05/05/1985", "987654321", "123456789", "02/01/2022 09:00", "03/01/2022 17:00"};
    // ...

    string CNH, placa, opcao;

    cout << "Digite o número da CNH do passageiro: ";
    cin >> CNH;

    cout << "Digite a placa do veículo: ";
    cin >> placa;

    if (checarDados(cadastros, tamanhoCadastro, CNH, placa)) {
        cout << "Dados verificados: CNH e placa estao corretos." << endl;

        RegistroLocacao registro;
        registro.CNH = CNH;
        registro.placa = placa;
        
        cout << "Deseja registrar a locacao? (S/s para sim, N/n para nao): ";
        cin >> opcao;

        if (opcao == "S" || opcao == "s") {
            SolicitarInformacoesRetirada(registro);

            registrosLocacao.push_back(registro);

            cout << "Locacao registrada com sucesso." << endl;
        } else {
            cout << "Registro de locacao cancelado." << endl;
        }
    } else {
        cout << "Erro: CNH ou placa não encontrados no cadastro." << endl;
    }

    // Exibir registros de locação
    cout << "Registros de Locacao:" << endl;
    for (const RegistroLocacao& registro : registrosLocacao) {
        cout << "CNH do Passageiro: " << registro.CNH << endl;
        cout << "Placa do Veículo: " << registro.placa << endl;
        cout << "Data Real de Retirada: " << registro.dataRetirada << endl;
        cout << "Retirada Aconteceu: " << (registro.retiradaAconteceu == 'S' || registro.retiradaAconteceu == 's' ? "Sim" : "Não") << endl;
    }

    cout << "\n";
    return 0;
}
