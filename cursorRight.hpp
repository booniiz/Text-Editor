#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"

class cursorRight : public Command
{
 public:
    virtual void execute(EditorModel& model)
  {
    model.cursorRight();
  }

  virtual void undo(EditorModel& model)
  {
    model.cursorLeft();
  }
};

#endif
