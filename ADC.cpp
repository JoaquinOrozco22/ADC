/*Archivo ADC.cpp
Este archivo contiene la implementación de cada metodo declarado en el archivo header ADC.h.*/

//Inclusion de librerias.
#include<iostream>
#include<math.h>
#include"ADC.hpp"

using namespace std;

	//Implementacion geters del metodo para la obtencion del valor de frecuencia.
	int ADC::get_frec(){
		return _frec;
	}
	//Implementacion geters del metodo para la obtencion del valor de del canal.
	int ADC::get_canal(){
		return _canal;
	}
	/*Implementación del metodo para leer el valor de frecuencia guardado en el main y pasarlo a la variable
	miembro de la clase.*/
	void ADC::leer_frec(int frec){
		_frec=frec;
	}
	/*Implementación del metodo para leer el valor de la resolucion guardado en el main y pasarlo a la variable
	miembro de la clase.*/
	void ADC::leer_resol(int resol){
		_resol=resol;
	}
	//Implementacion del metodo para mostrar el valor digital del canal seleccionado obtenido algebraicamente.
	void ADC::mostr_digi(){
		_digi=(int)(_analo/3.3*(pow(2,_resol)-1));
		cout<<"Valor digital de la lectura del canal "<<_canal<<": "<<_digi<<endl;
	}
	//Implementacion del metodo para introducir el valor analógico del voltaje.
	void ADC::leer_analo(){
		cout<<"Introduzca el valor del voltaje para el canal "<<_canal<<"."; 
		cout<<"\nRecuerde que el voltaje debe estar en un rango de 0v - 3.3v"<<endl;
		cout<<"Voltaje: "; cin>>_analo;
		while((_analo<0)||(_analo>3.3)){ //while encargado de validar que el valor introducido este dentro del rango permitido.
			cout<<"El valor introducido no esta dentro del rango de voltaje permitido."<<endl;
			cout<<"\nIntroduzca el valor del voltaje para el canal "<<_canal<<"."<<endl; 
			cout<<"Recuerde que el voltaje debe estar en un rango de 0v - 3.3v"<<endl;
			cout<<"Voltaje: "; cin>>_analo;
		}
	}
	//Implementacion del metodo para mostrar el canal analogico.
	void ADC::leer_canal(){
		cout<<"Canal An: "; cin>>_canal;
	}
