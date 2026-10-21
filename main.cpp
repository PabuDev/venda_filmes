#include <iostream>
#include <string>
#include <cstring> //Vê depois essa biblioteca


const int qtd_sala = 10;

using namespace std;

struct Filme{
    char titulo[50];
    int classificacao_filme;
    int ingressos_filme;
    float preco_filme;
};

struct RegistroVendasFilme{
    char titulo[25];
    float valor_venda_filme;
};

int cadastrarFilme( Filme filme[], int tamanho);
void exibirTabelaFilmes(const Filme filme[], int cadastados);
bool venderIngressos(Filme filme[], int tamanho, const char* titulo, int qtd, float& valor_total);
void salvarVenda(const char* titulo, float valor);

int main(){
    Filme cinema[qtd_sala];
    int filmes_cadastrado = 0;
    int opcao;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);

    do{
        cout << "\n --- MENU MULTICE UCS ---\n";
        cout << "1 - Cadastrar filmes. (até " << qtd_sala << " )" << endl;
        cout << "2 - Vender ingressos." << endl;
        cout << "3 - Ver Lucro Total do Cinema." << endl;
        cout << "4 - Sair" << endl;
        cin >> opcao;
        cin.ignore();
        switch (opcao)
        {
        case 1:
            filmes_cadastrado = cadastrarFilme(cinema, qtd_sala);
            break;
        case 2:
            if(filmes_cadastrado == 0){
                cout << endl << "[AVISO]: Nenhum filme cadastrado no momento!" << endl;
            }
            break;
            char titulo_busca[50];
            int qtd_desejada;
            float valor_final = 0.0;

            cout << endl << "--- Venda de Ingressos --- " << endl;
            cout << "------ UCS ------" << endl;
            exibirTabelaFilmes(cinema, filmes_cadastrado);

            cout << endl << "Digite o titulo do filme: ";
            cin.getline(titulo_busca, 50);

            cout << "Quantidade de ingressos: ";
            cin >> qtd_desejada;
            cin.ignore();

            if (venderIngressos(cinema, filmes_cadastrado, titulo_busca, qtd_desejada, valor_final)){
                cout << "Venda realizada com sucesso! Valor total: R$ " << valor_final << endl;
                salvarVenda(titulo_busca, valor_final);
            } else {
                cout << "Falha na venda!" << endl << "Verifique o titulo, estoque ou quantidade digitada." << endl;
            }
            break;
        case 3:
            calcularLucroTotal();
            break;
        case 0:
            cout << "Saindo do Sistema..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
        }
    }while(opcao != 0);

    return 0;

}

int cadastrarFilmes(Filme filme[], int tamanho){
    int i;
    char continuar;

    cout << endl << " --- Cadastro de Filmes --- " << endl;

    for (i = 0; i < tamanho; i++){
        cout << endl << "Sala " << (i + 1) << endl;
        cout << "Titulo do Filme: ";
        cin.getline(filme[i].titulo, 50);

        cout << "Classificacao do filme: ";
        cin >> filme[i].classificacao_filme;

        cout << "Quantidade de ingressos disponiveis: ";
        cin >> filme[i].ingressos_filme;

        cout << "Preco do ingresso: R$ ";
        cin >> filme[i].preco_filme;
        cin.ignore();

        if(i < tamanho - 1){
            cout << "Deseja cadastrar a proxima sala? (S/N): ";
            cin >> continuar;
            cin.ignore();
            if (continuar == 'n' || continuar == 'N'){
                i++;
                break;
            }
        }
    }
    cout << endl << "Cadastro finalizado! Total de filmes registrados: " << i << endl;

    return i;
}




