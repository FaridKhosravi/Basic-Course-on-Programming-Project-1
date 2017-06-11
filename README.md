# Basic-Course-on-Programming-Project-1
C++

Purpose of this programming project:
The purpose of this programming project is to familiarize the students with the C++ classes, using STL, and creating a program using simple modules.

The data manipulated by the program:
Let's consider the following kind of information relating to the products and their prices in the different stores of the different grocery store chains:

    S-Market
        Hervantakeskus
            milk          1.05
            peanut butter 3.25
    S-Market
        Pirkkala
            peanut butter 2.90
            milk          2.00
    S-Market
        Kaukajärvi
            milk          1.05
            peanut butter 3.25
    K-Citymarket
        Pirkkala
            milk          0.95
            peanut butter 2.90
    K-Citymarket
        Turtola
            peanut butter 4.20
            milk          0.95
    K-Citymarket
        Lielahti
            peanut butter 3.00
            milk          0.95
    K-Citymarket
        Linnainmaa
            milk          0.95
            peanut butter 2.90
    Prisma
        Kaleva
            milk          0.90
            peanut butter 2.90
    Prisma
        Lielahti
            milk          1.90
            peanut butter 2.90
    Prisma
        Koivistonkylä
            peanut butter 2.90
            milk          0.90
  
Even if the list above has exactly the same two products listed for every single store, this is of course not true generally: different stores have different selection. All the stores don't carry the same products. For example, Pirkka products can only be found in K-stores.
The product selection information shown above can be represented using csv-file like this:

      store_chain;store_location;product_name;product_price
  
The example used above would look like this when stored in a csv-file:

    S-Market;Hervantakeskus;milk;1.05
    Prisma;Koivistonkyla;peanut_butter;2.90
    S-Market;Hervantakeskus;peanut_butter;3.25
    S-Market;Pirkkala;milk;2.00
    K-Citymarket;Linnainmaa;peanut_butter;2.90
    S-Market;Kaukajarvi;peanut_butter;3.25
    K-Citymarket;Pirkkala;milk;0.95
    Prisma;Kaleva;peanut_butter;2.90
    K-Citymarket;Pirkkala;peanut_butter;2.90
    Prisma;Lielahti;milk;1.90
    K-Citymarket;Turtola;peanut_butter;4.20
    S-Market;Kaukajarvi;milk;1.05
    K-Citymarket;Lielahti;milk;0.95
    K-Citymarket;Linnainmaa;milk;0.95
    Prisma;Kaleva;milk;0.90
    Prisma;Lielahti;peanut_butter;2.90
    S-Market;Pirkkala;peanut_butter;2.90
    Prisma;Koivistonkyla;milk;0.90
    K-Citymarket;Lielahti;peanut_butter;3.00
    K-Citymarket;Turtola;milk;0.95
  
Every legal line has four semicolon separated fields. None of the fields are allowed to be empty or consist only from whitespace characters. The last field must represent a real number (double).

To keep things simple let's also agree that none of the fields can contain semicolon (;) or whitespace characters. In other words on an error free line there is always three semicolons, no whitespace characters, and none of the fields are empty.

Also notice, that the lines in the file can be in any order. It doesn't affect to the behaviour of the program.

The names of the store chains, store locations, and product names can contain any visible characters, except semicolons (as stated above).
If the same product is given to the same store more than once, the last one of them will be used as an actual value (price). For example:

    S-Market;Hervantakeskus;milk;0.55
    Prisma;Koivistonkyla;peanut_butter;2.90
    S-Market;Hervantakeskus;peanut_butter;3.25
    S-Market;Pirkkala;milk;2.00
    S-Market;Hervantakeskus;milk;1.05 
The price of the milk in S-Market Hervantakeskus would end up being 1.05.
The program to be implemented is able to read a file in the format described above, store the information in some suitable combination of STL containers, and allow the user to make simple queries/searches into the information stored in the data structure.

Behaviour of the implemented program:
When the program starts it reads a file named:

    products.txt
located in the same folder as the source codes of the project (or to be exact: from the current working directory). The name of the input file is not asked from the user.
The program parses the information it reads from the input file and stores it in a suitable STL data structure. You can decide the actual data structure yourself as long as it follows the guidelines given in the section special requirements.

Once the file has been read and the content stored in the memory, the program prints a prompt:

    product search>␣ 
After this, every time the program prints the prompt, the user can type any of the following commands:
quit
Program ends.
chains
Prints all the know store chain names in alphabetical order:
For example:

      product search>␣chains
      K-Citymarket
      Prisma
      S-Market
      product search>␣ 
      
stores chain_name
Prints on screen in alphabetical order the locations of all the stores belonging to the given store chain.
For example:

      product search>␣stores K-Citymarket
      Lielahti
      Linnainmaa
      Pirkkala
      Turtola
      product search>␣ 
      
cheapest product_name
Prints out the cheapest price of the product in all the known stores. Under the price it prints all the store chain and location pairs where the product can be found at the cheapest price.
The output should be formatted like this:

      product search>␣cheapest milk
      0.90
      Prisma Kaleva
      Prisma Koivistonkyla
      product search>␣ 
      
Store chain names are in alphabetical order and if there are multiple stores that have the same cheapest price for the product they will in turn be in alphabetical sub-order.

The price will be printed with two decimals.

If the product name is unknown, the following message will be printed:

      product search>␣cheapest sausage_milk
      This product is not available anywhere.
      product search>␣ 
      
selection chain_name store_location
The products available at the specified store will be printed in alphabetical order with the prices.
for example:

      product search>␣selection Prisma Lielahti
      milk 0.95
      peanut_butter 2.90
      product search>␣ 
      
The prices will be printed with two decimals.

When the command is finished the program prints the prompt again and waits for the next command from the user. This will repeat until the user inputs quit command.

Error handling:
There are broadly speaking two kinds of error conditions in this program:

Errors in the input file.
Errors in the user input.
The errors related to the input file arise when reading the input file fails for one reason or the other: the file can't be opened for reading, there are lines in the file that don't conform to the format described earlier etc. In these situations the program shoud print a message:

    Error:␣the input file can not be read.
After this the program ends without any additional printouts. Also, this error message should be only printed out once no matter how many errors there actually are in the file.
Errors arising from the user inputs are slightly more complicated but not much. Unknown commands or commands that are followed by wrong number of additional "parameters" will produce an error message. The actual wording of the error message you can decide yourself, but it must begin with the text:

    Error:␣
One line of user input only produces one error message, no matter how many errors there actually are.

After printing the error message the program returns to wait for the next line of user input:

    product search>␣ 
Unlike the error situations when reading the file, the errors in user input will not end the program.

Special requirements:

You are only allowed to read the input file once.
The data structure you will utilize in storing the information must contain at least one STL map container.
There must be at least one class in your program. This class must have a good public interface that allows you to do all the required operations to the objects of your class.
There has to be at least three modules in your program.
