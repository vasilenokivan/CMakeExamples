#include <iostream>

#include "version.h" //включаем файлы, которые будут сгенерированы cmake
#include "path.h"    //включаем файлы, которые будут сгенерированы cmake

#include "../lib_include/sLibrary.hpp"

static void cmd_parse(const int argc, const char* argv[]);
static void print_help(std::string aName);
static void print_version();
static void print_path();

//--------------------------MAIN------------------------------
int main(int argc, char* argv[])
{
  if(argc > 1)
  {
    cmd_parse(argc, const_cast<const char**>(argv));
    return 0;
  }  
  sLibrary sl;
  sl.print_info();
  
  return 0;  
}

static void print_help(std::string aName)
{
  std::cout
      << "Usage: "<< aName << " <option(s)>\n"
      << "Options:\n"
      << "\t-h, --help Show this help message\n"
      << "\t-v, --version Show version of program\n"
      << std::endl;
}

static void cmd_parse(const int argc, const char* argv[])
{  
  for(int i = 1; i < argc; ++i)
  {
    std::string param_name = argv[i];
    
    if(param_name == "-h" || param_name == "--help")
    {
      print_help(argv[0]);
      continue;
    }
    if(param_name == "-v" || param_name == "--version")
    {
      print_version();
      continue;
    }
    if(param_name == "-p" || param_name == "--path")
    {
      print_path();
      continue;
    }
    
  }
}
//-------------------------------------------------------
static void print_version()
{
  std::cout << "Version: " << g_version << std::endl;
}
//-------------------------------------------------------
static void print_path()
{
  std::cout << "Path to source of the program: " << g_source_path << std::endl;
  std::cout << "Path to binary of the program: " << g_binary_path << std::endl;
}
