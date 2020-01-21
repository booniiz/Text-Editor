#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"

class insertChar : public Command
{
public:
  insertChar(char key)
  {
    cKey = key;
  }
  
  virtual void execute(EditorModel& model)
  {
    model.insertChar(cKey);
  }

  virtual void undo(EditorModel& model)
  {
    model.backspace();
  }
private:
  char cKey;
};

#endif
  