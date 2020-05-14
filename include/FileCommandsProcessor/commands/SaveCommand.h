#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "BaseClasses/FileCommand.h"

class SaveCommand : public FileCommand {
	public:
		virtual ~SaveCommand();
		virtual void execute(File&);
		virtual String toString();
};
#endif
