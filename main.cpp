
#include <string>
//#include <assert.h> --> // '_wassert': ambiguous call to overloaded function
namespace
{
   #include <mylib.h>
}
// #include <assert.h> // --> '_wassert': ambiguous call to overloaded function


int main()
{
   std::string myname = "daniyal";
   assert(myname == "daniyal");
   mynewfunction(20);
}