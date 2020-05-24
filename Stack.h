#ifndef STACK_CLASS
#define STACK_CLASS

#include "Node.h"
using namespace std;

template <class T>
class Stack
{
    private:
        // a linked list to hold the stack items
        Node<T>* stackTop; // deepmost element of the stack unless the stack is empty

    public:
    	// constructor
        Stack(void);

        // stack access methods
        void Push(const T& item);
        T Pop(void);
        T Peek(void);

        // stack test and clear methods
        int StackEmpty(void) const; // return 1 iff the stack is empty
        void ClearStack(void); //dynamically allocated memory for the nodes must be returned
        void ShowStack(void) const; // prints the content of the stack from top to bottom on the standard output (with cout)
};

template <class T>
Stack<T>::Stack() {
    stackTop = NULL; // Initialize stackTop as NULL at the beginning
}

template <class T>
void Stack<T>::Push(const T& item) {
    Node<T> *p = new Node<T>(item);
    if(p==NULL) { // Heap size check
        cerr << "Memory allocation failed!" << endl;
        exit(1);
    }
    if(stackTop == NULL) { // If there is no element in the stack
        stackTop = p;
    } else {
        p->MyInsertFront(stackTop); // Else, insert the new element to front
    }
}

template <class T>
T Stack<T>::Pop(void) {
    Node<T>* p;
    if(stackTop==NULL) { // NULL check
        cerr << "Stack is already empty." << endl;
        exit(1);
    } else {
        T data = stackTop->data;
        if(stackTop->NextNode()==NULL) { // If there is only one element in the stack
            delete stackTop; // return memory
            stackTop = NULL;
        } else {
            p = stackTop; // Get the element that will be deleted
            stackTop = stackTop->NextNode(); // Update stackTop
            delete p; // return memory
        }
        return data;
    }
}

template <class T>
T Stack<T>::Peek(void) {
    if(stackTop!=NULL) {
        return stackTop->data; // If stack is not empty
    } else {
        cerr << "Stack is empty, nothing to show." << endl;
        exit(1);
    }
}

template <class T>
void Stack<T>::ClearStack(void) {
    while(stackTop!=NULL) {
        stackTop->DeleteFront(stackTop); // dynamic memory return is handled inside DeleteFront method
    }
}

template <class T>
int Stack<T>::StackEmpty(void) const {
    if(stackTop==NULL) { // empty check
        return 1;
    } else {
        return 0;
    }
}

template <class T>
void Stack<T>::ShowStack(void) const {
    // The NULL check is already done in PrintLinkedList method.
    // That's why I did not check it again over here.
    stackTop->PrintLinkedList(stackTop);
}


#endif  // STACK_CLASS
