//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964


#include "splitter.hpp"
#include "UI.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>


using namespace std;

// the code for this class was part of the weekly assignments.

Splitter::Splitter(const string& string_to_split){

    text_=string_to_split;

}

void Splitter::set_string_to_split(const string& string_to_split){

    text_=string_to_split;

}

unsigned int Splitter::split(char separator, bool ignore_empty){

    // Returns the size of the resulting word_vector.
    // separator: character to split the string by
    // ignore_empty: determines whether the empty fields are skipped or maintained
    // it appends substring elements into a vector named word_vector_.

    string::size_type start_position= 0;
    string::size_type pos= text_.find(separator, start_position);
    string temp="";
    while(pos!=string::npos){

        temp=text_.substr(start_position,pos-start_position);//a,"",bc
       if ((temp=="" && ignore_empty==false)||temp!=""){
            word_vector_.push_back(temp);
        }
        start_position=pos+1;
        pos= text_.find(separator, start_position);


    }
    word_vector_.push_back(text_.substr(start_position));

    return word_vector_.size(); // returns the number of fields after the split was done

}

unsigned int Splitter::number_of_fields() const{ // returns the number of fields if the split has been done

    return word_vector_.size();

}

string Splitter::fetch_field(unsigned int field_index) const{
    //This function is used to fetch the elements of word_vector_ at specified
    // position which is determined by field_index as a parameter.

    if (field_index>word_vector_.size()||word_vector_.size()==0){

       return "too large index or split not called";

    }else{

       return word_vector_.at(field_index);

    }

}


