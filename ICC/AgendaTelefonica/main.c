#include <stdio.h>
#include <string.h>// strcpy,strlen, strcmp
#include <locale.h>// acentuação


/*
 OBSERVAÇÕES DO CÓDIGO:
Agenda de contatos que realiza as seguintes atividades: Adição de Contato, Remoção de Contato,
Busca de Contato (por Nome e por Telefone) e Listar os Contatos (em Ordem Alfabética e
agrupar por Tipo de Relação). Cada contato será composto de Nome (até 100 caracteres), Telefone (11 dígitos),
Endereço (até 300 caracteres), Tipo de Relação (O usuário poderá escolher entre 3 opções de relação)
e email (até 50 caracteres).
Em termos lógicos fizemos um semi CRUD(Que nesse caso seria um CRSD(CREATE, READ, SORT, DELETE)) utilizando estrutura e
vetor estático para armazenar os dados.
REFERÊNCIAS:
clubedohardware.com.br; pt.stackoverflow.com; embarcados.com.br; t.me/cppbrazil; João Canuto(Monitor); www.vivaolinux.com.br;
Programação descomplicada https://www.youtube.com/playlist?list=PL8iN9FQ7_jt4DJbeQqv--jpTy-2gTA3Cp (Ordenação, Busca)
Xave Coding https://www.youtube.com/playlist?list=PL3ZslI15yo2pCf0WpZmV-ga02kMPxKH3p (Struct, String, Funções)
*/

//Função para limpar tela
void CleanScreen(){
system("clear");
//system("cls");//caso o SO seja Windows
}

void ShowMenu (){//função mais utilizada pelo programa, exibe o menu

    printf("\n#####################################################\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#              1 - Listar Contatos                  #\n"
           "#              2 - Buscar Contatos                  #\n"
           "#              3 - Adicionar Contato                #\n"
           "#              4 - Remover Contato                  #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#                                                   #\n"
           "#      Feito por: Janaína, João Pedro e Vinicius    #\n"
           "#####################################################\n");
}

//Criando a struct responsável pela "união" dos dados de um contato para que todos dados sejam salvos somente em uma posição do vetor
//Utilizamos o typedef junto com o struct para transformar essa struct em um novo tipo de variável
typedef struct dados_contact{
    char Name[101];//responsável por armazenar o nome
    char Telefone[12];//responsável por armazenar o telefone
    char Address[301];//responsável por armazenar o Endereço
    int RelationType;//responsável por armazenar o tipo de relação
    char Email[51];//responsável por armazenar o e-mail
}DadosCtt;//aqui demos o nome desse novo tipo de variável

DadosCtt dados[1000];// Criamos um vetor estático para armazenar a struct de dados dos contatos e já damos o limite máximo de contatos


DadosCtt *AddContact(int pos){
    char NameCMPExist[101];//Recebe o nome e compara
    char TelCMPExist[12];//Recebe o telefone e compara
    char EmailTemp[51];//Recebe o e-mail temporariamente
    char TelTemp[12];//Recebe o telefone temporariamente
    int DadosTam = 0;//Recebe o tamanho dos dados inseridos
    int QtdArroba = 0;//Contador de arrobas do e-mail
    
    // o usuário irá inserir um nome de até 100 caracteres
    printf("\nNome: ");
    fgets(NameCMPExist,100,stdin);
    fflush(stdin);//limpando stdin

    for(int i=0;i<pos;i++){//Percorre toda lista de contatos
        if(strcmp(NameCMPExist,dados[i].Name) == 0){//verifica se existe algum nome igual cadastrado
            printf("Este número já está salvo, delete ele caso queira cadastra-lo novamente!\n");
          
          return 0;
        }
    }
        
    //O usuário irá inserir um endereço de até 300 caracteres
    printf("\nEndereço: ");
    fgets(dados[pos].Address,300, stdin);
    fflush(stdin);

    //O usuário poderá inserir um email de até 50 caracteres
    printf("\nEmail: ");
    fgets(EmailTemp, 50, stdin);

    DadosTam = strlen(EmailTemp);//envia o tamanho do e-mail para a variável DadosTam
    for(int i= 0;i < DadosTam;i++){//percorre todo e-mail
        char a = EmailTemp[i];//o char a assume a posição i de cada vez que o for rodar, cada posição de i vale como uma letra  
        if(a == '@'){//caso alguma posição i seja equivalente ao caractere @
            QtdArroba++;//Essa variável irá somar mais 1 a ela mesma.
        }
    }

DadosTam = 0;//Zera o tamanho da variável para ser reutilizada
        
    if(QtdArroba>1 || QtdArroba<1){//Caso o formato de e-mail esteja incorreto(e-mail só pode possuir um arroba)
        printf("\nFormato de e-mail inválido, recomece seu cadastro!\n");
            
      return 0;
    }
    
    if (QtdArroba == 1){
        strcpy(dados[pos].Email, EmailTemp);
    }


    //O usuário irá inserir um telefone de 11 digitos
    printf("\nTelefone(11 Digitos no Máximo): ");
    scanf("%s", &TelTemp);
    getchar();//Consome o enter inserido pelo usuário
    
    DadosTam = strlen(TelTemp);//Envia o tamanho do telefone para DadosTam
    
    if(DadosTam != 11){//Caso o tamanho do telefone seja diferente de 11 o mesmo será considerado inválido
        printf("\nQuantidade de digitos inválida, recomece seu cadastro!\n");

      return 0;  
    }

    strcpy(TelCMPExist, TelTemp);//Caso esteja tudo ok o telefone passará para próxima verificação

    for(int i=0;i<pos;i++){//percorre toda lista de contatos
        if(strcmp(TelCMPExist,dados[i].Telefone) == 0){//Comparando o telefone inserido com todos cadastrados
            printf("Este número já está salvo, delete ele caso queira cadastra-lo novamente!\n");//caso exista algum igual
            
          return 0;
        }
    }
    
    //O usuário poderá escolher entre 3 opções de relação
    printf("\nTipo de relação com o contato(1 = Pessoal \\ 2 = Profissional \\ 3 = Outros): ");
    scanf("%d", &dados[pos].RelationType);
    getchar();//Consome o enter inserido pelo usuário

    strcpy(dados[pos].Name, NameCMPExist);//o strcpy é chamado para passar a string da variável comparadora para a struct
    strcpy(dados[pos].Telefone, TelCMPExist);

    return 0;//finaliza a função
}

void ListContacts(int Cont){
int i,j;//declaro variáveis utilizadas na posição

    //Ordenação por Insertion Sort(Em ordem alfabetica)
    DadosCtt AuxSort;//Crio uma struct do mesmo tipo da minha struct que armazena os dados
    for(i = 0; i < Cont; i++){//percorre o vetor para ordenar os contatos pela ordem alfabetica dos nomes
        AuxSort = dados[i];//insiro os dados de cada posição da minha struct Dados nesta struct Ordenadora
                           //O programa ordena por ordem alfabetica, começando pelo nome do 1° contato
                           //indo até o último contato, movendo suas posições até que estejam todos em ordem alfabetica.
        for(j=i;(j>0) && (strcmp(AuxSort.Name,dados[j-1].Name)<0);j--)//Ordeno alfabeticamente através deste for
            dados[j] = dados[j - 1];//Vou movendo meu contato para esquerda até que o contato esteja na posição correta
        
        dados[j] = AuxSort;//Devolvo o contatos que está na posição correta para minha struct de contatos
    }//reinicia todo processo


    printf("####### LISTA DE CONTATOS #######\n");

    printf("\n------- CONTATOS PESSOAIS -------\n");

    int checkerCtt = 0;// Variável responsável por checar se existe algum contato em determinado tipo de relação

    //Após possuirmos todos contatos em ordem alfabetica os mesmos são separados em tipos de relação, continuando em ordem alfabetica
    //O que acontece é que o for a seguir percorre todos contatos inserindo no print apenas os contatos que possuem a condição do if
    //Para que os contatos sejam exibidos de forma correta, foi utilizado um for e um if para cada tipo de relação 
    for(i=0; i<Cont; i++) {//percorre todo vetor estático verificando se o tipo de relação de algum contato é igual a 1.
        if(dados[i].RelationType == 1){

            printf("Nome: %s", dados[i].Name);
            printf("Telefone: %s\n", dados[i].Telefone);
            printf("Endereço: %s", dados[i].Address);
            printf("Email: %s\n", dados[i].Email);
            checkerCtt++;
        }

    }

    //Caso o if acima não tenha se tornado válido nenhuma vez, este próximo if se torna verdadeiro
    if(checkerCtt==0){
        printf("Nenhum Contato encontrado!\n");
    }

    printf("------- RELACAO PROFISSIONAL -------\n");
    
    checkerCtt = 0;// Zerando variável responsável por checar se existe algum contato em determinado tipo de relação

    for(i=0; i<Cont; i++) {
        if(dados[i].RelationType == 2){

            printf("Nome: %s", dados[i].Name);
            printf("Telefone: %s\n", dados[i].Telefone);
            printf("Endereço: %s", dados[i].Address);
            printf("Email: %s\n", dados[i].Email);
            checkerCtt++;
        }
    }
    
    if(checkerCtt==0){
        printf("Nenhum Contato encontrado!\n");
    }


    printf("------- OUTRAS RELACOES -------\n");

    checkerCtt = 0;// Zerando variável responsável por checar se existe algum contato em determinado tipo de relação

    for(i=0; i<Cont; i++) {

        if(dados[i].RelationType == 3){

            printf("Nome: %s", dados[i].Name);
            printf("Telefone: %s\n", dados[i].Telefone);
            printf("Endereço: %s", dados[i].Address);
            printf("Email: %s\n", dados[i].Email);
            checkerCtt++;
        }

    }

    if(checkerCtt==0){
        printf("Nenhum Contato encontrado!\n");
    }

}

void searchContacts(int contt){
    char nome[100]; //variavél que armazena o nome a ser buscado
    char tel[12];
    int i,option;

    printf("\nInforme a opção para buscar(1 = Nome \\ 2 = Telefone): ");
    scanf("%d", &option);
    getchar();

    switch(option){
    case 1:

        printf("\nDigite o nome para busca: "); //interação com o usuário p/entrada e leitura de dados
        fgets(nome,100,stdin);

        for(i=0;i<contt;i++){ //leitura fazendo referencia a variavel name da struct dados (leitura da struct)
            if(strcmp(nome,dados[i].Name) == 0){ //compara a variavel nome com os dados armazenados na struct dados em Name,
                                            //se for verdadeira entra nas condicionais

                if(dados[i].RelationType == 1){ //inicia a condicional relacionando o nome com dado do tipo de relação que ele está vinculado
                    printf("\n------- INFORMAÇÕES DO CONTATO -------\n"); //se no caso o tipo de relação do nome for == 1 ele entre no primeiro if
                    printf("\n\tNome:    %s", dados[i].Name);              // e assim sucessivamente, relacionando o nome ao tipo de relação
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de relação: Pessoal");
                    printf("\n--------------------------------------\n");
                  
                  return 0;
                }

                if(dados[i].RelationType == 2){
                    printf("\n------- INFORMAÇÕES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de relação: Profissional");
                    printf("\n--------------------------------------\n");
                  
                  return 0;
                }

                if(dados[i].RelationType == 3){
                    printf("\n------- INFORMAÇÕES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de relação: Outras relações");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

            }
        }
    
    break;

    case 2:

        printf("\nDigite o telefone para busca: ");
        fgets(tel,12,stdin);
        getchar();

        for(i=0;i<contt;i++){
            if(strcmp(tel,dados[i].Telefone) == 0){


                if(dados[i].RelationType == 1){
                    printf("\n------- INFORMAÇÕES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de relação: Pessoal");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

                if(dados[i].RelationType == 2){
                    printf("\n------- INFORMAÇÕES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de relação: Profissional");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

                if(dados[i].RelationType == 3){
                    printf("\n------- INFORMAÇÕES DO CONTATO -------\n");
                    printf("\n\tNome:    %s", dados[i].Name);
                    printf("\tTelefone:  %s\n", dados[i].Telefone);
                    printf("\tEndereco:   %s", dados[i].Address);
                    printf("\tEmail:  %s", dados[i].Email);
                    printf("\tTipo de relação: Outras relações");
                    printf("\n--------------------------------------\n");
                  return 0;
                }

            }


        }

}

    if(strcmp(tel,dados[i].Telefone) != 0){
        printf("\nContato não cadastrado!\n");
      return 0;
    }
}


DadosCtt *DelContact(int Lastposition){//Recebe a posição do último vetor e nomeia-o como Lastposition

    char NomeCMPDel[101];// variável que irá receber o telefone do contato que o usuário deseja deletar (NomeComparatorDelete)
    int op2; // variável que irá receber a opção de busca de contato que o usuário irá utilizar
    char TelCMPDel[12];// variável que irá receber o telefone do contato que o usuário deseja deletar (TelefoneComparatorDelete)
    int i, n;// Variável contadora para percorrer toda lista;

    printf("\nDigite 1 para pesquisar por nome ou digite 2 para pesquisar por telefone: ");
    scanf("%d", &op2);
    //Envia a opção do usuário para o endereço de memória da variável op2
    getchar();//Consome o enter

    switch (op2)//envia o dado da variável op2 para o switch case comparar com os casos
    {

    case 1:
    //caso o usuário envie 1 para op2

        printf("Informe o nome do contato que deseja deletar: ");
        fgets(NomeCMPDel, 101, stdin); //Enviando o nome do contato que o usuário deseja deletar para
                                      //a variável NomeCMPDel

        for(i=0;i<Lastposition; i++){//percorre toda lista de contatos
            if(strcmp(NomeCMPDel,dados[i].Name) == 0){//condição responsável por checar se há algum nome igual ao inserido
                for(n = i; n < Lastposition; n++)//percorre do contato desejado para apagar até o último(Este for não possui chaves, pois só existe uma instrução pra ele que é a linha logo abaixo)
                    dados[n] = dados[n + 1];//movendo cada contato para uma posição a esquerda
                                        //levando o contato desejado para última posição
                Lastposition--;//Diminui uma posição para esquerda, que no caso apaga também o contato desejado

                printf("Contato excluido com sucesso!");

              return 0;
            
            }

        }

    break;

    case 2:
    //caso o usuário envie 2 para op2

        printf("Informe o telefone do contato que deseja deletar: ");
        fgets(TelCMPDel, 12, stdin); //Enviando o telefone do contato que o usuário deseja deletar para
                                     //a variável TelCMPDel

        for(i=0;i<Lastposition; i++){// for responsável por percorrer toda lista
            if(strcmp(TelCMPDel, dados[i].Telefone) == 0){// if testador caso encontre o telefone na lista
                for(n = i; n < Lastposition; n++)
                    dados[n] = dados[n + 1];

                Lastposition--;

                printf("Contato excluido com sucesso!");

              return 0;
            }

        }


    }
}

int main(){
    setlocale(LC_ALL, "");

    //Declaração de variáveis(Opção do usuário para qual função utilizar; Posição inicial do vetor que irá guardar os dados)
    int option;
    int pos=0;

    //Inicia o Programa em Loop
    do{

        //Zerando a variável de opção do menu
        option = 0;

        //Chama função menu para exibi-lo
        ShowMenu();

        //Selecionar opção do menu inicial
        printf("Digite a opção desejada: ");
        scanf("%d", &option);
        getchar();//Consome o enter digitado


        //switch case das opções do menu para chamar as funções desejadas
        switch (option){

        //Listar contatos
        case 1:
            CleanScreen();
            if(pos>0){
                ListContacts(pos++);
            }
            else{
                printf("Nenhum Contato cadastrado!\n");
            }
        break;

        //Buscar Contato
        case 2:
            CleanScreen();
            if(pos>0){
                searchContacts(pos++);
            }else
            {
                printf("Você não pode buscar nenhum contato, pois não possui nenhum contato cadastrado!\n");
            }
        break;

        //Adicionar contato
        case 3:
            CleanScreen();
            AddContact(pos++);
        break;

        //Deletar Contato    
        case 4:
            CleanScreen();
            if(pos>0){
            DelContact(pos++);
            }else
            {
                printf("Você não pode deletar nenhum contato, pois não possui nenhum contato cadastrado!\n");
            }
        break;

        //Caso o usuário escolha uma opção incorreta
        default:
            printf("Opção incorreta!\n");
        break;
        }
    }while (option==1 || option==2 || option==3 || option==4);//O while irá verificar se a opção selecionada foi um desses 4 valores

    return 0;
}