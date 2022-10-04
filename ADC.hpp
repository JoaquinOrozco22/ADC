/*Archivo ADC.hpp
Este archivo "header" contiene la declaración de la clase, con sus atributos y sus métodos pertenecientes. */ 

//Clase llamada ADC
class ADC{
	static int _frec; //Las variables _frec y _resol se declaran como static debido a que se utilizaran los valores 
	static int _resol; //introducidos para cada canal.
	int _digi; 
	double _analo;
	int _canal;

	public: //Los metodos se declararon como publicos para que se pueda acceder a ellos.
		int get_frec();
		int get_canal();
		void leer_frec(int frec);
		void leer_resol(int resol);
		void mostr_digi();
		void leer_analo();
		void leer_canal();
};
