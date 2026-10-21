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


}




