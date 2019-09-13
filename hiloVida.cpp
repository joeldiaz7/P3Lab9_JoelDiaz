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
#include "jugador.cpp"

using namespace std;

#ifndef HILOVIDA_CPP
#define HILOVIDA_CPP
class hiloVida {
	private:
		bool vive;
		bool primera;
		string texto;
		int espera;
		int prob;
		jugador * jug;
	public:
		hiloVida(jugador * j) {
			espera = 6000;
			vive = true;
			jug = j;
			primera = true;
		}
		
		void setJugador(jugador * j) {
			espera = 6000;
			vive = true;
			jug = j;
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
			_beginthread(&hiloVida::runner, 0, static_cast<void*>(this));
		}
		
		static void runner(void* o) {
			static_cast<hiloVida*>(o)->runnerEstatico();
		}
		
		void runnerEstatico() {
			while (vive) {
				if (!primera) {
					if (jug->getVida() < jug->getMaxVida() and !(jug->getBatalla())) {
						jug->addVida();
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
		~hiloVida(){} 
};
#endif
