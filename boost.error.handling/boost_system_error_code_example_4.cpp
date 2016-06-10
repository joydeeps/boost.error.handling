// Using boost::system::error_condition

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
  boost::system::error_condition ecnd = ec.default_error_condition();
  
  std::cout << ecnd.value() << '\n';
  std::cout << ecnd.category().name() << '\n';
}

/*
 * boost::system::error_condition is used just like boost::system::error_code.
 * That's why it is possible as shown in the above example, to call the 
 * member functiosn value() and category() for an object of type 
 * boost::system::error_condition.
 * 
 * while the class boost::system::error_code is used for platform-dependent
 * error codes, boost::system::error_condition is used to access platform-
 * independent error codes.
 * 
 * The member function default_error_condition() translates a platform-
 * dependent error code into a platform-independent error code of type
 * boost::system::error_condition.
 * 
 * You can use boost::system::error_condition to identify errors that are
 * platform independent.
 * 
 * The last class provided by Boost.System is boost::system::system_error,
 * which is derived from std::runtime_error. It can be used to transport an
 * error code of type boost::system::error_code in an exception.
 * 
 */
