#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <windows.h>

using namespace std;

int valido(int posicion,int movimientocasilla ){
if ((posicion+movimientocasilla)>=0&&(posicion+movimientocasilla)<=64){ //prohibe  la salida del  vector
    return 1;
}else{return 0;}
}
int ponervenezolano(int movimientocasilla,int *pvector){
            pvector=pvector+movimientocasilla;
            *pvector=2;
            pvector=pvector-movimientocasilla;


}
int ponercolombiano(int movimientocasilla,int *pvector){
            pvector=pvector+movimientocasilla;
            *pvector=1;
            pvector=pvector-movimientocasilla;


}

int quitarficha(int *pvector){
            *pvector=0;
}
int contenidoV(int *pvector,int movimientocasilla){
    pvector+=movimientocasilla;
    if(*pvector==2)    //vigila que un gusrdia no caiga sobre la guardia
    {   pvector-=movimientocasilla;
        return 1;
    }else{pvector-=movimientocasilla;
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
        pfichas=pfichas-numeroficha;
}
int Dado8(int movimiento,int *pfichas){
            if(movimiento==1){return -15;}
            if(movimiento==2){return -6;}
            if(movimiento==3){return +10;}
            if(movimiento==4){return +17;}
            if(movimiento==5){return +15;}
            if(movimiento==6){
                    if(*pfichas==1||*pfichas==9||*pfichas==17||*pfichas==25||*pfichas==33||*pfichas==41||*pfichas==49||*pfichas==57
                       *pfichas==0||*pfichas==8||*pfichas==16||*pfichas==24||*pfichas==32||*pfichas==40||*pfichas==48||*pfichas==56){}else{return +6;}
            if(movimiento==7){return -10;}
            if(movimiento==8){return -17;}
}

void impresiontablero (int *pvector){
 for(int fila=0;fila<8;fila++){          //impresion tras 1 movimiento
                cout<<endl;
            for(int columna=0;columna<8;columna++){
            cout << *pvector<<" ";
            pvector++;
            }
                }       pvector-=64;
                        cout<<endl;
}

int main()
    {    srand(time(NULL));         // pone la semilla del relog
        int *pvector ;              //apuntador hacia el vector
        int *pfichas;               //apuntador hacia las fichas

    pfichas=new int [12];

    pvector=new int  [64];          //separa 64 casillas de memoria

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
            int Ndado;
            int verificador=0;
            int turno=1;
            int suma=1;
            //int ubicacionactual=0;

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
            x--;}else{ponercolombiano(aleatorio,pvector);
                       llenarfichas(pfichas,x,aleatorio);
                      }
            }
            pfichas-=2;                             //regresa el apuntador a ceros

            impresiontablero(pvector);


            Nvenezolano=rand()%2;              //define que venezolano se mueve
            Ndado=1+rand()%8;                     //define la jugada a realizar

            cout<<"El venezolano a mover es el numero "<<Nvenezolano<<endl;
            cout<<"Jugada inicial :"<<Ndado<<endl;
            pfichas+=Nvenezolano;   //mover apuntador hacia el venezolano
            cout<<"ubicacion venezolano"<<*pfichas<<endl;
            pvector+=*pfichas;

           while(suma!=0&&verificador==0){
            if((valido(*pfichas,(Dado8(Ndado,pfichas))))==1&&(contenidoV(pvector,(Dado8(Ndado,pfichas))))==0&&verificador==0){
                    cout<<"movimiento valido dado N: "<<Ndado<<endl;        // vigila que no se salga del vector
                    verificador++;
            }else{

                if (Ndado>0&&Ndado<=8&&suma==1){
                        Ndado++;cout<<"movimiento invalido++"<<endl;
                    if(Ndado==9){suma=2;
                                 Ndado--;   }

                        }
                if (Ndado>=0&&Ndado<=8&&suma==2){
                        Ndado--;cout<<"movimiento invalido--"<<endl;
                        if(Ndado==0){cout<<"cambio de ficha"<<endl;
                                    suma=0;}
                }
                                }

           }



    delete pvector;

    return 0;
}
    }
