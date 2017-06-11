//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964


#ifndef DATABASE_H
#define DATABASE_H

#include "splitter.hpp"

#include <iostream>
#include <map>

using namespace std;

class Chain_Markets
{
public:
    Chain_Markets();
    bool read_data_from_string(const string& text);
    bool read_data_from_file(const string& filename);
    void print(); // Just for debugging

    void print_chains(); // prints all the chains in database
    void print_stores(string market); // prints all the stores of a certain chain
    void cheapest(const string& prod); // finds and prints the cheapest price of a certain product and places that offer the price
    void chain_location(const string& Chain,const string& Loc); // prints out all the products available at a certain store and their prices.

private:
   // nested maps were used so the data is maintained in alphabetical order all the time.
   map<string, map<string, map<string, double> > > data_;
};


#endif // DATABASE_H
