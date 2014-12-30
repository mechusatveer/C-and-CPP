#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

using std::cout;
using std::endl;

std::vector<std::string> csv_read_row(std::istream &in, char delimiter);
std::vector<std::string> csv_read_row(std::string &in, char delimiter);

int main(int argc, char *argv[])
{
    std::ifstream in("input.csv");
    if (in.fail()) return (cout << "File not found" << endl) && 0;
    while(in.good())
    {
        std::vector<std::string> row = csv_read_row(in, ',');
        for(int i=0, leng=row.size(); i<leng; i++)
            cout << "[" << row[i] << "]" << "\t";
        cout << endl;
    }
    in.close();

    std::string line;
    in.open("input.csv");
    while(getline(in, line)  && in.good())
    {
        std::vector<std::string> row = csv_read_row(line, ',');
        for(int i=0, leng=row.size(); i<leng; i++)
            cout << "[" << row[i] << "]" << "\t";
        cout << endl;
    }
    in.close();

    return 0;
}

std::vector<std::string> csv_read_row(std::string &line, char delimiter)
{
    std::stringstream ss(line);
    return csv_read_row(ss, delimiter);
}

std::vector<std::string> csv_read_row(std::istream &in, char delimiter)
{
    std::stringstream ss;
    std::vector<std::string> row;//relying on RVO
    while(in.good())
    {
        char c = in.get();

        if (c==delimiter) //end of field
        {
            row.push_back( ss.str() );
            ss.str("");
        }
        else if ((c=='\r' || c=='\n') )
        {
            if(in.peek()=='\n') { in.get(); }
            row.push_back( ss.str() );
            return row;
        }
        else
        {
            ss << c;
        }
    }
}
