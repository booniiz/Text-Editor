#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP

#include "Command.hpp"

class cursorHome : public Command
{
public:
  virtual void execute(EditorModel& model)
  {
    line = model.cursorLine();
    col = model.cursorColumn();
    model.cursorHome();
  }

  virtual void undo(EditorModel& model)
  {
    model.undoCursor(line,col);
  }
  
private:
  int line, col;
};

#endif
