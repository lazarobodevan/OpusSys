//
// Created by lazarus on 12/01/20.
//
#include <stdio.h>
typedef struct{
    char nome[25];
    int categoria;
    double preco;
    int qtdPratileira;
    int qtdEstoque;
    char validade[11];
    int codigo;
}TProduto;

typedef struct CelulaProduto{
    TProduto produto;
    struct CelulaProduto *pProx, *pAnte;
}TCelulaProduto;

typedef struct {
    TCelulaProduto *pPrim, *pUlt;
}TProdutos;


//--> Lista Encadeada de Produtos para compor um carrinho
typedef struct CelulaCarrinho{
    TProduto produto;
    int quantidade;
    struct CelulaCarrinho *pProx;
}TCelulaCarrinho; //Celula contendo o produto

typedef struct {
    TCelulaCarrinho *pPrim, *pUlt;
}TCarrinho;


int iniciaProdutos(TProdutos *produtos);
int alocaProduto(TProdutos *produtos);
int cadastrarProduto(TProdutos *produtos, FILE *arqProdutos);
int validarCodigo(TProdutos *produtos, int codigo);
int leProduto(TProdutos *produtos, FILE *arqProdutos);

int verificaDisponibilidade(TProduto *produto);
int addProdPratileira(TProduto *produto, int qtd);
int addProdEstoque(TProduto *produto);
void resumoprodutos(TProdutos produtos);
void getCategoria(TProduto produto);

int iniciaCarrinho(TCarrinho *carrinho);
int addAoCarrinho(TProdutos *produtos, TCarrinho *carrinho);