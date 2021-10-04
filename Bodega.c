#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct BEBIDA{
    int codigo;
    char name[30];
    int volume;
    float preco;
    int qt_estoque;
    int alcollico;
    struct BEBIDA *next, *prev;
};
typedef struct BEBIDA bebida;

struct HEAD{
    bebida *first;
    bebida *last;
};
typedef struct HEAD head;   

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

head cad_bebidas(head *first){
    head *aux;
}

int main(){
    head pointers;
    int menu1;
    pointers.first=NULL;
    pointers.last=NULL;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-BEM VINDO A ESSA BODEGA-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    menu1 = menu();
    return 0;
}