#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

struct necesidades_basicas{
    int salud;
    int alimentacion;
    int entretenimiento;
    int limpieza;
};

void imprimir_necesidades_basicas(struct necesidades_basicas * nb){
    printf("Salud: %i %%\n", (*nb).salud);
    printf("Alimentacion: %i %%\n", (*nb).alimentacion);
    printf("Entretenimiento: %i %%\n", (*nb).entretenimiento);
    printf("Limpieza: %i %%\n", (*nb).limpieza);
}

void inicializar_necesidades_basicas(struct necesidades_basicas * nb){
    (*nb).salud = 50;
    (*nb).alimentacion = 50;
    (*nb).entretenimiento = 50;
    (*nb).limpieza = 50;
}

char tecla;
unsigned int contador = 0;
unsigned int segundos = 0;
unsigned int minutos = 0;

int main()
{
    struct necesidades_basicas *nb_p, nb;
    nb_p = &nb;

    inicializar_necesidades_basicas(nb_p);

    imprimir_necesidades_basicas(nb_p);

    while(1)
    {

        if(kbhit())
        {
            tecla = getch();

            switch(tecla)
            {
               case 'M':
                   if (nb.salud < 100)
                        nb.salud += 5;
                   break;

                case 'F':
                   if (nb.alimentacion < 100)
                        nb.alimentacion += 10;
                   break;

                case 'P':
                   if (nb.entretenimiento < 100)
                        nb.entretenimiento += 5;
                   break;

                case 'B':
                   if (nb.limpieza < 100)
                        nb.limpieza = 100;
                   break;
            }
            system("cls");
            imprimir_necesidades_basicas(nb_p);
        }


        contador++;
        Sleep(100);
        if(contador==10)
        {

            segundos++;
            contador = 0;

            gotoxy(0+segundos-1,10);
            printf("%c",32);
            gotoxy(0+segundos,10);
            printf("*");

            if(segundos==30)
            {
                if(nb.limpieza > 5)
                    nb.limpieza -= 5;

                system("cls");
                imprimir_necesidades_basicas(nb_p);
            }

            if(segundos==60)
            {
                segundos = 0;

                if(nb.salud > 0)
                    nb.salud -= 5;
                if(nb.alimentacion > 0)
                    nb.alimentacion -= 3;
                if(nb.entretenimiento > 0)
                    nb.entretenimiento -= 5;

                system("cls");
                imprimir_necesidades_basicas(nb_p);
            }

        }

    }


    return 0;
}
