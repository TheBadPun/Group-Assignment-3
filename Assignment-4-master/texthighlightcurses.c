#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


int main()
{
    char next;
    //replace with your functions
    initscr();
    raw();
    noecho();
    WINDOW* window = NULL;
    int maxY = getmaxy(stdscr);
    int maxX = getmaxx(stdscr);
    window = newwin(maxY, maxX, 0, 0);
    wrefresh(stdscr);
    wprintw(window, "procedure junk procedure process");//print something to the window to highlight
    start_color(); //need this to tell the program to run in color
    //set color to green
    init_pair(1, COLOR_GREEN, COLOR_BLACK);//declare pair we want to use to highlight text on window
///begin function---------------------------------------------------------------------------------------------------------

    int i = 0;
    int j = 0;
    //loops through print statement
    for(j = 0; j < maxY; j++)
    {
        for(i = 0; i < maxX; i++)
        {
            ///this if statement will look for the word "procedure"
            if((mvwinch(window, j, i) & A_CHARTEXT) == 'p'
                    && (mvwinch(window, j,(i+1))&A_CHARTEXT) == 'r'
                    && (mvwinch(window, j,(i+2))&A_CHARTEXT) == 'o'
                    && (mvwinch(window, j,(i+3))&A_CHARTEXT) == 'c'
                    && (mvwinch(window, j,(i+4))&A_CHARTEXT) == 'e'
                    && (mvwinch(window, j,(i+5))&A_CHARTEXT) == 'd'
                    && (mvwinch(window, j,(i+6))&A_CHARTEXT) == 'u'
                    && (mvwinch(window, j,(i+7))&A_CHARTEXT) == 'r'
                    && (mvwinch(window, j,(i+8))&A_CHARTEXT) == 'e')
                {
                    wattron(window,COLOR_PAIR(1));//turn on color
                    mvwprintw(window, j, i, "procedure"); //we have to overlap word in color now
                    wattroff(window, COLOR_PAIR(1));//turn off after printing word
                }
             /*-------------------------------------------------------/
             //    we need if statements here for other words        //
             /-------------------------------------------------------*/

            }//end of column loop

        }//end of row loop
///end of function---------------------------------------------------------------------------------------------------------

    wrefresh(window);//refresh window so text is written to screen
    getch();
    delwin(window);
	endwin(); //free memory under initscr

	return 0;
}
