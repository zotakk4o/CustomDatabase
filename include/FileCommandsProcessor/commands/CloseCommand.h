#ifndef CLOSECOMMAND_H
#define CLOSECOMMAND_H

#include "BaseClasses/FileCommand.h"

class CloseCommand : public FileCommand {
	public:
		virtual ~CloseCommand();
		virtual String toString();
		virtual void execute(File&);
};

#endif
