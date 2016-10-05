#pragma once
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;


template<class T>
class Nodo {
public:
	Nodo(T dat, Nodo<T> *pad = nullptr, Nodo<T> *izq = nullptr, Nodo<T> *der = nullptr) :
		dato(dat),padre(pad), pIzq(izq),pDer(der),FE(0){}
	T dato;
	T FE;
	Nodo<T> *pDer;
	Nodo<T> *pIzq;
	Nodo<T> *padre;
};

/*template<class T>
Nodo<T>::Nodo(T d) {
	dato = d;
	pDer = pIzq = nullptr;
}*/




template <class T>
class AVL{
private:
	Nodo<T>* root;
	Nodo<T>* aux;
	int rama;
	enum { IZQUIERDO, DERECHO };
public:
	AVL();
	
	inline Nodo<T>* get_root() { return root; }

	void insertar(T dat);
	void equilibrar(Nodo<T>*& nodo, int, bool);
	void RSI(Nodo<T>*& nodo);
	void RSD(Nodo<T>*& nodo);
	void RDI(Nodo<T>*& nodo);
	void RDD(Nodo<T>*& nodo);
	void AddL(T d);
	bool buscar(T d, Nodo<T>**& p);
	void eliminar1(Nodo<T>* nodo);
	void eliminar2(T d ,Nodo<T>* &nodo);
	void imprimir(Nodo<T>*);
};

template<class T>
AVL<T>::AVL()
{
	root = nullptr;
	aux = nullptr;
}

template<class T>
void AVL<T>::insertar(T dat)
{
	//Creo el nodo padre que seria el padre del nodo a insertar
	Nodo<T> * padre = nullptr;
	
	aux = root;
	//Busco en donde insertar 
	while(aux!=nullptr &&  dat!=aux->dato)
	{
		padre = aux;
		if (dat > aux->dato) { aux = aux->pDer; rama = 1; }
		else { aux = aux->pIzq; rama = 0; }
	}
	//SI TIENE AUNQUE SEA UN PADRE

	//SI SE REPITE EL ELEMENTO SALGO DE INSERTAR
	if (aux!=nullptr) { return; }
	if (padre == nullptr) { root = new Nodo<T>(dat); }
	//else {Nodo<T>* nuevo= new Nodo<T>(dat, padre); *aux = nuevo;/*equilibrar(padre, rama, true);*/}
	else if (dat < padre->dato) {
		padre->pIzq = new Nodo<T>(dat, padre);
		   equilibrar(padre, IZQUIERDO, true);
	}
	else if (dat > padre->dato) {
	    padre->pDer = new Nodo<T>(dat, padre);
		   equilibrar(padre, DERECHO, true);
	}

}




template<class T>
void AVL<T>::equilibrar(Nodo<T>*& nodo, int rama, bool nuevo)
{
	bool salir = false;
	while (nodo != nullptr && salir == false)
	{
		if (nuevo)
		{
			//if (padre < padre->padre) { padre->FE--; }
			if (rama == IZQUIERDO)nodo->FE--;
			else    nodo->FE++;
		}
		else
		{
			//PARA ELIMINAR
			if (rama == IZQUIERDO) nodo->FE++;
			else    nodo->FE--;
		}

		switch (nodo->FE) {

				case 0: { salir = true; break; }

				case 2: {
					if (nodo->pDer->FE == -1) { RDD(nodo); }
					else { RSI(nodo); }
					salir = true;
					break;
				}

				case -2: {
					if (nodo->pIzq->FE == 1) { RDI(nodo); }
					else { RSD(nodo); }
					salir = true;
					break;
				}

		}

		if (nodo->padre != nullptr)
		{
			if (nodo->padre->pDer == nodo) rama = DERECHO;
			else rama = IZQUIERDO;
		}
		nodo = nodo->padre;
	}

}



template<class T>
void AVL<T>::RSI(Nodo<T>*& p)
{
	Nodo<T> *Padre = p->padre;
	Nodo<T> *q = p->pDer;
	
	if (Padre)
		if (Padre->pDer == p) Padre->pDer = q;
		else Padre->pIzq = q;
	else root = q;

	p->pDer = q->pIzq;
	q->pIzq = p;
	p->FE = q->FE = 0;

	// Reasignar padres:
	p->padre = q;
	q->padre = Padre;
}

template<class T>
void AVL<T>::RSD(Nodo<T>*& p)
{
	Nodo<T> *Padre = p->padre;
	Nodo<T> *q = p->pIzq;

	if (Padre)
		if (Padre->pDer == p) Padre->pDer = q;
		else Padre->pIzq = q;
	else root = q;
	
	p->pIzq = q->pDer; //REMPLAZO EL CONTENIDO DE Q POR EL DE Q->DER
	q->pDer = p; //GUARDO TODO EL CONTENIDO DE P
	p->FE = q->FE = 0;

	// Reasignar padres
	p->padre = q;
	q->padre = Padre;

}

template<class T>
void AVL<T>::RDD(Nodo<T>*& p)
{
	Nodo<T>*Padre = p->padre;
	Nodo<T>*q = p->pDer;
	Nodo<T>*r = q->pIzq;

	if (Padre)
		if (Padre->pDer == p) Padre->pDer = r;
		else Padre->pIzq = r;
	else root = r;

	p->pDer = r->pIzq;
	q->pIzq = r->pDer;
	r->pIzq = p;
	r->pDer = q;

	switch (r->FE) {
	case 0:  p->FE = 0; q->FE = 0; break;
	case 1:  p->FE =-1; q->FE = 0; break;
	case -1: p->FE = 0; q->FE = 1; break;
	}
	
	r->FE = 0;//RESETEAMOS A 0

	//Reasignar Padres
	r->padre = Padre;
	p->padre = r;
	q->padre = r;
}

template<class T>
void AVL<T>::RDI(Nodo<T>*& p)
{
	Nodo<T> *Padre = p->padre;
	Nodo<T>*q = p->pIzq;
	Nodo<T>*r = q->pDer;
 
	if (Padre)
		if (Padre->pDer == p) Padre->pDer = r;
		else Padre->pIzq = r;
	else root = r;

	p->pIzq = r->pDer;//CASO 2
	q->pDer = r->pIzq;//CASO 2
	r->pDer = p;//CASO 1
	r->pIzq = q;//CASO 1

	switch (r->FE) {
	case 0:  q->FE = 0; p->FE = 0; break;
	case 1:  q->FE =-1; p->FE = 0; break;
	case -1: q->FE = 0; p->FE = 1; break;
	}

	r->FE = 0;//RESETEAMOS A 0

	//Reasignar Padres
	r->padre = Padre;
	p->padre = r;
	q->padre = r;
}




template<class T>
bool AVL<T>::buscar(T d,Nodo<T>**& p)
{
	//Nodo<T> *p = root;
	p = &root;

	while (*p != nullptr)
	{
		if ((*p)->dato == d)
			return true;
		if ((*p)->dato < d)
			p = &(*p)->pDer;
		else
			p = &(*p)->pIzq;
	}

	return false;
}




template<class T>
void AVL<T>::AddL(T d)
{
	Nodo<T> **q;
	if (buscar(d, q) == true)
	{
		return;
	}
	else
	{
		*q = new Nodo<T>(d);
	}
}


template<class T>
void AVL<T>::eliminar2(T d, Nodo<T>*& nodo)
{
    /*Nodo<T>**temporal;
	Nodo<T>**tem = temporal;
	if (!find(d, temporal)) { return false; }

	if ((*temporal) == raiz) {
		temporal = &(raiz->hijo[0]);
		while ((*temporal)->hijo[1])
		{
			temporal = &(*temporal)->hijo[1];
		}
		cout << endl;
		raiz->dato = (*temporal)->dato;
	}
	if ((*temporal)->hijo[0] && (*temporal)->hijo[0]) {
		Nodo<T>**tem_ = temporal;
		temporal = &((*temporal)->hijo[0]);
		while ((*temporal)->hijo[1]) {
			temporal = &(*temporal)->hijo[1];
		}
		cout << endl;
		(*tem_)->dato = (*temporal)->dato;
		delete *temporal;
		*temporal = 0;
		return true;
	}
	if ((*temporal)->hijo[0] && !(*temporal)->hijo[1]) {
		tem = temporal;
		while ((*tem)->hijo[0]) {
			tem = &(*tem)->hijo[0];
		}
		(*temporal)->dato = (*tem)->dato;
		delete *tem;
		*tem = 0;
		return true;

	}
	if (!(*temporal)->hijo[0] && (*temporal)->hijo[1]) {
		tem = temporal;
		while ((*tem)->hijo[1]) {
			tem = &(*tem)->hijo[1];
		}
		(*temporal)->dato = (*tem)->dato;
		delete *tem;
		*tem = 0;
		return true;

	}

	delete *temporal;
	(*temporal) = 0;
	return true;*/
}

template<class T>
void AVL<T>::imprimir(Nodo<T> *p)
{
	if (p != nullptr)
	{
	//p = root->padre->padre;
		if (p->pIzq != nullptr)
		{
			imprimir(p->pIzq);
		}
		printf("%d", p->dato);

		if (p->pDer != nullptr)
		{
			imprimir(p->pDer);
		}
	}
	else
	    printf("%s\n", "EL ARBOL ESTA VACIO");
}


template<class T>
void AVL<T>::eliminar1(Nodo<T>* Ptr)
{
	if (Ptr != nullptr)
	{
		if (Ptr->pIzq != nullptr)
		{
			eliminar1(Ptr->pIzq);
		}
		if (Ptr->pDer != nullptr)
		{
			eliminar1(Ptr->pDer);
		}
		cout << "Deleting the node containing key: ";
		cout << Ptr->dato << "\n";
		delete Ptr;	
	}
	root = nullptr;
	//else
	//	printf("%s\n", "EL ARBOL ESTA VACIO");
}