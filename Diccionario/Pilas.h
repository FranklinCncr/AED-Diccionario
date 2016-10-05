#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Nodo
{
public:
	T m_dato;
	Nodo<T> *m_psig;
public:
	Nodo(T d)
	{
		m_dato = d;
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
	void pushBack(T d);
	void pushFront(T d);
	bool find(T d);
	bool remove(T d);
	bool findR(T d, Nodo<T> *p);
	string print();
};
template <class T>
void Lista<T>::pushBack(T d)
{
	Nodo<T> *p_Nuevo = new Nodo<T>(d);
	if (m_pHead == 0)
		m_pHead = m_pLast = p_Nuevo;
	else{
		m_pLast->m_psig = p_Nuevo;
		m_pLast = p_Nuevo;
	}
}

template <class T>
void Lista<T>::pushFront(T d)
{
	Nodo<T> *p_Nuevo = new Nodo<T>(d);
	if (m_pHead == 0)
		m_pHead = m_pLast = p_Nuevo;
	else{
		p_Nuevo->m_psig = m_pHead;
		m_pHead = p_Nuevo;
	}
}
template <class T>
bool Lista<T>::remove(T d)
{
	Nodo<T> *aux1 = m_pHead;
	if (aux1 == 0){
		return false;
	}
	if (aux1->m_dato == d && aux1->m_psig == 0){
		delete aux1;
		m_pHead = m_pLast = 0;
		return true;
	}
	Nodo<T> *ant = m_pHead;
	while (aux1 != 0)
	{
		if (aux1->m_dato == d){
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
bool Lista<T>::find(T d)
{
	Nodo<T> *aux = m_pHead;
	while (aux != 0)
	{
		if (aux->m_dato == d){
			return true;
		}
		aux = aux->m_psig;
	}
	return false;
}
template <class T>
bool Lista<T>::findR(T d, Nodo<T> *p)
{
	if (p == 0)return false;
	if (p->m_dato == d)return true;
	findR(d, p->m_psig);
}
template<class T>
string Lista<T>::print()
{
	string str = "";
	Nodo<T> *aux = m_pHead;
	while (aux != 0)
	{
		str = str + aux->m_dato;
		aux = aux->m_psig;
	}
	return str;
}