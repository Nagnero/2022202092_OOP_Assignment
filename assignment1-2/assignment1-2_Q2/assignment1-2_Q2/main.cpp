#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
using namespace std;

void Transmission_channel(const char* data) {

    srand(time(NULL)); // ����ø��� �ٸ� �� ���

    for (int i = 0; i < 16; i++) {
        if (rand() % 20 == 0) // 0�� ������ ������ ����; 5% Ȯ��
            (data[i] + 1) % 2;
    }

    for (int i = 0; i < 16; i++)
        cout << data[i];

}

void Sender() {

    char input[13], send_data[16]{};
    int divisor[5] = { 1,1,0,1,1 }, i;

    cout << "Data: ";
    cin >> input;

    for (i = 0; i < 12; i++) {
        send_data[i] = input[i];
    }


    for (i = 0; i < 12; i++) {
        
        if (input[i] - 48 == 0) {
            continue;
        }
        
        /*for (int j = 0; j < 5; j++) {

            if (arr[i + j] - 48 != divisor[j]) {
                arr[i + j] = 1;
            }
            else {
                arr[i + j] = 0;
            }
            
        }*/
     }
    /*for (; i < 16; i++)
        send_data[i] = arr[i];
    for (int i = 0; i < 16; i++)
        cout << send_data[i];
    cout << endl;
    Transmission_channel(send_data);*/

}

int main() {

    Sender();

}

