//Created by Matt Perry
//Lab #4
//Using Binfiles
//9/15/18

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ios>
#include <vector>

int main(){
    //vector for storing numbers from file
    std::vector<int> myIntVector;
    //int to store the ints from data.dat
    int x;
    //ifstream for reading the file!
    std::ifstream myNumberFile("data.dat", std::ios::in | std::ios::binary);
    if(!myNumberFile.is_open()){
        std::cout << "Help its broken " << std::endl;
    }
    // seekg to get a pointer value from bit 0 to end
    myNumberFile.seekg(0,std::ios::end);
    // setting size of file from tell g in for of int
    int size = (int)myNumberFile.tellg();
    // then returning pointer to start of file for iteration to take vlaues out
    myNumberFile.seekg(0,std::ios::beg);
    //while statment reading values until reaching end 
    while(myNumberFile.tellg() < size){
        // type cast from char to int, incremenitng through the file by standard int size of 4 bytes!
        myNumberFile.read(reinterpret_cast<char *>(& x),4 );
        //pushing the int pulled from .dat file
        myIntVector.push_back(x);
    }
    //int decleration for handling values stored in container
    int sizeOfVector = myIntVector.size();
    int total = 0;
    int count = 0;
    //dumps contents of container to cout
    for(int i = 0; i < sizeOfVector; i++){
        std::cout  << myIntVector[i] << " ";
        total = total + myIntVector[i];
        count ++;
        //every 10th number we start a new line!
        if (count % 10 == 0){
            std::cout << std::endl;
        }
    }
    // final decleration of info
    std::cout << "The total count of numbers in file are: " << count << std::endl;
    std::cout << "The total sum of the numbers are: " << total << std::endl;
    std::cout << "The average of the sum of the numbers are: " << (total/count) << std::endl;
    //close file
    myNumberFile.close(); 
    // small while statment to hold until user ready to exit.
    while(true){
        std::cout << "Press 1 to exit" << std::endl;
        std::cin >> x;
        if(x == 1 ){
            break;
        }
    }
return 0;
}
