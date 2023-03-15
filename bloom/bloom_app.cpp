#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cmath>
#include <string>
#include "include/BloomFilter.h"
#include "../CaesarCipher/include/CLI11.hpp"
#include "include/file_read.h"
using namespace std;


int main(int argc, char **argv) {
    CLI::App bloom_filter{"A bloom filter is a probabilistic data structure that is based on hashing. It is extremely space efficient and is typically used to add elements to a set and test if an element is in a set."};

    
    int bit_vec_size;
    int num_of_hashes; //must be 1 or 2
    string input_file;

    bloom_filter.add_option("-i, --input_file", input_file, "Enter file path") 
    -> required(); 

    bloom_filter.add_option("-s, --vec_size", bit_vec_size, "Enter bit vector size") 
    ->check(CLI::PositiveNumber) 
    -> required();

    bloom_filter.add_option("-n, --num_of_hashes", num_of_hashes, "Enter number of hash algs to be used") 
    ->check(CLI::Range(1,2)) 
    -> required();
  



    CLI11_PARSE(bloom_filter, argc,argv);

    BloomFilter bf (bit_vec_size, num_of_hashes);
    double running_total; 
    cout << endl;
    fstream new_file; // file object
  
    try {
        new_file.open(input_file, ios::in); //open file object for reading
        if (!new_file.is_open()) {
            cout << "Error opening file: " << input_file << endl;
        }
        if (new_file.is_open()) {
            string file_text;
            while (getline(new_file, file_text)) { //read file text
              bf.insert(file_text);

              double curr_val_probability = stod(bf.search(file_text));
              running_total += curr_val_probability; 
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure& e) {
        cerr << "Error opening file: " << e.what() << endl;
    }
    
    
    cout << "---RESULT---" << endl;
    cout << "Reading from file : " << input_file << endl;
    cout << "Total insertions: " << bf.get_size() << endl;
    cout << "Bit vector size = " << bit_vec_size << endl;
    cout << "Number of hash algs = " << num_of_hashes << endl;
    cout << "Avg false positive probability: " << (running_total/bf.get_size()) * 100 << "%" << endl;
    cout << endl;

    // cout << "Enter \"q\" or \"quit\" to exit -> " << endl;
    // while (1) {
    //   string input = "";
    //   cout << "Would you like to insert a string, search or print the vector? -> ";
    //   cin >> input;
    //   cout << endl; //space
      
    //   if (input == "Insert" || input == "insert") {
    //     string insert_value = "";
    //     cout << "Insert string here -> "; 
    //     cin >> insert_value;
    //     bf.insert(insert_value);
    //     cout << endl; //space
    //   }

    //   if (input == "Search"|| input == "search") {
    //     string search_value = "";
    //     cout << "What string would you like to search for? -> "; 
    //     cin >> search_value;

    //     cout << "Here is your result... ";
    //     cout << bf.search(search_value) << endl;
    //     cout << endl; //space
    //   }

    //   if (input == "Print" || input == "print") {
    //     bf.print_data();
    //     cout << endl; //space
    //   }

    //   if(input == "quit" || input == "q") {
    //     break;
    //   }
    // }

    return 0;
}