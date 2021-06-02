/*
 * Queue.h
 *
 * Description: Queue data collection ADT class.
 *              Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Sehajvir Singh Pannu (301386534), Gursmeep Singh Syan (301386570)
 * Date: 31st October, 2019
 */

#include"EmptyDataCollectionException.h"
#include<iostream>
using namespace std;

 template <class ElementType>
 class Queue{

 private:
         static unsigned const INITIAL_SIZE = 6;
         ElementType* elements;          // replace this by int * elements in Question 4(a)

         unsigned elementCount;  // number of elements in the queue
         unsigned capacity;      // number of cells in the array
         unsigned frontindex;    // index the topmost element
         unsigned backindex;

 public:

        // Desc:  Constructor
        Queue();

        // Desc: Parameterized Constructor, creates a Queue with user defined capacity.
        Queue(int Capacity);

        // Desc:  Destructor
        ~Queue();

        // Description: Returns "true" is this Queue is empty, otherwise "false".
        // Postcondition:  The Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement at the "back" of this Queue
        //              (not necessarily the "back" of its data structure) and
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newElement);

        // Description: Removes (but does not return) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        void dequeue() throw(EmptyDataCollectionException);

        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() throw(EmptyDataCollectionException);

        //Description: Prints the Queue
        void printQueue();
 };



 // Desc:  Constructor
 template<class ElementType>
 Queue <ElementType> :: Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0)
 {
    this-> elements = new ElementType[capacity];
 }

 // Description : Parameterized constructor, creates a Queue with user defined capacity.
 template<class ElementType>
 Queue<ElementType> :: Queue(int Capacity) : elementCount(0), frontindex(0), backindex(0)
 {
    this -> capacity = Capacity;
    elements = new ElementType[capacity];
 }

 //Description : Destructor
 template<class ElementType>
 Queue<ElementType> :: ~Queue()
 {
    delete this -> elements;
 }

 // Description: Returns "true" is this Queue is empty, otherwise "false".
 // Postcondition:  The Queue is unchanged by this operation.
 // Time Efficiency: O(1)
 template<class ElementType>
 bool Queue<ElementType> :: isEmpty() const
 {
    return (elementCount == 0);
 }

 // Description: Inserts newElement at the "back" of this Queue
 //              (not necessarily the "back" of its data structure) and
 //              returns "true" if successful, otherwise "false".
 // Time Efficiency: O(1)
 template<class ElementType>
 bool Queue<ElementType> :: enqueue(ElementType& newElement)
 {
      int previousCount = elementCount;
      if(elementCount == capacity)    //Checks if the queue is full or not.
        {
            int newSize = capacity*2;
            ElementType *newArr = new ElementType[newSize];
            int i,j = 0;
            for(i = frontindex; i < capacity ; i++)
            {
                newArr[j] = elements[i];
                j++;
            }
            newArr[j] = newElement;
            delete []elements;        //delete the old array
            elements = newArr;
            backindex = capacity;
            capacity = newSize;
            frontindex = 0;
        }

        elementCount++;
        elements[backindex] = newElement;
        backindex = (backindex+1) % capacity;

        return elementCount > previousCount;
 }


 // Description: Removes (but does not return) the element at the "front" of this Queue
 //              (not necessarily the "front" of its data structure).
 // Precondition: This Queue is not empty.
 // Exception: Throws EmptyDataCollectionException if this Queue is empty.
 // Time Efficiency: O(1)
 template<class ElementType>
 void Queue<ElementType> :: dequeue() throw(EmptyDataCollectionException)
 {

        try{if(isEmpty())
             throw EmptyDataCollectionException("Queue is empty\n");
         }
         catch(EmptyDataCollectionException& e){
             cout<<e.what();
         }

    if( elementCount < capacity/4 && elementCount/4 > INITIAL_SIZE)             //Checks if the Queue is 1/4 of the capacity
        {
            ElementType* new_arr = new ElementType[capacity/4];                  //Making a new array with 1/4th of the capacity to save space
            int j = 0;
            for(int i = frontindex ; j < capacity ; i = ( i + 1)%capacity)
            {
                new_arr[j] = elements[i];
                j++;
            }
            delete elements;
            elements = new_arr;
            frontindex = (frontindex + 1) % capacity;
          }

 }

 // Description: Returns (but does not remove) the element at the "front" of this Queue
 //              (not necessarily the "front" of its data structure).
 // Precondition: This Queue is not empty.
 // Exception: Throws EmptyDataCollectionException if this Queue is empty.
 // Time Efficiency: O(1)
 template<class ElementType>
 ElementType& Queue<ElementType> ::peek() throw(EmptyDataCollectionException)
 {
   try{if(isEmpty())
        throw EmptyDataCollectionException("Queue is empty\n");
    }
    catch(EmptyDataCollectionException& e){
        cout<<e.what();
    }

    return elements[frontindex];
 }

 // Description: Prints the Queue
 template<class ElementType>
 void Queue<ElementType> :: printQueue()
 {
   cout << "{";
   for (int i = 0; i < elementCount; i++)
   {
       cout << elements[(i+frontindex) % capacity];
       if (i + 1 < elementCount)
       {
           cout << ',';
       }
   }
   cout << "}" << endl;
 }
