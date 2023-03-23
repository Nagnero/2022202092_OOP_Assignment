#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

bool compare_string(char* input1, char* input2);

int main() {
    char data[100], input[100], result[20][100]{};
    int cnt;

    cout << "Input file name : ";
    cin >> input >> cnt;

    ifstream fin;
    if (strcmp("filename_list.txt", input) == 0) {
        fin.open("filename_list.txt");
    }
    else {
        cout << "no match file";
    }

    if (fin) {
        cout << "no contents" << endl;
        fin.close();
        return 0;
    }

    for (int i = 0; i < cnt; i++) {
        cin >> input;
        while (!fin.eof()) {
            
            fin.getline(data, 100);

            if (compare_string(input, data)) {
                *result[i] = *data;
                
            }
        }
    }

    while (!fin.eof()) {
        fin.getline(data, 100);
        cout << data << endl;
    }

    fin.close();
}

bool compare_string(char* input1, char* input2) {
    cout << input1 << input2;
    return 1;
}