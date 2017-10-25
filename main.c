#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *arq;

//Registros devem possuir tamanho fixo e no m�ximo 100 bytes cada um
typedef struct
{
    char num[24];
} registro;

registro reg;

//Opera��o de cria��o criando um arquivo bin�rio vazio. Esta opera��o pode sobrescrever um arquivo preexistente.
void criacaoArquivo()
{
    arq = fopen("arquivo.dat", "w+b"); //Abre um novo arquivo para grava��o de dados. Se o arquivo j� existir, a grava��o vai sobrescrever os dados existentes
    if (arq == NULL)
        printf("\nErro ao abrir o arquivo\n");
    fclose(arq);
}
//A inser��o de um registro deve fazer a leitura dos dados e inserir o registro no arquivo.
//Devem ser aproveitados os espa�os dispon�veis gerados por remo��es.
//N�o deve haver preocupa��o quanto a repeti��es de valores. Opcionalmente � leitura, os dados podem ser gerados aleatoriamente.
void insercaoRegistro()
{
    reg.num[0] = 'a' + (char)(rand()%26);
}

//Uma busca por um registro deve ser feita dado o valor de uma chave. Cada trabalho deve eleger uma �nica chave para esta busca.
//Como h� possibilidade de repeti��es, apenas a primeira ocorr�ncia da chave deve ser retornada.
//O conte�do do registro encontrado deve ser apresentado no caso de busca bem sucedida.
void buscaRegistro(int chave)
{
    arq = fopen("arquivo.dat", "w+b");
    if(arq == NULL)
            printf("\nErro ao abrir o arquivo\n");
    fread(&reg, sizeof(registro), 1, arq); //A cada fread, o ponteiro avan�a para o registro seguinte
    while(!feof(arq))
    {
        if(reg.num == chave)
        {
            fseek(arq, -sizeof(registro), SEEK_CUR); //Posiciona o ponteiro no in�cio do registro que contem a chave buscada
            printf("%c ", reg.num); //Imprime o registro encontrado
        }
        fread(&reg, sizeof(registro), 1, arq);
    }
    printf("Registro nao encontrado"); //N�o encontrou
}

//A remo��o, que � precedida de um busca, deve ser feita de forma l�gica. Assim, apenas deve-se controlar a validade ou n�o dos registros.
void removeRegistro()
{
// Utiliza��o de caracteres $$$$$$$$$$$ para indicar fim do bloco
// Como cada bloco tem 512 bytes e queremos que os blocos possuam n�meros inteiros de registros
// Ir� ser utilizado at� 5 registros por bloco sendo que os 12 �ltimos bytes de cada bloco ser�o preenchidos por caracteres '$'.
}

//A listagem corresponde � apresenta��o de todos os registros v�lidos existentes no arquivo, na ordem f�sica em que aparecem.
void listagemRegistros()
{
    int cont = 0;
    arq = fopen("arquivo.dat","r+a"); //Abre o arquivo bin�rio existente para leitura e grava��o de dados do come�o do arquivo
    if(arq == NULL)
        printf("\nErro ao abrir o arquivo\n");
    fread(&reg, sizeof(registro), 1, arq);
    cont = 1;
    while(!feof(arq))
    {
        printf("%c ", reg.num); //Imprime o registro
        fread(&reg, sizeof(registro), 1, arq); //Le o pr�ximo registro
        cont++;
        if(cont == 5) //Leu os 5 registros do bloco
        {
            fseek(arq, 12, SEEK_CUR); //Avan�a para o pr�ximo bloco
            cont = 0;
        }
    }
    fclose(arq);
}


int main()
{
    return 0;
}
