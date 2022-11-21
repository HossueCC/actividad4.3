// 
//  Date: 22/10/2022
//  Autor: Hossue Edgardo Ceja Cartagena
//  Descripcion: Implementación de la clase Heap
//


#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T>
class Heap {
    private:

        T *dato;
        unsigned int capacidad;
        unsigned int count;

        unsigned int parent(unsigned int) const;
        unsigned int left(unsigned int) const;
        unsigned int right(unsigned int) const;

        void heapify(unsigned int);
        void swap(unsigned int, unsigned int);

    public:
        Heap(unsigned int);
        
        //OPERACIONES
        void push(T);
        void pop();
        T top() const;
        bool empty() const;
        int size() const;

        //METODO ADICIONAL
        string toString() const;
};


//Asignación de capacidad
template <class T>
Heap<T>::Heap(unsigned int sze) {
    capacidad = sze;
    dato = new T[capacidad];
    count = 0;
    
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;

}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);

}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);

}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && dato[le] < dato[min]) {
		min = le;
	}
	if (ri <= count && dato[ri] < dato[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

//Intercambio
template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	
    T aux = dato[i];
	dato[i] = dato[j];
	dato[j] = aux;
}

//Implementación de operación push
//Complejidad Temporal O(log n)
template <class T>
void Heap<T>::push(T val) {
	unsigned int pos = count;
	count++;
	while (pos > 0 && val < dato[parent(pos)]) {
		dato[pos] = dato[parent(pos)];
		pos = parent(pos);
	}
	dato[pos] = val;
}

//Implementación de operación pop
//Complejidad Temporal O(1)
template <class T>
void Heap<T>::pop() {
	T aux = dato[0];
	dato[0] = dato[--count];
	heapify(0);
}

//Implementación de operación top
//Complejidad Temporal O(1)
template <class T>
T Heap<T>::top() const {
    T aux = dato[0];
    return aux;
}

//Implementación de operación empty
//Complejidad Temporal O(1)
template <class T>
bool Heap<T>::empty() const {
	return (count == 0);
}

//Implementación de operación size
//Complejidad Temporal O(1)
template <class T>
int Heap<T>::size() const {
    return count;
}

//Insertamos espacios en la fila priorizada
template <class T>
string Heap<T>::toString() const {
	std::stringstream aux;

for (unsigned int i = 0; i < count; i++) {
		
        if (i != 0) {
			aux << " ";
		} aux << dato[i];
	
    } 
	
    return aux.str();
}

#endif