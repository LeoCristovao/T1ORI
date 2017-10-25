#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *arq;

//Registros devem possuir tamanho fixo e no máximo 100 bytes cada um
typedef struct
{
    char num[24];
} registro;

registro reg;

//Operação de criação criando um arquivo binário vazio. Esta operação pode sobrescrever um arquivo preexistente.
void criacaoArquivo()
{
    arq = fopen("arquivo.dat", "w+b"); //Abre um novo arquivo para gravação de dados. Se o arquivo já existir, a gravação vai sobrescrever os dados existentes
    if (arq == NULL)
        printf("\nErro ao abrir o arquivo\n");
    fclose(arq);
}
//A inserção de um registro deve fazer a leitura dos dados e inserir o registro no arquivo.
//Devem ser aproveitados os espaços disponíveis gerados por remoções.
//Não deve haver preocupação quanto a repetições de valores. Opcionalmente à leitura, os dados podem ser gerados aleatoriamente.
void insercaoRegistro()
{
    reg.num[0] = 'a' + (char)(rand()%26);
}

//Uma busca por um registro deve ser feita dado o valor de uma chave. Cada trabalho deve eleger uma única chave para esta busca.
//Como há possibilidade de repetições, apenas a primeira ocorrência da chave deve ser retornada.
//O conteúdo do registro encontrado deve ser apresentado no caso de busca bem sucedida.
void buscaRegistro(int chave)
{
    arq = fopen("arquivo.dat", "w+b");
    if(arq == NULL)
            printf("\nErro ao abrir o arquivo\n");
    fread(&reg, sizeof(registro), 1, arq); //A cada fread, o ponteiro avança para o registro seguinte
    while(!feof(arq))
    {
        if(reg.num == chave)
        {
            fseek(arq, -sizeof(registro), SEEK_CUR); //Posiciona o ponteiro no início do registro que contem a chave buscada
            printf("%c ", reg.num); //Imprime o registro encontrado
        }
        fread(&reg, sizeof(registro), 1, arq);
    }
    printf("Registro nao encontrado"); //Não encontrou
}

//A remoção, que é precedida de um busca, deve ser feita de forma lógica. Assim, apenas deve-se controlar a validade ou não dos registros.
void removeRegistro()
{
// Utilização de caracteres $$$$$$$$$$$ para indicar fim do bloco
// Como cada bloco tem 512 bytes e queremos que os blocos possuam números inteiros de registros
// Irá ser utilizado até 5 registros por bloco sendo que os 12 últimos bytes de cada bloco serão preenchidos por caracteres '$'.
}

//A listagem corresponde à apresentação de todos os registros válidos existentes no arquivo, na ordem física em que aparecem.
void listagemRegistros()
{
    int cont = 0;
    arq = fopen("arquivo.dat","r+a"); //Abre o arquivo binário existente para leitura e gravação de dados do começo do arquivo
    if(arq == NULL)
        printf("\nErro ao abrir o arquivo\n");
    fread(&reg, sizeof(registro), 1, arq);
    cont = 1;
    while(!feof(arq))
    {
        printf("%c ", reg.num); //Imprime o registro
        fread(&reg, sizeof(registro), 1, arq); //Le o próximo registro
        cont++;
        if(cont == 5) //Leu os 5 registros do bloco
        {
            fseek(arq, 12, SEEK_CUR); //Avança para o próximo bloco
            cont = 0;
        }
    }
    fclose(arq);
}


int main()
{
    return 0;
}
