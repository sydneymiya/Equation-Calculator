#include <iostream>
#include <stddef.h>

using namespace std;

template<typename E>
struct genericNode { 
	E elem; 
	genericNode<E> *next;
};

template<typename E>
class genericLinkedList { 
public: 
	genericLinkedList(); //constructor
	~genericLinkedList(); //destructor
	genericLinkedList(const genericLinkedList& other); //copy constructor
	bool empty() const; //is empty?
	const E& front() const; //returns header
	void addFront(const E& e); //adds to head
	void addBack(const E& e); //adds to tail
	void removeFront(); //removes head
	void print(); 
	int count(); //total nodes

private: 
	genericNode<E> *head; 
	genericNode<E> *tail;
};

//////////////////////////
// template definitions //
//////////////////////////


template<typename E>
genericLinkedList<E>::genericLinkedList(): head(NULL), tail(NULL) {}

//copy constructor
template<typename E> 
genericLinkedList<E>::genericLinkedList(const genericLinkedList& other) {
	head = NULL;
	genericNode<E> *cursor1 = head;
	genericNode<E> *cursor2 = other.head;
	while(cursor2 != NULL) {
		if(head == NULL) {
			head = new genericNode<E>;
			head->elem = cursor2->elem; 
			head->next = NULL;
			cursor1= head;
		} else {
			cursor1->next = new genericNode<E>;
			cursor1->next->elem = cursor2->elem;
			cursor1->next->next = NULL;
			cursor1 = cursor1->next;
		}
		cursor2 = cursor2->next;
	}
}

template<typename E>
bool genericLinkedList<E>::empty() const{ return head == NULL; } 

template<typename E>
const E& genericLinkedList<E>::front() const {
	return head->elem; 
}

template<typename E>
genericLinkedList<E>::~genericLinkedList() {
	while (!empty()) removeFront(); 
}

template<typename E>
void genericLinkedList<E>::addFront(const E& e) {
	genericNode<E> *v = new genericNode<E>;
	v->elem = e;
	v->next = head;
	head = v;
	if (head->next==NULL) {
		tail = head;
	}
}

template<typename E>
void genericLinkedList<E>::addBack(const E& e) {
	genericNode<E> *v = new genericNode<E>;
	v->elem = e;
	v->next = NULL;
	tail->next = v;
	tail = v;
}

template<typename E>
void genericLinkedList<E>::removeFront() {
	genericNode<E> *old = head;
	head = old->next;
	delete old;
}

template<typename E>
void genericLinkedList<E>::print() {
	genericNode<E> *v = head;
	while (v != NULL){
		cout << v->elem << " ";
		v = v->next;
	}
	cout << endl;
}

template<typename E>
int genericLinkedList<E>::count() {
	genericNode<E> *v = head;
	int n = 0;
	while (v != NULL){
		n++;
		v = v->next;
	}
	return n;
}
