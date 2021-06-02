/*
 * Main function of the app.
 *
 * Made by - Gursmeep Singh Syan(301386570), Sehajvir Singh Pannu(301386534)
 */


#include <iostream>
#include <fstream>
#include "Event.h"
#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"
#include "Queue.h"


using namespace std;
int main() {

    cout<<"Simulation Begins"<<endl;
    Queue<Event> BankLine;              //Empty bank line
    PriorityQueue<Event> EventQueue;    //Empty Event Queue
    int pplCounter = 0;                 //counts the number of customers
    float avg = 0;

    bool tellerAvailable = true;        //Teller is available

    int arrival,pTime;
    Event arr,dep;
    //Read input and insert into the Event Queue
    while( !cin.eof()){
        cin>>arrival;
        cin>>pTime;
        arr.setTime(arrival);
        arr.setLength(pTime);
        arr.setType('A');
        EventQueue.enqueue(arr);    //in goes the arrival
    }

    Event newEvent;
    //Event loop
    while(!EventQueue.isEmpty()) {

        newEvent = EventQueue.peek();
        Event customer = newEvent;
        //getting current time
        int curentTime = newEvent.getTime();
        if (newEvent.getType() == 'A') {    //if type is arrival
            EventQueue.dequeue();
            if(BankLine.isEmpty() && tellerAvailable ){
                dep.setType('D');   //creating a departure event
                dep.setTime(curentTime+newEvent.getLength());
                dep.setLength(0);
                if(curentTime/10 < 1) {
                    cout << "Processing an arrival event at time:     " << curentTime << endl;
                }else if(curentTime/10 > 1 && curentTime/10 < 10){
                    cout << "Processing an arrival event at time:    " << curentTime << endl;
                }else if( curentTime/10 < 100){
                    cout << "Processing an arrival event at time:   " << curentTime << endl;
                }
                EventQueue.enqueue(dep);
                pplCounter++;   //Customer ++
                tellerAvailable = false;    //teller is no longer available
            } else{
                if(curentTime/10 < 1) {
                    cout << "Processing an arrival event at time:     " << curentTime << endl;
                }else if(curentTime/10 >= 1 && curentTime/10 < 10){
                    cout << "Processing an arrival event at time:    " << curentTime << endl;
                }else if(  curentTime/10 <= 100 ){
                    cout << "Processing an arrival event at time:   " << curentTime << endl;
                }
                pplCounter++;   //customers++
                BankLine.enqueue(customer);
            }
        } else {//Its a departure event now
            if(curentTime/10 < 1) {
                cout << "Processing a departure event at time:    " << curentTime << endl;
            }else if(curentTime/10 >= 1 && curentTime/10 < 10){
                cout << "Processing a departure event at time:   " << curentTime << endl;
            }else if( curentTime/10 < 100){
                cout << "Processing a departure event at time:  " << curentTime << endl;
            }

            EventQueue.dequeue();
            if( !BankLine.isEmpty()){
                //next customer
                customer = BankLine.peek();
                BankLine.dequeue();
                dep.setType('D');
                dep.setTime(curentTime+customer.getLength());
                EventQueue.enqueue(dep);
                avg = avg + curentTime - customer.getTime();
            }else {
                tellerAvailable = true;
            }
        }
    }
    cout<<"Simulation Ends"<<endl<<endl;
    cout<<"Final Statistics:"<<endl<<endl;
    cout<<"    Total number of people processed: "<<pplCounter<<endl;
    cout<<"    Average amount of time spent waiting: "<<avg/pplCounter<<endl;

    return 0;
}
