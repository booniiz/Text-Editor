// EditorModel.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class


#include "EditorModel.hpp"
#include "EditorException.hpp"

EditorModel::EditorModel()
{
  cLine = 1;
  cColumn = 1;
  countLine = 1;
  cText.push_back("");
  ceMessage = "";
  oText="";
}

int EditorModel::cursorLine() const
{
  return cLine;
}

int EditorModel::cursorColumn() const
{
  return cColumn;
}

int EditorModel::lineCount() const
{
  return countLine;
}

const std::string& EditorModel::line(int lineNumber) const
{
  return cText[lineNumber-1];
}

const std::string& EditorModel::currentErrorMessage() const
{
  return ceMessage;
}

void EditorModel::setErrorMessage(const std::string& errorMessage)
{
  ceMessage = errorMessage;
}

void EditorModel::clearErrorMessage()
{
  ceMessage = "";
}

void EditorModel::insertChar(char key)
{
  cText[cLine-1].insert(cText[cLine -1].begin()+ cColumn-1, key);
  cColumn++;
}

char EditorModel::backspace()
{
 if(cColumn == 1)
   {
     if(cLine == 1)
       {
     EditorException e("Cannot backspace anymore");
     throw e;
       }
     else
       {
         cColumn = cText[cLine-2].size() +1;
         cText[cLine-2] += cText[cLine-1];
         cLine--;
         cText.erase(cText.begin() + cLine);
         countLine--;
       }
     return deleted;
   }
 else
   {
     deleted = cText[cLine-1][cColumn-2];
     cText[cLine-1].erase(cText[cLine -1].begin() + (cColumn -2));
     cColumn--;
     clearErrorMessage();
     return deleted;
   }
}

void EditorModel::nextLine()
{
  oText = cText[cLine-1].substr(cColumn-1,cText[cLine-1].size());//Get substring
  cText[cLine-1].erase(cColumn-1, cText[cLine-1].size() - (cColumn-1));//Erase
  cText.push_back("");
  cColumn = 1;
  cText.insert(cText.begin() + cLine,oText);//Insert substring to next line
  cLine++;
  countLine++;
  clearErrorMessage();
}

void EditorModel::cursorRight()
{
  if(cColumn == line(cLine).size()+1)
  {
    if(cLine != countLine)
      {
        cColumn = 1;
        cLine++;
        clearErrorMessage();
      }
    else
      {
    EditorException e("Already at the end");
    throw e;
      }
  }
  else
    {
      cColumn++;
      clearErrorMessage();
    }
}

void EditorModel::cursorLeft()
{
  if(cColumn == 1)
    {
      if(cLine != 1)
        {
          cColumn = line(cLine-1).size()+1;
          cLine--;
          clearErrorMessage();
        }
      else
        {
          EditorException e("Already at beginning");
          throw e;
        }
    }
  else
    {
      cColumn--;
      clearErrorMessage();
    }
}

void EditorModel::cursorUp()
{
  if(cLine == 1)
    {
      EditorException e("Already at the top");
      throw e;
    }
  else
    {
      if(cColumn > line(cLine-1).size()+1)
        {
          if(line(cLine).size()>line(cLine-1).size())
            {
              cColumn = line(cLine-1).size()+1;
              cLine--;
              clearErrorMessage();
            }
        }
      else
        {
          cLine--;
          clearErrorMessage();
        }
    }
}

void EditorModel::cursorDown()
{
  if(cLine == countLine)
    {
      EditorException e("Already at the bottom");
      throw e;
    }
  else
    {
      if(cColumn > line(cLine+1).size()+1)
        {
          cColumn = line(cLine+1).size()+1;
          cLine++;
          clearErrorMessage();
        }
      else
        {
          cLine++;
          clearErrorMessage();
        }
    }
}

void EditorModel::cursorHome()
{
  if(cColumn == 1)
    {
      EditorException e("Already at home");
      throw e;
    }
  else
    {
      cColumn = 1;
      clearErrorMessage();
    }
}

void EditorModel::cursorEnd()
{
  if(cColumn == line(cLine).size() +1)
    {
      EditorException e("Already at the end");
      throw e;
    }
  else
    {
      cColumn = line(cLine).size() +1;
      clearErrorMessage();
    }
}

void EditorModel::deleteLine()
{
  if(cLine != 1)
    {
      previous = cText[cLine-1];
      cText.erase(cText.begin()+cLine-1);
      if(cLine == countLine)
        {
          cLine--;
        }
      countLine--;
      if(cColumn > line(cLine).size())
        {
          cColumn = line(cLine).size() +1;
        }
      clearErrorMessage();
    }
  else
    {
      previous = cText[cLine-1];
      cColumn=1;
      if(countLine==1)
        {
          cText[cLine-1] ="";
        }
      else
        {
          cText.erase(cText.begin()+cLine-1);
          countLine--;
        }
      clearErrorMessage();
    }
}

void EditorModel::undonextLine(int col)
{
  if(cLine != 1)
    {
      cText[cLine-2] += cText[cLine-1];
      cText.erase(cText.begin() + (cLine-1));
      cColumn = col;
      cLine--;
      countLine--;
    }
  clearErrorMessage();
}

void EditorModel::undoCursor(int line, int col)
{
  cLine = line;
  cColumn = col;
}

void EditorModel::undoDeleteLine(int pTotal,std::string& nPrevious)
{
  if(cLine == 1 && countLine == 1 && cText[0] == "")
    {
      cText.insert(cText.begin() + cLine,nPrevious);
    }
  else
    {
      if(pTotal > countLine)
        {
          countLine++;
        }
      cText.insert(cText.begin() + cLine,nPrevious);
    }
  clearErrorMessage();
}

std::string EditorModel::returnLine()
{
  return previous;
}
