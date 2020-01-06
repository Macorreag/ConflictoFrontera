#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
//#include<windows.h>

using namespace std;

int media, *pposicion,*pnueva,i,m,j,c,l,p,columna, fila, registro, dado,temporal,z,conclusion;

void movimiento(int , int , int );

void movimiento_venezolano(int , int , int );


void impresiontablero (int *pvector){

 for(int filar=0;filar<8;filar++){          //impresion tras 1 movimiento

                cout<<endl;

            for(int columnar=0;columnar<8;columnar++){

            cout << *(pvector+(filar*8+columnar))<<" ";



            }

                }

                        cout<<endl;

}

struct casilla{
int contenido;
char *nombrejugador;
};


struct colombiano{
int posicion;
};


main(){


    char nombre[5];
   // uno.nombrejugador=nombre;
   struct colombiano jugador;
    pposicion=new int[12];
    pnueva=new int[65];
    for(int x=0;x<64;x++)
        {
            *(pnueva+x)=0;         //rellena el vector de "0"
        }

    cout<<"Ingrese su nombre:"<<endl;

//cin>>uno.*nombrejugador;
//uno.(nombrejugador+5)='\0';

//    cout<<"Bienvenido "<<inicial.nombre<<endl;
srand(time(NULL));

for(i=0;i<12;i++){

    media=1 + rand()%63;

    *(pposicion+i)=media;



   for(m=0;m<i;m++){



        if(*(pposicion+i)==*(pposicion+m)){

            i--;

            break;

        }

    }

    if(i<10){



            *(pnueva+(*(pposicion+i)))=1;



        }else{



            *(pnueva+(*(pposicion+i)))=2;





        }



   }

   cout<<"la posicion inicial del juego es "<<endl;

   cout<<" "<<endl;



   impresiontablero(pnueva);





for(l=1;l<=20;l++){

system("pause");





        j=0;

	if(l%2==1){                            //los impares son movimientos colombianos

		c=rand()%10;          //que colombiano se mueve

		while((*(pnueva+(*(pposicion+c))))==0 || (*(pnueva+(*(pposicion+c))))==2){ //si el colombiano no est� o si hay un venezolano

		if(c==10){c=1;}else{c++;}           //busca el siguiente colombiano

		}

		columna=(*(pposicion+c))%8;
   jugador.posicion= *(pposicion+c);

                  //ESTABLECE LA COLUMNA EN la que esta

		if(columna==0){columna=8;}

		fila=((*(pposicion+c))-columna)/8;           //define la fila en la que esta

		dado=rand()%8+1;                //define la jugada a hacer

		registro=0;                 //

		while(j!=1){

                if(dado==1){

                    movimiento((columna+1),(fila-2), dado);

                }

                if(dado==2){

                    movimiento((columna+2),(fila-1), dado);

                }

                if(dado==3){

                    movimiento((columna+2),(fila+1), dado);

                }

                if(dado==4){

                    movimiento((columna+1),(fila+2), dado);

                }

                if(dado==5){

                    movimiento((columna-1),(fila+2), dado);

                }

                if(dado==6){

                    movimiento((columna-2),(fila+1), dado);

                }

                if(dado==7){

                    movimiento((columna-2),(fila-1), dado);

                }

                if(dado==8){

                    movimiento((columna-1),(fila-2), dado);

                }

                if(dado==9){            //cuando reviso todas las jugadas

                        while(p==0){   //hasta que adonde se mueva el colombiano este ocupado

                                if(c==9){ //si es el ultimmo colombiano el 10

                                c=0;            // lo devuelve al primero

                                }else{

                                c=c+1;      //pasa al siguiente jugador

                                }

                                temporal=temporal+1; //

                                if(temporal==10){

                                    cout<<" todos los colombianos fueron capturados"<<endl;

                                    break;

                                    break;

                                    break;



                                }



                        if((*(pnueva+(*(pposicion+c))))!=0){                //si a donde se mueve el colombiano  esta ocupado

                            p=1;                                            //termina el ciclo

                        columna=(*(pposicion+c))%8;                         //define la columna

                        fila=((*(pposicion+c))-columna)/8;                  //define lA FILA

                        dado=rand()%8+1;                                    //define el dado aleaorio otra vez

                        registro=0;                                         ///no se que hace

                        }

                        }



                }





}





}else{

        j=0;

		c=rand()%2+10;

		columna=(*(pposicion+c))%8;

		if(columna==0){columna=8;}

		fila=((*(pposicion+c))-columna)/8;

		dado=rand()%8+1;

        while(j!=1){            //se sale cuando  hace el movimiento

                if(dado==1){

                    movimiento_venezolano((columna+1),(fila-2), dado);

                }

                if(dado==2){

                   movimiento_venezolano((columna+2),(fila-1), dado);

                }

                if(dado==3){

                   movimiento_venezolano((columna+2),(fila+1), dado);

                }

                if(dado==4){

                    movimiento_venezolano((columna+1),(fila+2), dado);

                }

                if(dado==5){

                    movimiento_venezolano((columna-1),(fila+2), dado);

                }

                if(dado==6){

                    movimiento_venezolano((columna-2),(fila+1), dado);

                }

                if(dado==7){

                   movimiento_venezolano((columna-2),(fila-1), dado);

                }

                if(dado==8){

                    movimiento_venezolano((columna-1),(fila-2), dado);

                }



}







}

//imprime el tablero para cada movimiento

        cout<<" "<<endl;

        cout<<"el resultado del movimiento "<<l<<" es"<<endl;

cout<<" "<<endl;



impresiontablero(pnueva);

}





for(z=1;z<=64;z++){

    if((*(pnueva+z))==1){

        conclusion++;

    }

}

cout<<endl;

cout<<"tras 20 movimientos fueron capturados "<<10-conclusion<<" colombianos "<<endl;





//return(0);





}





void movimiento(int alfa, int beta, int omega){       //columnas,fila,dado

int k;

if(0<alfa && alfa<9 && 0<=beta && beta<8){      // prohibe la salida del vector

                            for(k=0;k<12;k++){      //recorre todas las posiciones donde ha fichas(1,2)

                                if(k!=c && (*(pposicion+k))==(alfa+(beta*8))){ //si las pociciones anteriores son diferente de la ubicacion del  colombiano

                                    if(dado==8){dado=1; registro++;}else{dado++; registro++;}

                                     if(registro==8){

                                        dado=9;

                                        p=0;

                                    }

                                    break;

                                }



                            }

                            if(dado==omega){

                                (*(pnueva+(*(pposicion+c))))=0;

                                *(pposicion+c)=alfa+(beta*8);

                                (*(pnueva+(*(pposicion+c))))=1;

                                j=1;

                            }



                    }else{

                        if(dado==8){dado=1; registro++;}else{dado++; registro++;}

                                     if(registro==8){

                                        dado=9;

                                        p=0;

                    }

}

}



void movimiento_venezolano(int gamma, int epsilon, int pi){         //columnas,fila,dado

    int x;

if( 0<gamma && gamma<9 && 0<=epsilon && epsilon<8){         // prohibe la salida del tablero

                           for(x=10;x<12;x++){             //ciclo 2 veces  de venezolanos

                                if(x!=c && (*(pposicion+x))==gamma+(epsilon*8)){ //solo entra en 11 es diferente del numero ,,,,si la posicion del otro venezolano es igual a la del compa�ero

                                        if(pi==8){dado=1;}else{dado++;}         //hace la otra jugada



                                    break;

                                    }

                                    }









                                    if(dado==pi){

                                    (*(pnueva+(*(pposicion+c))))=0;

                                    (*(pposicion+c))=gamma+(epsilon*8);

                                    (*(pnueva+(*(pposicion+c))))=2;

                                     j=1;}

                     }else{

                     if(pi==8){dado=1;}else{dado++;}

                     }



}













































