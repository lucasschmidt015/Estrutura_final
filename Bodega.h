
struct BEBIDA{  //Cria a struct bebidas que recebe os dados do cadastro
    int codigo;
    char name[30];
    int volume;
    float preco;
    int qt_estoque;
    int alcollico;
    struct BEBIDA *next, *prev;
};
typedef struct BEBIDA bebida;

struct HEAD{  //struct que aponta para o inicio e o fim da lista
    bebida *first;
    bebida *last;
};
typedef struct HEAD body;   
int menu(){   //Menu, ira receber um valor entre 1 e 7
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
    printf("Digite o codigo da Bebida: ");                 
    scanf("%d",&cadastro->codigo);
    ver = verificador(estrutura,cadastro->codigo);              //Chama a função que verifica se o codigo já consta na lista
    while(ver==1){
        printf("Codigo ja cadastrado, tente novamente");
        scanf("%d",&cadastro->codigo);
        ver = verificador(estrutura,cadastro->codigo);
    }
    printf("Digite o nome da bebida: ");
    scanf("%s", cadastro->name);
    printf("Digite o volume da Bebida em ml: ");
    scanf("%d",&cadastro->volume);                      //Leitura de dados
    printf("Digite o preco: ");
    scanf("%f", &cadastro->preco);
    cadastro->qt_estoque = 0;
    printf("A bebida e alcoolica? [1]-Sim [2]-Nao");
    scanf("%d", &cadastro->alcollico);
    cadastro->next=NULL;
    cadastro->prev=NULL;
    return cadastro;
}

body cadastro_bebida(body estrutura){   //Enseri o elemento na lista 
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

body excluir(body aux) //Exclui um elemento na lista 
{
    int codigo;
    scanf("%d", &codigo);
    if(verificador(aux, codigo)) //Verifica se o elemento está na lista
    {
        bebida *i, *prev, *nex;
        if(aux.first->next == NULL && aux.first->codigo == codigo) // Se o elemento for o unico da lista
        {
            i = aux.first; 
            aux.first = NULL;
            aux.last = NULL;
            free(i);
        }
        else if(aux.last->codigo == codigo) //Se o elemento for o ultimo da lista
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
                if(aux.first->codigo == codigo) //Se o elemento for o primeiro da lista
                {
                    aux.first = aux.first->next;
                    aux.first->prev = NULL;
                    free(i);
                }
                else if(i->codigo == codigo) //Se o elemento estiver no meio da lista
                {
                    prev = i->prev;
                    prev->next = i->next;
                    free(i);
                }
            }
        }
    }
    return aux;
}

void print_bebida(body aux)
{
    bebida *i;
    for(i=aux.first;i!=NULL;i = i->next) //Percorre a lista imprimindo os elementos dela
    {
        printf("************************************************************\n");
        printf("Codigo: %d\nBebida: %s\nVolume: %dml\nPreco: R$%.2f\nEstoque: %d\nAlcoolica: %d\n", i->codigo, i->name, i->volume, i->preco, i->qt_estoque, i->alcollico);
        printf("************************************************************\n");
    }
}

void buscar_bebida(body estrutura){
    int codigo;
    bebida *aux;
    printf("Digite o codigo da bebida para buscar:\n");
    scanf("%d",&codigo);
    for(aux=estrutura.first;aux!=NULL;aux=aux->next){
        if(aux->codigo==codigo){
            printf("Codigo: %d\nBebida: %s\nVolume: %dml\nPreco: R$%.2f\nEstoque: %d\nAlcoolica: %d\n", aux->codigo, aux->name, aux->volume, aux->preco, aux->qt_estoque, aux->alcollico);
            return;
        }
    }
    printf("Bebida nao cadastrada!\n");
}

body comprar_bebida(body estrutura){
    int codigo, quantidade;
    bebida *aux;
    printf("Digite o codigo da bebida que voce quer buscar:\n");
    scanf("%d", &codigo);
    for(aux=estrutura.first;aux!=NULL;aux=aux->next){
        if(codigo==aux->codigo){
            printf("Quantas unidades de %s voce deseja comprar\n", aux->name);
            scanf("%d", &quantidade);
            while(quantidade<0){
                printf("Quantidade invalida!\n");
                printf("Quantas unidades de %s voce deseja comprar\n", aux->name);
                scanf("%d", &quantidade);
            }
            aux->qt_estoque = aux->qt_estoque + quantidade;
            printf("Certo, %d adicionados ao estoque de %s com sucesso.\nNovo estoque de %s e de %d\n", quantidade, aux->name, aux->name, aux->qt_estoque);
            return estrutura;
        }
    }
    printf("Bebida nao encontrada!\n");
    return estrutura;
}

body vender_bebidas(body estrutura){
    int idade, codigo, quantidade, confirmar;
    float total;
    bebida *aux;
    printf("Digite o codigo da bebida que voce quer comprar\n");
    scanf("%d", codigo);
    for(aux=estrutura.first;aux!=NULL;aux=aux->next){
        if(aux->codigo==codigo){
            if(aux->alcollico==1){
                printf("Digite sua idade para prosseguir: \n");
                scanf("%d", idade);
                if(idade<18){
                    printf("Voce não pode comprar essa bebida\n");
                    return estrutura;
                }
            }
            printf("Quantas unidades voce deseja comprar: \n");
            scanf("%d", quantidade);
            if(quantidade>aux->qt_estoque){
                printf("Quantida indisponivel\n");
                return estrutura;
            }
            total = aux->preco * quantidade;
            printf("Total da compra foi de: %.2f, Deseja confirmar a compra?[1]-Sim,[2]-Nao\n", total);
            scanf("%d",confirmar);
            if(confirmar==1){
                aux->qt_estoque = aux->qt_estoque - quantidade;
                printf("Compra concluida!\n");
                return estrutura;
            }else{
                printf("Compra cancelada!\n");
                return estrutura;
            }
        }
    }
    printf("Bebida não encontrada!\n");
    return estrutura;
}