#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>


int moveRight(int x, int maxX)
{
	int temp = x;
	if(temp + 1 < maxX)
	{
		x++;
	}
	return x;
}

int moveLeft(int x, int maxX)
{
	int temp = x;
	if(temp - 1 >= 0)
	{
		x--;
	}
	return x;
}

int moveDown(int y, int maxY)
{
	int temp = y;
	if(temp + 1 < maxY)
	{
		y++;
	}
	return y;
}

int moveUp(int y, int maxY)
{
	int temp = y;
	if(temp - 1 >= 0)
	{
		y--;
	}
	return y;
}


FILE *ifp; //input file stream
char *mode = "r";

int main()
{
    //char line[80]; //create an array 80 characters wide
    int position = 0; //start at first character in file
    char cha;
    ifp = fopen("maze.txt", mode); //NOTE: maze must be in same folder as program

    if (ifp == NULL)
    {
        fprintf(stderr, "Can't open input file maze.txt!\n");
        exit(1);
    }
///------------------------------------------------------------------------
///start a blank screen:
    initscr();              //create screen
	raw();
	noecho();               //don't show keyboard input
	WINDOW* window = NULL;
	//hold the maximum screen size
	int height = getmaxy(stdscr);
	int width = getmaxx(stdscr);
	window = newwin(21, 31, 0, 0);
	keypad(window, TRUE);   //enable keypad so we can navigate the maze
	wrefresh(stdscr);
///------------------------------------------------------------------------

    while((cha = fgetc(ifp)) != EOF) //gets one character at a time from file
    {
        if(cha != '\n'){ //need to ignore carriage return otherwise, we have double spacing
        wprintw(window,"%c",cha);}            //get character from file and print to the new window
        position++;
    }
///------------------------------------------------------------------------
///close file after we read in input put keep window open so user can navigate
    fclose(ifp);//close the file after we have read in every character
    int x = 0;
	int y = 0;
    int ch = ' ';
   while(1)//infite loop to keep window open while user gives input
	{//author:
        //mvwprintw(window, 0, 0, arr1[651]);
        wmove(window, y, x);
        //get input
		ch = wgetch(window);
        ///determine movement of cursor
        if(ch == KEY_DOWN)
		{   if(winch(window) != '-'){
			y = moveDown(y, height);}
		}
		if(ch == KEY_UP)
		{   if(winch(window) != '-'){
			y = moveUp(y, height);}
		}
		if(ch == KEY_LEFT)
		{   if(winch(window) != '|'){
			x = moveLeft(x, width);}
		}
		if(ch == KEY_RIGHT)
		{   if(winch(window) != '|'){
			x = moveRight(x, width);}
		}

		if(ch == 'q')
		{
			//exit the loop
			break;
		}
		wrefresh(window);
    }

    getch();
///------------------------------------------------------------------------
///undo initscr() after we quit
    delwin(window);
	endwin(); //free memory under initscr
	//fclose(ifp);//close the file after we have read in every character
	return 0;

}

