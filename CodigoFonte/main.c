#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0



typedef struct BaseRetangular
{
    int posSupX, posSupY; //Posi��es x e y da coordenada superior direito
} Base;


//Atribui as posi��es x e y da base retangular superior direito.
void setPosicaoSuperior(Base *base,int x, int y)
{
    base->posSupX = x;
    base->posSupY = y;
}


//Muda a orienta��o do Rover se o comando for L
void orientacaoRoverL(char *orientacao)
{
    if(*orientacao == 'N') *orientacao = 'W';
    else if(*orientacao == 'W') *orientacao = 'S';
    else if(*orientacao == 'S') *orientacao = 'E';
    else if(*orientacao == 'E') *orientacao = 'N';
}



//Muda a orienta��o do Rover se o comando for R
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

    //Verifica se n�o saiu dos limites do grid
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

    //Calcula a rota que o Rover est� fazendo dentro da grid
    while(aux)
    {
        comando = getchar();

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

            case 'M': //Move na orienta��o que o Rover estiver
            {
                posicaoRover(base, orientacaoAtual, &posAtualX, &posAtualY);
                break;
            }

            //Imprime a posi��o e orienta��o do Rover
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
    int posX, posY; //Posi��es passadas pelo usu�rio da coordenada superior direito
    int posXInicial=0, posYInicial; //Posi��o inicial do Rover
    char orientacaoInicial; //Orienta��o inicial do Rover
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
