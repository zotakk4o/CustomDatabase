#ifndef FILE_H
#define FILE_H
#include<fstream>
#include "String.h"

class File {
	protected:
		String data;
		String path;
		bool opened;

		bool saveData(const String&);
	public:
		File(const String& = "");
		File(const File&);

		bool open(const String&);
		bool save();
		bool saveAs(const String&);
		void close();
		void setData(const String&);

		String getData() const;
		String getPath() const;
		bool isOpened() const;
};
#endif