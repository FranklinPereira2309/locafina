#include <iostream>

using namespace std;

int main(){
    cout << "Selecione a opcao do que deseja fazer:\n\n ";
    cout << "1 - Incluir\n 2 - Excluir\n 3 - Alterar\n 4 - Listar\n 5 - Localizar\n 6 - Sair\n\n";
    int opcaoSelecionada;
    cin >> opcaoSelecionada;
    
    switch(opcaoSelecionada){
        case 1:
            cout << "Voce escolheu a opcao 1\n";
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
    }
    return 0;
}