// KeypressInteractionReader.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "insertChar.hpp"
#include "cursorRight.hpp"
#include "cursorLeft.hpp"
#include "cursorUp.hpp"
#include "cursorDown.hpp"
#include "nextLine.hpp"
#include "cursorHome.hpp"
#include "cursorEnd.hpp"
#include "backspace.hpp"
#include "deleteLine.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
  while (true)
    {
      Keypress keypress = keypressReader.nextKeypress();

      if (keypress.ctrl())
        {
          // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

          switch (keypress.code())
            {
            case 'X':{
              return Interaction::quit();
              break;
            }
            case 'Z':{
              return Interaction::undo();
              break;
            }

            case 'A':{
              return Interaction::redo();
              break;
            }
            case 'O':{
              cursorRight* right = new cursorRight;
              return Interaction::command(right);
              break;
            }
            case 'U':{
              cursorLeft* left = new cursorLeft;
              return Interaction::command(left);
              break;
            }
            case 'I':{
              cursorUp* up = new cursorUp;
              return Interaction::command(up);
              break;
            }
            case 'K':{
              cursorDown* down = new cursorDown;
              return Interaction::command(down);
              break;
            }
            case 'J':{
              nextLine* nLine = new nextLine;
              return Interaction::command(nLine);
              break;
            }
            case 'M':{
              nextLine* nLine = new nextLine;
              return Interaction::command(nLine);
              break;
            }
            case 'Y':{
              cursorHome* home = new cursorHome;
              return Interaction::command(home);
              break;
            }
            case 'P':{
              cursorEnd* end = new cursorEnd;
              return Interaction::command(end);
              break;
            }
             case 'D':{
              deleteLine* del = new deleteLine;
              return Interaction::command(del);
              break;
            }
            case 'H':{
              backspace* back = new backspace;
              return Interaction::command(back);
              break;
            }
            }
        }
      else
        {
          // The user pressed a normal key (e.g., 'h') without holding
          // down Ctrl; react accordingly
          insertChar* key = new insertChar(keypress.code());
          return Interaction::command(key);
        }
    }
}

