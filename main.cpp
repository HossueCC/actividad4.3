// =================================================================
//
// File: main.cpp
// Author: Hossue Edgardo Ceja Cartagena
// Date: 19/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	
	
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	int size, number;

	//Ingresamos el tamaño a recibir en el archivo
	infile>>size;
	heap<int> heap(size);

	//Recorremos el vector
	for (int i = 0; i < size; i++){
		infile>>number;
		//Agregamos el numero
		heap.add(number);
	}

	int x = 0;
	int acumulador = 0;

	while(heap.getCount()>1)
	{
		x = heap.remove() + heap.remove();
		heap.add(x);
		acumulador += x-1;
	}

	outfile<<acumulador<<endl;

	return 0;
}
