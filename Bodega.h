
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
    if(estrutura.first==NULL){          //Função que verifica se a lista está vazia
        return 1;
    }else{
        return 0;
    }
}

int verificador(body estrutura, int codigo){
    bebida *aux;
    for(aux=estrutura.first;aux!=NULL;aux=aux->next){       //Função que verifica se o codigo que o usuario está digitando já está na lista
        if(aux->codigo==codigo)
            return 1;
    }
    return 0;
}

bebida *nova_bebida(body estrutura){
    bebida *cadastro;                                                    //Função que lê uma nova bebida
    int ver;
    cadastro=(bebida *)malloc(sizeof(bebida));
    printf("Digite o codigo da Bebida:\n");                 
    scanf("%d",&cadastro->codigo);
    ver = verificador(estrutura,cadastro->codigo);              //Chama a função que verifica se o codigo já consta na lista
    while(ver==1){
        printf("Codigo ja cadastrado, tente novamente\n");
        scanf("%d",&cadastro->codigo);
        ver = verificador(estrutura,cadastro->codigo);
    }
    printf("Digite o nome da bebida:\n");
    scanf("%s", cadastro->name);
    printf("Digite o volume da Bebida em ml:\n");
    scanf("%d",&cadastro->volume);                      //Leitura de dados
    printf("Digite o preco:\n");
    scanf("%f", &cadastro->preco);
    cadastro->qt_estoque = 0;
    printf("A bebida e alcoolica? [1]-Sim [2]-Nao");
    scanf("%d", &cadastro->alcollico);
    cadastro->next=NULL;
    cadastro->prev=NULL;
    return cadastro;
}

body cadastro_bebida(body estrutura){
    bebida *cadastro;
    cadastro = nova_bebida(estrutura);
    if(estrutura.first==NULL){
        estrutura.first=cadastro;
        estrutura.last=cadastro;
    }else{
        cadastro->prev=estrutura.last;
        estrutura.last->next = cadastro;
        estrutura.last = cadastro;
    }
    return estrutura;
}

body excluir(body aux)
{
    int codigo;
    if(verificador(aux, codigo))
    {
        bebida *i, *prev, *nex;
        if(aux.first->next == NULL && aux.first->codigo == codigo)
        {
            i = aux.first;
            aux.first = NULL;
            aux.last = NULL;
            free(i);
        }
        else if(aux.last->codigo == codigo)
        {
            i = aux.last;
            aux.last->prev = i->prev;
            aux.last->next = NULL;
            free(i);
        }
        else
        {
            for(i=aux.first;i!=NULL;i = i->next)
            {
                if(aux.first->codigo == codigo)
                {
                    aux.first = aux.first->next;
                    aux.first->prev = NULL;
                    free(i);
                }
                else if(i->codigo == codigo)
                {
                    prev = i->prev;
                    prev->next = i->next;
                    free(i);
                }
            }
        }
        return aux;
    }
}

void print_bebida(body aux)
{
    bebida *i;
    for(i=aux.first;i!=NULL;i = i->next)
    {
        printf("Codigo: %d\nBebida: %s\nVolume: %dml\nPreco: R$%.2f\nEstoque: %d\nAlcoolica: %d\n", i->codigo, i->name, i->volume, i->preco, i->qt_estoque, i->alcollico);
    }
}
