/*
 * BinaryHeap.h
 *
 * Description: Binary Heap data collection ADT class.
 *
 * Class Invariant: ... in FIFO order
 *
 * Author: Sehajvir Singh Pannu (301386534), Gursmeep Singh Syan (301386570)
 * Date: 31st October, 2019
 */
#pragma once

 #include"EmptyDataCollectionException.h"
 #include<cmath>
 #include<iostream>
 using namespace std;

 template<class ElementType>
 class BinaryHeap
 {
 private:

        static const int rootIndex = 0;
        static const int Default_Capacity = 15;
        int capacity;
        ElementType* elements;
        int elementCount;

 public:

       //Description: Constructor
       BinaryHeap(int size);

       //Description: Parameterized Constructor.
       BinaryHeap(const ElementType someArray[], const int arraySize);

       // Description: Returns "true" is this Binary Heap is empty, otherwise "false".
       // Postcondition:  The Binary Heap is unchanged by this operation.
       // Time Efficiency: O(1)
       bool isEmpty() const;

       // Description: Inserts newElement in this Binary Heap and
       //              returns "true" if successful, otherwise "false".
       // Time Efficiency: O(log2 n)
       bool insert(ElementType& newElement);

       // Description: Removes (but does not return) the element located at the root.
       // Precondition: This Binary Heap is not empty.
       // Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
       // Time Efficiency: O(log2 n)
       void remove() throw(EmptyDataCollectionException);

       // Description: Returns (but does not remove) the element located at the root.
       // Precondition: This Binary Heap is not empty.
       // Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
       // Time Efficiency: O(1)
       ElementType& retrieve() throw(EmptyDataCollectionException);

       // Description: Reheaps the Binary Heap according to Max Binary order
       // Precondition: This Binary Heap is not empty
       void reHeap(int n ,int rootIndex);

       // Description: Prints the Binary Heap
       void printBinaryHeap() const;
 };

// Description: Constructor
 template<class ElementType>
 BinaryHeap<ElementType> :: BinaryHeap(int size) : capacity(size), elementCount(0)
 {
   this -> elements = new ElementType[capacity];
 }

 //Description: Parameterized Constructor
 template<class ElementType>
 BinaryHeap<ElementType> :: BinaryHeap(const ElementType someArray[],const int arraySize) : elementCount(arraySize)
 {
    elements = new ElementType[2*arraySize];

    for(int i = 0 ; i < elementCount;i++)
    {
      elements[i] = someArray[i];
    }

    this-> reHeap(this->elementCount,0);

 }

 // Description: Returns "true" is this Binary Heap is empty, otherwise "false".
 // Postcondition:  The Binary Heap is unchanged by this operation.
 // Time Efficiency: O(1)
 template<class ElementType>
 bool BinaryHeap<ElementType> :: isEmpty() const
 {
    return (elementCount==0);
 }

 // Description: Inserts newElement in this Binary Heap and
 //              returns "true" if successful, otherwise "false".
 // Time Efficiency: O(log2 n)
 template<class ElementType>
 bool BinaryHeap<ElementType> :: insert(ElementType& newElement)
 {
    /*if(elementCount == capacity)
      {
          this -> capacity = 2*capacity;
          int indexOfBottom = elementCount;
          ElementType* temp = new ElementType[capacity];
          int i = 0;
          for(; i < elementCount;i++)
          {
             temp[i] = element[i];
          }
          temp[i++] = newElement;
      }*/
      bool ans = false;
      if(elementCount == capacity)
      {
        ElementType tempArray[this->capacity*2];
        for(int i=0;i < this->elementCount;i++)
        {
          tempArray[i]= this->elements[i];
        }
        tempArray[elementCount]= newElement;
        delete [] elements;
        this->elements=tempArray;
        this->capacity=this->capacity*2;
        this->elementCount++;
        ans = true;
      }

      else
      {
        this->elements[elementCount]= newElement;
        this->elementCount++;
        ans = true;
      }
      this->reHeap(this->elementCount,0);
      return ans;

 }

 // Description: Removes (but does not return) the element located at the root.
 // Precondition: This Binary Heap is not empty.
 // Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
 // Time Efficiency: O(log2 n)
 template<class ElementType>
 void BinaryHeap<ElementType> ::remove() throw(EmptyDataCollectionException)
 {
   try{if(isEmpty())
       throw EmptyDataCollectionException("Queue is empty\n");
   }
   catch(EmptyDataCollectionException& e){
       cout<<e.what();
   }

       // Re-write the last element in the place of root
       elements[0] = elements[elementCount-1];

       // Decrease size of heap by 1
       this->elementCount--;
       this ->reHeap(this->elementCount, 0);

 }

 // Description: Returns (but does not remove) the element located at the root.
 // Precondition: This Binary Heap is not empty.
 // Exception: Throws EmptyDataCollectionException if Binary Heap is empty.
 // Time Efficiency: O(1)
 template <class ElementType>
 ElementType& BinaryHeap<ElementType> :: retrieve() throw(EmptyDataCollectionException)
 {
   try{if(isEmpty())
       throw EmptyDataCollectionException("Queue is empty\n");
   }
   catch(EmptyDataCollectionException& e){
       cout<<e.what();
   }

   return (elements[0]);

 }

 template<class ElementType>
 void BinaryHeap<ElementType> :: printBinaryHeap() const
 {
   cout << "{";
   for(int i = 0 ; i < elementCount ; i++)
   {
     cout << elements[i];
     if(i + 1<elementCount){
       cout << ",";
     }
   }
   cout << "}" << endl;
 }

 // Description: Reheaps the Binary Heap according to Max Binary order
 // Precondition: This Binary Heap is not empty
 template<class ElementType>
 void BinaryHeap<ElementType> ::reHeap(int elementCount , int rootIndex)
 {
     int n = this->elementCount-1;
     int largest = rootIndex; // Initialize largest as root
     int lc = 2 * rootIndex + 1; // left child = 2*i + 1
     int rc = 2 * rootIndex + 2; // right child = 2*i + 2

     // If left child is larger than root
     if (lc < n && this->elements[lc] > this->elements[largest])
         largest = lc;

     // If right child is larger than largest
     if (rc < n && this->elements[rc] > this->elements[largest])
         largest = rc;

     // If largest is not root
     if (largest != rootIndex)
     {
         int temp = this->elements[rootIndex];
          this->elements[rootIndex]=this->elements[largest];
          this->elements[largest]= temp;

         // Recursively reHeap the affected sub-tree
         this->reHeap(elementCount, largest);
     }
 }
