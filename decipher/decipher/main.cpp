//Created by Matthew Perry
//Decipher using Frequency Analysis
//11/28/17
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::sort;
using std::getline;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::cin;
// struct so I can sort the analysis
struct EncLet{
    double f;
    char letter;
};


int main(){
    //populating a char vector of all letters using ascii values
    vector<char> vchar;
    for(int k = 97; k < 123; k++){
        vchar.push_back(k);
    }
    vector<int> vcount;
    vector<vector<char>> decryptedBig;
    vector<string> encrypted;
    vector<string> decrypted;
    vector<char> decrypted1;
    vector<double> freqOfChars;
    vector<EncLet> sortVector;// our vector of structs to sort
    ofstream decipher;
    string fileInput;
    ifstream decryptKey("frequencyKeys.txt");
    ifstream encryptedFile("encrypted.txt");


    cout << "Hello welcome to the decipher guesser." << endl;
    cout << "The program will take an anaylsis of the frequency of letters in a text file." << endl;
    cout << "If you would like to test your own encrypted message, place it in a text file named: encrypted.txt" << endl;
    cout << "This is not designed to 100% break the cipher but to aid you!" << endl;
    cout << "The larger the sample of the cipher the more accurate we will be with the breaking!" << endl;
    cout << "Enter anything to begin!" << endl;
    char uI = 'a';
    // user interaction to continue
    while(uI != '\n'){
        cin.get(uI);
    }
    //our keys being passed in
    if(decryptKey){
        while(true){
            getline(decryptKey,fileInput);
            int fSize = fileInput.size();
            for(int i = 0; i < fSize; i++){
                decrypted1.push_back(fileInput[i]);
            }
            //pushing to a vector of vectors
            decryptedBig.push_back(decrypted1);
            // clearing the vector before next start of loop
            decrypted1.clear();
            if(decryptKey.eof()){
                cout << "File has been read successfully!" << endl;
                decryptKey.close();
                break;
            }

        }
    }
    //error handling
    else{
        cout << "Error reading file" << endl;
    }
    if(encryptedFile){
            string fileInput = "";
        while(true){
            getline(encryptedFile,fileInput);
            encrypted.push_back(fileInput);
            if(encryptedFile.eof()){
                break;
            }
        }
        cout << "File successfully read!" << endl;
    }else{
        cout << "Error Reading File" << endl;
    }
    int eSize = encrypted.size();
    for (int j = 97; j < 123; j++){ // ascii number count for loop
        int lcount = 0; // creating our counter
        for(int i = 0; i < eSize; i++){ // takes the size of the vector with strings from file
            string text = encrypted[i]; // passes the string that is at i
            int tSize = text.size(); // takes size to create for loop
            for(int ii = 0; ii < tSize; ii++){ // for loop to look at each char in the string
                if(text[ii] == j || text[ii] == (j-32)){ // if the char at ii is equal to an ascii char then increase lcount
                    lcount ++;
                }
            }
        }
        vcount.push_back(lcount); // after going through the whole vector push our count of letters to our vector
    }

    int countSize = vcount.size();
    int totalChars = 0;
    for (int i = 0; i < countSize; i++){
        totalChars = totalChars + vcount[i];
    }
    cout << "Total chars in our message is :" << totalChars << endl;
    //created a vector of doubles to post % of chars in file
    for(int i = 0; i < countSize; i++){
        double temp = vcount[i];
        double temp2 = temp/totalChars;
        temp2 = temp2 * 100;
        freqOfChars.push_back(temp2);
    }
    int sortSize = vchar.size();
    for(int i = 0; i < sortSize; i++){
        EncLet a;
        a.f = freqOfChars[i];
        a.letter = vchar[i];
        sortVector.push_back(a);
    }
    // printing out our letters before sort
    for(int i = 0; i < sortSize; i++){
            cout << sortVector[i].letter << " Made up this percent of the files letters: " << sortVector[i].f << endl;
    }
    cout << "Now we can sort the analysis!" << endl;
    cout << endl;
    //sort algorithm using a lamnda function to get the highest percentage of chars to the top of the vector
    sort (sortVector.begin(), sortVector.end(), [](const EncLet & lh, const EncLet & rh){
                return lh.f > rh.f;
          });
    //printing our letters after sorting
    for(int i = 0; i < sortSize; i++){
            cout << sortVector[i].letter << " Made up this percent of the files letters: " << sortVector[i].f << endl;
    }
    // printing out to a new file line by line based off keys pre made
    cout << "Based on the Frequency Analysis, we will now try several keys generated based on studies of English" << endl;
    int deSize = decryptedBig.size();
    decipher.open("decrypted.txt");
    if(decipher.is_open()){
            for(int d = 0; d < deSize; d++){ // first loop to count how many keys are in the system
                decipher << "Based on frequency analysis using this key we deciphered the file" << endl;
                decipher << "Key #:" << d+1 << endl;
                int kk = decryptedBig[d].size();
                for (int k = 0; k < kk; k++){ // then the size of each key saved in the vector
                    decipher << sortVector[k].letter << " became " << decryptedBig[d][k] << "  ";
                }
                decipher << endl;
                decipher << endl;
                for(int l = 0; l < eSize; l++){ // range based loop for the size of the encrypted vector
                    string change = encrypted[l]; // passing each line to the string
                    int thing; // this is to count if we replaced a letter or not, important for placing spaces and commas
                    int cSize = change.size();
                    for (int k = 0; k < cSize; k++){ // size of the string
                        thing = 0; // each time we try to replace a letter thing set to 0

                        for (int i =0; i < sortSize; i++){ // checks all chars in sort against the letter we are at in string.
                            if(change[k] == sortVector[i].letter){
                                decipher << decryptedBig[d][i];
                                thing++; // increment if letter changed
                            }
                        }
                        if(thing != 1){ // if not one then a char not found in the key was located and is to be printed out
                        decipher << change[k] ;
                        }
                    }
                    decipher << endl;
                }
                decipher << endl;
                decipher << endl;
                cout << "Trying a new key now!"  << endl;
            }
    }
    decipher.close();
    cout << "File Closed, check out what we got as a decryption!" << endl;
    cout << "Go check out the decryption file the key used to decipher is above the text!" << endl;
    cout << "Good luck breaking your cipher the rest of the way!" << endl;
    return 0;
}
