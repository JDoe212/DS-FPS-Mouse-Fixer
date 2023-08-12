/*
purpose: This file contains the driver functions, that either initialize the values for later functions, or poll the input list, with a few outliers that didnt fit into other files
*/

#include "InputStruct.c"
#include "Universal_Functions.c"
#include "MPH_Functions.c"
#include "DEM_Functions.c"
#include "COD_Functions.c"

extern int on, paused;

int leftBound, rightBound, topBound, bottomBound, weaponGrenadeToggle;

int mouseUp = MOUSEEVENTF_RIGHTUP, mouseDown = MOUSEEVENTF_RIGHTDOWN, activeMouse = 0x02;

float screenWidthRatio, screenHeightRatio, referenceWidth = 587, referenceHeight = 441;

float distanceFromBoarderSides = 50, distanceFromBoarderTop = 100, distanceNextButton = 100;
float mouseResetWait = 35, buttonWait = 100, swapWait = 220, keyWait = 50;
int autoMouseDrag = 1;

RECT playSpace;

POINT center;

//This is the function that initializes the playspace of the user's stylus screen
//listens for the first click, and assigns the point bottom left to that cursor position, and does the same for the second click and top right point
int InitializePoints(POINT* bottomLeft, POINT* topRight)
{
  //initialize is used to count which click has just been sent (when initialize is 0, set bottom left, when not 0 set top right)
  int initialize = 0;
  int clickDown = 0;
  while (initialize<=1)
  {
    //if you get the mouse click 
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
      //and it was not clicked before (script only calls whem the mouse down input is sent, not when the mouse is kept down)
      if (!clickDown)
        {
          clickDown=1;
          //if it is the first click, initialize the bottom left
          if (initialize==0)
          {
            GetCursorPos(bottomLeft);
            initialize++;
          }
          //second click, initialize top right, then scale the function values accordingly
          else
          {
            GetCursorPos(topRight);

            //sleep so that there is a small delay between the click and the script activating
            Sleep(100);

            //assign the bounds based on the two points
            leftBound = bottomLeft->x;
            rightBound = topRight->x;
            topBound = topRight->y;
            bottomBound = bottomLeft->y;
            
            SetRect(&playSpace, leftBound, topBound, rightBound, bottomBound);

            leftBound += 1;
            rightBound -= 1;
            topBound += 1;
            bottomBound -= 1;

            //determine the width and height of the playspace
            float screenWidth = rightBound - leftBound;
            float screenHeight = bottomBound - topBound;

            //get the ratio of the current playspace as compared to the reference playspace (my personal measurements)
            screenWidthRatio = screenWidth/referenceWidth;
            screenHeightRatio = screenHeight/referenceHeight;
            
            //using the ratio of (User playspace / reference playspace) scale up the default distance values by that ratio 
            distanceFromBoarderSides = 50 * screenWidthRatio;
            distanceNextButton = 100 * screenWidthRatio;
            distanceFromBoarderTop = 100 * screenHeightRatio;

            //Initialize th center pixel of the playspace
            center.x = (((rightBound-leftBound)/2) + leftBound);
            center.y = (((bottomBound-topBound)/2) + topBound);
            ResetPos();
            return 1;
          }
        }
    }
    else
      {
        clickDown = 0;
      }
  }
}

//press the button that is used for attack
void Shoot_Button_Down()
{
  keybd_event('N', 0, KEYEVENTF_KEYUP, 0);
  keybd_event('N', 0, 0, 0);
}

//release the button that is used for attack
void Shoot_Button_Up()
{
  keybd_event('N', 0, KEYEVENTF_KEYUP, 0);
}

//pause the script, can be unpaused
void Pause()
{
  mouse_event(mouseUp,0,0,0,0);
  SwapMouseButton(paused);
  Shoot_Button_Up();
  paused = !paused;
  if (paused)
  {
    ClipCursor(NULL);
  }
  else
  {
    ResetPos();
    //LockPlaySpace();
  }
}

//kill the script, can be unkilled
void Kill()
{
  on = 0;
  paused=1;
  mouse_event(mouseUp,0,0,0,0);
  Shoot_Button_Up();
  SwapMouseButton(0);
  ClipCursor(NULL);
}

//a script that does nothing to fill space in some of the input structs
void DoNothing()
{
  return;
}

//take an input struct and poll it
void RunInput(struct Input *input)
{
  //if the input searched for is right mouse
  if (input->inpNum == 0x02)
  {
    //listen for the right mouse up, rather than right mouse down
    if (GetAsyncKeyState(input->inpNum) & 0x8000) 
      {
        // key is pressed, do nothing
        if (!input->isDown)
        {
          input->isDown = 1;
          //input->gameFunction();
        }
      }
    else
      {
        //key was pressed but isnt now
        if (input->isDown)
        {
          //preform the function
          input->gameFunction();
          ResetPos();
        }
        input->isDown = 0;

        /*if (input->gameFunction == Shoot_Button_Down)
        {
          Shoot_Button_Up();
        }*/
      }
  }
  //for any other input, listen for the input down and perform the function
  else
  {
    if (GetAsyncKeyState(input->inpNum) & 0x8000) 
      {
        // key is pressed but was not last time polled
        if (!input->isDown)
        {
          input->isDown = 1;
          input->gameFunction();
        }
      }
    else
      {
        input->isDown = 0;
        if (input->gameFunction == Shoot_Button_Down)
        {
          //if the function of the input struct was shoot, and the button is no longer pressed, stop shooting
          Shoot_Button_Up();
        }
      }
  }
}

//take list of input strcuts and check them all
void InputCheck(struct Input* inputs, int length) 
{
  //printf("%d\n",inputs[0].inpNum);
  for (int i = 0; i < length; i++)
  {
    RunInput(&inputs[i]);
  }
}

//create the state checker input struct list, this is used to check if the script is paused or killed
//NOTE: the Pause and Kill buttons are permanently set to right shift and backspace respectively
struct Input* InitializeStateCheckers()
{
  struct Input* stateCheckers =   malloc(2 * sizeof(struct Input));
  stateCheckers[0].isDown = 0; stateCheckers[0].gameFunction = Pause; stateCheckers[0].inpNum = 0xA1;
  stateCheckers[1].isDown = 0; stateCheckers[1].gameFunction = Kill; stateCheckers[1].inpNum = 0x08;
  return stateCheckers;
}

