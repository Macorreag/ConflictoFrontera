
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<windows.h>

using namespace std;

int i, posicion[12],m, nueva[65]={0}, inicio, l, c, columna, fila, registro, dado, p, j,z, temporal, conclusion;
void movimiento(int , int , int );
void movimiento_venezolano(int , int , int );

main(){

srand(time(NULL));
   for(i=1;i<=12;i++){
    posicion[i]=1 + rand()%63;
   for(m=1;m<i;m++){
        if(posicion[i]== posicion[m]){
            i=i-1;
            break;
        }
    }
    if(i<=10){
            nueva[posicion[i]]=1;
        }else{
            nueva[posicion[i]]=2;
        }

   }

   cout<<"la posicion inicial del juego es "<<endl;
cout<<" "<<endl;
for(inicio=1;inicio<65;inicio+=8){
cout<<" "<<nueva[inicio]<<" "<<nueva[inicio+1]<<" "<<nueva[inicio+2]<<" "<<nueva[inicio+3]<<" "<<nueva[inicio+4]<<" "<<nueva[inicio+5]<<" "<<nueva[inicio+6]<<" "<<nueva[inicio+7]<<endl;
}
for(l=1;l<=20;l++){
system("pause");
        j=0;
		if(l%2==1){
		c=rand()%10+1;
		while(nueva[posicion[c]]==0 || nueva[posicion[c]]==2){
		if(c==10){c=1;}else{c++;}
		}
		columna=posicion[c]%8;
		if(columna==0){columna=8;}
		fila=(posicion[c]-columna)/8;
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
                                if(c==10){
                                c=1;
                                }else{
                                c=c+1;
                                }
                                temporal=temporal+1;
                                if(temporal==10){
                                    cout<<" todos los colombianos fueron capturados"<<endl;
                                    break;
                                    break;
                                    break;
                                }
                        if(nueva[posicion[c]]!=0){
                            p=1;
                        columna=posicion[c]%8;
                        fila=(posicion[c]-columna)/8;
                        dado=rand()%8+1;
                        registro=0;
                        }
                        }

                }


}


}else{
        j=0;
		c=rand()%2+11;
		columna=posicion[c]%8;
		if(columna==0){columna=8;}
		fila=(posicion[c]-columna)/8;
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
for(z=1;z<=64;z+=8){
    cout<<" "<<nueva[z]<<" "<<nueva[z+1]<<" "<<nueva[z+2]<<" "<<nueva[z+3]<<" "<<nueva[z+4]<<" "<<nueva[z+5]<<" "<<nueva[z+6]<<" "<<nueva[z+7]<<endl;


}
}
for(z=1;z<=64;z++){
    if(nueva[z]==1){
        conclusion++;
    }
}
cout<<endl;
cout<<"tras 20 movimientos fueron capturados "<<10-conclusion<<" colombianos "<<endl;

return(0);
}

void movimiento(int alfa, int beta, int omega){
int k;
if(0<alfa && alfa<9 && 0<=beta && beta<8){
                            for(k=1;k<=12;k++){
                                if(k!=c && posicion[k]==(alfa+(beta*8))){
                                    if(dado==8){dado=1; registro++;}else{dado++; registro++;}
                                     if(registro==8){
                                        dado=9;
                                        p=0;
                                    }
                                    break;
                                }

                            }
                            if(dado==omega){
                                nueva[posicion[c]]=0;
                                posicion[c]=alfa+(beta*8);
                                nueva[posicion[c]]=1;
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
    int x;
if( 0<gamma && gamma<9 && 0<=epsilon && epsilon<8){
                           for(x=11;x<=12;x++){
                                if(x!=c && posicion[x]==gamma+(epsilon*8)){
                                        if(pi==8){dado=1;}else{dado++;}

                                    break;
                                    }
                                    }

                                    if(dado==pi){
                                    nueva[posicion[c]]=0;
                                    posicion[c]=gamma+(epsilon*8);
                                    nueva[posicion[c]]=2;
                                    j=1;}
                     }else{
                     if(pi==8){dado=1;}else{dado++;}
                     }

}






