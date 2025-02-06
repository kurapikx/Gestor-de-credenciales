#include <iostream>
#include <cstdlib>
#include <windows.h> 
#include <time.h>
#include <string>
using namespace std;


int main() {
	//Assignacion de variables
	srand(time(NULL));

	string usuario = "";
	string passwrd = "";

	string inputUsuario = " ";
	string inputPasswrd = " ";

	bool Todocorecto = false;
	char respuestaUsuario = 's';
	char numeroUsuario = ' ';
	bool esAutomat = false;

	//Bucle que engloba todo el funcionamiento, mientras el usuario diga 's' o 'n'
	while (respuestaUsuario == 's' || respuestaUsuario == 'n')
	{
		system("cls");
		//switch que permite que cada vez que introduzca algo mal, se pueda restablecer sus credenciales con 's' y continuar con las anteriormente creadas con 'n'
		switch (respuestaUsuario)
		{
		case 's':
			//Mientras el usario no se haya creado unas credenciales seguira en el bucle
			while (Todocorecto == false && esAutomat == false)
			{
				cout << "VAMOS A CREARTE UNA CUENTA " << endl;
				cout << endl << "Pulse 1 : si quieres que se creen tus credenciales automaticamente : " << endl;
				cout << "Pulse 2 : si quieres crear tu tus credenciales : " << endl;
				cin >> numeroUsuario;
				system("cls");
				// En el momento de crear sus credenciales, el usuario tiene dos opciones: '1' hacerlo automaticamente y '2' hacerlo manual
				switch (numeroUsuario)
				{
				case '1':
					cout << "Se estan creando tus credenciales..." << endl;
					esAutomat = true;
					Sleep(1000);
					break;

				case '2':
					cout << endl << "Como te quieres llamar? : " << endl;
					cin >> usuario;
					cout << "Pon una password para mayor seguridad : " << endl;
					cin >> passwrd;

					//Regla para que la longitud de la constraseña sea mayor a 8
					if (passwrd.length() < 8)
					{
						cout << "ERROR: La password tiene que tener como minimo 8 caracteres" << endl;
						cout << endl;
						Sleep(3000);
						system("cls");
					}
					else
					{
						Todocorecto = true;
						Sleep(1000);
						system("cls");
					}
					break;

				default:
					break;
				}

			}
			//Una vez ya creada las credenciales tendra que iniciar sesion y en caso en el que el usuario se haya equivocado, pero quiera darle otra oportunidad

				//Mientras el usuario o la password no correspondan al input del usuario && si tambien se ha pasado la creacion de credenciales && si se ha heho en modo manual
			while ((usuario != inputUsuario || passwrd != inputPasswrd) && Todocorecto == true)
			{
				cout << "Introduzca su usuario :";
				cin >> inputUsuario;
				cout << "Introduzca su password :";
				cin >> inputPasswrd;

				//DIFERENTES CASOS DE FALLOS:

				//Fallo de las dos credenciales:
				if (usuario != inputUsuario && passwrd != inputPasswrd)
				{
					cout << endl << "usuario y password incorrectas , intentalo de nuevo" << endl;
					cout << endl << "Desea seguir intentando ? (s/n)" << endl;
					cin >> respuestaUsuario;

					if (respuestaUsuario != 's')
					{
						cout << endl << "Saliendo del sistema..." << endl;
						return 0;
					}
				}

				//Fallo de usuario
				else if (usuario != inputUsuario)
				{
					cout << endl << "usuario : " << inputUsuario << " incorrecto, intentalo de nuevo " << endl;
					cout << endl << "Desea seguir intentando ? (s/n)" << endl;
					cin >> respuestaUsuario;

					if (respuestaUsuario != 's')
					{
						cout << endl << "Saliendo del sistema..." << endl;
						return 0;
					}
				}
				//Fallo de contraseña
				else if (passwrd != inputPasswrd)
				{
					cout << endl << "password incorrecta , intentalo de nuevo" << endl;
					cout << endl << "Desea seguir intentando ? (s/n)" << endl;
					cin >> respuestaUsuario;

					if (respuestaUsuario != 's')
					{
						cout << endl << "Saliendo del sistema..." << endl;
						return 0;
					}
				}
				//Exito en el inicio de sesion
				else
				{
					cout << "Procesando la informacion..." << endl;
					Sleep(5000);
					cout << "------------------" << endl;
					cout << "ACCESO VALIDADO" << endl;
					cout << "------------------" << endl;
					return 0;
				}
				Sleep(2000);
				system("cls");
			}
			//Si no se elige ni 's' ni 'n' y si se eligio que fuera de manera automatica, se crearan las credenciales de manera automatica y random. 
			// En caso de que no se elige ni 's' ni 'n' ni se eligiera la manera automatica, saldra un ERROR para advertir que ha introducido un caract no correspondiente
		default:
			if (esAutomat == true)
			{
				Sleep(5000);
				cout << "------------------" << endl;
				cout << "ACCESO VALIDADO" << endl;
				cout << "------------------" << endl;

				//Randomizar Usuario
				const int llargadaUsuario = 10;
				char UsuarioCompleto[llargadaUsuario + 1];

				for (int i = 0; i < (llargadaUsuario); i++)
				{
					UsuarioCompleto[i] = 97 + rand() % (123 - 97);
				}
				UsuarioCompleto[llargadaUsuario] = '\0';

				//Randomizar password
				const int llargadaPassword = 20;
				char PasswordCompleto[llargadaPassword + 1];

				for (int i = 0; i < (llargadaPassword); i++)
				{
					PasswordCompleto[i] = 65 + rand() % (123 - 65);
				}
				PasswordCompleto[llargadaPassword] = '\0';

				//Printeada de credenciales automatica
				cout << "Tu usuario es : " << UsuarioCompleto << endl;
				cout << "Tu password es : " << PasswordCompleto << endl;

				cout << endl << "*Recomendamos guardarte esta informacion*" << endl;
				return 0;
			}
			//error de valor introducido

			else
			{
				cout << endl << "ERROR: has introducido un valor incorrecto, Vuelve a ejecutarlo." << endl;
				return 0;
			}
		}
	}
}

