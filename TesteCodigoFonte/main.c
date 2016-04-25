#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0



typedef struct BaseRetangular
{
    int posSupX, posSupY; //Posições x e y da coordenada superior direito
} Base;



//Cria a rota que o Rover faz a cada comando dado em uma matriz IxJ representando o campo navegado por ele.
void teste(int posX, int posY, int posXInicial, int posYInicial, char orientacaoInicial)
{
    int i, j;

    for(i = posY; i >= 0; i--)
    {
        //Enumera as colunas da matriz
        if(posY < 10) printf("%d ", i);
        else
        {
            if(i < 10) printf("%d  ", i);
            else printf("%d ", i);
        }

        //Constrói a matriz. Ponto '.' representa uma posição, uma letra 'S', 'W', 'E' ou 'N' é onde o Rover está localizado.
        for(j = 0; j <= posX; j++)
        {
            if(posX < 10)
            {
                if(j == posXInicial && i == posYInicial) printf("%c ", orientacaoInicial);
                else printf(". ");
            }
            else
            {
                if(j == posXInicial && i == posYInicial) printf("%c  ", orientacaoInicial);
                else printf(".  ");
            }
        }
        printf("\n");
    }


    //Coloca o espaço inicial entre os indices e a matriz
    if(posY < 10) printf("  ");
    else
    {
        if(i < 10) printf("   ");
        else printf("  ");
    }

    //Enumera as linhas da matriz
    for(i = 0; i <= posX; i++)
    {
        if(posX < 10) printf("%d ", i);
        else
        {
            if(i < 10) printf("%d  ", i);
            else printf("%d ", i);
        }
    }

    printf("\n");
}



//Atribui as posições x e y da base retangular superior direito.
void setPosicaoSuperior(Base *base,int x, int y)
{
    base->posSupX = x;
    base->posSupY = y;
}


//Muda a orientação do Rover se o comando for L
void orientacaoRoverL(char *orientacao)
{
    if(*orientacao == 'N') *orientacao = 'W';
    else if(*orientacao == 'W') *orientacao = 'S';
    else if(*orientacao == 'S') *orientacao = 'E';
    else if(*orientacao == 'E') *orientacao = 'N';
}



//Muda a orientação do Rover se o comando for R
void orientacaoRoverR(char *orientacao)
{
    if(*orientacao == 'N') *orientacao = 'E';
    else if(*orientacao == 'E') *orientacao = 'S';
    else if(*orientacao == 'S') *orientacao = 'W';
    else if(*orientacao == 'W') *orientacao = 'N';
}


//Muda a posical do Rover
void posicaoRover(Base base, char orientacao, int *x, int *y)
{
    if(orientacao == 'N') *y += 1;
    else if(orientacao == 'E') *x += 1;
    else if(orientacao == 'S') *y -= 1;
    else if(orientacao == 'W') *x -= 1;

    //Verifica se não saiu dos limites do grid
    if(*x < 0) *x = 0;
    if(*x > base.posSupX) *x = base.posSupX;
    if(*y < 0) *y = 0;
    if(*y > base.posSupY) *y = base.posSupY;
}


//Controla o movimento do Rover
void movimentoRover(Base base, int posXRover, int PosYRover, char orientacao, int posX, int posY)
{
    char comando = 'L';
    char orientacaoAtual = orientacao;
    int posAtualX = posXRover, posAtualY = PosYRover;
    int aux = TRUE;

    getchar();

    //Calcula a rota que o Rover está fazendo dentro da grid
    while(aux)
    {
        comando = getchar();

        teste(posX, posY, posAtualX, posAtualY, orientacaoAtual);
        printf("\n");

        switch(comando)
        {
            case 'L': //Vira a esquerda
            {
                orientacaoRoverL(&orientacaoAtual);

                break;
            }

            case 'R': //Vira a direita
            {
                orientacaoRoverR(&orientacaoAtual);
                break;
            }

            case 'M': //Move na orientação que o Rover estiver
            {
                posicaoRover(base, orientacaoAtual, &posAtualX, &posAtualY);
                break;
            }

            //Imprime a posição e orientação do Rover
            default:
            {
                printf("%d %d %c\n", posAtualX, posAtualY, orientacaoAtual);
                aux = FALSE;
            }
        }
    }
}


int main()
{
    int posX, posY; //Posições passadas pelo usuário da coordenada superior direito
    int posXInicial=0, posYInicial; //Posição inicial do Rover
    char orientacaoInicial; //Orientação inicial do Rover
    Base base;

    scanf("%d%d", &posX, &posY);

    setPosicaoSuperior(&base, posX, posY);

    while(scanf("%d", &posXInicial) > 0)
    {
        scanf("%d %c", &posYInicial, &orientacaoInicial);
        movimentoRover(base, posXInicial, posYInicial, orientacaoInicial, posX, posY);
    }


    return 0;
}
