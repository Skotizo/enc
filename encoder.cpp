#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
// payload generation: msfvenom -p windows/exec cmd=whoami -f num

int* hexToDec(string filename, int length);
int getLength(string filename);
void writeEncodedPayload(string outfilename, int data[], int length);

int main(int argc, const char *argv[])
{


    string filename = argv[1];
    int length = getLength(filename);
    cout << endl << "Length of bytecode --> " << (length-1) << endl << endl;
    int * ptr = hexToDec(filename,length);
    cout << "--BEGIN DECIMAL CODE--" << endl;

    ofstream outfile(argv[2]);

    for (int i=0; i < (length); i++)
    {
        cout << ptr[i] << " ";
        outfile << ptr[i] << " ";

    }
    outfile.close();
    cout << endl << "--END DECIMAL CODE--" << endl;
    cout << endl;

    return 0;
}

int * hexToDec(string filename, int length)
{
    int i = 0;
    string raw,num;
    int * arr = new int[length];
    ifstream infile(filename.c_str());
    cout << "--BEGIN BYTECODE--" << endl;
    while(infile)
    {
        infile >> raw;
        num = raw.substr(0,4);
        unsigned int x;
        stringstream ss;
        ss << std::hex << num;
        ss >> x;
        cout << raw << " ";
        arr[i]=x;
        i++;
    }
    cout << endl << "--END BYTECODE--" << endl <<endl;

    infile.close();
    return arr;
}

int getLength(string filename)
{
    ifstream infile(filename.c_str(), ios::binary);
    int begin = infile.tellg();
    infile.seekg (0, ios::end);
    int end = infile.tellg();
    int fsize = (end-begin);
    fsize = (fsize/6)-4;

    infile.close();
    return fsize;

}

