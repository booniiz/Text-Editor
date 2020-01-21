// InteractionProcessor.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
  view.refresh();

  while (true)
    {
      Interaction interaction = interactionReader.nextInteraction();

      if (interaction.type() == InteractionType::quit)
        {
          break;
        }
      else if (interaction.type() == InteractionType::undo)
        {
          if(sUndo.size() != 0)
            {
              sUndo.top()->undo(model);
              sRedo.push(sUndo.top());
              sUndo.pop();
              model.clearErrorMessage();
            }
          view.refresh();
        }
      else if (interaction.type() == InteractionType::redo)
        {
          if(sRedo.size() != 0)
            {
              sRedo.top()->execute(model);
              sUndo.push(sRedo.top());
              sRedo.pop();
              model.clearErrorMessage();
            }
      view.refresh();
        }
      else if (interaction.type() == InteractionType::command)
        {
          Command* command = interaction.command();
          try
            {
              command->execute(model);
              sUndo.push(command);
              model.clearErrorMessage();
            }
          catch (EditorException& e)
            {
              model.setErrorMessage(e.getReason());
            }

          view.refresh();

          // Note that you'll want to be more careful about when you delete
          // commands once you implement undo and redo.  For now, since
          // neither is implemented, I've just deleted it immediately
          // after executing it.  You'll need to wait to delete it until
          // you don't need it anymore.
        }
    }
}

 
