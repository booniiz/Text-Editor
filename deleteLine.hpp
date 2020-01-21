#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

class deleteLine : public Command
{
 public:
    virtual void execute(EditorModel& model)
  {
    line = model.cursorLine();
    col = model.cursorColumn();
    pTotal = model.lineCount();
    nPrevious = model.returnLine();
    model.deleteLine();
  }
  virtual void undo(EditorModel& model)
  {
    model.undoCursor(line, col);
    model.undoDeleteLine(pTotal,nPrevious);
  }
 private:
  int line,col,pTotal;
  std::string nPrevious;
};

#endif
