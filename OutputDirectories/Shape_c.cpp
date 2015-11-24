#include <new>
#include <string>
#include "Shape.h"

#if defined(__clang__)
#define Shape_c_API __attribute__((visibility("default")))
#elif defined(_MSC_VER)
#ifdef Shape_c_EXPORTS
#define Shape_c_API __declspec(dllexport)
#else
#define Shape_c_API __declspec(dllimport)
#endif
#endif

#define RC_SUCCESS 0
#define RC_FAIL 1

// Won't work on Apple clang as they claim ABI issues
// http://stackoverflow.com/questions/28094794/why-does-apple-clang-disallow-c11-thread-local-when-official-clang-supports/29929949#29929949
static thread_local std::string Shape_error_;

extern "C" {

Shape_c_API void Shape_clear_error()
{
  Shape_error_.clear();
}

Shape_c_API const char* Shape_error()
{
  return Shape_error_.c_str();
}

Shape_c_API void Shape_dispose(const void* myShape)
{
  delete reinterpret_cast<const Shape*>(myShape);
}

Shape_c_API int Shape_area(const void* myShape, double* rv)
{
  try 
  {
    *rv = reinterpret_cast<const Shape*>(myShape)->area();
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

Shape_c_API int Shape_perimeter(const void* myShape, double* rv)
{
  try 
  {
    *rv = reinterpret_cast<const Shape*>(myShape)->perimeter();
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

Shape_c_API int Shape_name(const void* myShape, const char** rv)
{
  try 
  {
    *rv = reinterpret_cast<const Shape*>(myShape)->name();
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

Shape_c_API int Shape_is_equal(const void* myShape, const void* s, int* rv)
{
  try 
  {
    *rv = reinterpret_cast<const Shape*>(myShape)->is_equal((const Shape *)s);
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

Shape_c_API int Shape_Circle_create(double radius, const void** rv)
{
  try 
  {
    *rv = new Circle(radius);
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

Shape_c_API int Shape_Square_create(double side, const void** rv)
{
  try 
  {
    *rv = new Square(side);
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

Shape_c_API int Shape_Pentagon_create(double side, const void** rv)
{
  try 
  {
    *rv = new Pentagon(side);
    return RC_SUCCESS;
  }
  catch(const std::exception& e)
  {
    Shape_error_ = e.what();
  }
  return RC_FAIL;
}

}
