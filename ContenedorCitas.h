#pragma once
#include "Librerias.h"
#include "Citas.h"
#include "Persona.h"

class ContenedorCitas {
private:
	vector<Citas*> listaCitas;
public:
	void setAgendarCita() {
		int numeroCita;

		do {
			cout << "Ingrese el numero de cita a registrar: "; cin >> numeroCita;
			if (numeroCita < 0 || numeroCita > 2222222222) {
				system("cls");
				cout << "Codigo invalido" << endl;//el codigo debe ser mayor a 0 para romper salir del bucle.
				system("pause");
				system("cls");
			}
		} while (numeroCita < 0 || numeroCita > 2222222222);

		if (this->listaCitas.empty()) { // En caso de estar vacia, hacer lo siguiente
			int cedulaUsuario;
			int codigoMedico;
			string fecha;
			int codigoServicio;
			float costoTotal;

			do {
				system("cls");
				cout << "Ingrese el cedula de usuario: "; cin >> cedulaUsuario;
				if (cedulaUsuario < 0) {
					system("cls");
					cout << "cedula invalida" << endl;
					system("pause");
					system("cls");
				}
			} while (cedulaUsuario < 0);
			system("cls");

			do {
				cout << "Digite el codigo del medico: "; cin >> codigoMedico;
				if (codigoMedico < 0) {
					system("cls");
					cout << "Codigo invalido" << endl;
					system("pause");
					system("cls");
				}
			} while (codigoMedico < 0);
			system("cls");

			cin.ignore();
			cout << "Introduzca la fecha: "; getline(cin, fecha);
			//system("pause");
			system("cls");

			do {
				cout << "Digite el codigo de servicio: "; cin >> codigoServicio;
				if (codigoServicio < 0) {
					system("cls");
					cout << "Codigo invalido" << endl;
					system("pause");
					system("cls");
				}
			} while (codigoServicio < 0);
			system("cls");

			do {
				cout << "Ingrese el costo total del servicio: "; cin >> costoTotal;
				if (costoTotal < 0) {
					system("cls");
					cout << "Monto invalido" << endl;
					system("pause");
					system("cls");
				}
			} while (costoTotal < 0);
			system("cls");
			Citas* newCita = new Citas(numeroCita, cedulaUsuario, codigoMedico, fecha, codigoServicio, costoTotal);
			listaCitas.push_back(newCita);
			cout << "Se ha registrado existosamente!" << endl;
			system("pause");
			system("cls");
			
		}else {
			for (int i = 0; i < listaCitas.size(); i++) {
				if (this->listaCitas[i]->getNumeroCita() == numeroCita) {
					cout << "Ya hay una cita agendada con ese codigo." << endl;
					return; //Esto es para que salga del método
				}
				else {
					int cedulaUsuario;
					int codigoMedico;
					string fecha;
					int codigoServicio;
					float costoTotal;

					do {    //si aquí se ingresa un monto muy grande, entra en el bucle y nunca sale, pero eso es porque se excede el rango de almacenamiento del tipo de dato, me falta arreglar eso
						system("cls");
						cout << "Ingrese el cedula de usuario: "; cin >> cedulaUsuario;
						if (cedulaUsuario < 0) {
							system("cls");
							cout << "cedula invalida" << endl;
							system("pause");
							system("cls");
						}
					} while (cedulaUsuario < 0);
					system("cls");

					do {
						cout << "Digite el codigo del medico: "; cin >> codigoMedico;
						if (codigoMedico < 0) {
							system("cls");
							cout << "Codigo invalido" << endl;
							system("pause");
							system("cls");
						}
					} while (codigoMedico < 0);
					system("cls");

					cin.ignore();
					cout << "Introduzca la fecha: "; getline(cin, fecha); 
					//system("pause");
					system("cls");


					do {
						cout << "Digite el codigo de servicio: "; cin >> codigoServicio;
						if (codigoServicio < 0) {
							system("cls");
							cout << "Codigo invalido" << endl;
							system("pause");
							system("cls");
						}
					} while (codigoServicio < 0);
					system("cls");

					do {
						cout << "Ingrese el costo total del servicio: "; cin >> costoTotal;
						if (costoTotal < 0) {
							system("cls");
							cout << "Monto invalido" << endl;
							system("cls");
						}
					} while (costoTotal < 0);
					system("cls");
					Citas* newCita = new Citas(numeroCita, cedulaUsuario, codigoMedico, fecha, codigoServicio, costoTotal);
					listaCitas.push_back(newCita);
					cout << "Se ha registrado existosamente!" << endl;
					system("pause");
					system("cls");
					break;
				}
				break;
			}
			
		}
		//tengo un problema con este metodo,cuando ingrese mas de una cita, y estas son de 3 cifras, el programa igual me permite que se creen citas duplicadas, o en lugar de decir que tal codigo ya se encuentra en el sistema por lo que no se puede añadir, lo qeu hace es que no dice nada y se devuelve al menu
		//por lo que cuando se generan 2 duplicados, tampoco se puede modificar con el segundo metodo pq dice que el codigo es invalido.
	}

	void setModificarCita() {
		int busqueda;

		if (this->listaCitas.empty()) {
			cout << "No hay ninguna cita agendada en el sistema." << endl;
			cout << endl;
		}else {
			cout << "Ingrese el numero de cita que se desea modificar: "; cin >> busqueda;
			system("cls");

			for (int i = 0; i < this->listaCitas.size(); i++) {
				if (this->listaCitas[i]->getNumeroCita() == busqueda) {
					int cedulaUsuario;
					int codigoMedico;
					string fecha;
					int codigoServicio;
					float costoTotal;   

					cout << "Digite su numero de cedula: "; cin >> cedulaUsuario;
					system("cls");
					cout << "Digite el codigo del medico: "; cin >> codigoMedico;
					system("cls");
					cout << "Ingrese la fecha en la que se agendo la cita: "; cin >> fecha;
					system("cls");
					cout << "Digite el codigo del servicio: "; cin >> codigoServicio;
					system("cls");
					cout << "Ingrese el costo total: "; cin >> costoTotal;

					this->listaCitas[i]->setCita(cedulaUsuario, codigoMedico, fecha, codigoServicio, costoTotal);

					cout << "\nSe ha acutalizado correctamente!" << endl;
					break;
				}
				else {
					cout << "No encontro ninguna cita con ese codigo." << endl;
					cout << endl;
					break;
				}
			}
		}
	}

	void consultarCitas() {
		if(this->listaCitas.empty()) {
			cout << "No hay ninguna cita agendada en el sistema." << endl;
			cout << endl;
		}
		else {
			for (int i = 0; i < this->listaCitas.size(); i++) {
				this->listaCitas[i]->getMostrarDatos();
				cout << endl;
			}
		}
	}
