//Created by Matt Perry
//HW#2
//Files
//9/25/18
//Prof James Long
#ifndef FILES_HPP_INCLUDED
#define FILES_HPP_INCLUDED

#include <iostream>
#include<fstream>
#include<string>
// decleration of getId
int getIdFromFile(std::string fileName, std::istream & is, std::ostream &os);
// decleration of numberChase
void numberChase(std::string fileName, std::ostream & os);
#endif // FILES_HPP_INCLUDED
