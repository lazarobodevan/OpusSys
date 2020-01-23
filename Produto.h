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
    char validade[10];
    int codigo;
}TProduto;

typedef struct{
    int pPrim, pUlt;
    TProduto produtos[10];
}TListaDeProdutos;

int addProdPratileira(TProduto *produto);
int addProdEstoque(TProduto *produto);
int cadastrarProduto(TProduto *produto, FILE *produtos, TListaDeProdutos *listadeprodutos);
void resumoprodutos(TListaDeProdutos produtos);
void getCategoria(TProduto produto);