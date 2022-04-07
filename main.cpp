//
//  main.cpp
//  BlackJack Dice Game Skeleton
//
//

#include <iostream>
#include <cassert>
#include "BJDice.h"
#include "TurnEvaluator.h"

void clearScreen( );





int main()
{
    
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    Die d1;
    d1.setValue( 1 );
    Die d2;
    d2.setValue( 2 );Die d3;
    d3.setValue( 3 );
    Die d4;
    d4.setValue( 4 );Die d5;
    d5.setValue( 5 );
    Die d6;
    d6.setValue( 6 );
    Player over;
    over.roll( d5, d4 );
    over.addDiceToRunningTotal();
    over.roll( d6, d6 );
    over.addDiceToRunningTotal();
    over.roll( d1, d2 );
    over.addDiceToRunningTotal();
    TurnEvaluator noonewon( over, over );
    assert(noonewon.evaluateTurn() == TurnEvaluator::NOONEWON);
    
    BJDice game;
    std::string action, prompt = "(r)oll (p)ass (q)uit: ";
    std::cout << prompt;
        
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                // end the game...
                return( 0 );
                break;
            case 'r':
            case 'R':
                game.humanPlay();
                cout << game.display( prompt ) << endl;
                break;
            case 'p':
            case 'P':
                game.humanEndTurn();
                cout << game.display(  ) << endl;
                getline( cin, action );
                do
                {
                    game.computerPlay();
                    cout << game.display(  ) << endl;
                    getline( cin, action );
                }
                while( game.computerKeepPlaying() );
                game.computerEndTurn();
                cout << game.display(  ) << endl;
                getline( cin, action );
                game.finishTurn();
                cout << game.display( prompt ) << endl;
                break;
        }
    } while( !game.isGameOver() );
    cout << game.display(  ) << endl;

    return( 0 );
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


