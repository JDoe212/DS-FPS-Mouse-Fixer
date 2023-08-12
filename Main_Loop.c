/*
purpose: This file contains the mainloop for the script, it initializes the playspace and the controls, as well as any other necessary values, then it begins polling the input list
*/

#include "FileHandler.c"
#include <winuser.h>

extern int on, paused, autoMouseDrag;

extern POINT center;

extern int gameSelected;

int Run()
{
  //initialize state checkers to pause or kill script
  struct Input* stateCheckers = InitializeStateCheckers(); 

  //initialize the config files necessary
  struct Input* inputList = FileHandle();

  //if COD MW3 or black ops is selected, increase the wait times because the games are less responsive
  if (gameSelected == 3 || gameSelected == 4)
  {
    mouseResetWait *=1.2;
    buttonWait *=1.5;
  }

  POINT cursorPos, bottomLeft, topRight;
  
  //initialize the playspace
  InitializePoints(&bottomLeft, &topRight);
  //swap the mouse buttons (left is right, right is left)
  //this is in order to allow mouse 1 to be a shoot/attack input, this is not possible on melon DS otherwise. This is reset when the script is killed or paused
  SwapMouseButton(1);
  //when looping on
  while (on)
  {
    //check for pause or kill
    InputCheck(stateCheckers,2);

    if (!paused)
    {
      //get the cursor position and if out of playspace, reset
      GetCursorPos(&cursorPos);
      if ((cursorPos.x>=rightBound || cursorPos.x<=leftBound || cursorPos.y>=bottomBound || cursorPos.y<=topBound) && autoMouseDrag)
      {
        ResetPos(&center);
      }
      //check all inputs and perform them as needed
      InputCheck(inputList,totalInputs);
    }
    // Add a small delay to reduce CPU usage
      Sleep(10);
  }
  //reset the mouse to normal
  SwapMouseButton(0);
  //release both mosue buttons
  mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
  mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
