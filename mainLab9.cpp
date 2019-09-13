#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <process.h>
#include <time.h>
//#include <stdlib.h>
//#include <sqlite3.h>
#include "hiloDinero.cpp"
#include "hiloBatalla.cpp"
#include "hiloVida.cpp"
#include "jugador.cpp"

using namespace std;
string name;

int main() {
	int ganadas=0;
	int j1, j2;
	int op=0;
	cout<<"Ingresa tu nombre: "<<endl;
	cin>>name;
	jugador *jug = new jugador();
	jug->setNombre(name);
	//h1 batallas  -  h2 dinero  -  h3 vida
	hiloBatalla h1; 
	h1.setJugador(jug);
	h1.run();
	
	hiloDinero* h2 = new hiloDinero(jug);
	h2->setJugador(jug);
	h2->run();
	
	hiloVida* h3 = new  hiloVida(jug);
	h3->setJugador(jug);
	h3->run();
	
	while (op!=3 && jug->getVida()>0) {
		if (jug->getBatalla()) {
			ganadas = 0;
			cout << "[!] Combate iniciado [!]" << endl;
			while (ganadas != jug->getNivel() and jug->getVida() > 0) {
				cout << "1) Piedra"<<endl;
				cout << "2) Papel"<<endl;
				cout << "3) Tijera"<<endl;
				cout << "Ingresa tu opcion: ";
				cin >> j1;
				j2 = (rand() % 3) + 1;	
				//opciones de piedra-papel-tijeras
				if (j1 == 1) {
					if (j2 == 1) {
						cout << "Empate!" << endl;
					}
					if (j2 == 2) { 
						cout << "Derrota" << endl;
						jug->hurt();
					}
					if (j2 == 3) {
						cout << "Victoria" << endl;
						ganadas++;
					}
				}
				if (j1 == 2) {
					if (j2 == 1) {
						cout << "Victoria" << endl;
						ganadas++;
					}
					if (j2 == 2) {
						cout << "Empate!" << endl;
					}
					if (j2 == 3) {
						cout << "Derrota" << endl;
						jug->hurt();
					}
				}
				if (j1 == 3) {
					if (j2 == 1) {
						cout << "Derrota" << endl;
						jug->hurt();
					}
					if (j2 == 2) {
						cout << "Victoria" << endl;
						ganadas++;
					}
					if (j2 == 3) {
						cout << "Empate!" << endl;
					}
				}
				system("pause");
				system("cls");
			}
			//---------------------------RESULTADOS----------------------------
			if (jug->getVida()>0) {
				cout<<"Has ganado! [Subes de nivel!]"<<endl;
				jug->subirNivel();
			}else{
				// Perdio
				cout<<"Has sido derrotado en combate!"<< endl;
			}
			//------------------------------------------------------------------
			system("pause");
			system("cls");
			jug->setBatalla(false);
		}else{
			cout<<"MENU"<<endl;
			cout<<"1> Datos del jugador"<<endl;
			cout<<"2> Curar vida ($1)"<<endl;
			cout<<"3> Salir" <<endl;
			cout<<"Opcion: ";
			cin>>op;
			system("cls");
			//----------------------OPCIONES DEL MENU----------------------------
			if (op == 1) {
				cout<<"DATOS"<<endl;
				cout<<"Nivel: "<<jug->getNivel()<<endl;
				cout<<"$ " <<jug->getDinero()<<endl;
				cout<<"Vida: "<< jug->getVida()<<"/"<< jug->getMaxVida()<<endl;
				system("pause");
			}
			if (op == 2) {
				if (jug->getDinero() > 0) {
					if (jug->getVida() < jug->getMaxVida()) {
						// agregar 1 de dinero
						jug->addVida();
						cout << "Compraste 1 de HP!" << endl;
						cout << "-$1" << endl;
					}else{
						cout << "Ya estas en tu vida maxima!" << endl;
					}
					
				}else{
					cout << "No tienes dinero suficiente!" << endl;
				}
				
				system("pause");
			}
			
			system("cls");
		}
	//------------------------------------------------------------------
	}
	//liberacion de memoria
	h1.stop();
	h2->stop();
	h3->stop();
	jug->~jugador();
	h1.~hiloBatalla();
	h2->~hiloDinero();
	h3->~hiloVida();
	cout<<"Gracias por jugar"<<endl;
	system("pause");

}
