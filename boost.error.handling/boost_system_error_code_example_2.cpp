// Using boost::system::error_category

#include <boost/system/error_code.hpp>
#include <iostream>

using namespace boost::system;

void fail(error_code &ec)
{
	ec = errc::make_error_code(errc::not_supported);
}

int main()
{
	error_code ec;
	fail(ec);

	std::cout << ec.value() << '\n';                                       
	std::cout << ec.category().name() << '\n';
}

/*
 * As shown in the above example, category() returns an error's category. This is
 * an object of type boost::system::error_category. 
 * 
 * You can also use the free-standing functions boost::system::generic_category()
 * to access the generic category.
 * 
 * Boost.System provides a second category. If you call the free-standing function
 * boost::system::system_category(), you get a reference to the system category. 
 * If you write the category's name to standard output, "system" is displayed.
 * 
 * Errors are uniquely identified by the error code and the error category. Because
 * error codes are only required to be unique within a category, you should create
 * a new category whenever you want to define error codes specific to your program.
 * This makes it possible to use error codes that do not interfere with error codes
 * from other developers.
 */