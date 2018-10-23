#include <string.h>
#include <stdio.h>
#define RANGE 26 //this can be changed to 255 and the if loop in the while can be taken out to get all ascii values 0-255

// I decided to only sort a-z assuming char arr[] would only include letters (no punctuation) but the range can be changed to 255 and the 
//if loop can be taken out of the while loop to create a function that'll sort all 255 ascii characters. A commented out version shows how this can be done.
using namespace std;

void countSort(char arr[])
{
	std::vector<char> letters(RANGE);
	std::vector<int> counts (RANGE);
	std::fill(counts.begin, counts.end(), 0); //fill vector with 0 initializing count of each character	
	
	for(int i = 0; i < RANGE; i++) //this will just store 
	{
		int temp = i + 65;
		letters[i] = (char)temp;
	}
	char* p = &arr[0];
	while(*p != '\0')
	{
		int temp = (int)*p;                // gives the ascii value of the letter
		if(temp > 90) 
		{
			temp = temp - 32;            //all letters have ascii value. 122 is Z and 90 is z, so two letters with a 32 difference in value are the same letter. We're assuming only letters are being included in this 
		}
		
		int index = temp - 65;         // A is 65, to store it as the first letter in counts, we must store that count in counts[0]
		counts[index] += 1;            // increase count of that value;
		++p;
	}
	
	cout << letters << endl;
	cout << counts << endl;
}
	/* 
	This section provides the loops you'll want to include if you want to store the sorted counts for all 255 ascii values. Just replace the for loop and while loop with the loops below. 
	Keep the initialization of the vectors (Lines 10-12) and change the definition of RANGE to 255 (Line 3). 
	
	///////////////////////////////////////
	
	for(int i  = 0; i < RANGE; i++)
	{
		letters[i] = (char)i;
	}
	
	char* p = &arr[0];
	while (*p != '\0')
	{
		int index = (int)*p;
		counts[index] += 1;
		++p;
	}

*/
