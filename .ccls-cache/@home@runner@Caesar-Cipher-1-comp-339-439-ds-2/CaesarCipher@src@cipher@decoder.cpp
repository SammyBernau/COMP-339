#include "../../include/file_read.h"
#include "../../include/decoder_helper.h"
#include "../../include/utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
using namespace std;

//Decrypts file encoded with caesar cipher given that each line has its own shift (tests all cases of shift to get decoded text)
void decoder(string encoded_file_path, string decoded_file_path){
  cout << "Decoding file... " << encoded_file_path << endl;
    string return_string;
    fstream new_file; // file object
    string decoded_text;
    try {
        new_file.open(encoded_file_path, ios::in); //open file object for reading

        if (!new_file.is_open()) {
            cout << "Error opening file: " << encoded_file_path << endl;
        }
        if (new_file.is_open()) {
            string file_text;
            int line = 1;
            while (getline(new_file, file_text)) { //read file text
                auto [decoded_text_temp , shift] = decoder_helper(file_text);
                string decoded_text = "Decoded line " + to_string(line) + " with key " + to_string(shift) + ": " + decoded_text_temp;
                cout << decoded_text << "\n"<< endl;
                write_to_file(decoded_file_path, decoded_text);
                line++;
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure& e){
        cerr << "Error opening file: " << e.what() << endl;
    }
}