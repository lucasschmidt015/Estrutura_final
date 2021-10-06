#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Bodega.h"



int main(){
    body beritas;
    int menu1;
    beritas.first=NULL;
    beritas.last=NULL;
    printf("=================================================================================\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-BEM VINDO A ESSA BODEGA-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("=================================================================================\n");
    while (menu1!=7)
    {
        
        menu1 = menu(); 
        switch (menu1)
        {
            case 1:
                system("cls"); //Limpa a tela anterior antes de chamar a funçao 
                beritas = cadastro_bebida(beritas); //Cadastra a bebida
                getch(); //O usuario tem que clicar uma tecla 
                break;
            case 2:
                system("cls");
                print_bebida(beritas); //Imprime todas as bebidas cadastrada 
                getch();
                break;    
            case 3:
                system("cls");
                buscar_bebida(beritas); //Procura uma bebida na lista e retorna ela
                break;
            case 4:
                system("cls");
                beritas = excluir(beritas); //Exclui uma bebida da lista
                break;
            case 5:
                system("cls");
                comprar_bebida(beritas); //Ao comprar a bebida adiciona o valor comprado ao estoque
                getch();
                break;    
            case 6:
                vender_bebidas(beritas);
                break;
            default:
                break;
        }
        system("cls");
    }
    
    return 0;
}
