#ifndef ELEMENT_CLASS
#define ELEMENT_CLASS

using namespace std;

template <class T>
class Element
{
    private:
    	// a linked list object to hold the stack items
    	T Data;
        int Priority;//non-negative value, similar to the processes in HW1 a smaller value shows a higher priority
	public:
    	// constructor
		Element(const T data, const int priority);//returns with error if priority is initialized a negative integer
        T ShowData(void){
            return Data;
        }
        int ShowPriority (void) const {
            return Priority;
        }
        //overload the comparison operator < such that < returns true for
        //element1<element2 if element2.Priority<= element1.Priority
        bool operator< (const Element<T>& rhs) const;

};

template <class T>
Element<T>::Element(const T data, const int priority) {
    if(priority < 0) { // Priority sign check
        cerr << "Priority cannot be negative." << endl;
        return;
    }
    this->Data = data; // set data
    this->Priority = priority; // set priority
}

// Operator overloading method
template <class T>
bool Element<T>::operator< (const Element<T> &rhs) const {
    if(rhs.ShowPriority()<=this->ShowPriority()){ // If rhs' priority is higher or equal to lhs' priority
        return true;
    } else {
        return false;
    }

}


#endif // ELEMENT_CLASS
