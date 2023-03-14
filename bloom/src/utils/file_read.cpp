#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include "../../include/BloomFilter.h"
using namespace std;


//get dictionary as vec
void file_read(string file_path, BloomFilter bf){
    fstream new_file; // file object
  
    try {
        new_file.open(file_path, ios::in); //open file object for reading
        if (!new_file.is_open()) {
            cout << "Error opening file: " << file_path << endl;
        }
        if (new_file.is_open()) {
            string file_text;
            while (getline(new_file, file_text)) { //read file text
              bf.insert(file_text); 
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure& e) {
        cerr << "Error opening file: " << e.what() << endl;
    }
}