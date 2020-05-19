#include<iostream>
#include "src/DBCommandsProcessor.h"
#include "src/config/DCPConfig.h"

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