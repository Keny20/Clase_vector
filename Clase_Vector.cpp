#include <iostream>
#include <windows.h>

using namespace std ;

class Coor 
{
	private:
		class Nodo //estructurra o tipo de nodo de la clase 
		{
			public:
			int x ;   //seccion dl entero
			int y ; //coordenada y
			int z ;
			Nodo *sig;
		};
		Nodo *raiz;   //segundo elemento que ingreso a la cola
		Nodo *fondo;  //primer elemento que ingreso a la cola
	/*--------------------*/
public :
	Coor ();   //constructor
	~Coor(); //destructor... evaluar elementos en la cola, y si los hay es de ir destruyendo nodo a nodk cada elemento
	void insertar (int x, int y, int z); // agregar
	int extraer();        //eliminar
	void mostrar ();       //mostrar
	void prome ();
	bool vacia () ;        //vacia
} ;

//llamada a ,a misma clase
Coor::Coor()
{
	raiz = NULL  ; //apunta a la direccion nula
	fondo = NULL;
}
Coor::~Coor()
{
	Nodo *reco = raiz; //reco de tipo nodo porq apunta a la raiz, reco apunta al ultimo elemtendo de la cola
	Nodo *bor ;   //puntero auxioliar, toma el ultimo nodo de la cola para poder eliminar
	
	 /*si reco es distinto de null, tando raiz como fono estara 
	 nulo, si reco esta nulo no hay elementos en la cola, 
	 y si es diferente hay elementos en la cola y entra, 
	 bor toma los elementos de reco
	 y reco es igual al recorrido siguiente, y hace que el puntero
	 se mueva al primer nodo*/
	while (reco != NULL)
	{
		bor = reco ;
		reco = reco->sig ;
		delete bor ;  // eliminar nodo 2
	}	
}

void Coor::insertar (int x, int y, int z)
{
	Nodo *nuevo; //auxiliar permite incorporar valores que se iran agregando
	nuevo = new Nodo (); //dos porciones en la memoria, una info y otra para el puntero
	nuevo->x =x ;    //ingreso de nuevo valor en x
	nuevo->y =y ;       //ingreso de nuevo valor en y
	nuevo->z =z ;         //ingreso de nuevo valor en z
	nuevo->sig =NULL;  //mitad siguiente, por que nulo si el primer dato que nulo
	
	if (vacia())
	{
		raiz = nuevo;   
		fondo = nuevo;
	}
	else 
	{
		fondo->sig = nuevo ;    //fondo siguiente igual a nuevo
		fondo = nuevo ;	     //fondo igual a nuevo, elemento que se acaba de agregar
	}
}

/*int Coor::extraer ()
{
	if (!vacia()) //si es distinto de vacia
	{
		int coor1 = raiz->x;    //la coordenada 1 cambia de posicion 
		int coor2 = raiz->y;    //la coordenada 2 cambia de posicion 
		int coor3 = raiz->z;     //la coordenada 2 cambia de posicion 
		Nodo *bor = raiz ;      //el nodo bor toma el valor de la raiz
		if (raiz == fondo)  //y raiz pasa a ser el primer valor
		{
			raiz = NULL; //segubndo valor nulo
			fondo = NULL;  //primer valor nulo
		}
		else{ 
			raiz = raiz->sig;   //sino raiz toma el siguiente valor
		}
		delete bor;
		return coor1, coor2, coor3;
		
	}
	else
	{
	return -1 ;
	}	
}  */

void Coor::mostrar(){
	int contador = 0;     //inicializamos un contador para el conteo de veces en que insertaremos un datp
	Nodo *reco = raiz;
	while(reco != NULL){
		cout<<"Coordenada <X>: "<<reco->x<<endl;;
		cout<<"Coordenada <Y>: "<<reco->y<<endl;
		cout<<"Coordenada <Z>: "<<reco->z<<endl;
		reco = reco->sig;
		cout<<"_~_~_~_~_~_~_~_~_~_~_~_~_~_~"<<endl;
		contador ++;
	}
	cout<<"Espacio ocupado en memoria >> "<<contador*12<<" bytes"<<endl;
	cout<<endl;
}
void Coor::prome(){
	Nodo *reco = raiz;
	float contador = 0;
	float a1;
	float a2;
	float a3;
	float respuX;
	float respuY;
	float respuZ;
	cout<<"Promedio: "<<endl;
	
	while(reco != NULL){
		a1 = a1 + reco->x;
		a2 = a2 + reco->y;
		a3 = a3 + reco->z;
		reco = reco->sig;
		contador++;
	}
		respuX = (a1/contador);
		respuY = (a2/contador);
		respuZ = (a3/contador);	
	cout<<"Coordenada <X>: "<<respuX<<endl;;
	cout<<"Coordenada <X>: "<<respuY<<endl;
	cout<<"Coordenada <X>: "<<respuZ<<endl;
	a1 = 0;
	a2 = 0;
	a3 = 0;
	cout<<endl;
	cout<<endl;
}
bool Coor::vacia ()
{
	if (raiz == NULL)
	{
		return true;
	}
	else
	{
		return false ;
	}
}

int main () 
{
	int opcion;
	int vecX;
	int vecY;
	int vecZ;
	char resp ;
	Coor *coor1 = new Coor();
	do 
	{
		system ("color a9" ) ; //color
		cout << "**************MENU**************"<< endl ;
		cout <<"1-Ingresar" << endl ;
		cout <<"2-Mostrar" << endl ;
		cout <<"3-Promedio" << endl ;
		cout << "4-Salir" << endl ;
		cin >> opcion ;   //lectura de varibale
		
		switch (opcion)
		{
		case 1:
			system ("cls");				
			do
			{
			  cout << "Ingrese el valor de <X>: " ;
			  cin >>  vecX ;
			  cout << "Ingrese el valor de <Y>: " ;
			  cin >>  vecY ;
			  cout << "Ingrese el valor de <Z>: " ;
			  cin >>  vecZ ;
			   coor1->insertar(vecX, vecY, vecZ);
				  
			cout<<"Desesa agregar otro dato? y/n"<<endl;
			cin>>resp;       //llamada de variable
			system ( "cls" ) ;      //limpiar	
				
			}while (resp == 'y' || resp == 'Y');			
			system ("cls");
			break;
		case 2 :
			coor1->mostrar();
			system ( "pause");   //pausa
			system ( "cls" ) ;      //limpiar
			 break;
		 case 3:
			coor1->prome ();
			system ( "pause");   //pausa
			system ( "cls" ) ;      //limpiar
			break;
				/*caso cuatro salir*/
		case 4 :            
			cout << "Gracias"<< endl ;
			system ("pause");
			return 0;
			break;			
		}	
	}while (opcion !=0);
	system ("pause") ;
	return 0 ;
}
