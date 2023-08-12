/*
purpose: This file contains functions that are used in each of the other "XXX_Functions.c" files. These are necessary for all the games to run.
*/

extern int mouseUp, mouseDown, activeMouse;

extern float mouseResetWait, buttonWait, swapWait, keyWait;
extern int autoMouseDrag;

extern RECT playSpace;

RECT tempRect;

extern POINT center;

//Wait for the mouse down message to be received
void GetActiveMouseDown(float *waitTime)
{
  while (1)
  {
    if (GetAsyncKeyState(activeMouse) & 0x8000)
    {
      //printf("\nclicked down\n");
      Sleep(*waitTime);
      return;
    }
    else
    {
      //printf("\nclicked up\n");
    }
  }
}

//Wait for the mouse up message to be received
void GetActiveMouseUp(float *waitTime)
{
  while (1)
  {
    if (GetAsyncKeyState(activeMouse) & 0x8000)
    {
      //printf("\nclicked down\n");
    }
    else
    {
      //printf("\nclicked up\n");
      Sleep(*waitTime);
      return;
    }
  }
}

void LockPlaySpace()
{
  ClipCursor(&playSpace);
}

//lift the cursor
void CursorUp()
{
  mouse_event(mouseUp,0,0,0,0);
  GetActiveMouseUp(&mouseResetWait);
}

//Reset mouse to center of playspace
void ResetPos()
{
  mouse_event(mouseUp,0,0,0,0);
  GetActiveMouseUp(&mouseResetWait);
  SetCursorPos(center.x,center.y);
  if (autoMouseDrag)
  {
    mouse_event(mouseDown,0,0,0,0);
  }
  GetClipCursor(&tempRect);
  if (tempRect.left != playSpace.left && tempRect.right != playSpace.right && tempRect.top != playSpace.top && tempRect.bottom != playSpace.bottom)
  {
    LockPlaySpace();
  }
}

//Reset mouse to center of playspace after pressing a button (added delay to make sure button press is heard)
int ResetPosAfterButton()
{
  GetActiveMouseDown(&buttonWait);
  mouse_event(mouseUp,0,0,0,0);
  GetActiveMouseUp(&buttonWait);
  SetCursorPos(center.x,center.y);
  if (autoMouseDrag)
  {
    mouse_event(mouseDown,0,0,0,0);
  }
  return 0;
}