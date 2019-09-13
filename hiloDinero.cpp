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
#include "jugador.cpp"
//#include <stdlib.h>
//#include <sqlite3.h>

using namespace std;

#ifndef HILODINERO_CPP
#define HILODINERO_CPP
class hiloDinero {
	private:
		
		bool vive;
		string texto;
		int espera;
		int prob;
		bool primera;
		jugador * jug;
		
	public:
		hiloDinero(jugador * j) {
			espera = 7000;
			vive = true;
			primera = true;
			jug = j;
		}
		
		void setJugador(jugador * j) {
			espera = 7000;
			vive = true;
			primera = true;
			jug = j;
		}
		
		void setVive(bool v) {
			vive = v;
		}
					
		void setEspera(int e) {
			espera = e;
		}
		
		void stop() {
			vive=false;
		}
		
		void run() {
			_beginthread(&hiloDinero::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o) {
			static_cast<hiloDinero*>(o)->runnerEstatico();
		}
		
		void runnerEstatico() {
			
			while (vive) {
				
				if (!primera) {
					if (!(jug->getBatalla())) {
						jug->addDinero();
					}
				}else{
					primera = false;
				}
					
				
				Sleep(espera);
				if (!vive) {
					_endthread();
				}
			}
		}
		~hiloDinero(){}
};
#endif
