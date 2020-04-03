// C++ implementation for representing 
// each word in a sentence as sum of 
// ASCII values of each word 
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

// Function to compute the sum of ASCII values of each 
// word separated by a space and return the total sum 
// of the ASCII values, excluding the space. 
long long int ASCIIWordSum(string str, 
						vector<long long int>& sumArr) 
{ 

	int l = str.length(); 
	int sum = 0; 
	long long int bigSum = 0L; 
	for (int i = 0; i < l; i++) { 

		// Separate each word by 
		// a space and store values 
		// corresponding to each word 
		if (str[i] == ' ') { 

			bigSum += sum; 
			sumArr.push_back(sum); 
			sum = 0; 
		} 
		else

			// Implicit type casting 
			sum += str[i];		 
	} 

	// Storing the value of last word 
	sumArr.push_back(sum); 
	bigSum += sum; 
	return bigSum; 
} 
// Driver function 
int main() 
{ 
	string str = "GeeksforGeeks a computer science "
				"portal for Geeks"; 
	vector<long long int> sumArr; 

	// Calling function 
	long long int sum = ASCIIWordSum(str, sumArr); 

	cout << "Sum of ASCII values:" << std::endl; 
	for (auto x : sumArr) 
		cout << x << " "; 
	cout << endl << "Total sum -> " << sum; 
	return 0; 
} 
