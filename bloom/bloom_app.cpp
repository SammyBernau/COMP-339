#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <tuple>
#include <iostream>
#include <cmath>
#include <string>
#include "include/BloomFilter.h"
#include "../CaesarCipher/include/CLI11.hpp"
#include "include/result.h"
#include <openssl/sha.h>

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

    cout << endl;
    
    //Computes the result of the user input
    result(input_file, bit_vec_size, num_of_hashes);

    return 0;
}