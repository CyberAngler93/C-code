//Created by Matt Perry
//Lab #3
//Using Streams

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ios>
#include <vector>
int main(){
	std::vector<std::string> myStringVector; // Vector for storing the strings from the text file
	std::ifstream inFile("input.txt"); // declaring the inFile file name
	std::string textInput; //strign to hold text input
	if (inFile.is_open()) { // bool check to make sure file opened
		 while (std::getline(inFile,textInput)) { // getline to take a whole line at once.
			 myStringVector.push_back(textInput); // push to my vector to store strings in a container.
			 std::cout << textInput << std::endl; // outputing the text to the console for user to see
			}
	}
	else{ // else statement for it the file opening has failed
		std::cout << "Cannot Open Input File" << std::endl;
		 return 1;
	}
  
	inFile.close(); // closing inFile.
	// section of code for handling user entered numbers
	int userLineNumber;
	int userCopyCount;
	std::cout << "Enter a number for the amount of copies you would like!" << std::endl; 
	std::cin >> userCopyCount;
	std::cin.ignore(); //clearing the cin for the newline
	std::cout << "Now pick a line number from the text!" << std::endl;
	std::cin >> userLineNumber;
	std::cout << userCopyCount <<  " " << userLineNumber << std::endl;
	// 

	//outfile handling.
	std::ofstream outFile("input.txt", std::ios::app);
	if(!outFile) {//error handling.
		std::cout << "Error opening file!" << std::endl;
	}

	//for loop for parsing the amount of coppies to append to the file via outFile.
	for (int i = 0; i < userCopyCount; i++){
		outFile << myStringVector[userLineNumber-1] << std::endl;
	}
	outFile.close();
	//infile handling once again
	inFile.open("input.txt");
	if (inFile.is_open()) {
		while (std::getline(inFile,textInput)) {
				std::cout << textInput << std::endl;
		}
	}
    //closing to clean up
	inFile.close();
		
    
    
return 0;
}