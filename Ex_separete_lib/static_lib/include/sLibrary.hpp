#ifndef _LIBRARY_H_
#define _LIBRARY_H_
//для сборки статической библиотеки не нужно указывать MYLIB_EXPORT, MYLIB_IMPORT, MYLIB_HIDDEN, т.к. файл на уровне исходников добавляется в исполняемый файл.
//данные вещи нужны только для динамических библиотек, дабы не было проблем при динамическом связывании на назных ОС

/*#if defined(_WIN32) || defined(_WIN64)
  #define MYLIB_EXPORT __declspec(dllexport)
  #define MYLIB_IMPORT __declspec(dllimport)
#else
  #define MYLIB_EXPORT __attribute__((visibility("default")))
  #define MYLIB_IMPORT __attribute__((visibitity("default")))
  #define MYLIB_HIDDEN __attribute__((visibitity("hidden")))
#endif*/

struct /*MYLIB_EXPORT*/ sLibrary
{
  void print_info();
};

#endif /*_LIBRARY_H_*/
