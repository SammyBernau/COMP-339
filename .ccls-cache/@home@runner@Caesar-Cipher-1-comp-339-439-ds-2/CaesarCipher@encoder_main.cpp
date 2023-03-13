#include "include/encoder.h"
#include "include/file_read.h"
#include "include/utils.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

#include "include/CLI11.hpp"
using namespace std;

int main(int argc, char **argv) {
    CLI::App ccencoder{"Program that encodes a \"n\" number of randomly generated sentences via random caesar cipher shift. Each sentence has its own random shift. Supports shift ranges from 1 to 26."};

    string input_file = "";
    int sentences = 5; 
  
    ccencoder.add_option("-i,--input_file", input_file, " input file")->required();
    ccencoder.add_option("-s,--sentences", sentences, " number of sentences to generate")->check(CLI::PositiveNumber)->required();

    CLI11_PARSE(ccencoder, argc, argv);
    encoder(input_file, sentences);
    return 0;
}
