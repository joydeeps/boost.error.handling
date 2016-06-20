// Using boost::system::system_error

#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <iostream>

using namespace boost::system;

void fail()
{
  throw system_error(errc::make_error_code(errc::not_supported));
}

int main()
{
 try
 {
  fail(); 
 }
 catch(system_error &e)
 {
  error_code ec = e.code();
  
  std::cerr << ec.value() << '\n';
  std::cerr << ec.category().name() << '\n';
 }
}

/*
 * In the above example, the free-standing function fail() has been changed 
 * to throw() an exception of type boost::system::system_error in case of an 
 * error. This exception can transport an error code of type 
 * boost::system::error_code. The exception is caught in main(), which writes
 * the error code and error category to the standard error.
 * 
 */