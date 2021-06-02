
/*
 *  Implementation of the Event class which consists of the events that take place during the simulation.
 *  variables of this class :
 *  int time -> time of start of event
 *  char type -> Arrival 'A' or departure 'D' event
 *  int length -> length of processing the event
 */

#include <stdio.h>
#include "Event.h"
using namespace std;

//Sets the time
void Event::setTime(const int t) {
    time = t;
}

//sets the type.
//Precondition : input should be 'A' or 'D'
void Event::setType(const char m) {
    if( m == 'A' || m == 'D')
    type = m;
    else{
        cout<<"Incorrect input."<<endl;
    }

}

//set length
void Event::setLength(const int len) {
    length = len;
}

//returns type
int Event::getTime() const {
    return time;
}

//returns type
char Event::getType() const{
    return type;
}

//returns length
int Event::getLength() const {
    return length;
}

//Constructing the Event
Event::Event() {
   length = 0;
   time = 0;
   type = 0;
}

//overloading the << just to print the output of the object
ostream &operator << (ostream &os, const Event &e)  {
    os << e.getLength()<<" , " <<e.getTime() << " , "<<e.getType()<<endl;
    return os;
}



//overloading the comparison operators to compare events
bool operator<(Event a, Event b) {
    if(a.getTime() != b.getTime())
         return a.getTime() < b.getTime();
    else
        return a.getType()>b.getType();
}


bool operator>(Event b, Event a) {
    if(a.getTime() != b.getTime())
        return a.getTime() < b.getTime();
    else
        return a.getType()<b.getType();
    }





