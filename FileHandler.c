/*
purpose: This file contains the main file handler that calls other file handlers (input readers) depending on what game was selected in the UI
*/

#include "GameFunctions.c"

extern float mouseResetWait, buttonWait, swapWait, keyWait;
int totalInputs;
extern int gameSelected;

#include "Config_FIle_Handler.c"
#include "COD_File_Handler.c"
#include "MPH_File_Handler.c"
#include "DEM_File_Handler.c"

//run the config reader then run input readers dependingo n what game was selected
struct Input* FileHandle()
{
  ConfigReader();

  switch (gameSelected) 
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return COD_Input_Reader();
        break;
    case 5:
    case 6:
        return DEM_Input_Reader();
        break;
    case 7:
        return MPH_Input_Reader();
        break;
    default:
        
        break;
  }
}