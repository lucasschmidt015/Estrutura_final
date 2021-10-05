
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
typedef struct HEAD body;   
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

int vazio(body estrutura){
    if(estrutura.first==NULL){
        return 1;
    }else{
        return 0;
    }
}

int verificador(body estrutura, int codigo){
    bebida *aux;
    for(aux=estrutura.first;aux!=NULL;aux=aux->next){
        if(aux->codigo==codigo)
            return 1;
    }
    return 0;
}

bebida *nova_bebida(body estrutura){
    bebida *cadastro;
    int ver;
    cadastro=(bebida *)malloc(sizeof(bebida));
    printf("Digite o codigo da Bebida:\n");
    scanf("%d",&cadastro->codigo);
    ver = verificador(estrutura,cadastro->codigo);
    while(ver==1){
        printf("Codigo ja cadastrado, tente novamente\n");
        scanf("%d",&cadastro->codigo);
        ver = verificador(estrutura,cadastro->codigo);
    }
    printf("Digite o nome da bebida:\n");
    scanf("%s", cadastro->name);
    printf("Digite o volume da Bebida em ml:\n");
    scanf("%d",&cadastro->volume);
    printf("Digite o preco:\n");
    scanf("%lf", &cadastro->preco);
    cadastro->qt_estoque = 0;
    printf("A bebida e alcoolica? [1]-Sim [2]-Nao");
    scanf("%d", &cadastro->alcollico);
    cadastro->next=NULL;
    cadastro->prev=NULL;
}


void print_bebida(body aux)
{
    bebida *i;
    for(i=aux.first;i!=NULL;i = i->next)
    {
        printf("Codigo: %d\nBebida: %s\nVolume: %dml\nPreco: R$%.2f\nEstoque: %d\nAlcoolica: %d\n");
    }
}
