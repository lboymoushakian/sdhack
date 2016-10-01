#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

int randInt(int min, int max);
void pull(vector<string> prompts, vector<string>responses);

int main()
{
    
    //this first chunk gets all the lines from promptCards.txt and
    //puts them into a vector called prompts
    const char WORDFILENAME[] = "/Users/lariboymoushakian/sdhacks/promptCards.txt";
    
    vector<string> prompts;
    string line;
    
    ifstream myfile (WORDFILENAME);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
            prompts.push_back(line);
        myfile.close();
    }
        else cout << "Unable to open file";

//for (vector<string>::const_iterator i = prompts.begin(); i != prompts.end(); ++i)
//cout << *i << "\n";

    //this gets all the lines from responseCards.txt and
    //puts them into a vector called responses
    const char WORDFILENAME2[] = "/Users/lariboymoushakian/sdhacks/responseCards.txt";
    
    vector<string> responses;
    ifstream myfile2 (WORDFILENAME2);
    if(myfile2.is_open())
    {
        while(getline (myfile2, line))
            responses.push_back(line);
        myfile2.close();
        
    }
    else cout << "Unable to open file";
    
    char input;
    cout << "Pull? y/n\n";
    cin >> input;
    while(input=='y' || input =='Y')
    {
    
    pull(prompts, responses);
        cout << "Pull again? y/n\n";
        cin >> input;
    }
    
    //for(vector<string>::const_iterator i = responses.begin(); i!=responses.end(); ++i)
      //  cout << *i << "\n";
    
}

void pull(vector<string> prompts, vector<string>responses)
{
    int a = randInt(0, (int)prompts.size());
    int b = randInt(0, (int)responses.size());
    cout << prompts[a] << "\n";
    cout << responses[b] << "\n";
}

// Return random int from min to max, inclusive
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}
