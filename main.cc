#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main(int argc, char *argv[]){
    cin.exceptions(ios::failbit|ios::eofbit); //begin with exceptions
    int nonexist = 0;
    int nonnum = 0;     //count if not a number
    int exist = 0;
    double myint;       //if read in is a float or double int
    string s;
    cout << "Non-existent files:";
    for(int i = 1; i < argc; i++){
        //loop to when till to # of argc is provided
        try{
            ifstream file(argv[i]);
            if(file.fail()){ //if fail not exist
                throw ios::failure("fail");
            }//if
            while(true){
                file >> s; //read in a string
                if(file.fail() && file.eof()) break;
                try{
                    //catch when go end of the string
                    istringstream ss(s);
                    ss >> myint;
                    //if read in is not a int
                    if(ss.fail()){throw ios::failure("fail2");}
                    int temp = myint;
                    if(temp == 0){throw ios::failure("fail2");}
                    myint = myint - temp;
                    //if is a number
                    if(temp > 0){exist = exist + temp;}
                    if(myint != 0){
                       if(myint < 1){throw ios::failure("fail2");}
                    }
                }
                //cath when read a not number
                catch(ios::failure fail2){
                    nonnum++;
                }
            }//while
        }
        catch(ios::failure fail){ //catch when fail not exist
            cout << " " << argv[i];
            nonexist++;
        }
    }//for
    cout << endl;
    cout << "Total of all numbers: " << exist << endl;
    cout << "Total number of non-numbers: " << nonnum << endl;
    return 0;
}//end
