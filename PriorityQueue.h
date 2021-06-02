/*
 * PriorityQueue.h
 *
 * Description: Binary Heap data collection ADT class.
 *
 * Class Invariant: ... in FIFO order
 *
 * Author: Sehajvir Singh Pannu (301386534), Gursmeep Singh Syan (301386570)
 * Date: 31st October, 2019
 */





 #include"EmptyDataCollectionException.h"
 #include"BinaryHeap.h"
 #include<iostream>
 #pragma once
 using namespace std;

 template <class ElementType>
 class PriorityQueue
 {
   private:
     BinaryHeap<ElementType> PQ;
     int elementCount;

   public:
    // Default Constructor
   PriorityQueue();

   PriorityQueue(BinaryHeap<ElementType>& someHeap);


   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Postcondition:  The Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in the Priority Queue.
   //              It returns "true" if successful, otherwise "false".
   // Time Efficiency: O(log2 n)
   bool enqueue(ElementType& newElement);

   // Description: Removes (but does not return) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   void dequeue() throw(EmptyDataCollectionException);

   // Description: Returns (but does not remove) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType& peek() throw(EmptyDataCollectionException);

   void print() throw(EmptyDataCollectionException);
};

/*template< class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
    this->elementCount=0;
}

// Non Default Constructor
template< class ElementType>
PriorityQueue<ElementType> :: PriorityQueue(BinaryHeap<ElementType>& someHeap)
{
this->PQ.elements= someHeap.elements;
this->PQ.elementCount= someHeap.elementCount;
this->elementCount= someHeap.elementCount;

}*/

// Check whether the PriorityQueue is empty
template< class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
 {
   return (this->elementCount==0);
 }

// Inset or Enqueue an elementin the PriorityQueue
 template< class ElementType>
 bool PriorityQueue<ElementType>::enqueue(ElementType& newElement)
 {
   return this->PQ.insert(newElement);
 }

// Remove the element with the max priority
 template< class ElementType>
 void PriorityQueue<ElementType> :: dequeue() throw(EmptyDataCollectionException)
 {

   try{if(isEmpty())
       throw EmptyDataCollectionException("Queue is empty\n");
   }
   catch(EmptyDataCollectionException& e){
       cout<<e.what();
   }

   this->PQ.remove();
 }

// Peek to see the element with max priority
 template< class ElementType>
 ElementType& PriorityQueue<ElementType> :: peek() throw(EmptyDataCollectionException)
{
  try{if(isEmpty())
      throw EmptyDataCollectionException("Queue is empty\n");
  }
  catch(EmptyDataCollectionException& e){
      cout<<e.what();
  }

  return this->PQ.retrieve();
}
template<class ElementType>
void PriorityQueue<ElementType>::print() throw(EmptyDataCollectionException)
   {
    if(isEmpty())
    {
    throw EmptyDataCollectionException("Heap is empty");
}
else
PQ.printBinaryHeap();
}
