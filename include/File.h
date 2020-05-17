#ifndef FILE_H
#define FILE_H
#include<fstream>
#include "String.h"
#include "Loggers/interfaces/ILogger.h"

class File {
	private:
		bool saveData(const String&) const;

	protected:
		String data;
		String path;
		bool opened;
		const ILogger* logger;
	public:
		File(const ILogger* = nullptr, const String& = "");
		File(const File& other);

		virtual ~File();
		virtual bool open(const String&) = 0;
		bool save() const;
		bool saveAs(const String&) const;
		bool close();
		void setData(const String&);

		String getData() const;
		String getPath() const;
		bool isOpened() const;
};
#endif