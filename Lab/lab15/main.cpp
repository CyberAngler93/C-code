//Matthew Perry
//cs202 Lab15 stl Algorithms
//Prof Long
//11/15/18

#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <thread>


int main(){
	//creating a vector with 1 to 9 inside
	std::vector<int> myVector = {1,2,3,4,5,6,7,8,9,10};
	//creating a random device
	std::random_device myRandom;
	//using the mersenne twister engine algorithm to make a random function
	std::mt19937 generate(myRandom());
	//#pragma omp parallel for // tried using threads for speed, we got alot slower in total time.
			//running until we arrive back at a sorted vector. random shuffle until sorted
			int testNumber = 0;
			int x = 0;
			//trying to get a shuffle and sort in 10 or less tries!
			while(x!=1){
				testNumber++;
				std::cout << "Running Test #" << testNumber << "\n";
				for(auto j = 0; j < 10; j++){
					//using the shuffle algorithm on my vector
					std::shuffle(myVector.begin(), myVector.end(), generate);
					if(std::is_sorted(myVector.begin(),myVector.end())){
						std::cout << "sorted in 10 shuffles of less. " << j << " was sorted on the " << testNumber << "\n";
						x = 1;
					}
					//using the is_sorted algorithm to check if the shuffle got back to 1-9 order
				}
			}
 return 0;
}
