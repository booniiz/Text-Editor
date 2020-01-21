#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class cursorEnd : public Command
{
 public:
  virtual void execute(EditorModel& model)
  {
    line = model.cursorLine();
    col = model.cursorColumn();
    model.cursorEnd();
  }

  virtual void undo(EditorModel& model)
  {
    model.undoCursor(line,col);
  }
  
private:
  int line, col;
};

#endif
