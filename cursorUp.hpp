#ifndef CURSORUP_HPP
#define CURSORUP_HPP

#include "Command.hpp"

class cursorUp : public Command
{
public:
  virtual void execute(EditorModel& model)
  {
    line = model.cursorLine();
    col = model.cursorColumn();
    model.cursorUp();
  }

  virtual void undo(EditorModel& model)
  {
    model.undoCursor(line,col);
  }
  
private:
  int line, col;
};

#endif
