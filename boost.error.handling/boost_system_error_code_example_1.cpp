/*
 * Boost System provides classes to describe and identify errors. Since C++11, these classes 
 * have been part of the standard library.
 * Boost Exception makes it possible to attach data to exceptions after they have been thrown.
 *
 * Boost.System is a library that, in essence, defines four classes to identify errors. All four classes 
 * were added to the standard libray with C++11. If your development enviornment supports C++11, you don't
 * need to use Boost.System, you might encounter Boost.System through those other libraries.
 *
 * boost::system::error_code is the most basic class in Boost.System; it represents operating 
 * system-specific errors. Because operating system typically enumerate errors, boost::system::error_code
 * saves an error code in a variable of type "int".
 * 
 * The below example illustrates how to use this class.
 */

// Using boost::system::error_code 

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
}

/*
 * The above example defines the function fail(), which is used to return an error. In order for the caller
 * to detect whether fail() failed, an object of type boost::system::error_code is passed by reference.
 * Many functions that are provided by Boost libraries use boost::system::error_code like this. 
 *
 * For example, Boost.Asio provides the function boost::asio::ip::host_name(), to which you can pass an 
 * object of type boost::system::error_code.
 *
 * Boost.System defines numerous error codes in the namespace boost::system::errc. The above example assigns
 * the error code boost::system::errc::not_supported to "ec". Because boost::system::errc::not_supported
 * is a number and "ec" is an object of type boost::system::error_code, the function 
 * boost::system::errc::make_error_code()is called. This function creates an object of type
 * boost::system::error_code with respective error code.
 *
 * In main(), value() is called on  "ec". This member function returns the error code stored in the object.
 *
 * By default, 0 means no error. Every other number refers to an error. Error code values are operating
 * system dependent. 
 *
 * In addition, to value(), boost::system::error_code provides the member function category(), which returns
 * an object of type boost::system::error_category.
 *
 * Error codes of type boost::system::error_code belong to a category that can be retrieved with
 * the member function category(). Errors created with boost::system::errc::make_error_code() 
 * automatically belong to the generic category. This is the category errors belong to if they aren't 
 * assigned to another category explicitly.
 *
 */
