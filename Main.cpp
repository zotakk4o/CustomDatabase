#include<iostream>
#include "include/String.h"

int main() {
	String test = "Sosho, Tosho, Pesho, Sasho, Gosho";
	Vector<String> res = test.split();
	res.print();
	
	return 0;
}