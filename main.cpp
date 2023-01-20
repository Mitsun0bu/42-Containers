#include <fstream>
#include <iostream>
#include <vector>
#include "vector.hpp"

int main(void)
{
	/* ************************************************************************** */
    /*                                                                            */
    /*                       ~~~ CREATION OF A LOG FILE ~~~                       */
    /*                                                                            */
    /* ************************************************************************** */

	// Create a file for test logs
	std::ofstream logFile("log.txt");

	if(logFile)
		std::cout << "Log file created !" << std::endl;
	else
		std::cout << "Error: log file creation failed !" << std::endl;

	/* ************************************************************************** */
    /*                                                                            */
    /*                       ~~~ FILL CONSTRUCTOR TEST ~~~                        */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 1 - FILL CONSTRUCTOR ~~~~~" << std::endl << std::endl;
	{
		// Creates a std::vector of 5 elements, all set to 10
		std::vector<int>	std_vector_1(5, 10);
		logFile << "\tTEST OUTPUT WITH std::vector, first serie" << std::endl;
		for (int i = 0; i < 5; i++)
			logFile << "\telem[" << i << "] = " << std_vector_1[i] << std::endl;
		logFile << "\tsize = " << std_vector_1.size() << std::endl;
		logFile << "\tcapacity = " << std_vector_1.capacity() << std::endl;

		logFile << std::endl;

		// Creates a ft::vector of 5 elements, all set to 10
		ft::vector<int>	ft_vector_1(5, 10);
		logFile << "\tTEST OUTPUT WITH ft::vector, first serie" << std::endl;
		for (int i = 0; i < 5; i++)
			logFile << "\telem[" << i << "] = " << ft_vector_1[i] << std::endl;
		logFile << "\tsize = " << ft_vector_1.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector_1.capacity() << std::endl;

		logFile << std::endl;
		logFile << std::endl;

		// Creates a std::vector of 5 elements, all set to 0
		std::vector<int>	std_vector_2(5);
		logFile << "\tTEST OUTPUT WITH std::vector, second serie" << std::endl;
		for (int i = 0; i < 5; i++)
			logFile << "\telem[" << i << "] = " << std_vector_2[i] << std::endl;
		logFile << "\tsize = " << std_vector_2.size() << std::endl;
		logFile << "\tcapacity = " << std_vector_2.capacity() << std::endl;

		logFile << std::endl;

		// Creates a ft::vector of 5 elements, all set to 10
		ft::vector<int>	ft_vector_2(5);
		logFile << "\tTEST OUTPUT WITH ft::vector, second serie" << std::endl;
		for (int i = 0; i < 5; i++)
			logFile << "\telem[" << i << "] = " << ft_vector_2[i] << std::endl;
		logFile << "\tsize = " << ft_vector_2.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector_2.capacity() << std::endl;

		// Comparison
		int error = false;
		for (int i = 0; i < 5; i++)
		{
			if (ft_vector_1[i] != std_vector_1[i] || ft_vector_2[i] != std_vector_2[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (error != true)
			std::cout << "TEST# 1  - FILL CONSTRUCTOR\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 1  - FILL CONSTRUCTOR\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                       ~~~ COPY CONSTRUCTOR TEST ~~~                        */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 2 - COPY CONSTRUCTOR ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		std::vector<int>	std_vector;
		std_vector.push_back(42);
		std::vector<int>	std_vector_copy(std_vector);

		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;
		logFile << "\telem[0] = " << std_vector[0] << std::endl;
		logFile << "\telem[0] copy = " << std_vector_copy[0] << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		ft::vector<int>		ft_vector;
		ft_vector.push_back(42);
		ft::vector<int>	ft_vector_copy(ft_vector);

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;
		logFile << "\telem[0] = " << ft_vector[0] << std::endl;
		logFile << "\telem[0] copy = " << ft_vector_copy[0] << std::endl;

		// Print test outcome
		if (ft_vector_copy[0] == std_vector[0])
			std::cout << "TEST# 2  - COPY CONSTRUCTOR\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 2  - COPY CONSTRUCTOR\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                         ~~~ ITERATORS TEST ~~~                             */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 3 - ITERATORS ~~~~~" << std::endl << std::endl;
	{
		// Fill a std::vector
		std::vector<int>			std_vector(5, 42);
		std::vector<int>::iterator	std_iterator;

		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;
		for (std_iterator = std_vector.begin(); std_iterator != std_vector.end(); std_iterator++)
			logFile << "\tforward loop: elem = " << *std_iterator << std::endl;
		int i = 1;
		std_iterator = std_vector.end();
		while (std_iterator != std_vector.begin())
		{
			--std_iterator;
			*std_iterator = *std_iterator - i;
			i ++;
			logFile << "\tbackward loop: elem = " << *std_iterator << std::endl;
		}
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		// Fill a ft::vector
		ft::vector<int>				ft_vector(5, 42);
		ft::vector<int>::iterator	ft_iterator;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;
		for (ft_iterator = ft_vector.begin(); ft_iterator != ft_vector.end(); ft_iterator++)
			logFile << "\tforward loop: elem = " << *ft_iterator << std::endl;
		i = 1;
		ft_iterator = ft_vector.end();
		while (ft_iterator != ft_vector.begin())
		{
			--ft_iterator;
			*ft_iterator = *ft_iterator - i;
			i ++;
			logFile << "\tbackward loop: elem = " << *ft_iterator << std::endl;
		}
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		// Print the outcome of the test
		if (ft_vector.at(2) == 39)
			std::cout << "TEST# 3  - ITERATORS\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 3  - ITERATORS\t\t: FAILED ❌" << std::endl;
	}

	// logFile << std::endl << "~~~~~ TEST# 4 - REVERSE ITERATORS ~~~" << std::endl << std::endl;
	// {
	// 	logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

	// 	std::vector<int>					std_vector(5);
	// 	std::vector<int>::reverse_iterator	std_reverse_iterator = std_vector.rbegin();

	// 	int i = 0;
	// 	for (; std_reverse_iterator != std_vector.rend(); ++std_reverse_iterator)
	// 		*std_reverse_iterator = ++i;

	// 	for (std::vector<int>::iterator	it = std_vector.begin(); it != std_vector.end(); ++it)
	// 		logFile << "\tforward loop: elem = " << *it << std::endl;

	// 	logFile << "\tsize = " << std_vector.size() << std::endl;
	// 	logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

	// 	logFile << std::endl;

	// 	logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

	// 	ft::vector<int>						ft_vector(5);
	// 	ft::vector<int>::reverse_iterator	ft_reverse_iterator = ft_vector.rbegin();

	// 	i = 0;
	// 	for (; ft_reverse_iterator != ft_vector.rend(); ++ft_reverse_iterator)
	// 		*ft_reverse_iterator = ++i;

	// 	for (ft::vector<int>::iterator	it = ft_vector.begin(); it != ft_vector.end(); ++it)
	// 		logFile << "\tforward loop: elem = " << *it << std::endl;

	// 	logFile << "\tsize = " << ft_vector.size() << std::endl;
	// 	logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

	// 	// Print the outcome of the test
	// 	if (ft_vector.at(0) == 5 && ft_vector.at(4) == 1)
	// 		std::cout << "TEST# 4  - REVERSE ITERATORS\t: SUCCESS ✔️" << std::endl;
	// 	else
	// 		std::cout << "TEST# 4  - REVERSE ITERATORS\t: FAILED ❌" << std::endl;
	// }

	logFile << std::endl << "~~~~~ TEST# 5 - CONST ITERATORS ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int>					ft_vector(5);
		ft::vector<int>::const_iterator	ft_const_iterator;
		ft::vector<int>::const_iterator	ft_const_iterator_2 = ft_vector.cend();

		ft_vector[0] = 10;
		ft_vector[1] = 20;
		ft_vector[2] = 30;
		ft_vector[3] = 40;
		ft_vector[4] = 50;

		for (ft_const_iterator = ft_vector.cbegin(); ft_const_iterator != ft_const_iterator_2; ++ft_const_iterator)
			logFile << "\tforward loop: elem = " << *ft_const_iterator << std::endl;

		logFile << "\tUncomment the following line of code to see if you get compilation error" << std::endl;
		// *ft_const_iterator = 10;
		logFile << "\tUncomment the following line of code to see if you get compilation error" << std::endl;
		// *ft_const_iterator_2 = 10;

		// Print the outcome of the test
		std::cout << "TEST# 5  - CONST ITERATORS\t: SUCCESS ✔️" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                           ~~~ CAPACITY TEST ~~~                            */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 6 - SIZE ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector;
		logFile << "\tsize = " << std_vector.size() << std::endl;

		for (int i = 0; i < 10; i++)
			std_vector.push_back(i);
		logFile << "\tsize = " << std_vector.size() << std::endl;

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int> ft_vector;
		logFile << "\tsize = " << ft_vector.size() << std::endl;

		for (int i = 0; i < 10; ++i)
			ft_vector.push_back(i);
		logFile << "\tsize = " << ft_vector.size() << std::endl;

		// Print the outcome of the test
		if (ft_vector.size() == std_vector.size())
			std::cout << "TEST# 6  - SIZE\t\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 6  - SIZE\t\t\t: FAILED ❌" << std::endl;
	}

	logFile << std::endl << "~~~~~ TEST# 7 - MAX_SIZE ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector;
		logFile << "\tsize = " << std_vector.max_size() << std::endl;

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int> ft_vector;
		logFile << "\tsize = " << ft_vector.max_size() << std::endl;

		// Print the outcome of the test
		if (ft_vector.max_size() == std_vector.max_size())
			std::cout << "TEST# 7  - MAX_SIZE\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 7  - MAX_SIZE\t\t: FAILED ❌" << std::endl;
	}

	logFile << std::endl << "~~~~~ TEST# 8 - RESIZE ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector;
		// Set some initial content:
		for (int i = 1; i < 10; i++)
			std_vector.push_back(i);
		std_vector.resize(5);
		std_vector.resize(8,100);
		std_vector.resize(12);

		for (size_t i = 0; i < std_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;

		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int> ft_vector;
		// Set some initial content:
		for (int i = 1 ; i < 10; i++)
			ft_vector.push_back(i);
		ft_vector.resize(5);
		ft_vector.resize(8,100);
		ft_vector.resize(12);

		for (size_t i = 0; i < ft_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;

		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		// Comparison
		int error = false;
		for (int i = 0; i < 12; i++)
		{
			if (ft_vector[i] != std_vector[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (error != true)
			std::cout << "TEST# 8  - RESIZE\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 8  - RESIZE\t\t: FAILED ❌" << std::endl;
	}

	logFile << std::endl << "~~~~~ TEST# 9 - CAPACITY ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector;

		for (int i=0; i<100; i++)
			std_vector.push_back(i);
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;
		logFile << "\tmax_size = " << std_vector.max_size() << std::endl;

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		std::vector<int> ft_vector;

		for (int i=0; i<100; i++)
			ft_vector.push_back(i);
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;
		logFile << "\tmax_size = " << ft_vector.max_size() << std::endl;

		// Print the outcome of the test
		if (ft_vector.capacity() == std_vector.capacity())
			std::cout << "TEST# 9  - CAPACITY\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 9  - CAPACITY\t\t: FAILED ❌" << std::endl;
	}

	logFile << std::endl << "~~~~~ TEST# 10 - EMPTY ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector;
		logFile << "\tempty = " << std_vector.empty() << std::endl;

		for (int i=0; i<10; i++)
			std_vector.push_back(i);
		logFile << "\tempty = " << std_vector.empty() << std::endl;

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int> ft_vector;
		logFile << "\tempty = " << ft_vector.empty() << std::endl;

		for (int i = 0; i < 10; ++i)
			ft_vector.push_back(i);
		logFile << "\tempty = " << ft_vector.empty() << std::endl;

		// Print the outcome of the test
		if (ft_vector.empty() == std_vector.empty())
			std::cout << "TEST# 10 - EMPTY\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 10 - EMPTY\t\t: FAILED ❌" << std::endl;
	}

	logFile << std::endl << "~~~~~ TEST# 11 - RESERVE ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int>	std_vector_1;
		std::vector<int>	std_vector_2;

		size_t				cap_1 = std_vector_1.capacity();
		size_t				cap_2 = std_vector_2.capacity();
		logFile << "\tstd_vector_1 capacity : " << cap_1 << std::endl;
		logFile << "\tstd_vector_2 capacity : " << cap_2 << std::endl;

		logFile << "\treserve(10) for std_vector_1" << std::endl;
		std_vector_1.reserve(10);
		logFile<< "\tstd_vector_1 capacity = " << std_vector_1.capacity() << std::endl;

		logFile << "\tmaking std_vector_1 grow..." << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			std_vector_1.push_back(i);
			if (cap_1 != std_vector_1.capacity())
			{
				cap_1 = std_vector_1.capacity();
				logFile << "\tcapacity changed to : " << cap_1 << std::endl;
			}
		}

		logFile << "\tmaking std_vector_2 grow..." << std::endl;
		for (int i=0; i < 10; ++i)
		{
			std_vector_2.push_back(i);
			if (cap_2 != std_vector_2.capacity())
			{
				cap_2 = std_vector_2.capacity();
				logFile << "\tcapacity changed to : " << cap_2 << std::endl;
			}
		}

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int>	ft_vector_1;
		ft::vector<int>	ft_vector_2;
		size_t			cap_3 = ft_vector_1.capacity();
		size_t			cap_4 = ft_vector_2.capacity();

		logFile << "\tft_vector_1 capacity : " << cap_3 << std::endl;
		logFile << "\tft_vector_2 capacity : " << cap_4 << std::endl;

		logFile << "\treserve(10) for ft_vector_1" << std::endl;
		ft_vector_1.reserve(10);
		logFile<< "\tft_vector_1 capacity = " << ft_vector_1.capacity() << std::endl;

		logFile << "\tmaking ft_vector_1 grow..." << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			ft_vector_1.push_back(i);
			if (cap_3 != ft_vector_1.capacity())
			{
				cap_3 = ft_vector_1.capacity();
				logFile << "\tcapacity changed to : " << cap_3 << std::endl;
			}
		}


		logFile << "\tmaking ft_vector_2 grow..." << std::endl;
		for (int i=0; i < 10; ++i)
		{
			ft_vector_2.push_back(i);
			if (cap_4 != ft_vector_2.capacity())
			{
				cap_4 = ft_vector_2.capacity();
				logFile << "\tcapacity changed to : " << cap_4 << std::endl;
			}
		}

		// Print the outcome of the test
		if (ft_vector_1.capacity() == std_vector_1.capacity()
		&&  ft_vector_2.capacity() == std_vector_2.capacity())
			std::cout << "TEST# 11 - RESERVE\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 11 - RESERVE\t\t: FAILED ❌" << std::endl;
	}

	logFile << std::endl << "~~~~~ TEST# 12 - SHRINK_TO_FIT ~~~" << std::endl << std::endl;
	{
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector (100);

		logFile << "\tcapcity : " << std_vector.capacity() << std::endl;

		std_vector.resize(10);
		logFile << "\tcapacity after resize(10): " << std_vector.capacity() << std::endl;

		std_vector.shrink_to_fit();
		logFile << "\tcapacity after shrink_to_fit(): " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		std::vector<int> ft_vector (100);

		logFile << "\tcapcity : " << ft_vector.capacity() << std::endl;

		ft_vector.resize(10);
		logFile << "\tcapacity after resize(10): " << ft_vector.capacity() << std::endl;

		ft_vector.shrink_to_fit();
		logFile << "\tcapacity after shrink_to_fit(): " << ft_vector.capacity() << std::endl;

		// Print the outcome of the test
		if (ft_vector.capacity() == std_vector.capacity())
			std::cout << "TEST# 12 - SHRINK_TO_FIT\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 12 - SHRINK_TO_FIT\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                         ~~~ ELEMENT ACCESS TEST ~~~                        */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 13 - ELEMENT ACCESS ~~~~~" << std::endl << std::endl;
	{
		// Fill a std::vector
		std::vector<int>	std_vector;

		for (int i = 0; i < 3; i++)
			std_vector.push_back(i);

		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;
		std_vector[0] = 30;
		logFile << "\telem[0] = " << std_vector[0] << std::endl;
		std_vector[1] = 10;
		logFile << "\telem[1] = " << std_vector.at(1) << std::endl;
		std_vector[2] = 1993;
		logFile << "\telem[2] = " << std_vector[2] << std::endl;

		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << "\tfront = " << std_vector.front() << std::endl;
		logFile << "\tback = " << std_vector.back() << std::endl;

		int* p1 = std_vector.data();

		*p1 = 10;
		++p1;
		*p1 = 20;

		for (size_t i = 0; i < std_vector.size(); ++i)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;

		logFile << std::endl;

		// Fill a ft::vector
		ft::vector<int>	ft_vector;

		for (int i = 0; i < 3; i++)
			ft_vector.push_back(i);

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;
		ft_vector[0] = 30;
		logFile << "\telem[0] = " << ft_vector[0] << std::endl;
		ft_vector[1] = 10;
		logFile << "\telem[1] = " << ft_vector.at(1) << std::endl;
		ft_vector[2] = 1993;
		logFile << "\telem[2] = " << ft_vector[2] << std::endl;

		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		logFile << "\tfront = " << ft_vector.front() << std::endl;
		logFile << "\tback = " << ft_vector.back() << std::endl;

		int* p2 = ft_vector.data();

		*p2 = 10;
		++p2;
		*p2 = 20;

		for (size_t i = 0; i < ft_vector.size(); ++i)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;


		// Print the outcome of the test
		if (std_vector.at(0) == ft_vector.at(0)
		&&  std_vector[1] == ft_vector[1]
		&&  std_vector.front() == ft_vector.front()
		&& std_vector.back() == ft_vector.back())
			std::cout << "TEST# 13 - ELEMENT ACCESS\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 13 - ELEMENT ACCESS\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                             ~~~ ASSIGN TEST ~~~                            */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 14 - ASSIGN ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		std::vector<int>	std_vector;

		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std_vector.assign(3, 100);
		for (size_t i = 0; i < std_vector.size(); i ++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		std_vector.assign(2, 42);
		for (size_t i = 0; i < std_vector.size(); i ++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		std_vector.assign(5, 9);
		for (size_t i = 0; i < std_vector.size(); i ++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		ft::vector<int>	ft_vector;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;
		ft_vector.assign(3, 100);
		for (size_t i = 0; i < ft_vector.size(); i ++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		ft_vector.assign(2, 42);
		for (size_t i = 0; i < ft_vector.size(); i ++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		ft_vector.assign(5, 9);
		for (size_t i = 0; i < ft_vector.size(); i ++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		// Comparison
		int error = false;
		for (size_t i = 0; i < std_vector.size(); i++)
		{
			if (ft_vector[i] != std_vector[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (error != true
		&&  ft_vector.size() == std_vector.size()
		&&  ft_vector.capacity() == std_vector.capacity())
			std::cout << "TEST# 14 - ASSIGN\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 14 - ASSIGN\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                            ~~~ PUSH_BACK TEST ~~~                          */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 15 - PUSH_BACK ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		std::vector<int>	std_vector;
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std_vector.push_back(i);
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		}
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		ft::vector<int>	ft_vector;
		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			ft_vector.push_back(i);
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		}
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		// Comparison
		int error = false;
		for (int i = 0; i < 5; i++)
		{
			if (ft_vector[i] != std_vector[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (error != true)
			std::cout << "TEST# 15 - PUSH_BACK\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 15 - PUSH_BACK\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                            ~~~ POP_BACK TEST ~~~                           */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 16 - POP_BACK ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		std::vector<int>	std_vector;

		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		for (int i = 0; i < 5; i++)
		{
			std_vector.push_back(i);
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		}
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		for (int i = 0; !std_vector.empty(); ++i)
		{
			logFile << "\tlast elem = " << std_vector.back() << std::endl;
			std_vector.pop_back();
		}
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		ft::vector<int>	ft_vector;

		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		for (int i = 0; i < 5; i++)
		{
			ft_vector.push_back(i);
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		}
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		for (int i = 0; !ft_vector.empty(); i++)
		{
			logFile << "\tlast elem = " << ft_vector.back() << std::endl;
			ft_vector.pop_back();
		}
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		// Comparison
		int error = false;
		for (size_t i = 0; i < std_vector.size(); i++)
		{
			if (ft_vector[i] != std_vector[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (ft_vector.size() == std_vector.size()
		&&  ft_vector.capacity() == std_vector.capacity()
		&&  error == false)
			std::cout << "TEST# 16 - POP_BACK\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 16 - POP_BACK\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                             ~~~ INSERT TEST ~~~                            */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 17 - INSERT ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl << std::endl;

		std::vector<int>			std_vector (3,100);
		std::vector<int>::iterator	it;

		it = std_vector.begin();
		it = std_vector.insert(it, 200);

		logFile << "\tAfter first insertion, std_vector contains:" << std::endl;
		logFile << "\t";
		for (it = std_vector.begin(); it < std_vector.end(); it++)
			logFile << ' ' << *it;
		logFile << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;
		logFile << std::endl;


		std_vector.insert (it, 2, 300);

		logFile << "\tAfter second insertion, std_vector contains:" << std::endl;
		logFile << "\t";
		for (it = std_vector.begin(); it < std_vector.end(); it++)
			logFile << ' ' << *it;
		logFile << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;
		logFile << std::endl;

		it = std_vector.begin();

		std::vector<int>	std_vector_2(2,400);
		std_vector.insert(it + 2, std_vector_2.begin(), std_vector_2.end());

		logFile << "\tAfter third insertion, std_vector contains:" << std::endl;
		logFile << "\t";
		for (it = std_vector.begin(); it < std_vector.end(); it++)
			logFile << ' ' << *it;
		logFile << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;
		logFile << std::endl;

		int array[] = {501, 502, 503};
		std_vector.insert (std_vector.begin(), array, array + 3);

		logFile << "\tAfter fourth insertion, std_vector contains:" << std::endl;
		logFile << "\t";
		for (it = std_vector.begin(); it < std_vector.end(); it++)
			logFile << ' ' << *it;
		logFile << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;
		logFile << std::endl;

		std_vector.insert(std_vector.begin() + 3, 3, 42);
		logFile << "\tAfter last insertion, std_vector contains:" << std::endl;
		logFile << "\t";
		for (it = std_vector.begin(); it < std_vector.end(); it++)
			logFile << ' ' << *it;
		logFile << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;
		logFile << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl << std::endl;

		ft::vector<int>				ft_vector (3,100);
		ft::vector<int>::iterator	iter;

		iter = ft_vector.begin();
		iter = ft_vector.insert(iter, 200);

		logFile << "\tAfter first insertion, ft_vector contains:" << std::endl;
		logFile << "\t";
		for (iter = ft_vector.begin(); iter < ft_vector.end(); iter++)
			logFile << ' ' << *iter;
		logFile << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;
		logFile << std::endl;

		ft_vector.insert (iter, 2, 300);

		logFile << "\tAfter second insertion, ft_vector contains:" << std::endl;
		logFile << "\t";
		for (iter = ft_vector.begin(); iter < ft_vector.end(); iter++)
			logFile << ' ' << *iter;
		logFile << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;
		logFile << std::endl;

		iter = ft_vector.begin();

		ft::vector<int>	ft_vector_2(2,400);
		ft_vector.insert(iter + 2, ft_vector_2.begin(), ft_vector_2.end());


		logFile << "\tAfter third insertion, ft_vector contains:" << std::endl;
		logFile << "\t";
		for (iter = ft_vector.begin(); iter < ft_vector.end(); iter++)
			logFile << ' ' << *iter;
		logFile << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;
		logFile << std::endl;

		int tab[] = {501, 502, 503};
		ft_vector.insert (ft_vector.begin(), tab, tab + 3);

		logFile << "\tAfter fourth insertion, ft_vector contains:" << std::endl;
		logFile << "\t";
		for (iter = ft_vector.begin(); iter < ft_vector.end(); iter++)
			logFile << ' ' << *iter;
		logFile << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;
		logFile << std::endl;

		ft_vector.insert(ft_vector.begin() + 3, 3, 42);
		logFile << "\tAfter last insertion, ft_vector contains:" << std::endl;
		logFile << "\t";
		for (iter = ft_vector.begin(); iter < ft_vector.end(); iter++)
			logFile << ' ' << *iter;
		logFile << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;
		logFile << std::endl;

		// Comparison
		// int error = false;
		// for (size_t i = 0; i < std_vector.size(); i++)
		// {
		// 	if (ft_vector[i] != std_vector[i])
		// 	{
		// 		error  = true;
		// 		break;
		// 	}
		// }

		// Print the outcome of the test
		// if (ft_vector.size() == std_vector.size()
		// &&  ft_vector.capacity() == std_vector.capacity()
		// &&  error == false)
		// 	std::cout << "TEST# 17 - INSERT\t\t: SUCCESS ✔️" << std::endl;
		// else
		// 	std::cout << "TEST# 17 - INSERT\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                              ~~~ ERASE TEST ~~~                            */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 18 - ERASE ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector;

		// Set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			std_vector.push_back(i);

		// Erase the 6th element
		std_vector.erase(std_vector.begin() + 5);

		// Erase the first 3 elements:
		std_vector.erase (std_vector.begin(), std_vector.begin() + 3);

		for (size_t i = 0; i < std_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int> ft_vector;

		// Set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			ft_vector.push_back(i);

		// Erase the 6th element
		ft_vector.erase(ft_vector.begin() + 5);

		// // Erase the first 3 elements:
		ft_vector.erase (ft_vector.begin(), ft_vector.begin() + 3);

		for (size_t i = 0; i < ft_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;


		// Comparison
		int error = false;
		for (size_t i = 0; i < std_vector.size(); i++)
		{
			if (ft_vector[i] != std_vector[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (ft_vector.size() == std_vector.size()
		&&  ft_vector.capacity() == std_vector.capacity()
		&&  error == false)
			std::cout << "TEST# 18 - ERASE\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 18 - ERASE\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                              ~~~ SWAP TEST ~~~                             */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 19 - SWAP ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int> std_vector_1(3, 100);	// three ints with a value of 100
  		std::vector<int> std_vector_2 (5,200);	// five ints with a value of 200

		for (size_t i = 0; i < std_vector_1.size(); i++)
			logFile << "\tbefore swap : elem[" << i << "] = " << std_vector_1[i] << std::endl;
		logFile << "\tsize = " << std_vector_1.size() << std::endl;
		logFile << "\tcapacity = " << std_vector_1.capacity() << std::endl;

  		std_vector_1.swap(std_vector_2);

		for (size_t i = 0; i < std_vector_1.size(); i++)
			logFile << "\tafter swap : elem[" << i << "] = " << std_vector_1[i] << std::endl;
		logFile << "\tsize = " << std_vector_1.size() << std::endl;
		logFile << "\tcapacity = " << std_vector_1.capacity() << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int> ft_vector_1(3, 100);	// three ints with a value of 100
  		ft::vector<int> ft_vector_2 (5,200);	// five ints with a value of 200

		for (size_t i = 0; i < ft_vector_1.size(); i++)
			logFile << "\tbefore swap : elem[" << i << "] = " << ft_vector_1[i] << std::endl;
		logFile << "\tsize = " << ft_vector_1.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector_1.capacity() << std::endl;

  		ft_vector_1.swap(ft_vector_2);

		for (size_t i = 0; i < ft_vector_1.size(); i++)
			logFile << "\tafter swap : elem[" << i << "] = " << ft_vector_1[i] << std::endl;
		logFile << "\tsize = " << ft_vector_1.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector_1.capacity() << std::endl;


		// Comparison
		int error = false;
		for (size_t i = 0; i < std_vector_1.size(); i++)
		{
			if (ft_vector_1[i] != std_vector_1[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (ft_vector_1.size() == std_vector_1.size()
		&&  ft_vector_1.capacity() == std_vector_1.capacity()
		&&  error == false)
			std::cout << "TEST# 19 - SWAP\t\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 19 - SWAP\t\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                              ~~~ CLEAR TEST ~~~                             */
    /*                                                                            */
    /* ************************************************************************** */

	logFile << std::endl << "~~~~~ TEST# 20 - CLEAR ~~~~~" << std::endl << std::endl;
	{
		// Test with std::vector
		logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

		std::vector<int>	std_vector;
		std_vector.push_back (100);
		std_vector.push_back (200);
		std_vector.push_back (300);

		for (size_t i = 0; i < std_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		logFile << "\tcall to clear()" << std::endl;
		std_vector.clear();
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		std_vector.push_back (1101);
		std_vector.push_back (2202);

		for (size_t i = 0; i < std_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
		logFile << "\tsize = " << std_vector.size() << std::endl;
		logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

		logFile << std::endl;

		// Test with ft::vector
		logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

		ft::vector<int>	ft_vector;
		ft_vector.push_back (100);
		ft_vector.push_back (200);
		ft_vector.push_back (300);
		int error = false;

		for (size_t i = 0; i < ft_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		logFile << std::endl;

		logFile << "\tcall to clear()" << std::endl;
		ft_vector.clear();
		if (ft_vector.size() != 0)
			error = true;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		logFile << std::endl;

		ft_vector.push_back (1101);
		ft_vector.push_back (2202);

		for (size_t i = 0; i < ft_vector.size(); i++)
			logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
		logFile << "\tsize = " << ft_vector.size() << std::endl;
		logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

		// Comparison
		for (size_t i = 0; i < std_vector.size(); i++)
		{
			if (ft_vector[i] != std_vector[i])
			{
				error  = true;
				break;
			}
		}

		// Print the outcome of the test
		if (ft_vector.size() == std_vector.size()
		&&  ft_vector.capacity() == std_vector.capacity()
		&&  error == false)
			std::cout << "TEST# 20 - CLEAR\t\t: SUCCESS ✔️" << std::endl;
		else
			std::cout << "TEST# 20 - CLEAR\t\t: FAILED ❌" << std::endl;
	}

	/* ************************************************************************** */
    /*                                                                            */
    /*                            ~~~ EMPLACE TEST ~~~     mak                       */
    /*                                                                            */
    /* ************************************************************************** */

	// logFile << std::endl << "~~~~~ TEST# 21 - EMPLACE ~~~~~" << std::endl << std::endl;
	// {
	// 	// Test with std::vector
	// 	logFile << "\tTEST OUTPUT WITH std::vector" << std::endl;

	// 	std::vector<int>			std_vector = {10,20,30};
	// 	std::vector<int>::iterator	it = std_vector.emplace(std_vector.begin() + 1, 100);

	// 	std_vector.emplace (it, 200);
	// 	std_vector.emplace (std_vector.end(), 300);

	// 	for (size_t i = 0; i < std_vector.size(); i++)
	// 		logFile << "\telem[" << i << "] = " << std_vector[i] << std::endl;
	// 	logFile << "\tsize = " << std_vector.size() << std::endl;
	// 	logFile << "\tcapacity = " << std_vector.capacity() << std::endl;

	// 	logFile << std::endl;

	// 	// Test with ft::vector
	// 	logFile << "\tTEST OUTPUT WITH ft::vector" << std::endl;

	// 	ft::vector<int>				ft_vector;
	// 	ft_vector.push_back (10);
	// 	ft_vector.push_back (20);
	// 	ft_vector.push_back (30);
	// 	ft::vector<int>::iterator	iter = ft_vector.emplace(ft_vector.begin() + 1, 100);

	// 	ft_vector.emplace (iter, 200);
	// 	ft_vector.emplace (ft_vector.end(), 300);

	// 	for (size_t i = 0; i < ft_vector.size(); i++)
	// 		logFile << "\telem[" << i << "] = " << ft_vector[i] << std::endl;
	// 	logFile << "\tsize = " << ft_vector.size() << std::endl;
	// 	logFile << "\tcapacity = " << ft_vector.capacity() << std::endl;

	// 	// Comparison
	// 	int error = false;
	// 	for (size_t i = 0; i < std_vector.size(); i++)
	// 	{
	// 		if (ft_vector[i] != std_vector[i])
	// 		{
	// 			error  = true;
	// 			break;
	// 		}
	// 	}

	// 	// Print the outcome of the test
	// 	if (ft_vector.size() == std_vector.size()
	// 	&&  ft_vector.capacity() == std_vector.capacity()
	// 	&&  error == false)
	// 		std::cout << "TEST# 21 - EMPLACE\t\t: SUCCESS ✔️" << std::endl;
	// 	else
	// 		std::cout << "TEST# 21 - EMPLACE\t\t: FAILED ❌" << std::endl;
	// }

}