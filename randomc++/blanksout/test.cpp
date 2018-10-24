
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int main(){
    string temp1;
    		string userId;
    	string temp;
    cout << "please make input" << endl;
    getline(cin, userId,' ');
    getline(cin, temp);
	while(!cin){


		int userNumber = 0;

		cout << userId << endl;
		int size = temp.size();
		for(int i = 0, ii = size; i < size; i++){
			userNumber += (temp[--ii]-'0')*pow(10,i);
		}

		if (userNumber == 42){
			cout << userId << " is awesome" << endl;
		}
		return 0;
	}

	}
