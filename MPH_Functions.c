/*
purpose: This file containts the game functions necessary for Metroid Prime Hunters. Each function contains necessary keypresses/mouse events to form macros for in game inputs.
*/

extern int leftBound, rightBound, topBound, bottomBound, weaponGrenadeToggle;

extern int mouseUp, mouseDown, activeMouse;

extern float distanceFromBoarderSides, distanceFromBoarderTop, distanceNextButton;
extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern POINT center;

void AmmoTypeOne_MPH()
{
  CursorUp();
  SetCursorPos(center.x-distanceFromBoarderSides*2, topBound + distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void AmmoTypeTwo_MPH()
{
  CursorUp();
  SetCursorPos(center.x, topBound + distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void AmmoTypeThree_MPH()
{
  CursorUp();
  SetCursorPos(center.x+distanceFromBoarderSides*2, topBound + distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void ScanVision_MPH()
{
  CursorUp();
  SetCursorPos(center.x, bottomBound - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void Ball_MPH()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides*1.5f, bottomBound - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void WeaponOne_MPH()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2,topBound+distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(center.x-distanceFromBoarderSides*1.5,topBound+distanceFromBoarderTop);
  ResetPosAfterButton();
}

void WeaponTwo_MPH()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2,topBound+distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(center.x-distanceFromBoarderSides*1.5,center.y-distanceFromBoarderTop/4);
  ResetPosAfterButton();
}

void WeaponThree_MPH()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2,topBound+distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(center.x-distanceFromBoarderSides,center.y+distanceFromBoarderTop/1.5f);
  ResetPosAfterButton();
}

void WeaponFour_MPH()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2,topBound+distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(center.x+distanceFromBoarderSides/2,bottomBound-distanceFromBoarderTop/1.2f);
  ResetPosAfterButton();
}

void WeaponFive_MPH()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2,topBound+distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(center.x+distanceFromBoarderSides*2,bottomBound-distanceFromBoarderTop/1.5f);
  ResetPosAfterButton();
}

void WeaponSix_MPH()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2,topBound+distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(rightBound-distanceFromBoarderSides*1.8,bottomBound-distanceFromBoarderTop/2);
  ResetPosAfterButton();
}

void Zoom_MPH()
{
  keybd_event('M', 0, KEYEVENTF_KEYUP, 0);
  keybd_event('M', 0, 0, 0);
  Sleep(keyWait);
  keybd_event('M', 0, KEYEVENTF_KEYUP, 0);
}

/*void LeftStrafe_MPH()
{
  ResetPos();
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(leftBound,center.y);
  ResetPos();
}

void RightStrafe_MPH()
{
  ResetPos();
  GetActiveMouseDown(&mouseResetWait);
  SetCursorPos(rightBound,center.y);
  ResetPos();
}*/