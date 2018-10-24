//Matthew Perry
//HW 7 part c
#include "blanksout.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;
void blanksOut(map<int, string> & data){
    //for loop to reach all the possibe keys
    for (int i = -1700; i <52; i ++){
            // if there is a key with i
            if(data.count (i) == 1){
                // storing the string at key i to change
            string change = data.at(i);
            for(int ii = 0; ii < change.size(); ii++){ // taking length of change to append it with string rules
                if(change[ii] == ' ' && change[ii+1] == ' '){ // if two spaces in a row remove
                    change.erase(ii,2);
                }
                if(change[ii] == ' ' && change[ii+1] == 'x'){ // if space then char then only erase one space
                    change.erase(ii,1);
                }
            }
            data.at(i) = change; // pass our new value change back to the map asso with i
        }
}
    }


