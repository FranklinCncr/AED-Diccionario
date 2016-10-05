// AVL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "AVL.h"

int main()
{

	AVL<int> mytree;
	//mytree.insertar(7);
	mytree.insertar(9);
	mytree.insertar(5);
    mytree.insertar(11);
    mytree.insertar(3);
    mytree.insertar(6);
 	mytree.insertar(8);
	
	mytree.imprimir(mytree.get_root());
	printf("\n");
	mytree.eliminar1(mytree.get_root());
	printf("SE TERMINO DE ELIMINAR \n");
	mytree.imprimir(mytree.get_root());

	


	//mytree.padre(1, mytree.get_root());

	//printf("\n");
	//printf("%d", mytree.findL(7));


	printf("\n");
	system("pause");
}

