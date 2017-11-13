#ifndef _SygnalLoader_h_
#define _SygnalLoader_h_
#include <string>
#include <fstream>
#include "SygnalProbkowany.h"
using namespace std;
class SygnalLoader
{
public:
	SygnalLoader() {}
	SygnalProbkowany wczytajSygnal(string _nazwaPliku)
	{
		ifstream plik;
        plik.open(_nazwaPliku.c_str(), ios::in);
        string linia;
        char znak;
        double liczba1, liczba2;
        SygnalProbkowany s;
        while (getline (plik, linia))
        {
	        plik >> liczba1 >> znak >> liczba2;
        	s.dodajProbke(Probka(liczba1,liczba2));
        }
        plik.close();
        return s;
	}
	void zapiszSygnal(SygnalProbkowany& _sygnal, std:: string _nazwaPliku)
	{
		ofstream plik;
		plik.open(_nazwaPliku.c_str(), ios::out);
		for (int i=1; i<_sygnal.iloscProbek(); ++i)
		{
			plik << _sygnal[i].t << ", " << _sygnal[i].x << endl;
		}
		plik.close();
	}
};
#endif
