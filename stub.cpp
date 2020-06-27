//read crypted bytecode and executes
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream> //used for debug todo: remove cout's
#include <bits/stdc++.h>
using namespace std;

void readCrypted(string filename, int arr[], int arrLength, char returnArr[]);
void exec(char buf[]);
int getLength(string filename);



int main(int argc, const char *argv[])
{
    int length = getLength(argv[1]);
    cout << "File length: " << length << endl;
    int crypted[length];
    char decrypted[length];
    readCrypted(argv[1], crypted, length, decrypted);
    exec(decrypted);

    return 0;
}

void exec(char payload[])
{
    (*(void (*)()) payload)();
    return;
}

void readCrypted(string filename, int arr[], int arrLength, char returnArr[])
{
    ifstream infile(filename.c_str());
    int i = 0;
    //cout << arr[0] << endl;
    stringstream ss;
    for(int i = 0; i < arrLength; i++)
    {
        infile >> arr[i];
        ss << std::hex << arr[i];
        returnArr[i] = arr[i];
        //cout << x << endl;
    }
    //ss << std::hex << arr[1];
    string res(ss.str());
    //cout << res;
    return;


}

int getLength(string filename)
{
    int* arr = new int[4096]; //todo: romove static 4Gb buffer
    ifstream infile(filename.c_str());
    int i = 0;
    while(infile)
    {
        infile >> arr[i];
        //cout << arr[i] << endl;
        i++;

    }
    delete[] arr;
    return i-1;
}

