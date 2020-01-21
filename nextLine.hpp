#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"

class nextLine : public Command
{
 public:
    virtual void execute(EditorModel& model)
  {
    col = model.cursorColumn();
    model.nextLine();
  }

  virtual void undo(EditorModel& model)
  {
    model.undonextLine(col);
  }
private:
  int col;
};

#endif
