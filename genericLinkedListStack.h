#include <iostream> 
#include "genericLinkedList.h"

using namespace std;

template <typename T>
class genericLinkedListStack {
public:
	genericLinkedListStack();
	int size() const;
	bool empty() const; 
	const T& top() const;
	void push(const T& elem);
	void pop();
	void print() const;


private:
	genericLinkedList<T> S; //linked list of elements called S
	int n; //total number of elements

};


template <typename T>
genericLinkedListStack<T>::genericLinkedListStack() {
	n = 0; 
}

template <typename T>
int genericLinkedListStack<T>::size() const{
	return n; 
}

template <typename T>
bool genericLinkedListStack<T>::empty() const{
	return S.empty();
}

template<typename T>
const T& genericLinkedListStack<T>::top() const{
	if(!S.empty()) {
		return S.front();
	}
}

template <typename T>
void genericLinkedListStack<T>::push(const T& elem) {
	S.addFront(elem);
	n++;
}

template <typename T>
void genericLinkedListStack<T>::pop(){
	if(!S.empty()) {
		S.removeFront();
		n--;
	}
}

template <typename T>
void genericLinkedListStack<T>::print() const{
	S.print();
}