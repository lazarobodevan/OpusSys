//
// Created by lazarus on 12/01/20.
//
#include <stdio.h>
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


//--> Operacoes
int alocaCliente(TClientes *clientes);
int iniciaClientes(TClientes *clientes);
int cadastraCliente(TClientes *clientes, FILE *arqClientes);
void imprimeClientes(TClientes clientes);
void imprimeDados(TCliente cliente);
int leClientes(TClientes *clientes, FILE *arqClientes);
int pesquisarCliente(TClientes *clientes);
