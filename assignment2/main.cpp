#include <iostream>
#include <fstream>
#include <string>

// check if line is empty
bool isLineEmpty(std::string current_line)
{
    if (current_line.length() > 0)
    {
        return false;
    }

    return true;
}

// read file line by line
int calculateLOC(std::ifstream &fin)
{
    int loc_counter = 0;
    std::string current_line;
    for (int i = 0; getline(fin, current_line); i++)
    {
        if (!isLineEmpty(current_line))
        {
            loc_counter++;
        }
        // getline(fin, current_line);
        // std::cout << current_line << "     " << current_line.length() << std::endl;
    }

    return loc_counter;
}

int main(int argc, char *argv[])
{
    std::cout << "Enter the filename(must be in the same directory as the executable" << std::endl;

    // take filename as input from user
    std::string filename;
    std::cin >> filename;
    // std::cout << filename << std::endl;

    std::ifstream fin;
    fin.open(filename);

    if (!fin)
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    int loc_counter = calculateLOC(fin);

    // print the LOC
    std::cout << filename << " LOC is: " << loc_counter << std::endl;

    fin.close();
    return 0;
}