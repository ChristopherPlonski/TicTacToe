#include <iostream>
#include <cassert>

#include "StringConverter.hpp"

using namespace std;

int main() {
	cout << "--Testing StringConverter \n";

	assert(StringConverter::try_get_int_from_string("2") == 2);
	assert(StringConverter::try_get_int_from_string("-1") == -1);
	assert(StringConverter::try_get_int_from_string("1234") == 1234);
	assert(StringConverter::try_get_int_from_string("blahahha") == NULL);
	assert(StringConverter::try_get_int_from_string("2040020420240024004200420") == NULL);

	cout << "--StringConverter tests have passed! \n";
	return 0;
}