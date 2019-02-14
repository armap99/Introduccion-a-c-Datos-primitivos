/*Nombre:Luis Armando Prado Núñez
  Maestro:Alfredo Gutierrez Hernadez Seccion: D11
  Clase:Estructuras de Datos I*/


#include <iostream>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctime>
#include <stdlib.h>

class datos{//clase
	int bits;
	std:: string tipo;
	double vmax,vmin;
	public:
		datos(int,std::string,double,double);
		void mostrar();
};

datos::datos(int _bits,std:: string _tipo,double _vmax,double _vmin){//constructor 
	bits=_bits;
	tipo=_tipo;
	vmax=_vmax;
	vmin=_vmin;
}

void datos::mostrar(){//accion de clase o atributo
	std::cout << tipo <<"         |         "<< 8*bits<< "         |         " <<  vmax << "         |         " << vmin <<"         |         "<<std::endl;
}

class operaciones{
	int n;
	float ma1[10][10],ma2[10][10];
	public:
		operaciones(int);
		void suma();
		void llenar();
		void multiplicacion();
		void imprimir();
};

operaciones::operaciones(int _n){
	n=_n;
}

void operaciones::llenar()
{
	int j,i;
	srand(time(NULL));
	for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						ma1[i][j]=float(-1000+(rand()%2000))*10/100;
						ma2[i][j]=float(-1000+(rand()%2000))*10/100;
					}
				}
}

void operaciones::suma(){
	int i,j;
	std::cout<<"Suma de Matrices: "<< std::endl;
	for(i=0;i<n;i++)
	{
		std::cout<<std::endl;
		for(j=0;j<n;j++)
		{
			std::cout<<ma1[i][j]+ma2[i][j]<<"    ";
		}
	}
	std::cout << " " <<std::endl;
}

void operaciones::multiplicacion(){
	int i,j,k;
	double C[10][10];
	std::cout<<"Multiplicacion de Matrices: "<<std::endl;
	for (i = 0 ; i < n ; i++ ) 
	{
    	for (j = 0 ; j < n ; j++ ) 
    	{
        	for (k = 0 ; k < n ; k++ ) 
            {                                  
            	C[i][j]+= ma1[i][k] * ma2[k][j];
        	}
        }
	}
    for (i=0;i<n;i++)
	{
		std::cout << " " << std::endl;
   		for (j=0;j<n;j++)
    	{
	 		std::cout << C[i][j] <<"    ";
   		}
   }
   std::cout << " " <<std::endl;
}

void operaciones::imprimir(){
	int i,j;
	std::cout<<"Las Matrices son:"<<std::endl;
	for(i=0;i<n;i++)
	{
		std::cout<<std::endl;
		for(j=0;j<n;j++)
		{
			std::cout<<ma1[i][j]<<"    ";
		}
	}
	std::cout << std::endl;
	for(i=0;i<n;i++)
	{
		std::cout<<std::endl;
		for(j=0;j<n;j++)
		{
			std::cout<<ma2[i][j]<<"    ";
		}
	}
	std::cout << std::endl;
}

main()
{
	char menu;
	int cu,i,j;
	float tr1[10][10],tr2[10][10];
	do{
		std::cout <<"MENU" <<std::endl;
		std::cout <<"A)Tamaño y rangos de los Tipos de Dato Primitivos" << std::endl;
		std::cout <<"B)Ejemplo de uso de Tipo de dato Estructurado" << std::endl;
		std::cout <<"C)Salir" <<std::endl;
		std::cin>> menu;
		toupper(menu);
		switch(menu)
		{
			
			case 'B':
				{
					do{
						std::cout<<"Tamaño de la matriz (mayor que 2 y menor que 11): "<<std::endl; 
						std::cin>> cu;
					}while(3>cu || cu>10);
					
					operaciones _matrices= operaciones(cu);
					_matrices.llenar();
					_matrices.imprimir();
					_matrices.suma();
					_matrices.multiplicacion();
				break;
				}
			
			case 'A':
				{
				
					std::cout << "Tipo De Dato                      Bits             Valor maximo            Valor Minimo" << std::endl;
					datos _char = datos(sizeof(signed char),"Caracter con signo",SCHAR_MAX,SCHAR_MIN);//caracter con signo
					datos _uchar = datos(sizeof(char),"Caracter sin signo",UCHAR_MAX,UCHAR_MAX-UCHAR_MAX);//caracter sin signo
					datos _int = datos(sizeof(short int),"Entero Corto sin signo",USHRT_MAX,USHRT_MAX-USHRT_MAX);//entero corto sin signo 
					datos _sint = datos(sizeof(short int),"Entero Corto con signo",SHRT_MAX,SHRT_MIN);//entero corto con signo 
					datos _lint= datos(sizeof(long int),"Entero Largo con signo",LONG_MAX,LONG_MIN);//entero largo con signo
					datos _ulint= datos(sizeof(long int),"Entero Largo sin signo",ULONG_MAX,ULONG_MAX-ULONG_MAX);//entero largo con signo                 
					datos _float= datos(sizeof(float),"Real de precisión simple",FLT_MAX,-FLT_MAX);
					datos _double=datos(sizeof(double),"Real de doble precisión",DBL_MAX,-DBL_MAX);
					_char.mostrar();
					_uchar.mostrar();
					_sint.mostrar();
					_int.mostrar();
					_lint.mostrar();  
					_ulint.mostrar();
					_float.mostrar();
					_double.mostrar();                                  
				break;
			}
		}
	}while(menu!='C');
}
