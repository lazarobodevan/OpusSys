//
// Created by lazarus on 12/01/20.
//

#include "Produto.h"
#include <stdlib.h>
#include <string.h>

int iniciaProdutos(TProdutos *produtos){
    produtos->pPrim = (TCelulaProduto*) malloc(sizeof(TCelulaProduto));
    produtos->pUlt = produtos->pPrim;
    produtos->pPrim->pProx = NULL;
    produtos->pUlt->pProx = NULL;
    return 1;
}
int alocaProduto(TProdutos *produtos){
    produtos->pUlt->pProx = (TCelulaProduto*) malloc(sizeof(TCelulaProduto));
    produtos->pUlt->pProx->pAnte = produtos->pUlt;
    produtos->pUlt = produtos->pUlt->pProx;
    produtos->pUlt->pProx = NULL;
    return 1;
}

int verificaDisponibilidade(TProduto *produto){
    if(produto->qtdPratileira <= 2 && produto->qtdEstoque > 10){
        printf("---> REALIZANDO REPOSICAO!\n");
        addProdPratileira(produto, 10);
    } else if(produto->qtdPratileira <=2 && produto->qtdEstoque > 0){
        printf("---> REALIZANDO RESPOSICAO!\n");
        addProdPratileira(produto, produto->qtdEstoque);
    } else{
        printf("---> NAO FOI POSSIVEL REPOR O PRODUTO!\n");
    }

    if(produto->qtdEstoque < 10 && produto->qtdEstoque > 0){
        printf("---> ESTOQUE LIMITADO! PECA AO FORNECEDOR!\n");
    } else{
        printf("---> ESTOQUE ZERADO!\n");
    }
}

int addProdPratileira(TProduto *produto, int qtd){
    produto->qtdPratileira = qtd;
    produto->qtdEstoque = produto->qtdEstoque - qtd;
}
//int addProdEstoque(TProduto *produto){
//
//}
int cadastrarProduto(TProdutos *produtos, FILE *arqProdutos){
    arqProdutos = fopen("produtos.txt", "a");
    if(arqProdutos == NULL){
        printf("---> Erro ao abrir arquivo de produtos!\n");
        return 0;
    }
    int validacaoCodigo = 1; //codigo valido a principio -> codigo nao utilizado anteriormente
    alocaProduto(produtos);
    printf("Produto: ");
    fgets(produtos->pUlt->produto.nome, 25, stdin);
    fprintf(arqProdutos, "%s", produtos->pUlt->produto.nome);

    printf("Categoria: 1 -> Frios e Laticinios\n");
    printf("           2 -> Prod. Limpeza\n");
    printf("           3 -> Carnes\n");
    printf("           4 -> Panificacao\n");
    printf("           5 -> Vestimenta\n");
    printf("           6 -> Casa\n");
    printf("           7 -> Mostruario no Caixa\n");
    printf("           8 -> Chocolates\n");
    printf("           9 -> Biscoitos\n");
    printf("          10 -> Cosmeticos\n");
    printf("          11 -> Bebidas\n");
    printf("          12 -> Hortifruti\n");
    printf("Opção: ");
    scanf("%d", &produtos->pUlt->produto.categoria);
    fprintf(arqProdutos, "%d\n", produtos->pUlt->produto.categoria);
    getchar();

    printf("Preco: ");
    scanf("%lf", &produtos->pUlt->produto.preco);
    fprintf(arqProdutos, "%.2lf\n", produtos->pUlt->produto.preco);
    getchar();

    printf("Qtd na Pratileira: ");
    scanf("%d", &produtos->pUlt->produto.qtdPratileira);
    fprintf(arqProdutos, "%d\n", produtos->pUlt->produto.qtdPratileira);
    getchar();

    printf("Qtd em Estoque: ");
    scanf("%d", &produtos->pUlt->produto.qtdEstoque);
    fprintf(arqProdutos, "%d\n", produtos->pUlt->produto.qtdEstoque);
    getchar();

    printf("Validade: ");
    fgets(produtos->pUlt->produto.validade, 11, stdin);
    fprintf(arqProdutos, "%s\n", produtos->pUlt->produto.validade);
    getchar();

    printf("Codigo: ");
    scanf("%d", &produtos->pUlt->produto.codigo);
    validacaoCodigo = validarCodigo(produtos, produtos->pUlt->produto.codigo);
    while (validacaoCodigo == 0){
        printf("Codigo: ");
        scanf("%d", &produtos->pUlt->produto.codigo);
        validacaoCodigo = validarCodigo(produtos, produtos->pUlt->produto.codigo);
    }
    fprintf(arqProdutos, "%d\n", produtos->pUlt->produto.codigo);

    printf("\n-------> PRODUTO CADASTRADO COM SUCESSO!\n");
    fclose(arqProdutos);
    return 1;
}

int validarCodigo(TProdutos *produtos, int codigo){
    TCelulaProduto *aux = produtos->pPrim;
    printf("\n   ---> VALIDANDO CODIGO...\n");
    while (aux->pProx != NULL){
        if(aux->produto.codigo == codigo){
            printf("---> CODIGO JA EXISTENTE!\n");
            return 0;
        }
        aux = aux->pProx;
    }
    printf("---> CODIGO VALIDADO COM SUCESSO!\n");
    return 1;

}


void resumoprodutos(TProdutos produtos){
    TCelulaProduto *aux = produtos.pPrim->pProx;
    printf("\n");
    printf("---> RESUMO DE PRODUTOS\n");
    printf("---------------------------\n");
    while (aux != NULL){
        printf("Produto: %s\n", aux->produto.nome);
        printf("Categoria: %d\n", aux->produto.categoria);
        printf("Preco: %lf\n", aux->produto.preco);
        printf("Qtd Pratileira: %d\n", aux->produto.qtdPratileira);
        printf("Qtd Estoque: %d\n", aux->produto.qtdEstoque);
        printf("Validade: %s\n", aux->produto.validade);
        printf("Codigo: %d\n", aux->produto.codigo);
        printf("---------------------------\n");
        aux = aux->pProx;
    }
}


void getCategoria(TProduto produto){
    switch (produto.categoria){
        case 1: {
            printf("1->Frios e Laticinios\n");
            break;
        }
        case 2:{
            printf("2->Prod. Limpeza\n");
            break;
        }
        case 3:{
            printf("3->Carnes\n");
            break;
        }
        case 4:{
            printf("4->Panificação\n");
            break;
        }
        case 5:{
            printf("5->Vestimenta\n");
            break;
        }
        case 6:{
            printf("6->Casa\n");
            break;
        }
        case 7:{
            printf("7->Mostruario no Caixa\n");
            break;
        }
        case 8:{
            printf("8->Chocolates\n");
            break;
        }
        case 9:{
            printf("9->Biscoitos\n");
            break;
        }
        case 10:{
            printf("10->Cosmeticos\n");
            break;
        }
        case 11:{
            printf("11->Bebidas\n");
            break;
        }
        case 12:{
            printf("Hortifruti\n");
            break;
        }
        default:printf("Categoria não Cadastrada\n");
    }
}

int leProduto(TProdutos *produtos, FILE *arqProdutos){
    arqProdutos = fopen("produtos.txt", "r");
    if(arqProdutos == NULL){
        printf("Erro ao ler arquivo de produtos;");
        return 0;
    }
    printf("\n---> LENDO PRODUTOS CADASTRADOS!\n");
    iniciaProdutos(produtos);
    char nome[25];
    int qtdLidos = 0;
    while (1){
        fgets(nome, 25, arqProdutos);
        if(feof(arqProdutos)){
            break;
        }
        alocaProduto(produtos);
        nome[strlen(nome)-1] = '\0';
        strcpy(produtos->pUlt->produto.nome, nome);

        fscanf(arqProdutos, "%d", &produtos->pUlt->produto.categoria);

        fscanf(arqProdutos, "%lf", &produtos->pUlt->produto.preco);

        fscanf(arqProdutos, "%d", &produtos->pUlt->produto.qtdPratileira);

        fscanf(arqProdutos, "%d", &produtos->pUlt->produto.qtdEstoque);
        fgetc(arqProdutos);

        fgets(produtos->pUlt->produto.validade, 11, arqProdutos);

        fscanf(arqProdutos, "%d", &produtos->pUlt->produto.codigo);
        fgetc(arqProdutos);

        qtdLidos++;

    }
    printf("---> LEITURA CONCLUIDA COM SUCESSO!\n");
    printf("---> %d PRODUTOS ENCONTRADOS!\n", qtdLidos);
    return 1;

}

//int iniciaCarrinho(TCarrinho *carrinho){
//    carrinho = (TCarrinho*) malloc(sizeof(carrinho));
//    carrinho->pPrim->pProx = NULL;
//    carrinho->pUlt = carrinho->pPrim;
//    strcpy(carrinho->pPrim->produto.nome, "");
//    carrinho->pPrim->produto.preco = -1;
//}
//int addAoCarrinho(TListaDeProdutos *produtos, TCarrinho *carrinho){
//    char nomeProduto[25];
//    printf("Digite o nome do produto");
//    fgets(nomeProduto, 25, stdin);
//    for (int i = 0; i < 10; ++i) {
//        if(strcmp(produtos->produtos->nome, nomeProduto)){
//            printf("Quantidade: ");
//            scanf("%d",&carrinho->pUlt->quantidade);
//            break;
//        }
//    }
//    printf("Não existe, moh!\n");
//}