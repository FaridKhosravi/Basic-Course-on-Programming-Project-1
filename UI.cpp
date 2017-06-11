//  This Project was done in a group of 4 people:

//  Damoon Mohamadi     student#:267601
//  Mehdi Mahmoodpour   student#:267958
//  Amir Mehman Sefat   student#:267946
//  Farid Khosravi      student#:267964


#include "UI.hpp"
#include "database.hpp"

#include <vector>
#include <map>

void run_command(const Splitter& input, Chain_Markets &data) // this functions calls proper method based on user input command
{

    if (input.fetch_field(0)==""){  // checking if any command was given
        cout<<"Error: No command!"<<endl;
        return;
    }

    if ( commands.find(input.fetch_field(0)) == commands.end() ) // ckecking if the input command is in map of defined commands
    {
        cout << "Error: unknown Command" << endl;

    }else{

        commands.at(input.fetch_field(0))(input, data); //runs the corresponding command
    }
}

void quit_cmd(const Splitter& params, Chain_Markets &data)
{
    if(not parameter_qty_check(params,1)){return;} // checking too make sure nothing is entered other than "quit" command
    exit(0);

}

void chains_cmd(const Splitter& params,  Chain_Markets &data)
{
    if(not parameter_qty_check(params,1)){return;} // checking too make sure nothing is entered other than "chains" command

        data.print_chains();

}

void stores_cmd(const Splitter& params, Chain_Markets &data)
{
    if(not parameter_qty_check(params,2)){return;} // checking too make sure correct number of parameters are entered
    data.print_stores(params.fetch_field(1));
}

void cheapest_cmd(const Splitter& params, Chain_Markets &data)
{
    if(not parameter_qty_check(params,2)){return;} // checking too make sure correct number of parameters are entered

    data.cheapest(params.fetch_field(1));

}

void selection_cmd(const Splitter& params, Chain_Markets &data)
{
    if(not parameter_qty_check(params,3)){return;} // checking too make sure correct number of parameters are entered
    data.chain_location(params.fetch_field(1),params.fetch_field(2));

}

bool parameter_qty_check(const Splitter& params, unsigned int correct_qty)
{

    if(params.number_of_fields()>correct_qty){
        cout<<"Error: Too Many Parameters"<<endl;
        return false;
    }

    if(params.number_of_fields()<correct_qty){
        cout<<"Error: Too Few Parameters"<<endl;
        return false;
    }

    return true;
}
