#ifndef NODE_CLASS
#define NODE_CLASS

using namespace std;

template <class T>
class Node
{
private:
    // next is the address of the following node
    Node<T> *next;

public:
    // the data is public
    T data;

    // constructor
    Node (const T& item, Node<T>* ptrnext = NULL);

    // list modification methods
    Node<T> *DeleteAfter(void);
    void InsertAfter(Node<T> *p);
    void DeleteFront(Node<T>* &head);
    void PrintLinkedList(Node<T>* head) const;
    void MyInsertFront(Node<T>*&head);

    // obtain the address of the next node
    Node<T> *NextNode(void) const;

};

// constructor. initialize data and pointer members
template <class T>
Node<T>::Node(const T& item, Node<T>* ptrnext) : next(ptrnext), data(item)
{}

// return value of private member next
template <class T>
Node<T> *Node<T>::NextNode(void) const
{
    return next;
}

// insert a node p after the current one
template <class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    // p points to successor of the current node,
    // and current node  points to p.
    p->next = next;
    next = p;
}

// delete the node following current and return its address
template <class T>
Node<T> *Node<T>::DeleteAfter(void)
{
    // save address of node to be deleted
    Node<T> *tempPtr = next;

    // if there isn't a successor, return NULL
    if (next == NULL)
        return NULL;

    // current node points to successor of tempPtr.
    next = tempPtr->next;

    // return the pointer to the unlinked node
    return tempPtr;
}


template <class T>
void Node<T>::DeleteFront(Node<T>* &head) {
    Node<T>* currentHead = head;
    if(currentHead != NULL) {
        head = currentHead->NextNode(); // New head is the next node of current head
        delete currentHead; // Return memory
    }
}

template <class T>
void Node<T>::PrintLinkedList(Node<T>* head) const {
    Node<T>* currentNode = head;
    if(currentNode == NULL) { // NULL check
        cerr << "List is empty." << endl;
    } else {
        while(currentNode!=NULL) { // Print currentNode data until the end
            cout << currentNode->data << endl;
            currentNode=currentNode->NextNode(); // Update currentNode
        }
    }
}

// Update front element as coming element's next is head, and the new head is current element
template <class T>
void Node<T>::MyInsertFront(Node<T>*&head) {
    this->next = head;
    head = this;
}

#endif  // NODE_CLASS
