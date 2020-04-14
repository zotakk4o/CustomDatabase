#ifndef DBFILE_H
#define DBFILE_H
#include<fstream>
#include "String.h"


class File {
	private:
		String data;
		String name;

		bool saveData(const String&);
	public:
		bool open(const String&);
		bool save() noexcept;
		bool saveAs(const String&);
		void close();
		void setData(const String&);

		String getData() const;
		String getName() const;
};
#endif