#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tpuntuaciones
{
char nombre [10];
int puntos;
}Tpuntos;

int menup(int x,int y,int s);
char elerom(int x, int y, int c);
char elenum(int x, int y, int n);
char elesim(int x, int y, char r);
void romanos(void);
void simbolos(void);
void juego1(void);
void juego2(void);
void logotipo(int x, int y);
void PintarLineaHz(int x, int y,int tam,int col, char l);
void PintarLineaVt(int x, int y,int tam,int col, char l);
void creditos(void);
void bienomal(int x);
void Listar(Tpuntos datos[10], int cant,int juego);
void Guardarpuntos(char NomArchi[15], Tpuntos datos[15], int cant);
void main()
{
	int s,c;
  
	Tpuntos puntajes1[15],puntajes2[15];
	
	textbackground(BLUE);
    clrscr();
    randomize();
    PintarLineaHz(1, 17, 75, WHITE,'Û' );
    PintarLineaVt(1, 17, 10, WHITE,'Û' );
    PintarLineaHz(1, 27, 75, WHITE,'Û' );
    PintarLineaVt(77,17, 10, WHITE,'Û' );
   
    logotipo(3,20);
  
    do
    {
    	
    	s = menup(20,5,c);
    	switch(s)
    	{
    		case 1: romanos();
   			break;
   			case 2: simbolos();
   			break;
   			case 3: juego1();
   			break;
   			case 4: juego2();
   			break;
   			case 5: creditos();
   			break;
   		}
   	}while(s!=6); 			   
}

void PintarLineaHz(int x, int y,int tam,int col, char l)
{
   int i;
   textcolor(col);

   for (i=x; i<=x+tam ; i++)
   {
  
	   gotoxy(i,y);
	   cprintf("%c",l);
   }

}
void PintarLineaVt(int x, int y,int tam,int col, char l)
{

   int j;
   textcolor(col);

   for (j=y; j<=y+tam ; j++)
   {
  
	   gotoxy(x,j);
	   cprintf("%c",l);
   }


}
void logotipo(int x, int y)
{
	gotoxy(x,y);  cprintf("###     ##   ##    ##   ##   ##    #   ##     ##       ##  ##            ");
	gotoxy(x,y+1);cprintf("#  #   #  #  # #  # #  #  #  # #   #  #  #   #  #   ###      ###    #####");
	gotoxy(x,y+2);cprintf("###   #    # #  ##  #  #  #  #  #  # #    #   #   #              #       ");
	gotoxy(x,y+3);cprintf("#  #   #  #  #      # ###### #   # #  #  #  #  #    ###      ###    #####");
	gotoxy(x,y+4);cprintf("#   #   ##   #      # #    # #    ##   ##    ##        ##   ##           ");
	
	gotoxy(x,y+10);cprintf("presione una tecla para acceder al menu principal");
	getch();
	getch();
	
}
int menup(int x,int y, int s)
{
	textbackground(GREEN);
	clrscr();
	PintarLineaHz(18, 4, 55, LIGHTRED,'Û' );
    PintarLineaVt(18, 4, 8,  YELLOW,'Û' );
    PintarLineaHz(18, 13,55, LIGHTRED,'Û' );
    PintarLineaVt(73, 4, 8,  YELLOW,'Û' ); 

	gotoxy(x,y);  cprintf("Que deseas hacer?");
	gotoxy(x,y+2);cprintf("1.Aprender numeros romanos");
	gotoxy(x,y+3);cprintf("2.Aprender mayor que, menor que e igual");
	gotoxy(x,y+4);cprintf("3.Jugar mayor que, menor que con numeros normales");
	gotoxy(x,y+5);cprintf("4.Jugar mayor que, menor que con numeros romanos");
	gotoxy(x,y+6);cprintf("5.Ver creditos");
	gotoxy(x,y+7);cprintf("6.Salir del juego\n");
	
	gotoxy(x,y+11);cprintf("Instrucciones:");
	gotoxy(x,y+12);cprintf("Para que funcione el programa, solo se utilizan los numeros");
	gotoxy(x,y+13);cprintf("ya que el programa fue diseñado solo para usar numeros");
	gotoxy(x,y+14);cprintf("cualquier otra tecla hara que el programa deje de funcionar");
	
	gotoxy(x+18,y);
	
	cscanf("%i",&s);
	
	return s;
}
void romanos(void)
{
	textbackground(BLUE);
	clrscr();
	cprintf("vamos a aprender los numeros romanos");
	getch();
	getch();
	clrscr();
	gotoxy(2,20);cprintf("Primero que nada, los numeros romanos utilizan 7 letras mayu£sculas,");
	gotoxy(2,21);cprintf("pero en este juego solo vamos a aprender las primeras cuatro y");
	gotoxy(2,22);cprintf("para empezar, vamos a aprender el valor de cada una");
	getch();
	getch();
	clrscr();
	
	elerom(2,2,1);
	elesim(15,2,'=');
	elenum(25,2,1);
	
	elerom(2,10,5);
	elesim(15,10,'=');
	elenum(25,10,5);
	
	elerom(2,20,10);
	elesim(10,20,'=');
	elenum(18,20,10);
	
	elerom(2,30,50);
	elesim(10,30,'=');
	elenum(18,30,50);
	
	getch();
	getch();
	
	clrscr();
	gotoxy(2,10);cprintf("Muy bien!, ahora que conoces los valores de cada n£mero tendras que aprender las siguientes reglas:");
	gotoxy(2,14);cprintf("1:Si a la derecha de un n£mero romano se escribe otro igual o menor, el valor de este se suma al anterior");
	gotoxy(2,16);cprintf("ejemplo:");
	
	elerom(2,18,6);
	elesim(20,18,'=');
	elenum(30,18,6);
	getch();
	getch();
	clrscr();
	gotoxy(2,10);cprintf("2:el n£mero I colocado detr s de la V o la X, les resta 1; la X, detr s de la L le resta 10");
	gotoxy(2,14);cprintf("ejemplo:");
	
	elerom(2,18,9);
	elesim(15,18,'=');
	elenum(25,18,9);
	
	elerom(2,24,40);
	elesim(15,24,'=');
	elenum(25,24,40);
	
	gotoxy(2,30);cprintf("3:En ning£n n£mero se puede poner una misma letra m s de tres veces seguidas");
	gotoxy(2,32);cprintf("Bueno, ahora que conoces los numeros y las reglas pasaremos de nuevo al men£ principal");
	gotoxy(2,36);cprintf("presiona una tecla para regresar");
	getch();
	getch();
}
void simbolos(void)
{

	textbackground(BLUE);
	clrscr();
	gotoxy(5,20);cprintf("ahora aprenderemos a usar los signos mayor que, menor que e igual");
	gotoxy(5,21);cprintf("bueno, no es tan complicado; solo necesitas recordas estas dos reglas:");
	gotoxy(5,22);cprintf("1: El numero que tiene mas valor es el que va del lado abierto del signo");
	gotoxy(5,23);cprintf("2: La forma de expresar las comparaciones son muy sencillas");
	getch();
	getch();
	clrscr();
	gotoxy(5,12);cprintf("la siguente comparacion se escribe de la siguiente manera:");
	elenum(5,15,18);
	elenum(30,15,24);
	elesim(20,15,'<');
	gotoxy(5,22);cprintf("18 es menor que 24");
	getch();
	getch();
	clrscr();
	gotoxy(5,12);cprintf("la siguente comparacion se escribe de la siguiente manera:");
	elenum(5,15,24);
	elenum(30,15,18);
	elesim(20,15,'>');
	gotoxy(5,22);cprintf("24 es mayor que 18");
	gotoxy(5,24);cprintf("con esto termina el tutorial del juego");
	gotoxy(5,25);cprintf("ahora podemos jugar a comparaciones!:)");
	gotoxy(5,26);cprintf("presiona una tecla para regresar al menu principal y elegir el juego");
	getch();
	getch();	
}
void juego1(void)                                             
{
	int veses, puntaje=0, n=random(50), m=random(50), result, opc=random(3),intentos;
	char y, u, i,nam1[10];
	y = '>';
	u = '<';
	i = '=';
	textbackground(BLUE);
 
	clrscr();
	gotoxy(5,20);cprintf("Juguemos a comparar numeros normales con mayor que,menor que e igual");
	getch();
	getch();
	clrscr();
	gotoxy(25,20);cprintf("¨Cu ntas veces quieres intentarlo? ");
	cscanf("%i",& veses);
	intentos=veses;
	clrscr();
	gotoxy(20,20);cprintf("ok, entonces jugaremos %i veces", veses);
	getch();
	getch();
	
	do
	{
		switch(opc=random(3))
		{
			case 0:
		
			clrscr();
			n=random(25);
			m=random(25)+25;
			elenum(5,15,n);
			elenum(30,15,m);
			elesim(20,15,u);
			gotoxy(10,25);cprintf("¨Cual es la expresion correcta? ");
			gotoxy(10,28);cprintf("1)%i es menor que %i",n,m);
			gotoxy(10,29);cprintf("2)%i es mayor a %i",n,m);
			gotoxy(10,30);cprintf("3)%i es igual a %i",n,m);
			gotoxy(10,26);cscanf("%i",& result);

			if (result==1)
			{

        		bienomal(1);
        		puntaje=puntaje+1;
        		getch();
        		getch();
        		veses=veses-1;
       
			}
			else
			{

       			bienomal(2);	
       			getch();
       			getch();
       			veses=veses-1;
       		}
				
			
			break;
			case 1:
			clrscr();
			n=random(25)+25;
			m=random(25);
			elenum(5,15,n);
			elenum(30,15,m);
			elesim(20,15,y);
			gotoxy(10,25);cprintf("¨Cual es la expresion correcta? ");
			gotoxy(10,28);cprintf("1)%i es menor que %i",n,m);
			gotoxy(10,29);cprintf("2)%i es mayor a %i",n,m);
			gotoxy(10,30);cprintf("3)%i es igual a %i",n,m);
			gotoxy(10,26);cscanf("%i",& result);

			if (result==2)
			{

        		bienomal(1);
        		puntaje=puntaje+1;
        		getch();
        		getch();
        		veses=veses-1;
       
			}
			else
			{
				bienomal(2);
       			getch();
       			getch();
       			veses=veses-1;
       		}
       		break;
       		case 2:
       		clrscr();
       		n=random(50);
       		m=n;
       		elenum(5,15,n);
       		elenum(30,15,m);
       		elesim(20,15,i);
       		gotoxy(10,25);cprintf("¨Cual es la expresion correcta? ");
			gotoxy(10,28);cprintf("1)%i es menor que %i",n,m);
			gotoxy(10,29);cprintf("2)%i es mayor a %i",n,m);
			gotoxy(10,30);cprintf("3)%i es igual a %i",n,m);
			gotoxy(10,26);cscanf("%i",& result);
			
			if (result==3)
			{

        		bienomal(1);
        		puntaje=puntaje+1;
        		getch();
        		getch();
        		veses=veses-1;
       
			}
			else
			{
				bienomal(2);
       			getch();
       			getch();
       			veses=veses-1;
       		}
					
		}
	}while(veses>0);
	clrscr();
	gotoxy(10,20);cprintf("tu puntaje final fue: %i", puntaje);
	elenum(15,25,puntaje);
	getch();
	getch();
	if(puntaje>intentos/2)
	{
	clrscr();
	bienomal(3);
	gotoxy(5,20);cprintf("ahora, ¨ser s capaz de superar las comparaciones con los numeros romanos?");
	getch();
	getch();
	}
	else
	{
	clrscr();
	bienomal(4);
	getch();
	getch();
	}
}
void juego2(void)
{
	int vcs, punt=0,resul, r=random(50), n=random(50),opc=random(3), intentos;
	char y, u, i,nam[10];
	y = '>';
	u = '<';
	i = '=';
	textbackground(BLUE);
	
	clrscr();
	gotoxy(5,20);cprintf("Juguemos a comparar numeros romanos con mayor que,menor que e igual");
	getch();
	getch();
	clrscr();
	gotoxy(25,20);cprintf("¨Cu ntas veces quieres intentarlo? ");
	cscanf("%i",& vcs);
	intentos=vcs;
	clrscr();
	gotoxy(20,20);cprintf("ok, entonces jugaremos %i veces", vcs);
	getch();
	getch();
		
	do
	{
		switch(opc=random(3))
		{
			case 0:
		
			clrscr();
			n=random(25)+25;
			r=random(25);
			elerom(5,15,n);
			elerom(48,15,r);
			elesim(38,15,y);
			gotoxy(10,25);cprintf("¨Cual es la expresion correcta? ");
			gotoxy(10,28);cprintf("1)A es mayor que B");
			gotoxy(10,29);cprintf("2)A es igual a B");
			gotoxy(10,30);cprintf("3)A es menor a B");
			gotoxy(10,26);cscanf("%i",& resul);

			if (resul==1)
			{

        		bienomal(1);
        		punt=punt+1;
        		getch();
        		getch();
        		vcs=vcs-1;
       
			}
			else
			{

       			bienomal(2);	
       			getch();
       			getch();
       			vcs=vcs-1;
       		}
				
			
			break;
			case 1:
			clrscr();
			n=random(25);
			r=random(25)+25;
			elerom(5,15,n);
			elerom(48,15,r);
			elesim(38,15,u);
			gotoxy(10,25);cprintf("¨Cual es la expresion correcta? ");
			gotoxy(10,28);cprintf("1)A es mayor que B");
			gotoxy(10,29);cprintf("2)A es igual a B");
			gotoxy(10,30);cprintf("3)A es menor a B");
			gotoxy(10,26);cscanf("%i",& resul);

			if (resul==3)
			{

        		bienomal(1);
        		punt=punt+1;
        		getch();
        		getch();
        		vcs=vcs-1;
       
			}
			else
			{
				bienomal(2);
       			getch();
       			getch();
       			vcs=vcs-1;
       		}
       		break;
       		case 2:
       		clrscr();
       		n=random(50);
       		r=n;
       		elerom(5,15,n);
       		elerom(48,15,r);
       		elesim(38,15,i);
       		gotoxy(10,25);cprintf("¨Cual es la expresion correcta? ");
			gotoxy(10,28);cprintf("1)A es mayor que B",n,r);
			gotoxy(10,29);cprintf("2)A es igual a B",n,r);
			gotoxy(10,30);cprintf("3)A es menor a B",n,r);
			gotoxy(10,26);cscanf("%i",& resul);
			
			if (resul==2)
			{

        		bienomal(1);
        		punt=punt+1;
        		getch();
        		getch();
        		vcs=vcs-1;
       
			}
			else
			{
				bienomal(2);
       			getch();
       			getch();
       			vcs=vcs-1;
       		}
					
		}
	}while(vcs>0);
	clrscr();
	gotoxy(10,20);cprintf("tu puntaje final fue: %i", punt);
	elenum(15,25,punt);
	getch();
	getch();
	if(punt>intentos/2)
	{
	clrscr();
	bienomal(3);
	gotoxy(10,20);cprintf("TE HAS CONVERTIDO EN TODO UN MAESTRO DE LAS COMPARACIONES!"); 
	getch();
	getch();
	}
	else
	{
	clrscr();
	bienomal(4);
	getch();
	getch();
	}
}
void creditos(void)
{
	textcolor(LIGHTRED);
	textbackground(BLUE);
	clrscr();
	gotoxy(17,13);cprintf("Este juego ha sido dise¤ado, creado y reproducido por:");
	gotoxy(28,14);cprintf("Enrique Martinez Salas");
	gotoxy(30,15);cprintf("Registro: 1922510");
	gotoxy(28,21);cprintf("Universidad Autonoma");
	gotoxy(30,22);cprintf("De Guadalajara");
	gotoxy(20,18);cprintf("ver.1 lanzada en 26/04/2013");
	
	PintarLineaHz(15, 11, 57, WHITE,'Û' );
    PintarLineaVt(15, 11, 13,  WHITE,'Û' );
    PintarLineaHz(15, 25,57, WHITE,'Û' );
    PintarLineaVt(72, 12, 13,  WHITE,'Û' ); 
	getch();
	getch();
}
char elerom(int x, int y, int c)
{
	textcolor(YELLOW);
	switch (c)
	{
		case 1:
		gotoxy(x,y);  cprintf("##########");
		gotoxy(x,y+1);cprintf("    ##    ");
		gotoxy(x,y+2);cprintf("    ##    ");
		gotoxy(x,y+3);cprintf("    ##    ");
		gotoxy(x,y+4);cprintf("##########");
		break;
		case 2:
		gotoxy(x,y);  cprintf("######### ");
		gotoxy(x,y+1);cprintf("  #   #   ");
		gotoxy(x,y+2);cprintf("  #   #   ");
		gotoxy(x,y+3);cprintf("  #   #   ");
		gotoxy(x,y+4);cprintf("######### ");
		break;
		case 3:
		gotoxy(x,y);  cprintf("#########");
		gotoxy(x,y+1);cprintf("  # # #  ");
		gotoxy(x,y+2);cprintf("  # # #  ");
		gotoxy(x,y+3);cprintf("  # # #  ");
		gotoxy(x,y+4);cprintf("#########");
		break;
		case 4:
		gotoxy(x,y);  cprintf("##### #        #");
		gotoxy(x,y+1);cprintf("  #    #      # ");
		gotoxy(x,y+2);cprintf("  #     #    #  ");
		gotoxy(x,y+3);cprintf("  #      #  #   ");
		gotoxy(x,y+4);cprintf("#####     ##    ");
		break;
		case 5:
		gotoxy(x,y);  cprintf("##      ##");
		gotoxy(x,y+1);cprintf(" ##    ## ");
		gotoxy(x,y+2);cprintf("  ##  ##  ");
		gotoxy(x,y+3);cprintf("   ####   ");
		gotoxy(x,y+4);cprintf("    ##    ");
		break;
		case 6:
		gotoxy(x,y);  cprintf("#        # ###");
		gotoxy(x,y+1);cprintf(" #      #   # ");
		gotoxy(x,y+2);cprintf("  #    #    # ");
		gotoxy(x,y+3);cprintf("   #  #     # ");
		gotoxy(x,y+4);cprintf("    ##     ###");
		break;
		case 7:
		gotoxy(x,y);  cprintf("#        # #####");
		gotoxy(x,y+1);cprintf(" #      #   # # ");
		gotoxy(x,y+2);cprintf("  #    #    # # ");
		gotoxy(x,y+3);cprintf("   #  #     # # ");
		gotoxy(x,y+4);cprintf("    ##     #####");
		break;
		case 8:
		gotoxy(x,y);  cprintf("#        # #######");
		gotoxy(x,y+1);cprintf(" #      #   # # # ");
		gotoxy(x,y+2);cprintf("  #    #    # # # ");
		gotoxy(x,y+3);cprintf("   #  #     # # # ");
		gotoxy(x,y+4);cprintf("    ##     #######");
		break;
		case 9:
		gotoxy(x,y);  cprintf("##### #   #");
		gotoxy(x,y+1);cprintf("  #    # # ");
		gotoxy(x,y+2);cprintf("  #     #  ");
		gotoxy(x,y+3);cprintf("  #    # # ");
		gotoxy(x,y+4);cprintf("##### #   #");
		break;
		case 10:
		gotoxy(x,y);  cprintf("##   ##");
		gotoxy(x,y+1);cprintf(" ## ## ");
		gotoxy(x,y+2);cprintf("  ##   ");
		gotoxy(x,y+3);cprintf(" ## ## ");
		gotoxy(x,y+4);cprintf("##   ##");
		break;
		case 11:
		gotoxy(x,y);  cprintf("#   # #####");
		gotoxy(x,y+1);cprintf(" # #    #  ");
		gotoxy(x,y+2);cprintf("  #     #  ");
		gotoxy(x,y+3);cprintf(" # #    #  ");
		gotoxy(x,y+4);cprintf("#   # #####");
		break;
		case 12:
		gotoxy(x,y);  cprintf("#   # #####");
		gotoxy(x,y+1);cprintf(" # #   # # ");
		gotoxy(x,y+2);cprintf("  #    # # ");
		gotoxy(x,y+3);cprintf(" # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #####");
		break;
		case 13:
		gotoxy(x,y);  cprintf("#   # #######");
		gotoxy(x,y+1);cprintf(" # #   # # # ");
		gotoxy(x,y+2);cprintf("  #    # # # ");
		gotoxy(x,y+3);cprintf(" # #   # # # ");
		gotoxy(x,y+4);cprintf("#   # #######");
		break;
		case 14:
		gotoxy(x,y);  cprintf("#   # ### #   #");
		gotoxy(x,y+1);cprintf(" # #   #  #   #");
		gotoxy(x,y+2);cprintf("  #    #  #   #");
		gotoxy(x,y+3);cprintf(" # #   #   # # ");
		gotoxy(x,y+4);cprintf("#   # ###   #  ");
		break;
		case 15:
		gotoxy(x,y);  cprintf("#   # #   #");
		gotoxy(x,y+1);cprintf(" # #  #   #");
		gotoxy(x,y+2);cprintf("  #   #   #");
		gotoxy(x,y+3);cprintf(" # #   # # ");
		gotoxy(x,y+4);cprintf("#   #   #  ");
		break;
		case 16:
		gotoxy(x,y);  cprintf("#   # #   # ###");
		gotoxy(x,y+1);cprintf(" # #  #   #  # ");
		gotoxy(x,y+2);cprintf("  #   #   #  # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # ");
		gotoxy(x,y+4);cprintf("#   #   #   ###");
		break;
		case 17:
		gotoxy(x,y);  cprintf("#   # #   # #####");
		gotoxy(x,y+1);cprintf(" # #  #   #  # # ");
		gotoxy(x,y+2);cprintf("  #   #   #  # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   #   #   #####");
		break;
		case 18:
		gotoxy(x,y);  cprintf("#   # #   # #######");
		gotoxy(x,y+1);cprintf(" # #  #   #  # # # ");
		gotoxy(x,y+2);cprintf("  #   #   #  # # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # # # ");
		gotoxy(x,y+4);cprintf("#   #   #   #######");
		break;
		case 19:
		gotoxy(x,y);  cprintf("#   # ### #   #");
		gotoxy(x,y+1);cprintf(" # #   #   # # ");
		gotoxy(x,y+2);cprintf("  #    #    #  ");
		gotoxy(x,y+3);cprintf(" # #   #   # # ");
		gotoxy(x,y+4);cprintf("#   # ### #   #");
		break;
		case 20:
		gotoxy(x,y);  cprintf("#   # #   #");
		gotoxy(x,y+1);cprintf(" # #   # # ");
		gotoxy(x,y+2);cprintf("  #     #  ");
		gotoxy(x,y+3);cprintf(" # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   #");
		break;
		case 21:
		gotoxy(x,y);  cprintf("#   # #   # ###");
		gotoxy(x,y+1);cprintf(" # #   # #   # ");
		gotoxy(x,y+2);cprintf("  #     #    # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # ");
		gotoxy(x,y+4);cprintf("#   # #   # ###");
		break;
		case 22:
		gotoxy(x,y);  cprintf("#   # #   # #####");
		gotoxy(x,y+1);cprintf(" # #   # #   # # ");
		gotoxy(x,y+2);cprintf("  #     #    # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #####");
		break;
		case 23:
		gotoxy(x,y);  cprintf("#   # #   # #######");
		gotoxy(x,y+1);cprintf(" # #   # #   # # # ");
		gotoxy(x,y+2);cprintf("  #     #    # # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #######");
		break;
		case 24:
		gotoxy(x,y);  cprintf("#   # #   # ### #   #");
		gotoxy(x,y+1);cprintf(" # #   # #   #  #   #");
		gotoxy(x,y+2);cprintf("  #     #    #  #   #");
		gotoxy(x,y+3);cprintf(" # #   # #   #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # ###   #  ");
		break;
		case 25:
		gotoxy(x,y);  cprintf("#   # #   # #   #");
		gotoxy(x,y+1);cprintf(" # #   # #  #   #");
		gotoxy(x,y+2);cprintf("  #     #   #   #");
		gotoxy(x,y+3);cprintf(" # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   #   #  ");
		break;
		case 26:
		gotoxy(x,y);  cprintf("#   # #   # #   # ###");
		gotoxy(x,y+1);cprintf(" # #   # #  #   #  # ");
		gotoxy(x,y+2);cprintf("  #     #   #   #  # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # ");
		gotoxy(x,y+4);cprintf("#   # #   #   #   ###");
		break;
		case 27:
		gotoxy(x,y);  cprintf("#   # #   # #   # #####");
		gotoxy(x,y+1);cprintf(" # #   # #  #   #  # # ");
		gotoxy(x,y+2);cprintf("  #     #   #   #  # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   #   #   #####");
		break;
		case 28:
		gotoxy(x,y);  cprintf("#   # #   # #   # #######");
		gotoxy(x,y+1);cprintf(" # #   # #  #   #  # # # ");
		gotoxy(x,y+2);cprintf("  #     #   #   #  # # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # # # ");
		gotoxy(x,y+4);cprintf("#   # #   #   #   #######");
		break;
		case 29:
		gotoxy(x,y);  cprintf("#   # #   # ### #   #");
		gotoxy(x,y+1);cprintf(" # #   # #   #   # # ");
		gotoxy(x,y+2);cprintf("  #     #    #    #  ");
		gotoxy(x,y+3);cprintf(" # #   # #   #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # ### #   #");
		break;
		case 30:
		gotoxy(x,y);  cprintf("#   # #   # #   #");
		gotoxy(x,y+1);cprintf(" # #   # #   # # ");
		gotoxy(x,y+2);cprintf("  #     #     #  ");
		gotoxy(x,y+3);cprintf(" # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   #");
		break;
		case 31:
		gotoxy(x,y);  cprintf("#   # #   # #   # ###");
		gotoxy(x,y+1);cprintf(" # #   # #   # #   # ");
		gotoxy(x,y+2);cprintf("  #     #     #    # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   # ###");
		break;
		case 32:
		gotoxy(x,y);  cprintf("#   # #   # #   # #####");
		gotoxy(x,y+1);cprintf(" # #   # #   # #   # # ");
		gotoxy(x,y+2);cprintf("  #     #     #    # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   # #####");
		break;
		case 33:
		gotoxy(x,y);  cprintf("#   # #   # #   # #######");
		gotoxy(x,y+1);cprintf(" # #   # #   # #   # # # ");
		gotoxy(x,y+2);cprintf("  #     #     #    # # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   # #######");
		break;
		case 34:
		gotoxy(x,y);  cprintf("#   # #   # #   # ### #   #");
		gotoxy(x,y+1);cprintf(" # #   # #   # #   #  #   #");
		gotoxy(x,y+2);cprintf("  #     #     #    #  #   #");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   # ###   #  ");
		break;
		case 35:
		gotoxy(x,y);  cprintf("#   # #   # #   # #   #");
		gotoxy(x,y+1);cprintf(" # #   # #   # #  #   #");
		gotoxy(x,y+2);cprintf("  #     #     #   #   #");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   #   #  ");
		break;
		case 36:
		gotoxy(x,y);  cprintf("#   # #   # #   # #   # ###");
		gotoxy(x,y+1);cprintf(" # #   # #   # #  #   #  # ");
		gotoxy(x,y+2);cprintf("  #     #     #   #   #  # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # #   # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   #   #   ###");
		break;
		case 37:
		gotoxy(x,y);  cprintf("#   # #   # #   # #   # #####");
		gotoxy(x,y+1);cprintf(" # #   # #   # #  #   #  # # ");
		gotoxy(x,y+2);cprintf("  #     #     #   #   #  # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   #   #   #####");
		break;
		case 38:
		gotoxy(x,y);  cprintf("#   # #   # #   # #   # #######");
		gotoxy(x,y+1);cprintf(" # #   # #   # #  #   #  # # # ");
		gotoxy(x,y+2);cprintf("  #     #     #   #   #  # # # ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   # #   # # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   #   #   #######");
		break;
		case 39:
		gotoxy(x,y);  cprintf("#   # #   # #   # ### #   #");
		gotoxy(x,y+1);cprintf(" # #   # #   # #   #   # # ");
		gotoxy(x,y+2);cprintf("  #     #     #    #    #  ");
		gotoxy(x,y+3);cprintf(" # #   # #   # #   #   # # ");
		gotoxy(x,y+4);cprintf("#   # #   # #   # ### #   #");
		break;
		case 40:
		gotoxy(x,y);  cprintf("#   # #   ");
		gotoxy(x,y+1);cprintf(" # #  #   ");
		gotoxy(x,y+2);cprintf("  #   #   ");
		gotoxy(x,y+3);cprintf(" # #  #   ");
		gotoxy(x,y+4);cprintf("#   # ####");
		break;
		case 41:
		gotoxy(x,y);  cprintf("#   # #    ###");
		gotoxy(x,y+1);cprintf(" # #  #     # ");
		gotoxy(x,y+2);cprintf("  #   #     # ");
		gotoxy(x,y+3);cprintf(" # #  #     # ");
		gotoxy(x,y+4);cprintf("#   # #### ###");
		break;
		case 42:
		gotoxy(x,y);  cprintf("#   # #    #####");
		gotoxy(x,y+1);cprintf(" # #  #     # # ");
		gotoxy(x,y+2);cprintf("  #   #     # # ");
		gotoxy(x,y+3);cprintf(" # #  #     # # ");
		gotoxy(x,y+4);cprintf("#   # #### #####");
		break;
		case 43:
		gotoxy(x,y);  cprintf("#   # #    #######");
		gotoxy(x,y+1);cprintf(" # #  #     # # # ");
		gotoxy(x,y+2);cprintf("  #   #     # # # ");
		gotoxy(x,y+3);cprintf(" # #  #     # # # ");
		gotoxy(x,y+4);cprintf("#   # #### #######");
		break;
		case 44:
		gotoxy(x,y);  cprintf("#   # #    ### #   #");
		gotoxy(x,y+1);cprintf(" # #  #     #  #   #");
		gotoxy(x,y+2);cprintf("  #   #     #  #   #");
		gotoxy(x,y+3);cprintf(" # #  #     #   # # ");
		gotoxy(x,y+4);cprintf("#   # #### ###   #  ");
		break;
		case 45:
		gotoxy(x,y);  cprintf("#   # #    #   #");
		gotoxy(x,y+1);cprintf(" # #  #    #   #");
		gotoxy(x,y+2);cprintf("  #   #    #   #");
		gotoxy(x,y+3);cprintf(" # #  #     # # ");
		gotoxy(x,y+4);cprintf("#   # ####   #  ");
		break;
		case 46:
		gotoxy(x,y);  cprintf("#   # #    #   # ###");
		gotoxy(x,y+1);cprintf(" # #  #    #   #  # ");
		gotoxy(x,y+2);cprintf("  #   #    #   #  # ");
		gotoxy(x,y+3);cprintf(" # #  #     # #   # ");
		gotoxy(x,y+4);cprintf("#   # ####   #   ###");
		break;
		case 47:
		gotoxy(x,y);  cprintf("#   # #    #   # #####");
		gotoxy(x,y+1);cprintf(" # #  #    #   #  # # ");
		gotoxy(x,y+2);cprintf("  #   #    #   #  # # ");
		gotoxy(x,y+3);cprintf(" # #  #     # #   # # ");
		gotoxy(x,y+4);cprintf("#   # ####   #   #####");
		break;
		case 48:
		gotoxy(x,y);  cprintf("#   # #    #   # #######");
		gotoxy(x,y+1);cprintf(" # #  #    #   #  # # # ");
		gotoxy(x,y+2);cprintf("  #   #    #   #  # # # ");
		gotoxy(x,y+3);cprintf(" # #  #     # #   # # # ");
		gotoxy(x,y+4);cprintf("#   # ####   #   #######");
		break;
		case 49:
		gotoxy(x,y);  cprintf("#   # #    ### #   #");
		gotoxy(x,y+1);cprintf(" # #  #     #   # # ");
		gotoxy(x,y+2);cprintf("  #   #     #    #  ");
		gotoxy(x,y+3);cprintf(" # #  #     #   # # ");
		gotoxy(x,y+4);cprintf("#   # #### ### #   #");
		break;
		case 50:
		gotoxy(x,y);  cprintf("#");
		gotoxy(x,y+1);cprintf("#");
		gotoxy(x,y+2);cprintf("#");
		gotoxy(x,y+3);cprintf("#");
		gotoxy(x,y+4);cprintf("#####");
		break;
	}   return c;	
} 
char elesim(int x, int y, char r)
{
	textcolor(WHITE);
	switch (r)
	{
	case '<':
	gotoxy(x,y);  cprintf("     ##");
	gotoxy(x,y+1);cprintf("  ### ");
	gotoxy(x,y+2);cprintf("##   ");
	gotoxy(x,y+3);cprintf("  ### ");
	gotoxy(x,y+4);cprintf("     ##");
	break;
	case '>':
	gotoxy(x,y);  cprintf("##   ");
	gotoxy(x,y+1);cprintf("  ### ");
	gotoxy(x,y+2);cprintf("     ##");
	gotoxy(x,y+3);cprintf("  ### ");
	gotoxy(x,y+4);cprintf("##   ");
	break;
	case '=':
	gotoxy(x,y);  cprintf("");
	gotoxy(x,y+1);cprintf("#######");
	gotoxy(x,y+2);cprintf("");
	gotoxy(x,y+3);cprintf("#######");
	gotoxy(x,y+4);cprintf("");
	}
	return r;
}
char elenum (int x, int y, int n)
{
	textcolor(YELLOW);
	switch (n)
	{
		case 1:    
		gotoxy(x,y);  cprintf("  ###   ");
    	gotoxy(x,y+1);cprintf("## ##   ");
    	gotoxy(x,y+2);cprintf("   ##   ");
    	gotoxy(x,y+3);cprintf("   ##   ");
    	gotoxy(x,y+4);cprintf("########");
    	break;
    	case 2:
    	gotoxy(x,y);  cprintf("  ###  ");
    	gotoxy(x,y+1);cprintf("##   ##");
    	gotoxy(x,y+2);cprintf("   ##  ");
    	gotoxy(x,y+3);cprintf(" ##    ");
    	gotoxy(x,y+4);cprintf("#######");
    	break;
    	case 3:
    	gotoxy(x,y);  cprintf(" #### ");
    	gotoxy(x,y+1);cprintf("#   ##");
    	gotoxy(x,y+2);cprintf("  ### ");
    	gotoxy(x,y+3);cprintf("#   ##");
    	gotoxy(x,y+4);cprintf(" #### ");
    	break;
    	case 4:
    	gotoxy(x,y);  cprintf("##  ##");
    	gotoxy(x,y+1);cprintf("##  ##");
    	gotoxy(x,y+2);cprintf("######");
    	gotoxy(x,y+3);cprintf("    ##");
    	gotoxy(x,y+4);cprintf("    ##");
    	break;
    	case 5:    
    	gotoxy(x,y);  cprintf("####");
    	gotoxy(x,y+1);cprintf("#   ");
    	gotoxy(x,y+2);cprintf("####");
    	gotoxy(x,y+3);cprintf("   #");
    	gotoxy(x,y+4);cprintf("####");
    	break;
    	case 6:
    	gotoxy(x,y);  cprintf(" ## ");
    	gotoxy(x,y+1);cprintf("#   ");
    	gotoxy(x,y+2);cprintf("### ");
    	gotoxy(x,y+3);cprintf("#  #");
    	gotoxy(x,y+4);cprintf(" ## ");
    	break;
    	case 7:
    	gotoxy(x,y);  cprintf("######");
    	gotoxy(x,y+1);cprintf("   ## ");
    	gotoxy(x,y+2);cprintf("  ##  ");
    	gotoxy(x,y+3);cprintf(" ##   ");
    	gotoxy(x,y+4);cprintf("##    ");
    	break;
    	case 8:
    	gotoxy(x,y);  cprintf(" ### ");
    	gotoxy(x,y+1);cprintf("#   #");
    	gotoxy(x,y+2);cprintf(" ### ");
    	gotoxy(x,y+3);cprintf("## ##");
    	gotoxy(x,y+4);cprintf(" ### ");
    	break;
    	case 9:
    	gotoxy(x,y);  cprintf(" ## ");
    	gotoxy(x,y+1);cprintf("#  #");
    	gotoxy(x,y+2);cprintf(" ###");
    	gotoxy(x,y+3);cprintf("   #");
    	gotoxy(x,y+4);cprintf(" ## ");
    	break;
    	case 10:
    	gotoxy(x,y);  cprintf(" ##    ### ");
    	gotoxy(x,y+1);cprintf("# #   #   #");
    	gotoxy(x,y+2);cprintf("  #   #   #");
    	gotoxy(x,y+3);cprintf("  #   #   #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 11:
    	gotoxy(x,y);  cprintf(" ##    ##  ");
    	gotoxy(x,y+1);cprintf("# #   # #  ");
    	gotoxy(x,y+2);cprintf("  #     #  ");
    	gotoxy(x,y+3);cprintf("  #     #  ");
    	gotoxy(x,y+4);cprintf("##### #####");
    	break;
    	case 12:
    	gotoxy(x,y);  cprintf(" ##    ### ");
    	gotoxy(x,y+1);cprintf("# #   #   #");
    	gotoxy(x,y+2);cprintf("  #     #  ");
    	gotoxy(x,y+3);cprintf("  #    #   ");
    	gotoxy(x,y+4);cprintf("##### #####");
    	break;
    	case 13:
    	gotoxy(x,y);  cprintf(" ##    ###  ");
    	gotoxy(x,y+1);cprintf("# #   #   # ");
    	gotoxy(x,y+2);cprintf("  #     ##  ");
    	gotoxy(x,y+3);cprintf("  #   #   # ");
    	gotoxy(x,y+4);cprintf("#####  ###  ");
    	break;
    	case 14:
    	gotoxy(x,y);  cprintf(" ##   #   #");
    	gotoxy(x,y+1);cprintf("# #   #   #");
    	gotoxy(x,y+2);cprintf("  #   #####");
    	gotoxy(x,y+3);cprintf("  #       #");
    	gotoxy(x,y+4);cprintf("#####     #");
    	break;
    	case 15:
    	gotoxy(x,y);  cprintf(" ##   ####");
    	gotoxy(x,y+1);cprintf("# #   #   ");
    	gotoxy(x,y+2);cprintf("  #   ####");
    	gotoxy(x,y+3);cprintf("  #      #");
    	gotoxy(x,y+4);cprintf("##### ####");
    	break;
    	case 16:
    	gotoxy(x,y);  cprintf(" ##    ### ");
    	gotoxy(x,y+1);cprintf("# #   #    ");
    	gotoxy(x,y+2);cprintf("  #   #### ");
    	gotoxy(x,y+3);cprintf("  #   #   #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 17:
    	gotoxy(x,y);  cprintf(" ##   #####");
    	gotoxy(x,y+1);cprintf("# #      # ");
    	gotoxy(x,y+2);cprintf("  #     #  ");
    	gotoxy(x,y+3);cprintf("  #    #   ");
    	gotoxy(x,y+4);cprintf("##### #    ");
    	break;
    	case 18:
    	gotoxy(x,y);  cprintf(" ##    ### ");
    	gotoxy(x,y+1);cprintf("# #   #   #");
    	gotoxy(x,y+2);cprintf("  #    ### ");
    	gotoxy(x,y+3);cprintf("  #   #   #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 19:
    	gotoxy(x,y);  cprintf(" ##    ### ");
    	gotoxy(x,y+1);cprintf("# #   #   #");
    	gotoxy(x,y+2);cprintf("  #    ####");
    	gotoxy(x,y+3);cprintf("  #       #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 20:
    	gotoxy(x,y);  cprintf(" ###  ## ");
    	gotoxy(x,y+1);cprintf("#  # #  #");
    	gotoxy(x,y+2);cprintf("  #  #  #");
    	gotoxy(x,y+3);cprintf(" #   #  #");
    	gotoxy(x,y+4);cprintf("##### ## ");
    	break;
    	case 21:
    	gotoxy(x,y);  cprintf(" ###   ##  ");
    	gotoxy(x,y+1);cprintf("#  #  # #  ");
    	gotoxy(x,y+2);cprintf("  #     #  ");
    	gotoxy(x,y+3);cprintf(" #      #  ");
    	gotoxy(x,y+4);cprintf("##### #####");
    	break;
    	case 22:
    	gotoxy(x,y);  cprintf(" ###   ###  ");
    	gotoxy(x,y+1);cprintf("#   # #   # ");
    	gotoxy(x,y+2);cprintf("  #      #  ");
    	gotoxy(x,y+3);cprintf(" #      #   ");
    	gotoxy(x,y+4);cprintf("#####  #####");
    	break;
    	case 23:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  #     ## ");
    	gotoxy(x,y+3);cprintf(" #    #   #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 24:
    	gotoxy(x,y);  cprintf(" ###  #   #");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  #   #####");
    	gotoxy(x,y+3);cprintf("#         #");
    	gotoxy(x,y+4);cprintf("#####     #");
    	break;
    	case 25:
    	gotoxy(x,y);  cprintf(" ###  ####");
    	gotoxy(x,y+1);cprintf("#   # #   ");
    	gotoxy(x,y+2);cprintf("  #   ####");
    	gotoxy(x,y+3);cprintf("#        #");
    	gotoxy(x,y+4);cprintf("##### ####");
    	break;
    	case 26:
    	gotoxy(x,y);  cprintf(" ###    ### ");
    	gotoxy(x,y+1);cprintf("#   #  #    ");
    	gotoxy(x,y+2);cprintf("  #    #### ");
    	gotoxy(x,y+3);cprintf(" #     #   #");
    	gotoxy(x,y+4);cprintf("#####   ### ");
    	break;
    	case 27:
    	gotoxy(x,y);  cprintf(" ###  #####");
    	gotoxy(x,y+1);cprintf("#   #    # ");
    	gotoxy(x,y+2);cprintf("  #     #  ");
    	gotoxy(x,y+3);cprintf(" #     #   ");
    	gotoxy(x,y+4);cprintf("##### #    ");
    	break;
    	case 28:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  #    ### ");
    	gotoxy(x,y+3);cprintf(" #    #   #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 29:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  #    ####");
    	gotoxy(x,y+3);cprintf(" #        #");
    	gotoxy(x,y+4);cprintf("#####  ### ");
    	break;
    	case 30:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  ##  #   #");
    	gotoxy(x,y+3);cprintf("#   # #   #");
    	gotoxy(x,y+4);cprintf(" ###   ### ");
    	break;
    	case 31:
    	gotoxy(x,y);  cprintf(" ###   ##  ");
    	gotoxy(x,y+1);cprintf("#   # # #  ");
    	gotoxy(x,y+2);cprintf("  ##    #  ");
    	gotoxy(x,y+3);cprintf("#   #   #  ");
    	gotoxy(x,y+4);cprintf(" ###  #####");
    	break;
    	case 32:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  ##    #  ");
    	gotoxy(x,y+3);cprintf("#   #  #   ");
    	gotoxy(x,y+4);cprintf(" ###  #####");
    	break;
    	case 33:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  ##    ## ");
    	gotoxy(x,y+3);cprintf("#   # #   #");
    	gotoxy(x,y+4);cprintf(" ###   ### ");
    	break;
    	case 34:
    	gotoxy(x,y);  cprintf(" ###  #   #");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  ##  #####");
    	gotoxy(x,y+3);cprintf("#   #     #");
    	gotoxy(x,y+4);cprintf(" ###      #");
    	break;
    	case 35:
    	gotoxy(x,y);  cprintf(" ###  ####");
    	gotoxy(x,y+1);cprintf("#   # #   ");
    	gotoxy(x,y+2);cprintf("  ##  ####");
    	gotoxy(x,y+3);cprintf("#   #    #");
    	gotoxy(x,y+4);cprintf(" ###  ####");
    	break;
    	case 36:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #    ");
    	gotoxy(x,y+2);cprintf("  ##  #### ");
    	gotoxy(x,y+3);cprintf("#   # #   #");
    	gotoxy(x,y+4);cprintf(" ###   ### ");
    	break;
    	case 37:
    	gotoxy(x,y);  cprintf(" ###  #####");
    	gotoxy(x,y+1);cprintf("#   #    # ");
    	gotoxy(x,y+2);cprintf("  ##    #  ");
    	gotoxy(x,y+3);cprintf("#   #  #   ");
    	gotoxy(x,y+4);cprintf(" ###  #    ");
    	break;
    	case 38:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  ##   ### ");
    	gotoxy(x,y+3);cprintf("#   # #   #");
    	gotoxy(x,y+4);cprintf(" ###   ### ");
    	break;
    	case 39:
    	gotoxy(x,y);  cprintf(" ###   ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("  ##   ####");
    	gotoxy(x,y+3);cprintf("#   #     #");
    	gotoxy(x,y+4);cprintf(" ###   ### ");
    	break;
    	case 40:
    	gotoxy(x,y);  cprintf("#   #  ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("##### #   #");
    	gotoxy(x,y+3);cprintf("    # #   #");
    	gotoxy(x,y+4);cprintf("    #  ### ");
    	break;
    	case 41:
    	gotoxy(x,y);  cprintf("#   #  ##  ");
    	gotoxy(x,y+1);cprintf("#   # # #  ");
    	gotoxy(x,y+2);cprintf("#####   #  ");
    	gotoxy(x,y+3);cprintf("    #   #  ");
    	gotoxy(x,y+4);cprintf("    # #####");
    	break;
    	case 42:
    	gotoxy(x,y);  cprintf("#   #  ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("#####   #  ");
    	gotoxy(x,y+3);cprintf("    #  #   ");
    	gotoxy(x,y+4);cprintf("    # #####");
    	break;
    	case 43:
    	gotoxy(x,y);  cprintf("#   #  ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("#####   ## ");
    	gotoxy(x,y+3);cprintf("    # #   #");
    	gotoxy(x,y+4);cprintf("    #  ### ");
    	break;
    	case 44:
    	gotoxy(x,y);  cprintf("#   # #   #");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("##### #####");
    	gotoxy(x,y+3);cprintf("    #     #");
    	gotoxy(x,y+4);cprintf("    #     #");
    	break;
    	case 45:
    	gotoxy(x,y);  cprintf("#   # ####");
    	gotoxy(x,y+1);cprintf("#   # #   ");
    	gotoxy(x,y+2);cprintf("##### ####");
    	gotoxy(x,y+3);cprintf("    #    #");
    	gotoxy(x,y+4);cprintf("    # ####");
    	break;
    	case 46:
    	gotoxy(x,y);  cprintf("#   #   ### ");
    	gotoxy(x,y+1);cprintf("#   #  #    ");
    	gotoxy(x,y+2);cprintf("#####  #### ");
    	gotoxy(x,y+3);cprintf("    #  #   #");
    	gotoxy(x,y+4);cprintf("    #   ### ");
    	break;
    	case 47:
    	gotoxy(x,y);  cprintf("#   # #####");
    	gotoxy(x,y+1);cprintf("#   #    # ");
    	gotoxy(x,y+2);cprintf("#####   #  ");
    	gotoxy(x,y+3);cprintf("    #  #   ");
    	gotoxy(x,y+4);cprintf("    # #    ");
    	break;
    	case 48:
    	gotoxy(x,y);  cprintf("#   #  ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("#####  ### ");
    	gotoxy(x,y+3);cprintf("    # #   #");
    	gotoxy(x,y+4);cprintf("    #  ### ");
    	break;
    	case 49:
    	gotoxy(x,y);  cprintf("#   #  ### ");
    	gotoxy(x,y+1);cprintf("#   # #   #");
    	gotoxy(x,y+2);cprintf("#####  ####");
    	gotoxy(x,y+3);cprintf("    #     #");
    	gotoxy(x,y+4);cprintf("    #  ### ");
    	break;
    	case 50:
    	gotoxy(x,y);  cprintf("####  ### ");
    	gotoxy(x,y+1);cprintf("#    #   #");
    	gotoxy(x,y+2);cprintf("#### #   #");
    	gotoxy(x,y+3);cprintf("   # #   #");
    	gotoxy(x,y+4);cprintf("####  ### ");
    	break;
    }
    return n;
} 
void bienomal(int x)
{
	switch (x)
	{
		case 1:
		clrscr();
		gotoxy(10,5);cprintf("##      ##  ##    ## ##      ##  ###### ###### ####### ###     ## ##");
 		gotoxy(10,6);cprintf("####  ####  ##    ##  ##    ##   ##  ##   ##   ##      ####    ## ##");
		gotoxy(10,7);cprintf("##  ##  ##  ##    ##   ##  ##    ##  #    ##   ##      ## ##   ## ##");
        gotoxy(10,8);cprintf("##      ##  ##    ##     ##      #####    ##   #####   ##  ##  ## ##");
        gotoxy(10,9);cprintf("##      ##  ##    ##     ##      ##  ##   ##   ##      ##   ## ## ##");
        gotoxy(10,10);cprintf("##      ##   ##   ##     ##      ##  ##   ##   ##      ##    ####   ");
        gotoxy(10,11);cprintf("##      ##     ###       ##      #####  ###### ####### ##     ### ##");
        			
        gotoxy(20,14);cprintf("   #####   ");
        gotoxy(20,15);cprintf(" ## 0 0 ## ");
        gotoxy(20,16);cprintf("##       ##");
        gotoxy(20,17);cprintf(" ##  U  ## ");
        gotoxy(20,18);cprintf("   #####   ");
        break;
        case 2:
        clrscr();
        gotoxy(10,5);cprintf("##      ##   ###   ##");
      	gotoxy(10,6);cprintf("####  ####  ## ##  ##");
      	gotoxy(10,7);cprintf("##  ##  ## ##   ## ##");
      	gotoxy(10,8);cprintf("##      ## ####### ##");
      	gotoxy(10,9);cprintf("##      ## ##   ## ##");
        gotoxy(10,10);cprintf("##      ## ##   ## ##");
      	gotoxy(10,11);cprintf("##      ## ##   ## ##########");
      	
      	gotoxy(20,14);cprintf("   #####   ");
        gotoxy(20,15);cprintf(" ## Â Â ## ");
        gotoxy(20,16);cprintf("##       ##");
        gotoxy(20,17);cprintf(" ##  n  ## ");
       	gotoxy(20,18);cprintf("   #####   ");
       	break;
       	case 3:
       	gotoxy(10,14);cprintf("##### ##### #     #####  #### ##### ####     ##   ####  #####  ### #");
        gotoxy(10,15);cprintf("#     #     #       #   #       #   #   #    ##   #   # #     #    #");
        gotoxy(10,16);cprintf("###   ###   #       #   #       #   #   #   #  #  #   # ###   ###  #");
        gotoxy(10,17);cprintf("#     #     #       #   #       #   #   #  ###### #   # #        #  ");
        gotoxy(10,18);cprintf("#     ##### ##### #####  #### ##### ####   #    # ####  ##### ###  #");
        break;
        case 4:
       	gotoxy(15,8); cprintf("#####  #   # ##### ####  #####  ###");
        gotoxy(15,9); cprintf("#    # #   # #     #   # #     #    ");
        gotoxy(15,10);cprintf("#####  #   # ###   #   # ###   ###  ");
        gotoxy(15,11);cprintf("#      #   # #     #   # #        # ");
        gotoxy(15,12);cprintf("#       ###  ##### ####  ##### ###  ");
        
        gotoxy(15,14);cprintf("#   #   ##    #### ##### #####   #      ##");
       	gotoxy(15,15);cprintf("#   #   ##   #     #     #    #  #     #  #"); 
       	gotoxy(15,16);cprintf("#####  #  #  #     ###   #####   #    #    #");
       	gotoxy(15,17);cprintf("#   # ###### #     #     #    #  #     #  #");
       	gotoxy(15,18);cprintf("#   # #    #  #### ##### #     # #####  ##");

       	gotoxy(15,20);cprintf("##   # #####  ####  ####   #####  ");
       	gotoxy(15,21);cprintf("##  ## #        #  #    #  #    # "); 
       	gotoxy(15,22);cprintf("# ## # ###      # #      # #####  ");
       	gotoxy(15,23);cprintf("#    # #     #  #  #    #  #    # ");
       	gotoxy(15,24);cprintf("#    # #####  ##    ####   #     #");
       	break;
	}
}
