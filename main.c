#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
struct itens
{
    int Cod;
    char Nome[25];
    float Valor;
    int Estoque;
    int Vendas;
    float Subtotal;
    int QTDtotal;
};
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
struct itens prod[]; // array para cadastrar novos itens na struct declarada acima
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Exibir() // apenas exibe os itens e retorna pra função que chamou ela
{
    printf("\n quatidade total %d \n", prod[0].QTDtotal); // mostra quantidade total de ittens cadastrados
    printf("| Item (Codigo)\t| Nome do item\t\t\t| Valor (Unidade)\t| Estoque\n");
    for (int i = 0; i < prod[0].QTDtotal; i++)
    {
        printf("| %d\t\t| %-25s\t| R$ %.2f\t\t| %d\n", prod[i].Cod, prod[i].Nome, prod[i].Valor, prod[i].Estoque); // construção da tabela com todos os ittens
    }
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Cadastrar()
{
    int i, j, x = 1, QTD, TAM;

    printf("Digite a quantidade de produtos que deseja cadastrar: \n");
    scanf("%d", &QTD);

    for(j = 0; j < QTD; j++) // contador para cadastrar a quantidadde de itens que o usuario escolheu
    {
        TAM = prod[0].QTDtotal; // atribuindo a quantidade total a variavel tamanho
        printf("\nDigite o codigo do item a ser cadastrado: \n");
        scanf("%d", &prod[TAM].Cod);
        getchar();
        for(i = 0; i < TAM; i++) // enquanto o i for menor que tam
        {
            while(prod[TAM].Cod == prod[i].Cod || prod[TAM].Cod < 0) // condição de looping caso o item nao esteja cadastrado
            {
                printf("Codigo invalido ou ja existente, digite novamente: \n");
                scanf("%d", &prod[TAM].Cod);
                getchar();
            }
        }
        do
        {
            printf("Digite o nome do item: \n");
            fgets(prod[TAM].Nome, 25, stdin);  // salva o nome do item a struct
            strtok(prod[TAM].Nome, "\n");
            for(i = 0; i < 25; i++) // conferindo se os caracteres estao ente a e z maiusculos e minusculos
            {
                if((prod[TAM].Nome[i] >= 'a' && prod[TAM].Nome[i] <= 'z') || (prod[TAM].Nome[i] >= 'A' && prod[TAM].Nome[i] <= 'Z'))
                {
                    x = 0;
                }
            }
            for(i = 0; i < TAM; i++)
            {
                if(strcasecmp(prod[TAM].Nome, prod[i].Nome) == 0)  // conferindo se nao esta igual a outro nome cadastrado
                {
                    x = 1;
                }
            }
            if(x == 1)  // se o nome ja existir aparecera essa mensagem de nome invalido
            {
                printf("Nome invalido, digite novamente: \n");
            }
        }
        while(x == 1);   // se o nome ja existir esse looping ocorre para cadastrar o nome de novo
        do
        {
            printf("Digite o valor do item: \n");
            scanf("%f", &prod[TAM].Valor); // salva valor do item na struct
            if(prod[TAM].Valor < 0)
            {
                printf("Valor invalido, digite novamente: \n"); // se o valor for negativo da erro
            }
        }
        while(prod[TAM].Valor < 0); // looping para digitar novamente
        do
        {
            printf("Digite a quantidade em estoque do produto: \n");
            scanf("%d", &prod[TAM].Estoque);  // salva o estoque na struct
            if(prod[TAM].Estoque < 0)
            {
                printf("Quantidade invalida, digite novamente: \n");  // se o estoque a quantidade for negativa nao é permitido o cadastro
            }
        }
        while(prod[TAM].Estoque < 0); // looping para cadastrar quantidade de novo
        prod[0].QTDtotal++; // se o item for cadastrado á atribuido a struct
    }
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Atualizar()
{
    int i, codigo;

    if (prod[0].QTDtotal == 0) // se não houver nenhum produto cadastrado exibira essa mensagem
    {
        printf("Nenhum produto cadastrado. \n");
        return 1;
    }
    printf("Tem %d itens cadastrados\n", prod[0].QTDtotal);  // diz a quantidade de itens cadastrados
    Exibir();  // exibe todos os itens cadastrados
    printf("Digite o codigo do item que deseja atualizar: \n");
    scanf("%d", &codigo);
    for (i = 0; i < prod[0].QTDtotal; i++)  // for para encontar o indice que queremos alterar
    {
        if (prod[i].Cod == codigo) // executa esse codico quando encontra o item a ser alterado
        {
            printf("Produto encontrado!\n\n");
            printf("| Item (Codigo)\t| Nome do item\t\t\t| Valor (Unidade)\t| Estoque\n");
            printf("| %d\t\t| %-25s\t| R$ %.2f\t\t| %d\n", prod[i].Cod, prod[i].Nome, prod[i].Valor, prod[i].Estoque); // mostra as informações do item
            do
            {
                printf("Digite a nova quantidade: ");
                scanf("%d", &prod[i].Estoque);  // atualiza novo quantidade
                if (prod[i].Estoque < 0)
                {
                    printf("Quantidade invalida, digite novamente: \n");
                }
            }
            while (prod[i].Estoque < 0); // validador de quantidade
            do
            {
                printf("Digite o novo valor: ");
                scanf("%f", &prod[i].Valor);  // atualiza valor
                if (prod[i].Valor < 0)
                {
                    printf("Valor invalido, digite novamente: \n");
                }
            }
            while (prod[i].Valor < 0); // valida valor

            printf("Atualizacao realizada com sucesso!\n");
            printf("Novo estoque: %d\n", prod[i].Estoque);
            printf("Novo valor: %.2f\n", prod[i].Valor);
            break;
        }
    }
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Excluir()
{
    int i, codigo, opc;

    Exibir();  // chama a função para mostrar os produtos disponiveis

    printf("Digite o codigo do item que deseja excluir: \n");
    scanf("%d", &codigo);
    getchar();

    for(i = 0; i < prod[0].QTDtotal; i++) // enquanto i for menor que qtd vai rodar
    {
        if(prod[i].Cod == codigo) // se o codigo digitado estiver entre os itens cadastrados..
        {
            printf("Produto encontrado!\n\n");
            printf("| Item (Codigo)\t| Nome do item\t\t\t| Valor (Unidade)\t| Estoque\n");
            printf("| %d\t\t| %-25s\t| R$ %.2f\t\t| %d\n", prod[i].Cod, prod[i].Nome, prod[i].Valor, prod[i].Estoque);

            printf("Deseja realmente excluir este produto?\n1.Sim\n2. Nao\n");
            do
            {
                scanf("%d", &opc);
                getchar();

                if(opc < 1 || opc > 2)
                {
                    printf("Opcao invalida, digite novamente");
                }
            }
            while(opc < 1 || opc > 2);  // se a opc nao for 1 ou 2, fará o looping da condição "if"

            if(opc == 1)
            {
                for(i = 0; i < prod[0].QTDtotal - 1; i++) // enquanto i for menor que qtd vai rodar
                {
                    prod[i] = prod[i+1]; // aumenta no idice, pois o vetor começa no 0
                }

                prod[0].QTDtotal--; // retira o item da struct
                printf("Produto excluido!\n");
            }
            else
            {
                printf("Nenhum produto foi excluido!\n");
            }
        }
    }
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void salvar()
{
    FILE *save = fopen("produtos.txt", "w"); // Abrindo arquivo produtos
    FILE *save2 = fopen("produtos.bin", "wb"); // abrindo arquivo em binario

    if (save == NULL || save2 == NULL)  //confirmando se os arquivos foram abertos com sucesso
    {
        printf("\nErro, o arquivo nao pode ser aberto!\n");
        exit(1);
    }

    fprintf(save, "%d\n", prod[0].QTDtotal); //printando no arquivo save

    for (int i = 0; i < prod[0].QTDtotal; i++)
    {
        fprintf(save, "\n%d\n%s\n%.2f\n%d\n%d", prod[i].Cod, prod[i].Nome, prod[i].Valor, prod[i].Estoque, prod[i].Vendas); //printando no arquivo save
    }

    int size = sizeof(struct itens);
    int num_element = prod[0].QTDtotal;

    fwrite(&prod[0], size, num_element, save2); //fwrite permite a escrita de um bloco de bytes em arquivos
    printf("\nAs alteracoes foram salvas!");

    fclose(save);// fechando o arquivo pra n dar merda
    fclose(save2);// fechando o arquivo pra n dar merda
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Ler()
{
    FILE *Inv = fopen("produtos.txt", "r"); // abrindo arquivo pra leitura

    if (Inv == NULL)//confirmando se os arquivos foram abertos com sucesso
    {
        printf("Erro, o arquivo nao pode ser aberto!\n");
        return 1;
    }
    fscanf(Inv, "%d", &prod[0].QTDtotal); // lendo os dados do arquivo e salvando na struct
    printf("%d itens\n", prod[0].QTDtotal); //informando quantos itens tem salvo

    for (int i = 0; i < prod[0].QTDtotal; i++) //enquanto i for menor q qtd, vai rodar
    {
        fscanf(Inv, "%d", &prod[i].Cod); //lendo os codigos do arquvo e salvando na struct
        fgetc(Inv);
        fgets(prod[i].Nome, sizeof(prod[i].Nome), Inv);//lendo os nomes do arquvo e salvando na struct
        strtok(prod[i].Nome, "\n");
        fscanf(Inv, "%f", &prod[i].Valor); //lendo os valores do arquvo e salvando na struct
        fscanf(Inv, "%d", &prod[i].Estoque);//lendo o estoque do arquvo e salvando na struct
        fscanf(Inv, "%d", &prod[i].Vendas);//lendo os itens vendidos do arquvo e salvando na struct
    }
    fclose(Inv); // fechando o arquivo pra n dar merda
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Voltar()
{
    printf("Voltanto ao Menu...\n");
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Produtos()
{
    int opc;
    int QTDtotal;

    prod[0].QTDtotal =  QTDtotal;

    struct itens *prod;  // criando a struct ponteiro prod para alocar memoria
    prod = (struct itens *)malloc(QTDtotal * sizeof(struct itens)); // alocando memoria na struct prod

    if (prod == NULL)// confirmando se foi alocado
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    do
    {
        printf("---SUB-MENU--\n");
        printf("-------------\n");
        printf("1. Exibir   |\n2. Cadastrar|\n3. Atualizar|\n4. Excluir  |\n5. Salvar   |\n6. Ler      |\n7. Voltar   |\n");
        printf("-------------\n");
        scanf("%d", &opc);
        getchar();
        switch (opc)
        {
        case 1:
            Exibir();
            break;
        case 2:
            Cadastrar();
            break;
        case 3:
            Atualizar();
            break;
        case 4:
            Excluir();
            break;
        case 5:
            salvar();
            break;
        case 6:
            Ler();
            break;
        case 7:
            Voltar();
            break;
        default:
            printf("\nOpcao invalida, digite novamente:\n");
            break;
        }
    }
    while (opc < 1 || opc > 7 || opc != 7);
    free(prod); // limpando a memoria
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Realizar_Venda()
{
    int i, j, opc, opc_pag, opc_troco, QTD, Codigo, Num_Parcelas;
    float Valor_total, Desconto, Acrescimo, Valor_Parcelas, Troco, Saldo;

    do
    {
        do
        {
            Exibir();
            printf("\nDigite o codigo do produto: ");
            scanf("%d", &Codigo);
            getchar();

            for (i = 0; i < prod[0].QTDtotal; i++)
            {
                if (prod[i].Cod == Codigo)
                {
                    printf("Produto encontrado!\n\n");
                    printf("| Item (Codigo)\t| Nome do item\t\t\t| Valor (Unidade)\t| Estoque\n");
                    printf("| %d\t\t| %-25s\t| R$ %.2f\t\t| %d\n", prod[i].Cod, prod[i].Nome, prod[i].Valor, prod[i].Estoque);
                    break;
                }
            }
            if (prod[i].Cod != Codigo)
            {
                printf("\nCodigo de produto invalido, selecione o produto novamente\n\n");
            }
        }
        while (prod[i].Cod != Codigo);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &QTD);
        getchar();

        if (QTD > 0 && QTD <= prod[i].Estoque)
        {
            prod[i].Vendas = prod[i].Vendas + QTD; // salvando a quantidade de itens vendidos na struct
            prod[i].Subtotal = QTD * prod[i].Valor; //fazendo calculo dos itens vendidos e salvando na struct
            prod[i].Estoque = prod[i].Estoque - QTD; //retiando da struct os itens vendidos
        }
        else
        {
            printf("\nQuantidade invalida, estoque atual de: %d\n", prod[i].Estoque);
        }

        do
        {
            printf("\nDeseja comprar um novo produto?\n1. Sim\n2. Nao\n");
            scanf("%d", &opc);

            if (opc == 2) // se a opc digitada for 2, o codigo vai continuar
            {
                continue;
            }
            else if (opc < 1 || opc > 2)
            {
                printf("Opcao invalida, digite novamente\n");
            }
        }
        while (opc < 1 || opc > 2); // validação da opc
    }
    while (opc == 1); // se opc for 1, fazer o looping

    struct itens temp_prod[prod[0].QTDtotal]; // criando uma struct temporaria para ordenar os valores na nota fiscal

    for (i = 0; i < prod[0].QTDtotal; i++) // se i for menor q qtd, continua
    {
        temp_prod[i] = prod[i]; // atribuindo o indice i a struct
    }

    for (i = 0; i < temp_prod[0].QTDtotal; i++)  // bubble short paraordenar os valores na nota fiscal em ordem decrescente
    {
        for (j = 0; j < temp_prod[0].QTDtotal - i - 1; j++)
        {
            if (temp_prod[j].Subtotal < temp_prod[j + 1].Subtotal)
            {
                struct itens temp = temp_prod[j];
                temp_prod[j] = temp_prod[j + 1];
                temp_prod[j + 1] = temp;
            }
        }
    }
    printf("| Item (Codigo)\t| Nome do item\t\t\t| Valor (Unidade)\t| Quantidade\t| Subtotal\n");
    for (i = 0; i < prod[0].QTDtotal; i++)
    {
        if (temp_prod[i].Vendas > 0)
        {
            printf("| %d\t\t| %-25s\t| R$ %.2f\t\t| %d\t\t| %.2f\n", temp_prod[i].Cod, temp_prod[i].Nome, temp_prod[i].Valor, temp_prod[i].Vendas, temp_prod[i].Subtotal);
            Valor_total += temp_prod[i].Subtotal; // calculo do valor total
        }
    }
    printf("|\t\t\t\t\t\t\tTotal:\t R$ %.2f\n", Valor_total);

    printf("\nSelecione a forma de pagamento:\n1. A vista\n2. A prazo\n");

    do
    {
        scanf("%d", &opc_pag);
        if (opc_pag < 1 || opc_pag > 2)
        {
            printf("\nOpcao de pagamento invalida, digite novamente\n");
        }
    }
    while (opc_pag < 1 || opc_pag > 2);

    if (opc_pag == 1)
    {
        if (Valor_total <= 50)
        {
            Desconto = Valor_total * 0.05; // se menor que R$ 50 = 5% de desconto
            Valor_total -= Desconto;
        }
        else if (Valor_total < 100)
        {
            Desconto = Valor_total * 0.1; // se maior que R$ 50 e menor que R$ 100 = 10% de desconto
            Valor_total -= Desconto;
        }
        else
        {
            Desconto = Valor_total * 0.18; // caso contrário, se maior que R$ 100 = 18% de desconto
            Valor_total -= Desconto;
        }

        printf("\nPagamento a vista selecionado, precisa de troco?\n1.Sim\n2.Nao\n");
        do
        {
            scanf("%d", &opc_troco);
            if (opc_troco < 1 || opc_troco > 2)
            {
                printf("Opcao invalida, digite novamente: \n");
            }
        }
        while (opc_troco < 1 || opc_troco > 2);

        if (opc_troco == 1)
        {
            printf("Informe o valor de seu saldo: ");
            scanf("%f", &Saldo);

            while (Saldo < Valor_total)
            {
                printf("Saldo insuficiente, tente novamente\n");
                scanf("%f", &Saldo);
            }
            Troco = Saldo - Valor_total; // calculo do troco
            printf("Troco: R$ %.2f\n", Troco);
            printf("Desconto de: R$ %.2f\n", Desconto);
        }
    }
    else if (opc_pag == 2)
    {
        printf("\nValor total da compra: R$ %.2f\n", Valor_total);
        printf("Digite o numero de parcelas: ");
        scanf("%d", &Num_Parcelas);

        while (Num_Parcelas <= 0)
        {
            printf("Numero de parcelas invalido, digite um valor igual ou acima de 1 parcela.\n");
            scanf("%d", &Num_Parcelas);
        }
        if (Num_Parcelas > 3) // Se numero de parcelas maior que 3 = 8% de acréscimo
        {
            Acrescimo = Valor_total * 0.08;
            Valor_total += Acrescimo;
        }
        else
        {
            Acrescimo = Valor_total * 0.05; // Caso contrário, se for 1 ou 2 = 5% de acréscimo
            Valor_total += Acrescimo;
        }
        Valor_Parcelas = Valor_total / Num_Parcelas;
        printf("\n%dx parcelas de: R$ %.2f\n", Num_Parcelas, Valor_Parcelas);
        printf("Acrescimo de: R$ %.2f\n", Acrescimo);
    }
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Relatorio()
{
    printf("| Item (Codigo)\t| Nome do item\t\t\t| Estoque| Vendidos\t\n");
    for (int i = 0; i < prod[0].QTDtotal; i++)
    {
        printf("| %d\t\t| %-25s\t| %d\t | %d\n", prod[i].Cod, prod[i].Nome, prod[i].Estoque, prod[i].Vendas);
    }
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//
void Vendas()
{
    int opc;

    do
    {
        printf("-----------------------\n");
        printf("1. Realizar venda     |\n2. Relatorio de vendas|\n3. Voltar             |\n");
        printf("-----------------------\n");
        scanf("%d", &opc);
        getchar();

        switch (opc)
        {
        case 1:
            Realizar_Venda();
            break;
        case 2:
            Relatorio();
            break;
        case 3:
            Voltar();
        default:
            printf("Opcao invalida, digite novamente!\n");
            break;
        }
    }
    while (opc < 1 || opc > 3 || opc != 3);
}
// MWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMWMMWMWMMWMWWMMWMWMWMWMWWMWMWMWMMWWMWMWMWMWMWMWMWMWMWM//

int main()
{
    int opc;
    Ler();
    do
    {
        printf("----MENU----\n");
        printf("------------\n");
        printf("1. Produtos|\n2. Vendas  |\n3. Sair    |\n");
        printf("------------\n");
        scanf("%d", &opc);
        getchar();

        switch (opc)
        {
        case 1:
            Produtos();
            break;
        case 2:
            Vendas();
            break;
        case 3:
            return 0;
        default:
            printf("Opcao invalida, digite novamente!\n");
            break;
        }
    }
    while (opc < 1 || opc > 3 || opc != 3);

    return 0;
}
