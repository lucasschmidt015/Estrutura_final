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
            system("cls");
            beritas = cadastro_bebida(beritas);
            break;
        case 2:
            system("cls");
            print_bebida(beritas);
            break;    
        case 3:
            system("cls");
            buscar_bebida(beritas);
            break;
        case 4:
            system("cls");
            beritas = excluir(beritas);
            break;
        case 5:
            break;    
        case 6:
            break;
        default:
            break;
        }
    }
    
    return 0;
}
