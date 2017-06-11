//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964


#ifndef SPLITTER_H
#define SPLITTER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;

const unsigned int SPLIT_ERROR = 0;

class Splitter { // the code for this class was part of the weekly assignments.

        public:

          Splitter(const string& string_to_split = "");

          void set_string_to_split(const string& string_to_split);

          unsigned int split(char separator=' ', bool ignore_empty = false);

          unsigned int number_of_fields() const;

          string fetch_field(unsigned int field_index) const;


        private:

            vector<string> word_vector_;
            string text_;

};

#endif // SPLITTER_H
