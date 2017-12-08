#ifndef DEBUG_H
#define DEBUG_H
#include <cassert>
static int constexpr DEBUG=false; //Set to true to enable verbose output (to see where stuff breaks / does undefined behaviour)
#define ASSERT(...) assert(__VA_ARGS__)
#endif
