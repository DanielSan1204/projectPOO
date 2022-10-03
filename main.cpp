#include "controller/SesionController.h"
#include <fstream>
#include <iostream>
using namespace std;

SesionController *objSesionController = new SesionController();
void menu();
void login();
void registrer();
int main() { menu(); }

void menu() {
  int opt;

  do {
    cout << "__      __        _          __  __" << endl;
    cout << "\\ \\    / /       | |        |  \\/  |" << endl;
    cout << " \\ \\  / /__ _ __ | |_ __ _  | \\  / | __ _ ___ " << endl;
    cout << "  \\ \\/ / _ \\ '_ \\| __/ _` | | |\\/| |/ _` / __|" << endl;
    cout << "   \\  /  __/ | | | || (_| | | |  | | (_| \\__ \"" << endl;
    cout << "    \\/ \\___|_| |_|\\__\\__,_| |_|  |_|\\__,_|___/\n" << endl;
    cout << "\t*****Acceso al Sistema*****" << endl;
    cout << "Registrer*[1]" << endl;
    cout << "Login*****[2]" << endl;
    cout << "Salir*****[3]" << endl;
    cout << "Ingrese una opcion: [1- 3]: ";
    cin >> opt;
    system("cls");
    switch (opt) {
    case 1:
      registrer();
      system("pause");
      system("cls");
      break;
    case 2:
      login();
      system("pause");
      system("cls");
      break;
    case 3:
      cout << "Gracias por usar nuestro programa\n";
      break;
    default:
      system("cls");
      cout << "Ingresa una opción correcta[1-3]\n";
    };

  } while (opt != 3);
}

void registrer() {
  string usuario, contrasenia;
  cout << "\tNUEVO REGISTRO\n\n";
  cin.ignore();
  cout << "Ingrese su usuario: ";
  getline(cin, usuario);
  cout << "Ingrese su contrasenia: ";
  getline(cin, contrasenia);

  Sesion sesion(usuario, contrasenia);
  objSesionController->agregarObjeto(sesion);
  objSesionController->grabarArchivo(sesion);
}

void login() {
  string users, contrasenia;
  cout << "\tLOG IN\n\n";
  cin.ignore();
  cout << "Escriba su Usuario: ";
  getline(cin, users);

  cout << "Escriba su Contrasenia: ";
  getline(cin, contrasenia);
  objSesionController->verificarLogin(users, contrasenia);
}
