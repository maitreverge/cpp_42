#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main (int ac, char **av){

    if ( ac != 2)
        cout << "usage incorrect" << endl;

    string remplacing = "\", \"";

    string mainArg(av[1]);

    // insert Double quote at the begining and the end

    mainArg.insert(mainArg.begin(), '\"');
    mainArg.insert(mainArg.end(), '\"');

    for (size_t i = 0; i < mainArg.size(); ++i)
    {
        if ( std::isspace(mainArg[i])){

            mainArg.replace(i, 1, remplacing);
            i += remplacing.size() - 1;
        }
    }
    
    cout << mainArg << endl;

}