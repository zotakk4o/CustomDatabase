#ifndef IDBCOMMANDVALIDATOR_H
#define IDBCOMMANDVALIDATOR_H

class IDBCommandValidator {
	public:
		virtual ~IDBCommandValidator() {};
		virtual bool isValid(const Vector<String>&) = 0;
		virtual String toString() = 0;
};

#endif