#include<iostream>
#include "src/DBCommandsProcessor.h"

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