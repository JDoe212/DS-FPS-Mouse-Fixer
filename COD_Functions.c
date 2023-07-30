/*
purpose: This file containts the game functions necessary for the COD games. Each function contains necessary keypresses/mouse events to form macros for in game inputs.
*/

extern int leftBound, rightBound, topBound, bottomBound, weaponGrenadeToggle;

extern int mouseUp, mouseDown, activeMouse;

extern float distanceFromBoarderSides, distanceFromBoarderTop, distanceNextButton;
extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern POINT center;

void Crouch()
{
  keybd_event('S', 0, 0, 0);
  Sleep(keyWait);
  keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
  Sleep(keyWait);
  keybd_event('S', 0, 0, 0);
  Sleep(keyWait);
  keybd_event('S', 0, KEYEVENTF_KEYUP, 0);
}

void Sprint()
{
  keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
  Sleep(keyWait);
  keybd_event('W', 0, 0, 0);
  Sleep(keyWait);
  keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
  Sleep(keyWait);
  keybd_event('W', 0, 0, 0);
}

void Reload()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, center.y);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void SwapWeapon()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, center.y);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&swapWait);
  SetCursorPos(leftBound + distanceFromBoarderSides + distanceNextButton, center.y);
  ResetPosAfterButton();
}

void SwapWeapon_MW3()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides, center.y + distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  ResetPosAfterButton();
}

void SwapGrenade()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, bottomBound - distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&swapWait);
  SetCursorPos(leftBound + distanceFromBoarderSides + distanceNextButton, bottomBound - distanceFromBoarderTop);
  ResetPosAfterButton();
}

void Interact()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, topBound + distanceFromBoarderTop/1.1f);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void Interact_MW3()
{
  CursorUp();
  SetCursorPos(center.x, bottomBound - distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void ADS()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides, topBound + distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void ADS_WaW()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides, topBound + distanceFromBoarderTop/3);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void ADS_MW3()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides, topBound + distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void ADS_COD4()
{
  CursorUp();
  Sleep(mouseResetWait);
  SetCursorPos(center.x, center.y);
  mouse_event(mouseDown,0,0,0,0);
  GetActiveMouseDown(&buttonWait);
  CursorUp(); 
  mouse_event(mouseDown,0,0,0,0);
}

void SwapToGrenade()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, bottomBound - distanceFromBoarderTop);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void SwapToGrenade_MW3()
{
  CursorUp();
  SetCursorPos(rightBound - distanceFromBoarderSides, topBound + distanceFromBoarderTop*1.5);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}

void GrenadeWeaponToggle()
{
  if (!weaponGrenadeToggle)
  {
    SwapToGrenade();
  }
  else
  {
    Reload();
  }
  weaponGrenadeToggle = !weaponGrenadeToggle;
}

void GrenadeWeaponToggle_MW3()
{
  if (!weaponGrenadeToggle)
  {
    SwapToGrenade_MW3();
  }
  else
  {
    Reload();
  }
  weaponGrenadeToggle = !weaponGrenadeToggle;
}

void MeleeWeapon_MW3()
{
  CursorUp();
  SetCursorPos(leftBound + distanceFromBoarderSides, bottomBound - distanceFromBoarderTop/2);
  mouse_event(mouseDown,0,0,0,0);
  ResetPosAfterButton();
}