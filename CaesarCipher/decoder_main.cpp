#include "include/decoder.h"
#include <iostream>
#include <string>
#include "include/CLI11.hpp"
using namespace std;

int main(int argc, char** argv) {
  CLI::App ccdecoder{"Program that decodes an encoded caesar cipher file."};
  
  string input_file = "";
  string output_file = "";
  
  ccdecoder.add_option("-i, --input_file", input_file," input file name")->required();
  ccdecoder.add_option("-o, --output_file",output_file," output file name")->required();
  
  CLI11_PARSE(ccdecoder, argc, argv);
  decoder(input_file, output_file);
  return 0;
  
}