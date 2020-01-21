#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP

#include "Command.hpp"

class cursorDown : public Command
{
public:
  virtual void execute(EditorModel& model)
  {
    line = model.cursorLine();
    col = model.cursorColumn();
    model.cursorDown();
  }

  virtual void undo(EditorModel& model)
  {
    model.undoCursor(line,col);
  }
  
private:
  int line, col;
};

#endif
