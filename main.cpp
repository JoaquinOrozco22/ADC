#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include"ADC.hpp"
using namespace std;

int ADC::_resol=0;
int ADC::_frec=0;

int main(int argc, char** argv) {
	int frec_mues, resol, cantcan;
	
	cout<<"\tSIMULADOR DE CONVERTIDOR ANALOGICO A DIGITAL"<<endl<<endl;
	cout<<"Ingrese la resolucion del ADC."<<endl;
	cout<<"Recuerde que la resolucion del ADC es de 8, 10 o 12 bits."<<endl; 
	cout<<"Resolucion: "; cin>>resol;
	while(resol!=8&&resol!=10&&resol!=12){
		cout<<"El valor de resolucion introducido es invalido."<<endl;
		cout<<"Recuerde que la resolucion del ADC es de 8, 10, 12 bits."<<endl;
		cout<<"Resolucion: "; cin>>resol;
	}
	cout<<"Ingrese la Frecuencia de Muestreo (MHz): "; cin>>frec_mues;
	cout<<"Ingrese el numero de canales a leer."<<endl;
	cout<<"Recuerde que el rango de canales es de 1 a 32 Canales."<<endl;
	cout<<"Numero de canales: "; cin>>cantcan;
	while(cantcan<1||cantcan>32){
		cout<<"El numero de canales ingresado no es valido o esta fuera del rango permitido."<<endl;
		cout<<"Recuerde que el rango de canales es de 1 a 32 Canales."<<endl;
		cout<<"Numero de canales: "; cin>>cantcan;
	}
	
	ADC *nadcs= new ADC[cantcan];
	
	nadcs[0].leer_resol(resol);
	nadcs[0].leer_frec(frec_mues);
	cout<<"Introduzca el/los canales que desea leer"<<endl;
	cout<<"Recuerde que el rango de canales es de 1 a 32 Canales."<<endl;
	for(int i=0; i<cantcan;i++){
		nadcs[i].leer_canal();
		for(int j=0;j<i;j++){
			if(nadcs[i].get_canal() == nadcs[j].get_canal()){
				cout<<"El canal ya ha sido configurado, ingrese un canal distinto: "<<endl; 
				nadcs[i].leer_canal();
				j--;
			}
		}
	}
	cout<<"Frecuencia de muestreo: "<<nadcs[0].get_frec()<<" MHz "<<endl;
	for(int i=0; i<cantcan; i++){
			nadcs[i].leer_analo();
	}	
	for(int i=0; i<cantcan; i++){
		nadcs[i].mostr_digi();
	}
	delete nadcs;
	
	getch();
	return 0;
}
