#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include "../../include/utils.h"
using namespace std;

//get dictionary as vec
vector<string> read_from_file_to_vec(string file_path){
    fstream new_file; // file object

    //vector used over set to allow for fast indexing when grabbing random words.
    //If a set were used, it would take an additional O(n) time to iterate and randomly grab words whereas accessing via vector takes O(1)
    vector<string> dict;
  
    try {
        new_file.open(file_path, ios::in); //open file object for reading
        if (!new_file.is_open()) {
            cout << "Error opening file: " << file_path << endl;
        }
        if (new_file.is_open()) {
            string file_text;
            while (getline(new_file, file_text)) { //read file text
                string temp = remove_non_alpha(file_text); //remove non alphabetical chars
                string converted_text = to_upper_case(temp);  //convert to uppercase
                dict.push_back(converted_text); //insert into set
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure& e) {
        cerr << "Error opening file: " << e.what() << endl;
    }
    return dict;
}

//get dictionary as set
set<string> read_from_file_to_set(string file_path){
    fstream new_file; // file object
    set<string> dict; //Creates a set of the dictionary to easily tell if words are in the set
    try {
        new_file.open(file_path, ios::in); //open file object for reading
        if (!new_file.is_open()) {
            cout << "Error opening file: " << file_path << endl;
        }
        if (new_file.is_open()) {
            string file_text;

            while (getline(new_file, file_text)) { //read file text

                //remove non alphabetical chars
                string temp = remove_non_alpha(file_text);
              
                //convert to uppercase
                string converted_text = to_upper_case(temp);

                //insert into set
                dict.insert(converted_text);
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure& e) {
        cerr << "Error opening file: " << e.what() << endl;
    }
    return dict;
}

void write_to_file(string file_path, string text) {
    fstream new_file;
    try {
        new_file.open(file_path, ios::app); //open file for writing (can change to ios::app so that it appends to the file rather than overwriting existing lines)

        if (!new_file.is_open()) {
            cout << "Error opening file: " << file_path<<endl;
        }
        if (new_file.is_open()) {
            new_file << text << endl; //write to file
            new_file.close();
        }
    }
    catch (const ios_base::failure& e) {
        cerr << "Error writing to file: " << e.what() << endl;
    }
}




