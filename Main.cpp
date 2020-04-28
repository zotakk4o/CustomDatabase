#include<iostream>
#include "src/DBCommandsProcessor.h"
#include "include/String.h"

int main() {
	try
	{
		DBCommandsProcessor::start();
	}
	catch (const String& err)
	{
		std::cout << err;
	}
	
	return 0;
}