#include <terminal.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

Terminal getTerminal()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	Terminal newTerminal;
	newTerminal.columns = w.ws_col;
	newTerminal.lines = w.ws_row;

	return newTerminal;
}

