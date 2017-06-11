//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964


#ifndef UI_H
#define UI_H

#include "database.hpp"
#include "splitter.hpp"

#include <iostream>
#include <map>


using namespace std;

void run_command(const Splitter& input, Chain_Markets& data); // this functions calls proper method based on user input command

// For the sake of UI integrity all the functions that can be called by run_command have the same type of inputs.

void quit_cmd(const Splitter& params, Chain_Markets& data);  // quits the program (does not use the input parameters)
void chains_cmd(const Splitter& params, Chain_Markets &data); // Calls "print_chains" for "Chain_Markets" object
void stores_cmd(const Splitter& params, Chain_Markets& data); // Calls "print_stores" for "Chain_Markets" object
void cheapest_cmd(const Splitter& params, Chain_Markets& data); // Calls "cheapest" for "Chain_Markets" object
void selection_cmd(const Splitter& params, Chain_Markets& data);// Calls "chain_location" for "Chain_Markets" object

bool parameter_qty_check(const Splitter &params, unsigned int correct_qty);// checks if the number of parameters conform with the required value

using input_command = decltype(&quit_cmd); // defining a pointer to a sample function as a  type to be used in map of commands

const map<string, input_command> commands = { // a map of commands and the pointers to corresponding functions
    { "quit",  quit_cmd },
    { "chains",  chains_cmd },
    { "stores",  stores_cmd },
    { "cheapest",  cheapest_cmd },
    { "selection",  selection_cmd },

};




#endif // UI_H
