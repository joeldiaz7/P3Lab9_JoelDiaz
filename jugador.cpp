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

using namespace std;

#ifndef JUGADOR_CPP
#define JUGADOR_CPP
class jugador{
	private:
		string nombre;
		int dinero, vida, maxVida, nivel;
		bool batalla;
	public:
		jugador(){
			dinero = 0;
			vida = 1;
			maxVida = 3;
			nivel = 1;
			batalla = false;
		}
		
		bool getBatalla() {
			return batalla;
		}
		
		bool setBatalla(bool v) {
			batalla = v;
		}
		
		void setNombre(string n) {
			nombre = n;
		}
		
		void addDinero() {
			cout<<"+1 de dinero!"<<endl;
			dinero ++;
		}
		
		void subirNivel() {
			maxVida++;
			nivel++;
		}
		
		void hurt() {
			vida--;
		}
		
		int getNivel() {
			return nivel;
		}
		
		int getVida() {
			return vida;
		}
		
		int getMaxVida() {
			return maxVida;
		}
		
		int getDinero() {
			return dinero;
		}
		
		void addVida() {
			cout<<"+1 HP"<<endl;
			vida++;	
		}
		
		~jugador() {}	
};
#endif
