//
// Created by lazarus on 21/01/20.
//
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#include "Interface.h"
#include "Cliente.h"
#include "Produto.h"
void interface(){

    TClientes *clientes;
    TProdutos *produtos;
    FILE *arqClientes, *arqProdutos;

    printf(GREEN"\n\n     ---> BEM VINDO AO OpusSystem!\n");
    printf(GREEN"          ---> INICIALIZANDO...\n "RESET);
    printf(BLUE);

    leClientes(clientes, arqClientes);
    leProduto(produtos, arqProdutos);

    printf(RESET);


}
