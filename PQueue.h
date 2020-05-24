#ifndef PQUEUE_CLASS
#define PQUEUE_CLASS

#include "Node.h"
using namespace std;

template <class T>
class PQueue
{
    private:
    	// a linked list to hold the queue items
        Node<T>* queueFront;//pointer to the head of the list
        int count=0;//number of elements in the the queues

    public:
    	// constructor
        PQueue(void);

        // queue access methods
        void PQInsert(const T& item);//inserts the item in the correct position.
        T PQDelete(void);//Deletes the highest priority element at the queue front

        // queue access returns the highest priority element that is in the queue in O(1) time
        T PQFront(void);

        // queue test methods
        int PQLength(void) const;
        int PQEmpty(void) const;// return 1 iff the queue is empty
        void PQClear(void);//dynamically allocated memory for the nodes must be returned
        void ShowPQ (void) const; // prints the content of the priority queue from front to rear on the standard output (with cout)

};

template <class T>
PQueue<T>::PQueue() {
    queueFront = NULL; // Initialize queueFront as NULL at the beginning
}

template <class T>
void PQueue<T>::PQInsert(const T& item) {
    Node<T> *p = new Node<T>(item);
    Node<T> *temp = queueFront; // Protect queueFront pointer
    Node<T> *prev; // This variable will be used to insert coming element at the specific position
    if(p==NULL) { // Heap size check
        cerr << "Memory allocation failed!" << endl;
        exit(1);
    }
    else {
        count++; // Increase count to hold length information
        if(queueFront == NULL) { // If queue is empty
            p->MyInsertFront(queueFront);
        }
        // If there is only one item in the queue, and the coming priority is higher
        else if(item.ShowPriority() < queueFront->data.ShowPriority()) {
            // Insert coming one to front and update queueFront in MyInsertFront method
            p->MyInsertFront(queueFront);
        }
        // Remaining scenarios including there is only one item with coming priority is lower
        else {
            while(true) {
                if(item.ShowPriority() > temp->data.ShowPriority() && temp->NextNode() != NULL) {
                    prev = temp; // Store previous pointer
                    temp = temp->NextNode(); // Temp is next of itself, go and check again
                }
                else {
                    // Lower priority is found, insert coming element to correct position
                    if(item.ShowPriority()<temp->data.ShowPriority()) {
                        prev->InsertAfter(p);
                    }
                    // Lower priority could not found, insert coming element to rear
                    else {
                        temp->InsertAfter(p);
                    }
                    break; // Stop, placement is done
                }
            }
        }
    }
}

template <class T>
T PQueue<T>::PQDelete(void) {
    Node<T>* p;
    if(PQLength() <= 0) { // Check queue length
        cerr << "Queue is empty, nothing to delete." << endl;
        exit(1);
    } else {
        T temp = queueFront->data; // Get the data of the element that will be deleted
        if(queueFront->NextNode()==NULL){ // If there is only one element in the queue
            delete queueFront; // Return memory
            queueFront = NULL;
        } else {
            p = queueFront; // Get the element that will be deleted
            queueFront = queueFront->NextNode(); // Update stackTop
            delete p; // Return memory
        }
        count--; // Decrease counter
        return temp;
    }
}

template <class T>
int PQueue<T>::PQLength(void) const {
    return count; // return length
}

template <class T>
int PQueue<T>::PQEmpty(void) const {
    if(count<=0) { // Empty condition
        return 1;
    }
    else {
        return 0;
    }
}

template <class T>
void PQueue<T>::ShowPQ(void) const {
    Node<T>* temp = queueFront; // Protect queueFront
    while(temp!=NULL){
        cout << temp->data.ShowData() << endl;
        temp = temp->NextNode(); // Update temp to show next pointer
    }
}

template <class T>
T PQueue<T>::PQFront(void){
    if(queueFront==NULL){
        cerr << "Queue is empty, nothing at the front." << endl;
        exit(1);
    }
    return queueFront->data; // Return front's data
}

template <class T>
void PQueue<T>::PQClear(void) {
    Node<T> *temp = queueFront;
    while(queueFront!=NULL){
        queueFront = queueFront->NextNode(); // update queueFront to be deleted
        delete temp; // return memory
    }
    count = 0; // Reset counter
}

#endif  // PQUEUE_CLASS
