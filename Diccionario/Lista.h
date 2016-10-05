#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Nodo
{
public:
	T m_palabra;
	T m_traduccion;
	Nodo<T> *m_psig;
public:
	Nodo(T p,T t)
	{
		m_palabra = p;
		m_traduccion = t;
		m_psig = 0;
	}
};
template <class T>
class Lista
{
public:
	Nodo<T> *m_pHead;
	Nodo<T> *m_pLast;
public:
	Lista()
	{
		m_pHead = m_pLast = 0;
	}
	void pushBack(T p,T t);
	//void pushFront(T p,T t);
	string find(T p);
	//bool remove(T p);
	//bool findR(T p, Nodo<T> *p);
	//string print();
};
template <class T>
void Lista<T>::pushBack(T p,T t)
{
	Nodo<T> *p_Nuevo = new Nodo<T>(p,t);
	if (m_pHead == 0)
		m_pHead = m_pLast = p_Nuevo;
	else{
		m_pLast->m_psig = p_Nuevo;
		m_pLast = p_Nuevo;
	}
}
template <class T>
string Lista<T>::find(T p)
{
	string cadena;
	Nodo<T> *aux = m_pHead;
	while (aux != 0)
	{
		if (aux->m_palabra == p){
			cadena = aux->m_palabra+"    Traduccion = " + aux->m_traduccion;
			return cadena;
		}
		aux = aux->m_psig;
	}
	return "no encontrado";
}

/*template <class T>
void Lista<T>::pushFront(T p,T t)
{
	Nodo<T> *p_Nuevo = new Nodo<T>(p,t);
	if (m_pHead == 0)
		m_pHead = m_pLast = p_Nuevo;
	else{
		p_Nuevo->m_psig = m_pHead;
		m_pHead = p_Nuevo;
	}
}
template <class T>
bool Lista<T>::remove(T p)
{
	Nodo<T> *aux1 = m_pHead;
	if (aux1 == 0){
		return false;
	}
	if (aux1->m_palabra == p && aux1->m_psig == 0){
		delete aux1;
		m_pHead = m_pLast = 0;
		return true;
	}
	Nodo<T> *ant = m_pHead;
	while (aux1 != 0)
	{
		if (aux1->m_palabra == p){
			ant->m_psig = aux1->m_psig;
			delete aux1;
			return true;
		}
		ant = aux1;
		aux1 = aux1->m_psig;
	}
	return false;
}

template <class T>
/*bool Lista<T>::findR(T d, Nodo<T> *p)
{
	if (p == 0)return false;
	if (p->m_dato == d)return true;
	findR(d, p->m_psig);
}
template<class T>
/*string Lista<T>::print()
{
	string str="";
	Nodo<T> *aux = m_pHead;
	while (aux != 0)
	{
		str= str + aux->m_dato;
		aux = aux->m_psig;
	}
	return str;
}*/