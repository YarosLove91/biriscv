#ifndef DEBUG_MACRO_H
#define DEBUG_MACRO_H

#include <iostream>
#include <string_view>
#include <source_location>

#define LOGGING_ENABLED
#define DEBUG
#define DEBUG_ARG

#ifdef LOGGING_ENABLED
    #define LOG_FUNCTION(comment) \
        fprintf(stderr, "File: %s, Function: %s, Line: %d, Comment: %s\n", __FILE__, __func__, __LINE__, comment)
#else
    #define LOG_FUNCTION(comment) ((void)0)
#endif


#ifdef DEBUG
#define DEBUG_PRINT(comment) fprintf(stderr, "DEBUG: %s:%d:%s(): %s\n", \
                                __FILE__, __LINE__, __func__, comment)
#else
#define DEBUG_PRINT(comment) ((void)0)
#endif

#ifdef DEBUG_ARG
#define DEBUG_PRINT_ARG(fmt, ...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt "\n", \
                                __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define DEBUG_PRINT_ARG(fmt, ...) ((void)0)
#endif


// void log(std::string_view message,
//          std::source_location location = std::source_location::current()
// ) {
//     std::cout << "info:"
//               << location.file_name() << ":"
//               << location.line() << ":"
//               << location.function_name() << " "
//               << message << '\n';
// }


#endif