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
#include "lista.h"

/*--Metodo costruttore
 FUNZIONAMENTO: vengono inizializzati gli attributi first e n_elementi,
first ha un basso valore negativo e punta a se stesso in entrambi i sensi
*/
Lista::Lista()  {

/*qui si istanzia un puntatore di tipo Box:
      - sizeof(Box): determina la dimensione di un oggetto di tipo Box;
      - malloc: riserva in memoria lo spazio risultante da sizeof
      -(Box*): effettua il casting al risultato di malloc in modo da 
               definire il tipo della variabile creata        
*/                      
    first = (Box*) malloc(sizeof(Box));
	
    first->dato = -9999;
	first->succ = first;
	first->prec = first;                        

    n_elementi = 0; 
};

/*
metodo distruttore
*/
Lista::~Lista() {};

  
void Lista::insLista(int in, Box* pos)
/*
 * PARAMETRI:
 *  		  in   valore di tipo intero dell'elemento
 *  			   inserito nella lista
 *            pos  posizione precedente dell'elemento 
 *                 all'interno della lista
 *       	     
 * FUNZIONAMENTO: viene istanziato un elemento Box* 
 * 				  il quale viene collegato dopo la posizione fornita.
 *                
 */
{
    Box* temp;

	temp = (Box*) malloc(sizeof(Box));
    //si assegna il valore dell'elemento della lista
    temp->dato = in;
    
    
//se la lista è vuota    
    if (n_elementi == 0) {
       //collego il nuovo elemento con la variabile sentinella            
       first->succ = temp;
       first->prec = temp;
       temp->succ = first;
       temp->prec = temp;            
    } 
    else 
    //altrimenti abbiamo due possibilità
    { 
   //Se stiamo inserendo il secondo elemento della lista              
        if (pos == first) {  
           //lo colleghiamo al primo elemento     
           temp->succ = first->succ;
           temp->prec = first->succ;
           first->succ->succ = temp; 
           first->succ->prec = temp; 
        } 
        //se abbiamo gia almeno due elementi allora
        //il nuovo elemento della lista verrà inserito DOPO 
        //la posizione fornita
       if (n_elementi >= 2) {      
           temp->succ = pos->succ;
           pos->succ->prec = temp;
           pos->succ = temp;
           temp->prec  = pos;
       }  
    }

    n_elementi++;
};

 
void Lista::scriviLista(int n, Box* p)  
/*
 * PARAMETRI:   n  nuovo valore dell'elemento 
 *              p  posizione dell'elemento da sovrascrivere
 *
 *  FUNZIONAMENTO: viene aggiornato l'elemento indicato 
 *                 della lista con il dato fornito come parametro
 *          
 */
{   // viene sempre controllato che la lista non sia vuota 
    if (!listaVuota()) { 
       p->dato = n;
    }
};

/*
*
* FUNZIONAMENTO: viene fornito il primo elemento della lista 
*                puntato dall'attributo first
*/
 
Box* Lista::primoLista() 
{
   Box* output; //posizione
   output = first->succ;
   return output;
};
 
/*
* FUNZIONAMENTO: se il campo n_elementi è pari a 0 la lista è vuota
*/
bool Lista::listaVuota()
{
	return (n_elementi == 0);
};

//
bool Lista::fineLista(Box* pos)
/*
 * PARAMETRI:
 *            pos  posizione dell'elemento in considerazione
 *
 * FUNZIONAMENTO: si verifica che l'elemento fornito come parametro
 *                sia l'ultimo della lista o meno.
 *                Un elemento è l'ultimo della lista quando il suo campo succ
 *                punta al primo elemento della lista
 */
{
                  
	 bool esito = false;
	 Box* px;

	 px = first;

	do
	{
		px = px->succ;
	} while (px->succ == first->succ);


	  if (pos == px)
	    esito = true;

	  return esito;
};


int Lista::leggiLista(Box* pos) 
/*
 * PARAMETRI:
 *            pos posizione dell'elemento da leggere
 *
 * FUNZIONAMENTO: se la lista non è vuota, si restituisce il valore 
 *                dell'elemento indicato come parametro 
 */
{ 
  int value = -9999;
  if(!(listaVuota())) {
     value = pos->dato;               
  }
            
  return value;
};


 Box* Lista::succLista(Box* pos)
/*
 * PARAMETRI:
 *         pos posizione dell'elemento di cui si vuol
 *             conoscere il successivo
 */
{
  Box* output = pos->succ;

  return output;
};


Box* Lista::precLista(Box* pos)
/*
 *  PARAMETRI:
 *       pos  posizione dell'elemento di cui si vuol
 *            conoscere il precedente
 */
{
   Box* output = pos->prec;

   return output;
};

//
void Lista::cancLista(Box* pos)  
/*
 *  PARAMETRI:
 *      pos  posizione dell'elemento da cancellare
 */
{
   if (!listaVuota()) {
     //se vado a cancellare il primo elemento                  
     if (first->succ == pos) {
        //faccio puntare first all'elemento successivo al primo             
        first->succ =  pos->succ;
        first->prec = pos->succ;
        //anche gli elementi precedenti e successivi vengono 
        //collegati opportunamente con gli elementi rimanenti
         pos->succ->prec = pos->prec;
   	     pos->prec->succ = pos->succ;               
     }   
     else {
        // se cancello un generico elemento 
        // il suo precedente e il suo successivo  
        // andranno collegati tra loro
        pos->succ->prec = pos->prec;
	    pos->prec->succ = pos->succ;
        pos = pos->succ; 
     }              

     n_elementi--;                   
   } 
};

//
void Lista::stampaLista()  
/*
 *  FUNZIONAMENTO:  vengono stampati gli elementi della lista tranne
 *  				l'elemento sentinella
 */
{
   if (!(listaVuota())) {
      Box* pos = first->succ;
	 
	   do {
		cout << "Elemento: " << pos->dato << "\n";
		pos = pos->succ;
	  } while (pos != first->succ);                     
   } 
   else
       cout << "Lista vuota." << "\n";   
};


