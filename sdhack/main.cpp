#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
    
    string rArray[460];
    string pArray[90];
    
    //feeds list of responses into an array
    ifstream file("rwords.txt");
    if(file.is_open())
    {
        
        
        for(int i = 0; i != 460; i++)
        {
            file >> rArray[i];
        }
    }
    
    //feeds list of prompts into an array
    ifstream file2("bwords.txt");
    if(file2.is_open())
    {
        
        for(int i = 0; i != 90; i++)
        {
            file2 >> pArray[i];
        }
    }
    
    //initializes random number generator
    srand((unsigned) time(NULL));
    
    
    string sInput = "";
    string sResponse = "";
    
    while(1) {
        cout << ">";
        getline(cin, sInput);
        int nSelection = rand() % 90;
        sResponse = pArray[nSelection];
        nSelection = rand() % 460;
        sResponse += rArray[nSelection];
        cout << sResponse << endl;
    }
    
    return 0;
}





