#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define T 4
#define RA 4
#define RB 1
#define P_REPL 0.99
#define P_INF 0.0001
#define PHIV 0.05

typedef struct 
{
	char state;
}Cell;

/*A macro used in system() function
it changes deppending on the operating system
*/
#ifdef _WIN32
   #define CLEAR "cls"
#elif __WIN64
	#define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __linux__
    #define CLEAR "clear"
#else
#   error "Unknown compiler"
#endif

//prototypes of functions
void start(void);
Cell **createLattice(void);
void printLattice(Cell **);