#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"

class backspace : public Command
{
 public:
  virtual void execute(EditorModel& model)
  {
    col = model.cursorColumn();
    c = model.backspace();
  }

  virtual void undo(EditorModel& model)
  {
    if(col !=1)
      {
        model.insertChar(c);
      }
    else
      {
        model.nextLine();
      }
  }
private:
  char c;
  int col;
};

#endif
