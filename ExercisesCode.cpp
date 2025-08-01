#include <algorithm>
#include <ranges>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <complex>

using Complex = std::complex<double>; //It tells the compiler: //“Whenever I write Complex, I really mean std::complex<double>.”
constexpr char REAL2 = 'r';
constexpr char IMAG2 = 'i';
constexpr char ZERO1 = 'z';
constexpr char COMPLEX2 = 'c';
constexpr double negSign{ -1.0 };
constexpr double posSign{  1.0 };


Complex simplifyDiscriminant(Complex a , Complex b , Complex c)
{
	/*std::complex<double> aAndcRes{};
	std::complex<double> bSquared = b * b;
	aAndcRes = 4.0 * (a * c);
	return bSquared - aAndcRes;*/
	//removed and changed to a one line return statemnt
	return b * b - 4.0 * (a * c);
}
char realComplexImagZero(Complex discriminant) // take the result of of simplpifydisciminant
{
	if (discriminant.imag() != 0)
	{
		return COMPLEX2;
	}
	else if (discriminant.real() > 0)
	{
		return REAL2;
	}
	else if (discriminant.real() <0)
	{
		return IMAG2;
	}
}
Complex solveForX(Complex a, Complex b, Complex c,double sign)
{
	Complex discriminant = simplifyDiscriminant(a, b, c);
	//realComplexZero(discriminant);
	Complex sqrtDiscriminant{ std::sqrt(discriminant) };
	return ( - b + sign * sqrtDiscriminant ) / 2.0 * a;
}
Complex solveForX1(Complex a, Complex b, Complex c)
{
	Complex discriminant = simplifyDiscriminant(a, b, c);
	//realComplexZero(discriminant);
	Complex negB{ -b };
	Complex sqrtDiscriminant{std::sqrt(discriminant)};
	Complex numerator{ negB + sqrtDiscriminant };
	Complex denominator{ 2.0 * a };
	Complex x1 = numerator / denominator;
	
	
	return x1;
}
Complex solveForX2(Complex a, Complex b, Complex c)
{
	Complex discriminant = simplifyDiscriminant(a, b, c);
	//realComplexZero(discriminant);
	Complex negB{ -b };
	Complex sqrtDiscriminant{ std::sqrt(discriminant) };
	Complex numerator{ negB - sqrtDiscriminant };
	Complex denominator{ 2.0 * a };
	Complex x2 = numerator / denominator;


	return x2;
}
int main()
{
	//solve quadratic equations ax2 + bx + c = 0.
	Complex a{};
	Complex b{};
	Complex c{};


	Complex discriminant{};
	Complex x1{};
	Complex x2{};

	std::cout << "Enter the coefficients 'a', 'b' and 'c' as double to get the results of a quadratic equation (Followed by 'Enter')" << '\n';
	std::cin >> a >> b >> c;
	//The solution of 1x ^ 2 + 3x + 1 = 0 is real
	discriminant = simplifyDiscriminant(a, b, c);
	char solutionType = realComplexImagZero(discriminant);
	if (solutionType == REAL2)
	{
		std::cout << "the solution of: " << a.real() << "x^2" << '+' << b.real() << "x " << '+' << c.real() << " is real" << '\n';
		x1 = solveForX(a, b, c,posSign );
		x2 = solveForX(a, b, c,negSign);

		std::cout << "x1 = " << x1.real() << '\n';
		std::cout << "x2 = " << x2.real() << '\n';
	}
	else if (solutionType == COMPLEX2)
	{
		std::cout << "the solution of: " << a.real() << "x^2" << '+' << b.real() << "x " << '+' << c.real() << " is Complex" << '\n';
		x1 = solveForX(a, b, c, posSign);
		x2 = solveForX(a, b, c, negSign);

		std::cout << "x1 = " << x1 <<  '\n';
		std::cout << "x2 = " << x2 <<  '\n';
	}
	else if (solutionType == IMAG2)
	{
		std::cout << "the solution of: " << a << "x^2" << '+' << b << "x " << '+' << c << " is imaginary" << '\n';
		x1 = solveForX(a, b, c, posSign);
		x2 = solveForX(a, b, c, negSign);

		std::cout << "x1 = " << x1 << '\n';
		std::cout << "x2 = " << x2 << '\n';
	}
	else if (solutionType == ZERO1)
	{
		std::cout << "the solution of: " << a.real() << "x^2" << '+' << b.real() << "x " << '+' << c.real() << "is real with only solution for x" << '\n';
		x1 = solveForX(a, b, c,posSign);

		std::cout << "x1 = " << x1.real() << '\n';
	}
	
		
}




//12
//std::vector<int> primes;
//bool isThisPrime(int val)
//{
//	//This function will:
//
//		// Check if the number is ≤ 1 → not prime
//
//     //Loop through all stored prime numbers,
//     //but only up to those ≤ sqrt(val),
//     //because any factor larger than sqrt(val)
//    //would have a corresponding smaller factor already checked.
//
//    //If divisible by any of them → not prime
//    //If no divisors found → it's prime
//
//	if (val <= 1)
//	{
//		return false;
//	}
//
//	for (int i = 0; i < primes.size() && primes[i] <= std::sqrt(val);++i)
//	{
//		if (val % primes[i] == 0) // if theres  isnt a reminder , perfect divison resulting in a whole number = not prime.
//		{
//			return false;
//		}
//	}
//	// if none of the above come true then we return true.
//	return true;
//}
//
//int main()
//{
//	//12 , prime numbers
//	primes.push_back(2); // intializse the vector with the smallest prime number
//
//	for (int i = 3/*we start from the next number after the smallest prime */;i <= 100;++i)
//	{
//		if (isThisPrime(i))
//		{
//			// if i is prime we store it in our prime vector for the next check
//			primes.push_back(i);
//		}
//	}
//
//	for (int i = 0; i < primes.size();i++)
//	{
//		std::cout << primes[i] << ',';
//	}
//}



// 13 Sieve of Eratosthenes.,
//std::vector<bool> primes;
//
//void populateVectorSieve(int val) // we input a size for the vector of prime number that we want to check up to and populate it with true(unamarked) for all numbers
//{
//	primes.clear(); // if it will be called more then once
//	for (int i = 0;i <= val;++i)
//	{
//		primes.push_back(true);
//	}
//
//	primes[0] = primes[1] = false; // i set the first two cells ( 0 and 1 ) as false . as a prime has to be bigger then one.
//
//}
//
//int main()
//{
//	//13 , prime numbers sieve of eras
//	int limit{ 100 };
//	int countOuter{};
//	int countInner{};
//
//	populateVectorSieve(limit);
//	for (int i = 2;i <= sqrt(limit); ++i)
//	{
//		if (primes[i])
//		{
//			// https://docs.google.com/document/d/1bYKBoiEjSStqcgXUloQWNKK0aFW2nS-cmLbLnyzvMMY/edit?tab=t.0
//				// Start from i*i because smaller multiples were already handled
//				//Why is i * i the first new multiple?
//				// Because:
//				// Any number less than i* i that is a multiple of i must have already been marked by a smaller prime.
//
//			//	Suppose i = 5:
//					 //2 * 5 = 10 → already marked when i = 2
//					//3 * 5 = 15 → already marked when i = 3
//					// 4 * 5 = 20 → already marked when i = 2
//					//5 * 5 = 25 → first multiple of 5 that hasn't been marked yet
//					//✅ So start at j = 25 → i * i
//					//Then mark 30, 35, 40, … by j += i
//
//			for (int j = i * i; j <= limit;j += i) //Starting at i * i, keep adding i to get the next multiple of i — until you pass the limit
//			{
//				if (primes[j])  // Only mark and count if this multiple hasn't been marked yet
//				{
//					primes[j] = false;
//					countInner++;
//					std::cout << "Marking " << j << " as not prime\n";
//				}
//			}
//		}
//		countOuter++;
//	}
//	std::cout << "number of times outer loop ran:" << countOuter << ":\n";
//	std::cout << "number of times inner loop ran:" << countInner << ":\n";
//
//	std::cout << "Prime numbers up to " << limit << ":\n";
//	for (int i = 2; i < primes.size(); ++i) {
//		if (primes[i]) // print all "unmarked"(prime) cells
//		{
//			std::cout << i << " ";
//		}
//	}
//}

// 14 
//std::vector<bool> primes;
//
//void populateVectorSieve(int val) // we input a size for the vector of prime number that we want to check up to and populate it with true(unamarked) for all numbers
//{
//	primes.clear(); // if it will be called more then once
//	for (int i = 0;i <= val;++i)
//	{
//		primes.push_back(true);
//	}
//
//	primes[0] = primes[1] = false; // i set the first two cells ( 0 and 1 ) as false . as a prime has to be bigger then one.
//
//}
//
//int main()
//{
//
//	int limit{ 100 };
//	int countOuter{};
//	int countInner{};
//	int targetPrimes{};
//
//	populateVectorSieve(limit);
//	for (int i = 2;i <= sqrt(limit); ++i)
//	{
//		if (primes[i])
//		{
//			// https://docs.google.com/document/d/1bYKBoiEjSStqcgXUloQWNKK0aFW2nS-cmLbLnyzvMMY/edit?tab=t.0
//				// Start from i*i because smaller multiples were already handled
//				//Why is i * i the first new multiple?
//				// Because:
//				// Any number less than i* i that is a multiple of i must have already been marked by a smaller prime.
//
//			//	Suppose i = 5:
//					 //2 * 5 = 10 → already marked when i = 2
//					//3 * 5 = 15 → already marked when i = 3
//					// 4 * 5 = 20 → already marked when i = 2
//					//5 * 5 = 25 → first multiple of 5 that hasn't been marked yet
//					//✅ So start at j = 25 → i * i
//					//Then mark 30, 35, 40, … by j += i
//
//			for (int j = i * i; j <= limit;j += i) //Starting at i * i, keep adding i to get the next multiple of i — until you pass the limit
//			{
//				if (primes[j])  // Only mark and count if this multiple hasn't been marked yet
//				{
//					primes[j] = false;
//					countInner++;
//					//std::cout << "Marking " << j << " as not prime\n";
//				}
//			}
//		}
//		countOuter++;
//	}
//	std::cout << "number of times outer loop ran:" << countOuter << ":\n";
//	std::cout << "number of times inner loop ran:" << countInner << ":\n";
//
//	std::cout << "Enter how many prime numbers you want to find (e.g., 5): " << '\n';
//	while (std::cin >> targetPrimes)
//	{
//		if (targetPrimes < 2 || targetPrimes > 100)
//		{
//			std::cout << "invalid number, try again" << '\n';
//			continue;
//		}
//		break; // finish  input loop if valid input
//	}
//
//	std::cout << " the first " << targetPrimes << " primes , are:" << '\n';
//	int primesPrintCount{ 0 };
//	for (int i = 2; primesPrintCount < targetPrimes;++i) // start at 2 bcz first two indexs primes[0] and primes[1] are always false
//	{
//		//we loop through the primes vector , and every time we land on one we print it , and add 1 to the primesPrintCount , once we printed the target amount we finish
//		if (primes[i])
//		{
//			std::cout << i << ',';
//			primesPrintCount++;
//		}
//	}
//
//
//}


//14 , find mode for int seqeunece
//int getNumber()
//{
//	int numberInput{};
//	bool goodInput = true;
//	std::cout << "enter a number like 1 , 2 ,3 or CTRL Z to stop" << '\n';
//	while (goodInput)
//	{
//		if (std::cin >> numberInput && numberInput > 0)
//		{
//			return numberInput;
//		}
//		else if (std::cin.eof())
//		{
//			std::cout << "stopped taking input" << '\n';
//			return -1;
//		}
//		else
//		{
//			std::cout << "input invalid , enter a number like 1 , 2 ,3 " << '\n';
//			std::cin.clear();                     // clear the fail state
//			std::cin.ignore(10000, '\n');         // discard invalid input		
//		}
//	}
//}
//
//int findMode(std::vector<int> seq)
//{
//
//	int mode = seq[0];
//	int MaxModeCount{};
//	int count{};
//
//	for (int i = 0; i < seq.size();++i)
//	{
//		count = 0;
//		for (int j = 0;j < seq.size();++j)
//		{
//			if (seq[i] == seq[j])
//			{
//				count++;
//			}
//		}
//
//		if (count > MaxModeCount)
//		{
//			MaxModeCount = count;
//			mode = seq[i];
//		}
//	}
//
//	return mode;
//	// Find the mode (most frequent number) in the sequence
//// Step-by-step explanation:
//// We loop through each number in the vector (outer loop)
//// For each number, we loop again to count how many times it appears (inner loop)
//// If this count is higher than the highest we've seen (MaxModeCount),
//// we update the mode to this number and save the new highest count
//
//// Example: for sequence = {3, 5, 3, 2, 5, 5, 1}
//// - 3 appears 2 times → mode = 3, MaxModeCount = 2
//// - 5 appears 3 times → mode = 5, MaxModeCount = 3 (updated)
//// - 2 and 1 appear once → not more than 3, so mode stays 5
//}
//
//int main()
//{
//	//find mode in a sequence of positive ints
//
//	std::vector<int> sequence{};
//	int input{};
//	std::cout << "start the sequnce now: , finished entering numbers ? enter CTRL Z to stop." << '\n';
//	while (true)
//	{
//		input = getNumber();
//		if (input == -1)
//		{
//			break;
//		}
//		else
//		{
//			sequence.push_back(input);
//		}
//	}
//
//
//	int mode = findMode(sequence);
//
//
//
//
//	std::cout << "your seqeunce was:" << '\n';
//	for (int x : sequence)
//	{
//		std::cout << x << ',';
//
//	}
//
//	std::cout << "mode is: " << mode << '\n';
//
//
//
//}


//16 find mode , min and max of string seqeunce
//std::string FindMaxString(std::vector<std::string> stringList)
//{
//	std::string errorEmptyList{ "List is empty cant check" };
//	std::string maxString{};
//	if (stringList.empty())
//	{
//		return errorEmptyList;
//	}
//	else
//	{
//		maxString = stringList[0];
//		for (int i = 0;i < stringList.size();++i)
//		{
//			if (stringList[i] > maxString)
//			{
//				maxString = stringList[i];
//			}
//		}
//		return maxString;
//	}
//
//
//
//}
//std::string FindMinString(std::vector<std::string> stringList)
//{
//	std::string errorEmptyList{ "List is empty cant check" };
//	std::string minString{};
//	if (stringList.empty())
//	{
//		return errorEmptyList;
//	}
//	else
//	{
//		minString = stringList[0];
//		for (int i = 0;i < stringList.size();++i)
//		{
//			if (stringList[i] < minString)
//			{
//				minString = stringList[i];
//			}
//		}
//		return minString;
//	}
//
//
//
//}
//std::string getString()
//{
//	std::string Str{};
//	std::string terminate{ "TERMINATE" }; // used for loops to stop taking input withou CTRL Z .
//	std::cout << " enter a word, or TERMINATE to stop." << '\n';
//	if (std::cin >> Str
//		)
//	{
//		return Str;
//
//	}
//	else
//	{
//		return terminate;
//	}
//}
//
//std::string findMode(std::vector<std::string> seq)
//{
//
//	std::string mode = seq[0];
//	int MaxModeCount{};
//	int count{};
//
//	for (int i = 0; i < seq.size();++i)
//	{
//		count = 0;
//		for (int j = 0;j < seq.size();++j)
//		{
//			if (seq[i] == seq[j])
//			{
//				count++;
//			}
//		}
//
//		if (count > MaxModeCount)
//		{
//			MaxModeCount = count;
//			mode = seq[i];
//		}
//	}
//	if (MaxModeCount == 1) // if count was not greater then 1 , that means no word appeared more then once, therefor no mode.
//	{
//		std::cout << "all words appear only once , there is no mode." << '\n';
//		return "NO MODE";
//	}
//	return mode;
//	// Find the mode (most frequent number) in the sequence
//// Step-by-step explanation:
//// We loop through each number in the vector (outer loop)
//// For each number, we loop again to count how many times it appears (inner loop)
//// If this count is higher than the highest we've seen (MaxModeCount),
//// we update the mode to this number and save the new highest count
//
//// Example: for sequence = {3, 5, 3, 2, 5, 5, 1}
//// - 3 appears 2 times → mode = 3, MaxModeCount = 2
//// - 5 appears 3 times → mode = 5, MaxModeCount = 3 (updated)
//// - 2 and 1 appear once → not more than 3, so mode stays 5
//}
//
//int main()
//{
//	//find mode in a sequence of strings
//	std::vector<std::string> sequence{};
//	bool keepRunning = true;
//	std::string input{};
//	std::cout << "start the sequnce now: , finished entering numbers ? enter CTRL Z to stop." << '\n';
//
//
//	while (true)
//	{
//		input = getString();
//		if (input == "TERMINATE")
//		{
//			break;
//		}
//		else
//		{
//			sequence.push_back(input);
//		}
//	}
//
//	std::string mode = findMode(sequence);
//
//
//	std::cout << "your seqeunce was:" << '\n';
//	for (std::string x : sequence)
//	{
//		std::cout << x << ',';
//
//	}
//
//	std::cout << "mode is: " << mode << '\n';
//	std::cout << "max is: " << FindMaxString(sequence) << '\n';
//	std::cout << "min is: " << FindMinString(sequence) << '\n';
//
//
//	//what did i learn from excersice 16? 
//	//1.finding the mode , min and max of a string seqeunece is almost the same as numbers,
//	//2. i used a Terminate word to stop input , if the return result was the terminate variable then the loop would stop and we would move on
//	//3. i succesfully broke down each needed action into a function.//
//}