//Created by Matt Perry
//HW#2
//Files
//9/25/18
//Prof James Long

#include "files.hpp"
//definition of getId
int getIdFromFile(std::string fileName , std::istream &  is, std::ostream & os){
    //creating input file stream
    std::ifstream fInput(fileName);
    //checking to see if we opened our file
    if(fInput.is_open()){
            //strings to hold values a temp and name
        std::string name;
        std::string temp;
    //ints to hold values temp and id
        int tempId;
        int userId;
          // while loop passing input stream to name
        while(is >> name){
                //clearing buffer
            fInput.clear();
        //seekg to start of file
            fInput.seekg(0,std::ios::beg);
            //setting id to -1 in case user not defined.
            userId =-1;
            //while loop taking file input into temp string into temp id and comparing
            while(fInput >> temp >> tempId){
                if(temp == name){
                        // if we get a hit then store tempid to userID
                    userId = tempId;
                    break;
                }
            }
            // if user id  == -1 then we output error and ask them to enter again.
            if(userId == -1){
                os << "error" << std::endl;
            } else {
                // else we push the id
                os << userId << std::endl;
            }
        }
        return 0;
        } else {
        //close file
         fInput.close();
        return -1;
    }

}

//number chase definition
void numberChase(std::string fileName , std::ostream & os){
    // input file stream  ios::in and binary
     std::ifstream fileInput(fileName, std::ios::in | std::ios::binary);
     //fence posting x = 0 so we start at slot 0 in file
      int x = 0;
      //checking for open
     if(fileInput.is_open()){
            // loop to seek to x which is the number we find at
            while(true){
            //seeking to x location in file.
            fileInput.seekg(x*sizeof(int),std::ios::beg);
            // recast of char* to deref int at the size of int 4 bytes
            fileInput.read(reinterpret_cast<char * >( &x), sizeof(int));
            //if our x is less than 0 then we leave and print final number
            if(x < 0){
                os << x << std::endl;
                break;
            }
            // if x not less than zero print and return to top of loop
            os << x << std::endl;
         }
        fileInput.close();
     }
}





