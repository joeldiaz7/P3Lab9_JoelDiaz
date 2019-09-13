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
#include "hiloVida.cpp"
#include "jugador.cpp"
using namespace std;

#ifndef HILOBATALLA_CPP
#define HILOBATALLA_CPP
class hiloBatalla{
	private:
		bool vive;
		string texto;
		int espera;
		int prob;
		int lvl;
		jugador * jug;
		bool primera;
		
	public:
		hiloBatalla(){}
		
		void setJugador(jugador * j) {
			jug = j;
			espera = 10000;
			vive = true;
			lvl = 1;
			primera = true;
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
			_beginthread(&hiloBatalla::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o) {
			static_cast<hiloBatalla*>(o)->runnerEstatico();
		}
		
		void runnerEstatico() {
			while (vive) {
				if (!primera) {
					if (jug->getBatalla()) {
					}else{
						srand(time(0));
						prob = rand() % 5 + 1;
						if (prob<=4) {
							jug->setBatalla(true);
						}else{
							jug->setBatalla(false);
						}	
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
		~hiloBatalla(){} 
};
#endif
