
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