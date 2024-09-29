#ifndef TERMINAL_H
#define TERMINAL_H


typedef struct
{
	int lines;
	int columns;
} Terminal;

Terminal getTerminal();

#endif
