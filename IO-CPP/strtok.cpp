#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main(int argc, char *argv[])
{

    /* C++ IO

    Streams
    1)ifstream    void ifstream::open(char* file,ios::openmode mode = ios::in);
    2)ofstream    void ofstream::open(char* file,ios::openmode mode = ios::out | ios::trunc);
    3)fstream     void fstream::open(char* file,ios::openmode mode = ios::in | ios::out);
    bool is_open();
    istream& get(char &ch);
    istream& get(char* buf, int size) //it read till new line or EOF or size-1 it not remove delim
    istream& get(char* buf,int size, char delim)//it read till delim or EOF or size-1 do not remove delim
    int get() //return a char
    istream& getline(char* buf,int size) // read till new line and remove new line
    istream& getline(char* buf, int size, char delim) //read till delim and remvoe it
    istream& ignore(int size, chat delim)//ignore size no of char or till delim not encountered do not remvoe delim
    int_type peek()//get char from string without removing
    istream putback(char c)
    istream& seekg(offset, seekdir origin)  ios::beg, ios::cur,ios::end
    ofstream seekp(offset,seekdir origin)
    pos_type tellg()
    pos_type tellp()
    ostream& put(char ch);
    istream& read(char* buf, size);
    ostream& write(const char* buf,size);
    getline
    peek
    putback

    */
    string str = "This is a text file, which i want to check , who is owner of this file, tell me, Hello";
    stringstream ss(str);

    string str1;

    char arr[30];

    while(ss)
    {
        ss.getline((char*)arr,30,',');
        char* temp = strtok(arr," ");

        while(temp != NULL)
        {
            cout<<temp<<endl;
            temp = strtok(NULL," ");
        }

    }
    return 0;
}
