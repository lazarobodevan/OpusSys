#include <stdio.h>
#include "Cliente.h"
int main() {
    TClientes *clientes;
    FILE *arqClientes;
    //cadastraCliente(cliente, clientes);
    leClientes(clientes, arqClientes);
    imprimeClientes(*clientes);
    //cadastraCliente(clientes, arqClientes);
    //imprimeClientes(*clientes);
    pesquisarCliente(clientes);
    return 0;
}