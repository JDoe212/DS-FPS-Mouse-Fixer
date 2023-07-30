/*
purpose: This file containts the game functions necessary for the Dementium games. Each function contains necessary keypresses/mouse events to form macros for in game inputs.
*/

extern int leftBound, rightBound, topBound, bottomBound, weaponGrenadeToggle;

extern int mouseUp, mouseDown, activeMouse;

extern float distanceFromBoarderSides, distanceFromBoarderTop, distanceNextButton;
extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern POINT center;

void Resume_DEM()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void Examine_DEM()
{
  CursorUp();
  SetCursorPos(center.x, topBound + distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}


void Items_DEM()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, bottomBound - distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
  CursorUp();
}

void Notepad_DEM()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, topBound + distanceFromBoarderTop/2.5);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
  CursorUp();
}

void Items_DEM2()
{
  Notepad_DEM();
}

void Jump_DEM2()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides/2, center.y - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void Crouch_DEM2()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides/2, center.y + distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void Flashlight_DEM2()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides*2, bottomBound - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void Reload_DEM2()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides*2, bottomBound - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void Equipment_DEM2()
{
  CursorUp();
  SetCursorPos(center.x, bottomBound - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
}

void Map_DEM()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides, topBound + distanceFromBoarderTop/2.5);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void NextWeapon_DEM()
{
  Zoom_MPH();
}

void HotBar1_DEM()
{
  CursorUp();
  SetCursorPos(leftBound+distanceFromBoarderSides/1.2, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar2_DEM()
{
  CursorUp();
  SetCursorPos(leftBound+distanceFromBoarderSides*2.2, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar3_DEM()
{
  CursorUp();
  SetCursorPos(leftBound+distanceFromBoarderSides*3.7, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar4_DEM()
{
  CursorUp();
  SetCursorPos(center.x-distanceFromBoarderSides, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar5_DEM()
{
  CursorUp();
  SetCursorPos(center.x+distanceFromBoarderSides, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar6_DEM()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*3.7, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar7_DEM()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides*2.2, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void HotBar8_DEM()
{
  CursorUp();
  SetCursorPos(rightBound-distanceFromBoarderSides/1.2, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}