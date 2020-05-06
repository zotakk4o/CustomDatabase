#include<iostream>
#include "src/DBCommandsProcessor.h"

int main() {
	try
	{
		DBCommandsProcessor processor;
		processor.start();
	}
	catch (const String& err)
	{
		std::cout << err;
	}
	
	return 0;
}