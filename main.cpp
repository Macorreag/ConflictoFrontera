#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<windows.h>

using namespace std;

int i, *pposicion,m, *pnueva, inicio, l, c, columna, fila, registro, dado, p, j,z, temporal, conclusion;
void movimiento(int , int , int );
void movimiento_venezolano(int , int , int );

void impresiontablero(int *pnueva);


main(){
    pposicion=new int[13];
    pnueva=new int[65];

    for(int x=1;x<65;x++)
        {
            *(pnueva+x)=0;         //rellena el vector de "0"
        }

srand(time(NULL));
   for(i=1;i<=12;i++){
    ((*(pposicion+i)))=1 + rand()%63;
   for(m=1;m<i;m++){
        if((*(pposicion+i))== (*(pposicion+i))){
            i=i-1;
            break;
        }
    }
    if(i<=10){
            (*(pnueva+(*(pposicion+i))))=1;
        }else{
            (*(pnueva+(*(pposicion+i))))=2;
        }

   }

   cout<<"la posicion inicial del juego es "<<endl;
cout<<" "<<endl;
for(z=1;z<=64;z+=8){
    cout<<" "<<(*(pnueva+z))<<" "<<*(pnueva+z+1)<<" "<<*(pnueva+z+2)<<" "<<*(pnueva+z+3)<<" "<<*(pnueva+4)<<" "<<*(pnueva+z+5)<<" "<<*(pnueva+z+6)<<" "<<*(pnueva+z+7)<<endl;


}

impresiontablero(pnueva);




for(l=1;l<=20;l++){
system("pause");
        j=0;
		if(l%2==1){
		c=rand()%10+1;
		while((*(pnueva+(*(pposicion+c))))==0 || (*(pnueva+(*(pposicion+c))))==2){
		if(c==10){c=1;}else{c++;}       // si no hay jugador en esa posicion busca el proximo
		}
		columna=(*(pposicion+c))%8;
		if(columna==0){columna=8;}
		fila=((*(pposicion+c))-columna)/8;

		dado=rand()%8+1;
		registro=0;
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
                if(dado==9){
                        while(p==0){
                                if(c==10){ // el ultimo colombiano
                                c=1;        //pasa al primer colombiano
                                }else{
                                c=c+1;
                                }
                                temporal=temporal+1; // recorrio los die< campos colombianos y no estan
                                if(temporal==10){
                                    cout<<" todos los colombianos fueron capturados"<<endl;
                                    break;
                                    break;
                                    break;
                                }
                        if((*(pnueva+(*(pposicion+c))))!=0){  // hay un colombiano o un venezolano
                            p=1;                    // cambia la condicion para buscar otro colombiano
                        columna=(*(pposicion+c))%8;
                        fila=((*(pposicion+c))-columna)/8;
                        dado=rand()%8+1;
                        registro=0;
                        }
                        }

                }


}


}else{
        j=0;
		c=rand()%2+11;
		columna=(*(pposicion+c))%8;
		if(columna==0){columna=8;}
		fila=((*(pposicion+c))-columna)/8;
		dado=rand()%8+1;
        while(j!=1){
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

return(0);
}

void movimiento(int alfa, int beta, int omega){
if(0<alfa && alfa<9 && 0<=beta && beta<8){
                            for(int k=1;k<=12;k++){
                                if(k!=c && (*(pposicion+k))==(alfa+(beta*8))){
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
                                (*(pposicion+c))=alfa+(beta*8);
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

void movimiento_venezolano(int gamma, int epsilon, int pi){
    if( 0<gamma && gamma<9 && 0<=epsilon && epsilon<8){
                           for(int x=11;x<=12;x++){
                                if(x!=c && *(pposicion+x)==gamma+(epsilon*8)){
                                        if(pi==8){dado=1;}else{dado++;}

                                    break;
                                    }
                                    }

                                    if(dado==pi){
                                    
                                    óp*(pnueva+(*(pposicion+c))))=0;

                                   (*(pposicion+c))=gamma+(epsilon*8);
                                    (*(pnueva+(*(pposicion+c))))=2;
                                    j=1;}
                     }else{
                     if(pi==8){dado=1;}else{dado++;}
                     }

}
void impresiontablero(int *pnueva){
 for(int filar=0;filar<8;filar++){          //impresion tras 1 movimiento

            for(int columnar=1;columnar<9;columnar++){
                    cout << (*(pnueva+(columnar+(filar*8))))<<" ";
                                                    }
                cout<<endl;
                                }

}
