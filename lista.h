/**
*Quest'opera è stata rilasciata con licenza Creative Commons Attribuzione - Non commerciale - 
*Condividi allo stesso modo 3.0 Italia. 
*Per leggere una copia della licenza visita il sito web http://creativecommons.org/licenses/by-nc-sa/3.0/it/
*o spedisci una lettera a Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**************************************************************************
REALIZZAZIONE DI LISTA IMPLEMENTATA CON PUNTATORI
               
Autore: Riccardo Monterisi  http://riccardomonterisi.tk/
**************************************************************************/


/*
 * Classe lista:  è la lista vera e propria che è composta da elementi
 *                di tipo Box (che è una classe); i vari metodi pubblici
 *                sono i metodi standard per la gestione di una lista.
 */
 
//queste inclusioni e direttive vengono riportate anche nel file lista.cpp
#include "box.h"
//per utilizzare l'output a video
#include <iostream>
using namespace std;

class Lista  {

public:
	Lista(); // costruttore
	~Lista(); // distruttore

	bool listaVuota(); // TRUE se la lista non ha elementi, 
                      // FALSE al contrario

    // data la posizione come parametro (puntatore di tipo Box)
    // viene restituito l'elemento corrispondente                  
	int leggiLista(Box* ); 
	// restituisce la posizione del primo elemento della lista
	Box* primoLista();
	// restituisce TRUE se l'elemento inserito è l'ultimo della lista
	bool fineLista(Box*);
	// dato un elemento generico della lista, ne restituisce il successivo
	Box* succLista(Box*);
	// dato un elemento generico della lista, ne restituisce il precedente
	Box* precLista(Box*);
	//questo metodo viene usato per inserire un nuovo elemento dopo la
    // posizione fornita
	void insLista(int, Box*);
	//serve per eliminare l'elemento specificato da parametro Box*
	void cancLista(Box*);
	//serve per modificare un elemento gia presente in lista specificato
	// dal parametro Box*
	void scriviLista(int, Box*);
	
	//--metodo di utilità per la visualizzazione a video dell'intera
	// lista
	void stampaLista();

private:
  //variabile sentinella: punta al primo elemento della lista      
     Box* first;   
     //contatore degli elementi presenti in lista
 	 int n_elementi;
};
