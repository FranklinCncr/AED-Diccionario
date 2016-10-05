template <class T>
class Nodo
{
public:
	T m_Dato;
	Nodo<T> *m_pDer;
	Nodo<T> *m_pIzq;
public:
	Nodo(T d){
		m_Dato = d;
		m_pDer = m_pIzq = 0;
	}
};

template <class T>
class tree{
private:
	Nodo<T> *m_pRoot;
public:
	tree(){ m_pRoot = 0 };
	bool Find(T d);
	bool Add(T d);
};
template <class T>
bool Add(T d)
{
	if (!m_pRoot){ m_pRoot = new Nodo<T>(d) };
	else{
		Nodo<T> *p, *q;
		p = q = m_pRoot;
		while (q != 0){
			p = q;
			if (q->m_Dato == d)return false;
			if (q->m_Dato < d)q = q->m_Der;
			else q = q->m_Izq;
		}

	}
}