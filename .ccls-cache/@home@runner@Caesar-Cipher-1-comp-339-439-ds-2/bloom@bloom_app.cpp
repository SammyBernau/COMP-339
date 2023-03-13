#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cmath>
#include "include/BloomFilter.h"
#include "../CaesarCipher/include/CLI11.hpp"
using namespace std;


int main(int argc, char **argv) {
    CLI::App bloom_filter{"A bloom filter is a probabilistic data structure that is based on hashing. It is extremely space efficient and is typically used to add elements to a set and test if an element is in a set."};

    
    int bit_vec_size;
    int num_of_hashes; //must be 1 or 2

    bloom_filter.add_option("-s, --vec_s", bit_vec_size, "Enter bit vector size") -> required();

    bloom_filter.add_option("-n, --hash_n", num_of_hashes, "Enter number of hash algs to be used")->check(CLI::Range(1,2)) -> required();
  



    CLI11_PARSE(bloom_filter, argc,argv);
    BloomFilter bf (bit_vec_size, num_of_hashes);

    cout << "Enter \"q\" or \"quit\" to exit -> " << endl;
    while (1) {
      string input = "";
      cout << "Would you like to insert a string, search or print the vector? -> ";
      cin >> input;
      cout << endl; //space
      
      if (input == "Insert" || input == "insert") {
        string insert_value = "";
        cout << "Insert string here -> "; 
        cin >> insert_value;
        bf.insert(insert_value);
        cout << endl; //space
      }

      if (input == "Search"|| input == "search") {
        string search_value = "";
        cout << "What string would you like to search for? -> "; 
        cin >> search_value;

        cout << "Here is your result... ";
        cout << bf.search(search_value) << endl;
        cout << endl; //space
      }

      if (input == "Print" || input == "print") {
        bf.print_data();
        cout << endl; //space
      }

      if(input == "quit" || input == "q") {
        break;
      }
    }

    return 0;
}