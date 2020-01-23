//
// Created by lazarus on 12/01/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

int alocaCliente(TClientes *clientes){
    clientes->pUlt->pProx = (TCelulaCliente*) malloc(sizeof(TCelulaCliente));
    clientes->pUlt->pProx->pAnte = clientes->pUlt;
    clientes->pUlt = clientes->pUlt->pProx;
    clientes->pUlt->pProx = NULL;
}

int cadastraCliente(TClientes *clientes, FILE *arqClientes){
    arqClientes = fopen("clientes.txt", "a");
    if(arqClientes == NULL) {
        printf("Erro ao encontrar o arquivo!\n");
        return 0;
    }
    printf("\n------CADASTRO DE CLIENTES------\n");
    alocaCliente(clientes);
    printf("Nome: ");
    fgets(clientes->pUlt->cliente.nome,40,stdin);
    fprintf(arqClientes, "%s", clientes->pUlt->cliente.nome);

    printf("CPF: ");
    fgets(clientes->pUlt->cliente.cpf, 15, stdin);
    fprintf(arqClientes, "%s", clientes->pUlt->cliente.cpf);
    fprintf(arqClientes, "%c", '\n');

    printf("Data de nascimento (dd/mm/aaaa): ");
    getchar();
    fgets(clientes->pUlt->cliente.dtNasc, 11, stdin);
    fprintf(arqClientes, "%s", clientes->pUlt->cliente.dtNasc);
    fprintf(arqClientes, "%c", '\n');
    clientes->qtdClientes++;
    printf("\n------CADASTRO EFETUADO COM SUCESSO------\n");
    return 1;
}

int iniciaClientes(TClientes *clientes){
    clientes->pPrim = (TCelulaCliente*) malloc(sizeof(TCelulaCliente));
    clientes->pUlt = clientes->pPrim;
    clientes->pPrim->pProx = NULL;
    clientes->pPrim->pAnte = NULL;
    return 1;
}

void imprimeClientes(TClientes clientes){
    TCelulaCliente *celulaAux = clientes.pPrim->pProx;
    while (celulaAux != NULL) {
        printf("Nome: %s\n", celulaAux->cliente.nome);
        printf("CPF: %s\n", celulaAux->cliente.cpf);
        printf("Data de Nascimento: %s\n", celulaAux->cliente.dtNasc);
        printf("\n---------------------------\n");
        celulaAux = celulaAux->pProx;
    }
}

void imprimeDados(TCliente cliente){
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("Data de Nascimento: %s\n", cliente.dtNasc);
}

int iniciaCarrinho(TCarrinho *carrinho){
    carrinho = (TCarrinho*) malloc(sizeof(carrinho));
    carrinho->pPrim->pProx = NULL;
    carrinho->pUlt = carrinho->pPrim;
    strcpy(carrinho->pPrim->produto.nome, "");
    carrinho->pPrim->produto.preco = -1;
}
int addAoCarrinho(TListaDeProdutos *produtos, TCarrinho *carrinho){
    char nomeProduto[25];
    printf("Digite o nome do produto");
    fgets(nomeProduto, 25, stdin);
    for (int i = 0; i < 10; ++i) {
        if(strcmp(produtos->produtos->nome, nomeProduto)){
            printf("Quantidade: ");
            scanf("%d",&carrinho->pUlt->quantidade);
            break;
        }
    }
    printf("Não existe, moh!\n");
}

int leClientes(TClientes *clientes, FILE *arqClientes){
    arqClientes = fopen("clientes.txt", "r");
    if(arqClientes == NULL){
        printf("Erro ao ler arquivo!\n");
        return 0;
    }
    iniciaClientes(clientes);
    int i = 0;
    char nome[40];
    char cpf[15];
    char dtNasc[11];
    while (1){
        fgets(nome, 40, arqClientes);
        nome[strlen(nome)-1] = '\0';
        if(feof(arqClientes))
            break;
        fscanf(arqClientes, "%s", cpf);
        fscanf(arqClientes, "%s", dtNasc);
        fgetc(arqClientes);

        alocaCliente(clientes);
        strcpy(clientes->pUlt->cliente.nome, nome);
        strcpy(clientes->pUlt->cliente.cpf, cpf);
        strcpy(clientes->pUlt->cliente.dtNasc, dtNasc);
        i++;
    }
    clientes->qtdClientes = i;
    printf("\n---> %d clientes lidos!\n", i);
}

int pesquisarCliente(TClientes *clientes){
    char nome[40];
    printf("Nome do cliente: ");
    fgets(nome, 40, stdin);
    nome[strlen(nome)-1] = '\0';
    TCelulaCliente *aux = clientes->pPrim->pProx;
    while (aux != NULL){
        if(strcmp(nome, aux->cliente.nome) == 0){
            imprimeDados(aux->cliente);
            return 1;
        }
        aux = aux->pProx;
    }
    printf("\n----Cliente não cadastrado!----\n");
    return 0;

}