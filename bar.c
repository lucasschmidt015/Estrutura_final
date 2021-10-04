#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Bodega.h"

int menu(){
    int menu1;
    printf("[1]-Cadastrar bebida\n[2]-Listar bebidas\n[3]-Buscar bebidas\n[4]-Excluir bebidas\n[5]-Comprar Bebidas\n[6]-Vender Bebidas\n[7]-Sair do Sistema\n");
    scanf("%d", &menu1);
    while(menu1<1||menu1>7){
        printf("Opcao invalida\n");
        printf("[1]-Cadastrar bebida\n[2]-Listar bebidas\n[3]-Buscar bebidas\n[4]-Excluir bebidas\n[5]-Comprar Bebidas\n[6]-Vender Bebidas\n[7]-Sair do Sistema\n");
        scanf("%d", &menu1);
    }
    return menu1;
}