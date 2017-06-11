//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964

#include "splitter.hpp"
#include "database.hpp"
#include "UI.hpp"

#include <iostream>
#include <sstream>

using namespace std;

int main()
{

    Chain_Markets doc; // creating an object of class "Chain_Markets"

    if (not doc.read_data_from_file("products.txt")){
        // transfering the data inside the input file to the data base (doc)
        // if for any reason(file opening issues or incorrect data format in the file),
        // "read_data_from_file" method returns "false", proper error message is printed out and
        // program is terminated.

        cout<<"Error: the input file can not be read."<<endl;
        return 0;
    }


    while (true) // the loop contnues to keep readig the commands from command line
    {
        cout<<"product search> ";

        string input("");
        getline(cin, input);


        Splitter input_command(input); // defining an splitter object an assigning the input to it
        input_command.split(' ',true); // splitting the input using white space as separator in order to separate input parameters

        run_command(input_command,doc);


    }

    return 0;

}

