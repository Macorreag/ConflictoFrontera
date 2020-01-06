
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <windows.h>

using namespace std;

int ponervenezolano(int movimientocasilla,int *pvector){
            *pvector=0;
            pvector=pvector+movimientocasilla;
            *pvector=2;
            pvector=pvector-movimientocasilla;
            return 1;


}
int ponercolombiano(int movimientocasilla,int *pvector,int verificador){ //quitar a verificado no hace nada
            *pvector=0;
            pvector=pvector+movimientocasilla;
            *pvector=1;
            pvector=pvector-movimientocasilla;
            return 1;


}
int saltovalidocolombia (int *pvector,int movimientocasilla ) //
{
    pvector+=movimientocasilla;
    if (*pvector==0){return 0;}else{ return 1;}
    pvector-=movimientocasilla;

}

int contenidoV(int *pvector,int movimientocasilla,int colombianosmuertos){
    pvector+=movimientocasilla;

    if(*pvector==2)    //vigila que un gusrdia no caiga sobre la guardia
    {   pvector-=movimientocasilla;
        return 1;
    }else{
        if (*pvector==1){colombianosmuertos++;}
        pvector-=movimientocasilla;
        return 0;}

}
int contenido(int *pvector,int movimientocasilla){
    pvector+=movimientocasilla;
    if(*pvector==2||*pvector==1)    //vigila que un colombiano no caiga sobre la guardia ni sobre un compañero
    {   pvector-=movimientocasilla;
        return 1;
    }else{pvector-=movimientocasilla;
        return 0;}

}

int llenarfichas(int *pfichas,int numeroficha,int aleatorio){
        pfichas=pfichas+numeroficha;

        *pfichas=aleatorio;
        cout<<*pfichas<<endl;



        pfichas=pfichas-numeroficha;
}


void impresiontablero (int *pvector,int *pFilas,int *pColumnas){
 for(int fila=0;fila<8;fila++){          //impresion tras 1 movimiento
                cout<<endl;

            for(int columna=0;columna<8;columna++){
            cout << *pvector<<" ";

            *pFilas=fila;
            pFilas++;
            *pColumnas=columna;
            pColumnas++;
            pvector++;
            }
                }       pvector-=64;
                        pFilas-=64;
                        pColumnas-=64;
                        cout<<endl;
}
void impresiontablerosolo (int *pvector){
 for(int fila=0;fila<8;fila++){          //impresion tras 1 movimiento
                cout<<endl;
            for(int columna=0;columna<8;columna++){
            cout << *pvector<<" ";
            pvector++;
            }
                }       pvector-=64;
                        cout<<endl;
}
int Dado8(int movimiento){
            if(movimiento==1){return -15;}
            if(movimiento==2){return -6;}
            if(movimiento==3){return +10;}
            if(movimiento==4){return +17;}
            if(movimiento==5){return +15;}
            if(movimiento==6){return +6;}
            if(movimiento==7){return -10;}
            if(movimiento==8){return -17;}
}


int main()
{
     srand(time(NULL));         // pone la semilla del relog
        int *pvector ;              //apuntador hacia el vector
        int *pfichas;               //apuntador hacia las fichas
        int *pColumnas;              //apuntador hacia Columnas
        int *pFilas;                 //apuntador hacia Filas
        int *guardar;
        int *guardarcol;

    pColumnas=new int [64];         //separa 64 casillas de memoria
    pFilas=new int [64];            //separa 64 casillas de memoria
    pfichas=new int [12];           //ubicacion de los colombianos y venezolanos
    pvector=new int  [64];          //separa 64 casillas de memoria

    cout<<"ubicacion de apuntador pvector;"<<pvector<<endl;



     for(int x=0;x<64;x++)
        {
            *pvector=0;         //rellena el vector de "0"
            pvector++;

        }

    pvector=pvector-64;        //pone el vector en la posicion inicial
    if(pvector==NULL)
    {
        cout<<"No hay recursos";

    }
    else{   int aleatorio;
            int Nvenezolano;
            int Ncolombiano;
            int Ndado;
            int verificador=0;         // verifica jugada realizada
            int turno=0;
            int suma=0;
            int salto=0;
            int colombianosmuertos=0;


            for(int x=0;x<2;x++){
            aleatorio=rand()%63;                //ubica dos venezolanos
            if((contenido(pvector,aleatorio))==1){
            x--;}else{ponervenezolano(aleatorio,pvector);
                        llenarfichas(pfichas,x,aleatorio);
                        }
            }
           pfichas+=2;                              //salta en el vector para poner posiciones de colombianos

            for(int x=0 ;x<10;x++){                 //ubica 10 colombianos aleatorios
            aleatorio=rand()%63;
            if((contenido(pvector,aleatorio))==1){
            x--;}else{ponercolombiano(aleatorio,pvector,verificador);
                       llenarfichas(pfichas,x,aleatorio);
                      }
            }
            pfichas-=2;                             //regresa el apuntador a ceros
            impresiontablero(pvector,pFilas,pColumnas); //imprime tablero inicial define filas y columnas

             for(int j=0;j<12;j++)
            {
                cout<<*pfichas<<endl;
                pfichas++;
            }
            pfichas-=12;
            guardarcol=pColumnas;
            guardar=pFilas;
            cout<<"ubicacion de apuntador pvector;"<<pvector<<endl;
            cout <<"ubicacion pfilas;"<<pFilas;


            cout<<"ubicacion pColumnas"<<pColumnas;

            cout <<"entrega del posicion del pfcihas:"<<pfichas<<endl;

for(int y=0;y<5;y++){
/////////////////////////////////////////////CORRE JUGADA COLOMBIANO//////////////////////////////////////////////


             cout<<"columna:"<<*pColumnas<<"fila:"<<*pFilas<<endl;
            Ncolombiano=2+rand()%10;                //escoje el colombiano
            Ndado=1+rand()%8;                     //define la jugada a realizar
            cout<<"jugada del colombiano:"<<Ncolombiano<<endl;
            cout<<"jugada a probar :"<<Ndado<<endl;
            pfichas+=Ncolombiano;   //mover apuntador hacia el Numero de colombiano
            cout<<"ubicacion:"<<*pfichas<<endl;
            pvector+=*pfichas;          //muevo el apuntador hacia la ubicacion del colombiano en el vectorgeneral
            pFilas+=*pfichas;               //ubico la fila
            pColumnas+=*pfichas;                //ubico la columna

             cout<<"columna:"<<*pColumnas<<"fila:"<<*pFilas<<endl;


while(verificador==0){
            if ( Ndado==1&& (*pColumnas+1)<8 && 0<=(*pFilas-2) && (saltovalidocolombia(pvector,-15))==0 ) //no se sale del tablero y no salta sobre venezolano y colombiao
             {
                verificador=ponercolombiano(-15,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==2&&(*pColumnas+2)<8 && 0<=(*pFilas-1) && (saltovalidocolombia(pvector,-6))==0 )
            {
                verificador=ponercolombiano(-6,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==3&&(*pColumnas+2)<8 && (*pFilas+1)<8 && (saltovalidocolombia(pvector,10))==0 )
            {
                verificador=ponercolombiano(10,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==4&&(*pColumnas+1)<8 && (*pFilas+2)<8 && (saltovalidocolombia(pvector,17))==0 )
            {
                verificador=ponercolombiano(17,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==5&&(*pFilas+2)<8 && 0<=(*pColumnas-1) && (saltovalidocolombia(pvector,15))==0 )
            {
                verificador=ponercolombiano(15,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==6&&(*pFilas+1)<8 && 0<=(*pColumnas-2) && (saltovalidocolombia(pvector,6))==0 )
            {
                verificador=ponercolombiano(6,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==7&&0<=(*pColumnas-2) && 0<=(*pFilas-1) && (saltovalidocolombia(pvector,-10))==0 )
            {
                verificador=ponercolombiano(-10,pvector,verificador);                   //salto colomiano
            }
            if (Ndado==8&&0<=(*pColumnas-1) && 0<=(*pFilas-2) && (saltovalidocolombia(pvector,-17))==0 )
            {
                verificador=ponercolombiano(-17,pvector,verificador);                   //salto colomiano
            }
            if (verificador==0)     //hace la siguiente jugada por que no se hizo ninguna
            {
                if (Ndado==1&&suma==1){
                    // Ncolombiano++; salta de jugador
                    verificador++;
                }
                if(Ndado==8&&suma==0){
                suma++;}
                if (Ndado<8&&suma==0){
                Ndado++;
                }
                if (suma==1&&Ndado>1){Ndado--;}
            }
}
            pFilas=guardar;
            pColumnas=guardarcol; // dejo en cero el apuntador de columnas

            pvector-=*pfichas;              //pongo el apuntador en ceros
            pfichas-=Ncolombiano;
            cout<<"verificador:"<<verificador<<endl;
            cout<<" jugada hecha:"<<Ndado;
             cout<<"columna:"<<*pColumnas<<"fila:"<<*pFilas;

            impresiontablerosolo(pvector);
            cout <<"entrega del posicion del vector"<<pvector<<endl;
            cout <<"entrega del posicion del pfcihas:"<<pfichas<<endl;
            cout <<"emntrega ubicacion pfilas;"<<pFilas;

            cout<<"entrega ubicacion pColumnas"<<pColumnas;

/////////////////////////////////////////////CORRE JUGADA VENEZOLANO    //////////////////////////////////////////////
            cout<<"columna:"<<*pColumnas<<"fila:"<<*pFilas<<endl;
                Nvenezolano=rand()%2;              //define que venezolano se mueve
            Ndado=1+rand()%8;                     //define la jugada a realizar
            cout<<"El venezolano a mover es el numero "<<Nvenezolano<<endl;
            cout<<"Jugada inicial :"<<Ndado<<endl;

            pfichas+=Nvenezolano;   //mover apuntador hacia el venezolano
            cout<<"ubicacion venezolano"<<*pfichas<<endl;
            pvector+=*pfichas;          //muevo el apuntador hacia la ubicacion del venezolano en el vector
            pFilas+=*pfichas;           //define en que fila esta
            pColumnas+=*pfichas;        //define en que columna esta
            cout<<"columna:"<<*pColumnas<<"fila:"<<*pFilas;

while(turno==0){
            if ( Ndado==1&& (*pColumnas+1)<8 && 0<=(*pFilas-2) && (contenidoV(pvector,-15,colombianosmuertos))==0 ) //no se sale del tablero y no salta sobre venezolano y colombiao
             {
                turno=ponervenezolano(-15,pvector);                   //salto colomiano
                *pfichas-=15;

            }
            if (Ndado==2&&(*pColumnas+2)<8 && 0<=(*pFilas-1) && (contenidoV(pvector,-6,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(-6,pvector);                   //salto colomiano
                *pfichas-=6;
            }
            if (Ndado==3&&(*pColumnas+2)<8 && (*pFilas+1)<8 && (contenidoV(pvector,10,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(10,pvector);                   //salto colomiano
                *pfichas+=10;

            }
            if (Ndado==4&&(*pColumnas+1)<8 && (*pFilas+2)<8 && (contenidoV(pvector,17,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(17,pvector);                   //salto colomiano
                *pfichas+=17;
            }
            if (Ndado==5&&(*pFilas+2)<8 && 0<=(*pColumnas-1) && (contenidoV(pvector,15,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(15,pvector);                   //salto colomiano
                *pfichas+=15;
            }
            if (Ndado==6&&(*pFilas+1)<8 && 0<=(*pColumnas-2) && (contenidoV(pvector,6,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(6,pvector);                   //salto colomiano
                *pfichas+=6;
            }
            if (Ndado==7&&0<=(*pColumnas-2) && 0<=(*pFilas-1) && (contenidoV(pvector,-10,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(-10,pvector);                   //salto colomiano
                *pfichas-=10;
            }
            if (Ndado==8&&0<=(*pColumnas-1) && 0<=(*pFilas-2) && (contenidoV(pvector,-17,colombianosmuertos))==0 )
            {
                turno=ponervenezolano(-17,pvector);                   //salto colomiano
                *pfichas-=17;

            }
            if (turno==0)     //hace la siguiente jugada por que no se hizo ninguna
            {
                if (Ndado==1&&salto==1){
                        turno++;
                    //Nvenezolano++; //salta de jugador
                }
                if(Ndado==8&&salto==0){
                salto++;}
                if (Ndado<8&&salto==0){
                Ndado++;
                }
                if (salto==1&&Ndado>1){Ndado--;}
            }


}

            pFilas=guardar; //dejo en ceros el apuntador de filas
            //pFilas+=(Dado8(Ndado));
            pColumnas=guardarcol; // dejo en cero el apuntador de columnas
            //pColumnas+=(Dado8(Ndado));

            pvector-=*pfichas;              //pongo el apuntador en ceros
            pvector+=(Dado8(Ndado));
            pfichas-=Nvenezolano      ;           //dejo el jugador en 0
            cout<<"verificador:"<<turno<<endl;
            cout<<" jugada hecha:"<<Ndado;
            cout<<"columna:"<<*pColumnas<<"fila:"<<*pFilas;
            impresiontablerosolo(pvector);

            cout<<"columbianos muertos:"<<colombianosmuertos<<endl;

            cout <<"entrega del posicion del vector"<<pvector<<endl;
            cout <<"entrega del posicion del pfcihas:"<<pfichas<<endl;
            cout <<"emntrega ubicacion pfilas;"<<pFilas;
            cout<<"entrega ubicacion pColumnas"<<pColumnas;


            for(int j=0;j<12;j++)
            {
                cout<<*pfichas<<endl;
                pfichas++;
            }
            pfichas-=12;
          }



    }

    return 0;
}
