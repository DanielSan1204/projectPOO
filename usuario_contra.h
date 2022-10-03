#include<iostream>
#include<fstream>

using namespace std;
//var globals
string users;
string contrasenia;

string linea;//Variable temporal donde se almacenarán usuario y contraseña separados por coma y sacados desde el archivo csv
string arreglo[2];//Este arreglo servirá para separar el usuario y la contraseña guardándolos en una casilla distinta
size_t pos=0;//variable que contendrá la posición donde se encuentra la coma que separa el usuario de la contraseña
int contador = 0;//Servirá para avanzar en las casillas del arreglo
string dato;//Contendrá temporalmente el usuario o la contraseña mientras se separan
int fin = 0;//Servirá para darle fin a un bucle



int main() 
{
  cout<<"Escriba su Usuario: "<<endl;
  cin>>users;

  cout<<"Escriba su Contrasenia: "<<endl;
  cin>>contrasenia;


  fstream archivo("datos.csv");

  while (getline(archivo,linea) && fin==0)//Este bucle se repetira mientras la funcion getline pueda obtener lineas nuevas del archivo y la variable fin valga 0
  {
    while ((pos = linea.find(",")) != string::npos)/*Si el valor devuelto por la funcion find es distinto a la constante npos esto significa que si se ha encontrado lo que se busca dentro de la variable linea */
    {
    	dato = linea.substr(0,pos);//Se separan los caracteres desde la posicion 0 hasta una posicion previa al caracter separador que es la coma
    	arreglo[contador] = dato;//Se Guarda el dato anterior dentro de la casilla 0 o la 1 dependiendo del valor de contador
    	linea.erase(0,pos + 1);//Se elimina los caracteres desde la posicion 0 hasta la posicion donde se encuentra el caracter separador coma,incluida la coma
    	contador++;//El valor del contador aumenta
    }
    if (arreglo[0].find(users, 0) != string::npos)
    {
    	fin = 1;/*Si el nombre de alguna linea es igual al ingresado por el usuario cambiamos el valor de la variable fin para que se termine el bucle, sin importar que la contraseña sea incorrecta */

    } 		
    contador = 0; /* el valor del contador a 0 por si en la línea previa no estuviesen el nombre y la contraseña de nuestro usuario, así
continuamos en el bucle buscando hasta que se encuentre o se acaben los datos en el archivo.*/
  }

  /*si el nombre de usuario y la contraseña son iguales a los ingresados por el usuario de ser asi avanzamos,

le damos un mensaje de bienvenida y realizamos cualquier otra accion que necesitemos*/

 if (users == arreglo[0]&&contrasenia==arreglo[1])
 {
 	cout<<"Bienvenido Sr. Stark"<<endl;
 }
 else
 {
 	cout<<"Los datos son erroneos"<<endl;
 }

 //_getch(); //programa para que no se cierre
}