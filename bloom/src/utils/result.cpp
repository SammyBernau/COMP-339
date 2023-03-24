#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include "../../include/BloomFilter.h"
using namespace std;

// get dictionary as vec
void result(string input_file, int bit_vec_size, int num_of_hashes)
{
    BloomFilter bf(bit_vec_size, num_of_hashes);
    fstream new_file; // file object
    double running_total;

    try
    {
        new_file.open(input_file, ios::in); // open file object for reading
        if (!new_file.is_open())
        {
            cout << "Error opening file: " << input_file << endl;
        }
        if (new_file.is_open())
        {
            string line;
            while (getline(new_file, line))
            { // read file text
                string curr_word = "";
                for (auto &ch : line)
                {
                    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    {
                        curr_word += ch;
                    }

                    if (ch == ' ')
                    {
                        //cout << "Current word: "<< curr_word << endl;
                        bf.insert(curr_word);
                        double curr_val_probability = stod(bf.search(curr_word));
                        running_total += curr_val_probability;
                        curr_word = "";
                    }
                }
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure &e)
    {
        cerr << "Error opening file: " << e.what() << endl;
    }

    cout << "---RESULT---" << endl;
    cout << "Reading from file: " << input_file << endl;
    cout << "Total insertions: " << bf.get_size() << endl;
    cout << "Bit vector size: " << bit_vec_size << endl;
    cout << "Number of hash algs: " << num_of_hashes << endl;
    cout << "Avg false positive probability: " << (running_total / bf.get_size()) * 100 << "%" << endl;
    cout << "Number of collisions: " << bf.get_collisions() << endl;
    cout << endl;
}