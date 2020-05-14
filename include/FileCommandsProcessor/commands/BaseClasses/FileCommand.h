#ifndef FILECOMMAND_H
#define FILECOMMAND_H

#include "../../../File.h"
#include "CommandValidator.h"

class FileCommand : public CommandValidator
{
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~FileCommand();
		virtual void execute(File&) = 0;
};

#endif
