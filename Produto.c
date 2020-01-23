//
// Created by lazarus on 12/01/20.
//

#include "Produto.h"
int addProdPratileira(TProduto *produto){

}
int addProdEstoque(TProduto *produto){

}
int cadastrarProduto(TProduto *produto, FILE *produtos, TListaDeProdutos *listadeprodutos){
    printf("Produto: ");
}
void resumoprodutos(TListaDeProdutos produtos){
    for (int i = 0; i < 10; i++) {
        printf("-------------------\n");
        printf("Produto: %s\n", produtos.produtos[i].nome);
        printf("Categoria: ");
        getCategoria(produtos.produtos[i]);
        printf("Preço: %.2lf\n", produtos.produtos[i].preco);
        printf("Qtd em Estoque: %d\n", produtos.produtos[i].qtdEstoque);
        printf("Qtd na Pratileira: %d\n", produtos.produtos[i].qtdPratileira);
        printf("Validade: %s\n", produtos.produtos[i].validade);
        printf("Código: %d\n", produtos.produtos[i].codigo);
        printf("-------------------\n");
    }
}
void getCategoria(TProduto produto){
    switch (produto.categoria){
        case 1: {
            printf("Frios\n");
            break;
        }
        case 2:{
            printf("Prod. Limpeza\n");
            break;
        }
        case 3:{
            printf("Carnes\n");
            break;
        }
        case 4:{
            printf("Panificação\n");
            break;
        }
        case 5:{
            printf("Vestimenta\n");
            break;
        }
        case 6:{
            printf("P/ Casa\n");
            break;
        }
        case 7:{
            printf("Variados no Caixa\n");
            break;
        }
        default:printf("Categoria não Cadastrada\n");
    }
}