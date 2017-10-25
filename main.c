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
        printf("Erro ao abrir o arquivo de dados.");

    fclose(arq);
}

void insercaoRegistro()
{
    reg.num[0] = 'a' + (char)(rand()%26);
}

int buscaRegistro(int chave)
{
    fread(&reg, sizeof(registro), 1, arq); //A cada fread, o ponteiro avan�a para o registro seguinte
    while(!feof(arq))
    {
        if(reg.num == chave)
        {
            fseek(arq, -sizeof(registro), SEEK_CUR //Posiciona o ponteiro no in�cio do registro que contem a chave buscada
            return 1;
        }
        fread(&reg, sizeof(registro), 1, arq);
    }
    return 0; //N�o encontrou
}

void removeRegistro()
{
// Utiliza��o de caracteres $$$$$$$$$$$ para indicar fim do bloco
// Como cada bloco tem 512 bytes e queremos que os blocos possuam n�meros inteiros de registros
// Ir� ser utilizado at� 5 registros por bloco sendo que os 12 �ltimos bytes de cada bloco ser�o preenchidos por caracteres '$'.
}

void listagemRegistros()
{

}


int main()
{
    return 0;
}
