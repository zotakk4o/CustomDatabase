#ifndef FCP_CONFIG_CPP
#define FCP_CONFIG_CPP

#include "../../String.h"
#include "../../Vector.cpp"

namespace FCPConfig {
	const Vector<String> filesCommandsKeywords{
		"open",
		"close",
		"save",
		"saveas",
		"help",
		"exit"
	};
}

#endif