#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<windows.h>
#include <string>

using namespace std;

int i,m, inicio, l, c, columna, fila, registro, dado, p, j,z, temporal, conclusion;
struct casilla *pnueva;
string vacio="°°°°°";
void movimiento(int , int , int );
void movimiento_venezolano(int , int , int );
void impresiontablero( casilla *pnueva);
string recorte(string cadena);
 struct casilla{
                int contenido;
                string * nombre;

    };
    struct casilla posicion[13];
    struct nombre {
            string nombre;
                };
    struct nombre directorio[13];

int main(){

pnueva=new struct casilla[65];

for(int x=1;x<65;x++)
        {
            (pnueva+x)->contenido=0;         //rellena el vector de "0"
            (pnueva+x)->nombre=&vacio;
        }



cout<<"-------------------Bienvenido a conflicto en la frontera-------------------"<<endl;


//pposicion=new int [13];


srand(time(NULL));
   for(i=1;i<=12;i++){
    posicion[i].contenido=1 + rand()%63;
   for(m=1;m<i;m++){
        if(posicion[i].contenido==posicion[m].contenido){
            i=i-1;
            break;
        }
    }
    if(i<=10){
            (pnueva+posicion[i].contenido)->contenido=1; //pone el jugador colombiano dentro del tablero

        }else{
            (pnueva+posicion[i].contenido)->contenido=2;    //pone el jugador venezolano dentro del tablero
        }

   }


   for (int x=1;x<=12;x++){
        if(x<11){cout <<"ingrese el nombre de el  colombiano "<<x<<":";}else{cout <<"ingrese el nombre de el  venezolano "<<x<<":";}
        string cad1;
        cin>>cad1;
        directorio[x].nombre=recorte(cad1);
        posicion[x].nombre=&directorio[x].nombre; //direcciona el apuntador hacia el nombre

        if(x<11){cout<<"el nombre asignado al colombiano fue:"<<*(posicion[x].nombre)<<endl;}else
            {
                cout<<"el nombre asignado al venezolano  fue:"<<*(posicion[x].nombre)<<endl;
            }
        (pnueva+posicion[x].contenido)->nombre=posicion[x].nombre;


}
 system("cls");
   cout<<"la posicion inicial del juego es "<<endl;
cout<<" "<<endl;
for(inicio=1;inicio<65;inicio+=8){
cout<<"   "<<(pnueva+inicio)->contenido<<"     "<<(pnueva+inicio+1)->contenido<<"     "<<(pnueva+inicio+2)->contenido<<"     "<<(pnueva+inicio+3)->contenido<<"     "<<(pnueva+inicio+4)->contenido<<"     "<<(pnueva+inicio+5)->contenido<<"     "<<(pnueva+inicio+6)->contenido<<"     "<<(pnueva+inicio+7)->contenido<<endl;
cout<<" "<<*((pnueva+inicio)->nombre)<<" "<<*((pnueva+inicio+1)->nombre)<<" "<<*((pnueva+inicio+2)->nombre)<<" "<<*((pnueva+inicio+3)->nombre)<<" "<<*((pnueva+inicio+4)->nombre)<<" "<<*((pnueva+inicio+5)->nombre)<<" "<<*((pnueva+inicio+6)->nombre)<<" "<<*((pnueva+inicio+7)->nombre)<<endl;

}




for(l=1;l<=20;l++){
system("pause");
//system("cls");

        j=0;
		if(l%2==1){
		c=rand()%10+1;
		while((pnueva+posicion[c].contenido)->contenido==0 || (pnueva+posicion[c].contenido)->contenido==2){
		if(c==10){c=1;}else{c++;}       // si no hay jugador en esa posicion busca el proximo
		}
		columna=posicion[c].contenido%8;
		if(columna==0){columna=8;}
		fila=(posicion[c].contenido-columna)/8;

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
                        if((pnueva+posicion[c].contenido)->contenido!=0){  // hay un colombiano o un venezolano
                            p=1;                    // cambia la condicion para buscar otro colombiano
                        columna=posicion[c].contenido%8;
                        fila=(posicion[c].contenido-columna)/8;
                        dado=rand()%8+1;
                        registro=0;
                        }
                        }

                }


}


}else{
        j=0;
		c=rand()%2+11;
		columna=posicion[c].contenido%8;
		if(columna==0){columna=8;}
		fila=(posicion[c].contenido-columna)/8;
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


for(inicio=1;inicio<65;inicio+=8){
cout<<"   "<<(pnueva+inicio)->contenido<<"     "<<(pnueva+inicio+1)->contenido<<"     "<<(pnueva+inicio+2)->contenido<<"     "<<(pnueva+inicio+3)->contenido<<"     "<<(pnueva+inicio+4)->contenido<<"     "<<(pnueva+inicio+5)->contenido<<"     "<<(pnueva+inicio+6)->contenido<<"     "<<(pnueva+inicio+7)->contenido<<endl;
cout<<" "<<*((pnueva+inicio)->nombre)<<" "<<*((pnueva+inicio+1)->nombre)<<" "<<*((pnueva+inicio+2)->nombre)<<" "<<*((pnueva+inicio+3)->nombre)<<" "<<*((pnueva+inicio+4)->nombre)<<" "<<*((pnueva+inicio+5)->nombre)<<" "<<*((pnueva+inicio+6)->nombre)<<" "<<*((pnueva+inicio+7)->nombre)<<endl;

}

}
for(z=1;z<=64;z++){
    if((pnueva+z)->contenido==1){
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
                                if(k!=c && posicion[k].contenido==(alfa+(beta*8))){
                                    if(dado==8){dado=1; registro++;}else{dado++; registro++;}
                                     if(registro==8){
                                        dado=9;
                                        p=0;
                                    }
                                    break;
                                }

                            }
                            if(dado==omega){
                                (pnueva+posicion[c].contenido)->contenido=0;
                                (pnueva+posicion[c].contenido)->nombre=&vacio;
                                posicion[c].contenido=alfa+(beta*8);
                                (pnueva+posicion[c].contenido)->nombre=posicion[c].nombre;
                                (pnueva+posicion[c].contenido)->contenido=1;
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
                                if(x!=c && posicion[x].contenido==gamma+(epsilon*8)){
                                        if(pi==8){dado=1;}else{dado++;}

                                    break;
                                    }
                                    }

                                    if(dado==pi){

                                    (pnueva+posicion[c].contenido)->contenido=0;
                                    (pnueva+posicion[c].contenido)->nombre=&vacio;
                                    posicion[c].contenido=gamma+(epsilon*8);
                                    if((pnueva+posicion[c].contenido)->contenido==1)
                                    {
                                        cout<<"Ha sido capturado el  colombiano de nombre :";
                                        for(int y=1;y<11;y++)
                                        {
                                            if((posicion[c].contenido)==posicion[y].contenido)
                                            {
                                                cout<<*(posicion[y].nombre)<<endl;

                                            }
                                    }
                                    }
                                    (pnueva+posicion[c].contenido)->nombre=posicion[c].nombre;


                                    (pnueva+posicion[c].contenido)->contenido=2;
                                    j=1;}
                     }else{
                     if(pi==8){dado=1;}else{dado++;}
                     }

}

string recorte(string cadena){
string cad3="-----";
string cad2="-----";
int borrado =1;
cad3 = cadena.substr(0,5);
if(cad3[1]=='\0'||cad3[2]=='\0'||cad3[3]=='\0'||cad3[4]=='\0'){
                    cad2[0]=cad3[0];

                    if (cad3[1]==' '||cad3[1]=='\0'){cad2[1]='-';cad2[2]='-';cad2[3]='-';borrado++;return cad2;}else{cad2[1]=cad3[1];}
                    if (cad3[2]==' '||cad3[2]=='\0'&&borrado==1){cad2[2]='-';cad2[3]='-';borrado++;return cad2;}else{cad2[2]=cad3[2];}
                    if (cad3[3]==' '||cad3[3]=='\0'&&borrado==1){cad2[3]='-';return cad2;}else{cad2[3]=cad3[3];}
                    cad2[4]='-';
                    return cad2;
                    }else{return cad3;}
}


