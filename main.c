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
        printf("Erro ao abrir o arquivo de dados.");

    fclose(arq);
}

void insercaoRegistro()
{
    reg.num[0] = 'a' + (char)(rand()%26);
}

int buscaRegistro(int chave)
{
    fread(&reg, sizeof(registro), 1, arq); //A cada fread, o ponteiro avança para o registro seguinte
    while(!feof(arq))
    {
        if(reg.num == chave)
        {
            fseek(arq, -sizeof(registro), SEEK_CUR //Posiciona o ponteiro no início do registro que contem a chave buscada
            return 1;
        }
        fread(&reg, sizeof(registro), 1, arq);
    }
    return 0; //Não encontrou
}

void removeRegistro()
{
// Utilização de caracteres $$$$$$$$$$$ para indicar fim do bloco
// Como cada bloco tem 512 bytes e queremos que os blocos possuam números inteiros de registros
// Irá ser utilizado até 5 registros por bloco sendo que os 12 últimos bytes de cada bloco serão preenchidos por caracteres '$'.
}

void listagemRegistros()
{

}


int main()
{
    return 0;
}
