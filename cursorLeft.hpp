#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"

class cursorLeft : public Command
{
 public:
    virtual void execute(EditorModel& model)
  {
    model.cursorLeft();
  }

  virtual void undo(EditorModel& model)
  {
    model.cursorRight();
  }
};

#endif
