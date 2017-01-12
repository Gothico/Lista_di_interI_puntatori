/**
*Quest'opera è stata rilasciata con licenza Creative Commons Attribuzione - Non commerciale - 
*Condividi allo stesso modo 3.0 Italia. 
*Per leggere una copia della licenza visita il sito web http://creativecommons.org/licenses/by-nc-sa/3.0/it/
*o spedisci una lettera a Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
/**************************************************************************
REALIZZAZIONE DI LISTA IMPLEMENTATA CON PUNTATORI
               
Autore: Riccardo Monterisi  http://riccardomonterisi.TK/
**************************************************************************/


// Classe Box: contiene il singolo elemento di una lista 
//Questa classe ha solo tre attributi pubblici :
//     - dato: l'elemento effettivo della lista
//     - prec: puntatore di tipo Box che indica l'elemento precedente  
//     - succ: puntatore di tipo Box che indica l'elemento successivo
 
class Box {
public:
	int dato;
	Box  *prec;
	Box  *succ;
}; 
 
