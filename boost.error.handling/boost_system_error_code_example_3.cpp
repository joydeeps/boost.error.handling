// Creating error categories

#include <boost/system/error_code.hpp>
#include <string>
#include <iostream>

class application_category : public boost::system::error_category
{
public:
  const char* name() const noexcept
  {
    return "my application error category";
  }
  
  std::string message(int ev) const
  {
    return "error message"; 
  }
};

application_category cat;

int main()
{
  boost::system::error_code	ec(129, cat);
  
  std::cout << ec.value() << '\n';
  std::cout << ec.category().name() << '\n';  
}

/*
 * A new error category is defined by creating a class derived from 
 * boost::system::error_category. This requires you to define various member
 * functions. At a minimum, the member functions name() and message() must be
 * supplied because they are defined as pure virtual member functions in 
 * boost::system::error_category. For additional member functions, the default
 * behaviour can be overriden if required.
 * 
 * While name() returns the name of the error category, message() is used to
 * retrieve the error description for a particular code. Unlike the above 
 * example, the parameter "ev" is usually evaluated to return a description
 * based on the error code.
 * 
 * An object of the type of the newly created error category can be used to 
 * initialize an error code. The above example defines the error code "ec" 
 * using the new category "application_category". Therefore, the error code 
 * 129 is no longer a generic error; instead, it's meaning is defined by the 
 * developer of the new category.
 * 
 * boost::system::error_code provides a member function called
 * default_error_condition(), that returns an object of the type 
 * boost::system::error_condition.
 * 
 * The interface of the boost::system::error_condition is almost identical to
 * the interface of the boost::system::error_code. The only difference is the 
 * member function default_error_condition(), which is provided by 
 * boost::system::error_code.
 */