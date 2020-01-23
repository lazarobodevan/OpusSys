//
// Created by lazarus on 12/01/20.
//
#include "Produto.h"

//--> T-Item
typedef struct{
    char nome[40];
    char cpf[15];
    char dtNasc[11];
}TCliente;


//--> Lista Encadeada de Clientes
typedef struct CelulaCliente{
    TCliente cliente;
    struct CelulaCliente *pProx, *pAnte;
}TCelulaCliente;

typedef struct{
    TCelulaCliente *pPrim, *pUlt;
    int qtdClientes;
}TClientes;


//--> Lista Encadeada de Produtos
typedef struct CelulaProduto{
    TProduto produto;
    int quantidade;
    struct CelulaProduto *pProx;
}TCelulaProduto; //Celula contendo o produto

typedef struct {
    TCelulaProduto *pPrim, *pUlt;
}TCarrinho;

//--> Operacoes
int alocaCliente(TClientes *clientes);
int iniciaClientes(TClientes *clientes);
int cadastraCliente(TClientes *clientes, FILE *arqClientes);
void imprimeClientes(TClientes clientes);
void imprimeDados(TCliente cliente);
int iniciaCarrinho(TCarrinho *carrinho);
int addAoCarrinho(TListaDeProdutos *produtos, TCarrinho *carrinho);
int leClientes(TClientes *clientes, FILE *arqClientes);
int pesquisarCliente(TClientes *clientes);
