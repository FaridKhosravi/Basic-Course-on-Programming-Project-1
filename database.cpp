//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964


#include "database.hpp"
#include <iostream>
#include <iomanip>
#include <typeinfo>

bool isnumber(string s); // The function checks if a string is a positive real number

Chain_Markets::Chain_Markets () // constructor, initializes the chain_markets class with an empty array/vector.
{
    data_={};
}

bool Chain_Markets::read_data_from_string(const string& text)
{
    // reads the data from an string and if the data does not conform
    // to the required format reading stops and "false: is returrned,
    // otherwise after the reading is finished it returnes "true.

    Splitter splitter_object(text);  // assigning the input string to an "Splitter" object.
    splitter_object.split(';',false); // splitting the input taking ';' as seperator character and maintaining the empty fields

    if(splitter_object.number_of_fields()!=4){
        //if the number of of fields is not equal to 4 it means eaither not enough fields are provided
        // or there are too many of them or there is a field with a ';' inside.
        // in all three circumstances the formatting is wrong and "false" is returned.

        return false;

    }


    for (int i=0;i<4;i++){
        // looks for white space characters in all 4 fields and if it
        //finds one reading is terminated and "false" is returned.
        string temp=splitter_object.fetch_field(i);

        if (temp.find(' ')!=string::npos ||temp==""){

            return false;
        }

    }

    string temp_1=splitter_object.fetch_field(0);
    string temp_2=splitter_object.fetch_field(1);
    string temp_3=splitter_object.fetch_field(2);

    if(not isnumber(splitter_object.fetch_field(3))){
        // examines the 4th field to see if its a real number
        // otherwise reading is terminated and "false" is returned.
        return false;
    }

    double temp_4=stod(splitter_object.fetch_field(3));


    if (data_.find(temp_1)==data_.end()){
        data_.insert( { temp_1, {} } );
    }

    if (data_.at(temp_1).find(temp_2)==data_.at(temp_1).end()){
        data_.at(temp_1).insert( {temp_2 ,{} } );
    }

    if (data_.at(temp_1).at(temp_2).find(temp_3)==data_.at(temp_1).at(temp_2).end()){
        data_.at(temp_1).at(temp_2).insert( { temp_3 , temp_4 } ) ;
    }else{
        data_.at(temp_1).at(temp_2).at(temp_3)=temp_4;
    }

    return true;
}

bool Chain_Markets::read_data_from_file(const string& filename) {
    ifstream file(filename);

    if ( not file ) {
        // reurns "false" if for some reason reading the file fails.
        return false;
    }

    string line;
    while ( getline(file, line) ) {
        // The lines read from a file are formed from fields separated
        // by ';' we can utilize the read_data_from_string method
        // above to add the data in a line into the chainmarket object.

        if (not read_data_from_string(line)){
            // ckeck if the data in the line does not conform with the
            // correct format and returns "false" if it does not.
            return false;
        }
    }

    file.close();

    return true; // returns true if all the file reading requirments are passed.
}

void Chain_Markets::print() //just for debugging purposes, dont mind it ;) (prints every thing in order)
{

    for(auto Chain:data_)
    {
        cout<<Chain.first<<endl;
        for(auto Branch:Chain.second )
        {
            cout<<"   "<<Branch.first<<endl;
            for(auto Product:Branch.second)
            {
                cout<<"   "<<"   "<<Product.first<<" : "<<Product.second<<endl;
            }
        }
    }
}

void Chain_Markets::print_chains(){

    for (auto temp:data_)
    {
        cout<<temp.first<<endl;
    }
}

void Chain_Markets::print_stores(string market){
    // prints all the branches/stores of a certain Chain/Brand
    // if does not find the Chain name informs the user with proper Error message

    if (data_.count(market)>0)
    {
       auto temp = data_.find(market);
       for(auto Chain:temp->second)
       {
           cout<<Chain.first<<endl;
       }
    }
    else
    {
        cout << "Error: The name of market does not exist in the database"<<endl;
    }
}

void Chain_Markets::cheapest(const string& prod){
    // Prints out the cheapest price of a certain product and
    // the stores where that product is available with that price.

    double min= -100; // the min variable is also used as flag to determin whether the product was found

    for(auto Chain:data_) // scans through all the data to find out if the product exists in the database
    {
        // scans through all the data to find out if the product exists in the database
        // we need this loop since we dont know the scale of prices and we cannot assume a
        // big enough value to initialize the min.
        for(auto Branch:Chain.second )
        {
            for(auto product:Branch.second){
                if(product.first==prod)
                {
                    min=product.second; // assigning the price first of first found product to min
                    break;
                }
            }
        }
    }

    if (min<0){ // checks if the product was found

        cout<<"This product is not available anywhere."<<endl;
        return;
    }

    for(auto Chain:data_) // Scans through all the data and finds the minimum price of given product
    {
        for(auto Branch:Chain.second )
        {
            for(auto product:Branch.second){
                if(product.second<min && product.first==prod){
                    min=product.second;
                }
            }
        }
    }

    cout<<setprecision(2)<<fixed<<min<<endl; // printing the minimum, available price.

    for(auto Chain:data_) // Scans through all the data and prints out all the stores that offer the min price
    {
        for(auto Branch:Chain.second )
        {
            for(auto product:Branch.second){
                if(product.second==min && product.first==prod){
                    cout<<Chain.first<<" "<<Branch.first<<endl;
                }
            }
        }
    }
}

void Chain_Markets::chain_location(const string& Chain,const string& Loc)
{
    // chain: requested Brand   ,  Loc: Requested Location
    // The products and their prices at the required chain market at requested location (branch/store),
    // will be printed in alphabetical order.

    auto it1=data_.find(Chain);
    if (it1!=data_.end())
    {
       auto it2=it1->second.find(Loc);
       if(it2!=it1->second.end())
       {
           for(auto products:it2->second)
           {
               cout<<products.first<<" "<<setprecision(2)<<fixed<<products.second<<endl;
           }
       }else {cout<<"Error: Branch name does not exist"<<endl;}
    }
    else{ cout<<"Error: Chain name does not exist"<<endl;}
}

bool isnumber(string s) // The function checks if a string is a positive real number
{
    int nb_point=0;
    for (unsigned int i=0; i<s.length();i++)
    {
         if (s.at(i)=='.')
         {
              nb_point++;
         }
         else if (!isdigit(s.at(i))) //checks if each character is a digit
         {
              return false;
         }
    }
    if (nb_point<=1) // checks if there are more than one floating point
    {
          return true;
    }
    else
    {
          return false;
    }
}
