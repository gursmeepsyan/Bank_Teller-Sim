
/*
 * Declaration of the Events in the app, that is arrival and departure of customers
 * Made by : Maheeppartap Singh and Conor Murphy
 */

#ifndef ASSIGNMENT_3_EVENT_H
#define ASSIGNMENT_3_EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{
private:
    int time;
    char type;
    int length;

public:
    //Default constructor
    Event();
    //Destructor

    // Setters
    void setTime(int time);
    void setType( char type);
    void setLength(int length);


    //Getters
    int getTime()const;
    char getType()const;
    int getLength()const;
    //Some overloading operators
    friend ostream&operator<<(ostream & os,const Event & e);

    friend bool operator <(Event a,Event b);

    friend bool operator >(Event b,Event a);
};
#endif //ASSIGNMENT_3_EVENT_H
