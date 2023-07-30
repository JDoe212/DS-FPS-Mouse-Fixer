/*
purpose: This file containts the file handler and Input Generator for the Dementium games.
*/

extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern int totalInputs;
extern int gameSelected;

//Generate the inputstruct list for the mainloop

void GenerateInputs_DEM(FILE *inputFile, struct Input* inputList)
{
    int i = 0;
    int hexVal;
    char line[100];
    //read each line in the inputs file
    /*
    for each line:
    identify the command we are assigning
    remove the command declaration substring, ex: "Shoot = "
    then scan the hex value
    then create a new input struct in the input struct list, using the hex value given and the command specified
    */
    //NOTE: some of the inputs contain nested if statements, this is to differentiate between functions for Dementium 1 and 2
    while (fgets(line, sizeof(line), inputFile) != NULL) 
    {
      //printf("%s", line);
      line[strcspn(line, "\n")] = '\0';
      if (strstr(line,"Shoot = ")!=NULL)
      {
        removeSubstring(line, "Shoot = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Shoot_Button_Down; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Mouse Manual Reset = ")!=NULL)
      {
        removeSubstring(line, "Mouse Manual Reset = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = ResetPos; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Next Weapon = ")!=NULL)
      {
        removeSubstring(line, "Next Weapon = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = NextWeapon_DEM; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Notepad = ")!=NULL)
      {
        removeSubstring(line, "Notepad = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Notepad_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Interact = ")!=NULL)
      {
        removeSubstring(line, "Interact = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Examine_DEM; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Items = ")!=NULL)
      {
        removeSubstring(line, "Items = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Items_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Items_DEM2; inputList[i].inpNum = hexVal;
        }
        
        i++;
      }
      else if ( strstr(line,"Resume = ")!=NULL)
      {
        removeSubstring(line, "Resume = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Resume_DEM; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Map = ")!=NULL)
      {
        removeSubstring(line, "Map = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Map_DEM; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Sprint = ")!=NULL)
      {
        removeSubstring(line, "Sprint = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Sprint; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Hotbar 1 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 1 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar1_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 2 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 2 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar2_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 3 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 3 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar3_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 4 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 4 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar4_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 5 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 5 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar5_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 6 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 6 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar6_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 7 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 7 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar7_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Hotbar 8 = ")!=NULL)
      {
        removeSubstring(line, "Hotbar 8 = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = HotBar8_DEM; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Jump = ")!=NULL)
      {
        removeSubstring(line, "Jump = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Jump_DEM2; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Crouch = ")!=NULL)
      {
        removeSubstring(line, "Crouch = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Crouch_DEM2; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Flashlight = ")!=NULL)
      {
        removeSubstring(line, "Flashlight = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Flashlight_DEM2; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Reload = ")!=NULL)
      {
        removeSubstring(line, "Reload = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Reload_DEM2; inputList[i].inpNum = hexVal;
        }
        i++;
      }
      else if (strstr(line,"Equipment = ")!=NULL)
      {
        removeSubstring(line, "Equipment = ");
        sscanf(line, "%x", &hexVal);
        if (gameSelected == 5)
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = DoNothing; inputList[i].inpNum = hexVal;
        }
        else
        {
          inputList[i].isDown = 0; inputList[i].gameFunction = Equipment_DEM2; inputList[i].inpNum = hexVal;
        }
        i++;
      }
    }
}

//Read/Create the DEM input file
struct Input* DEM_Input_Reader()
{
  totalInputs = 0;

  FILE* DEMInputs = fopen("DS_DEM_Controls.txt", "r");
  if (DEMInputs == NULL) 
  {
    // File not found, create a new DEMInputs
    DEMInputs = fopen("DS_DEM_Controls.txt", "w");

    if (DEMInputs != NULL) 
    {
      // Write data to the DEMInputs if needed
      fprintf(DEMInputs, "Edit Controls for Dementium The Ward and Dementium II in this file.\nInputs must be denoted by their corresponding hex values as denoted here: \nhttps://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes \n\n");
      
      fprintf(DEMInputs, "Shoot = 0x01\n");
      fprintf(DEMInputs, "Mouse Manual Reset = 0x04\n");
      fprintf(DEMInputs, "Next Weapon = 0x05\n");
      fprintf(DEMInputs, "Interact = 0x45\n");
      fprintf(DEMInputs, "Items = 0x47\n");
      fprintf(DEMInputs, "Resume = 0x56\n");
      fprintf(DEMInputs, "Map = 0x4D\n");
      fprintf(DEMInputs, "Sprint = 0xA0\n");

      fprintf(DEMInputs, "\nREMINDER: The following commands only work in Dementium The Ward.\n\n");

      fprintf(DEMInputs, "Notepad = 0x51\n");
      fprintf(DEMInputs, "Hotbar 1 = 0x31\n");
      fprintf(DEMInputs, "Hotbar 2 = 0x32\n");
      fprintf(DEMInputs, "Hotbar 3 = 0x33\n");
      fprintf(DEMInputs, "Hotbar 4 = 0x34\n");
      fprintf(DEMInputs, "Hotbar 5 = 0x35\n");
      fprintf(DEMInputs, "Hotbar 6 = 0x36\n");
      fprintf(DEMInputs, "Hotbar 7 = 0x37\n");
      fprintf(DEMInputs, "Hotbar 8 = 0x38\n");

      fprintf(DEMInputs, "\nREMINDER: The following commands only work in Dementium II.\n\n");
      fprintf(DEMInputs, "Jump = 0x20\n"); 
      fprintf(DEMInputs, "Crouch = 0xA2\n");
      fprintf(DEMInputs, "Flashlight = 0x46\n"); 
      fprintf(DEMInputs, "Reload = 0x52\n"); 
      fprintf(DEMInputs, "Equipment = 0x31\n");
      
      // Close the DEMInputs
      fclose(DEMInputs);

      totalInputs = 22;

      //open the recently created input file
      FILE* DEMInputs = fopen("DS_DEM_Controls.txt", "r");
      
      //create the inputstruct list, the length set to the default number of inputs from the generic inputs.txt
      struct Input* inputList = malloc(totalInputs * sizeof(struct Input));
      
      //Generate the inputs
      GenerateInputs_DEM(DEMInputs, inputList);


      fclose(DEMInputs);

      //return the inputlist
      return inputList;
    } 
    else
    {
      printf("Error creating DEMInputs");

    }
  } 
  else 
  {
    // Read data from the DEMInputs if needed
    char line[100];
    //Read the text file line by line, and count the number of inputs that need to be in the inputstruct list
    while (fgets(line, sizeof(line), DEMInputs) != NULL) 
    {
      //printf("%s", line);
      line[strcspn(line, "\n")] = '\0';
      if ((strstr(line,"Shoot = ")!=NULL) || (strstr(line,"Mouse Manual Reset = ")!=NULL) || (strstr(line,"Notepad = ")!=NULL) || (strstr(line,"Sprint = ")!=NULL) || strstr(line,"Interact = ")!=NULL || strstr(line,"Items = ")!=NULL || strstr(line,"Resume = ")!=NULL || strstr(line,"Map = ")!=NULL || strstr(line,"Next Weapon = ")!=NULL || strstr(line,"Hotbar 1 = ")!=NULL || strstr(line,"Hotbar 2 = ")!=NULL || strstr(line,"Hotbar 3 = ")!=NULL || strstr(line,"Hotbar 4 = ")!=NULL || strstr(line,"Hotbar 5 = ")!=NULL || strstr(line,"Hotbar 6 = ")!=NULL || strstr(line,"Hotbar 7 = ")!=NULL || strstr(line,"Hotbar 8 = ")!=NULL || (strstr(line,"Jump = ")!=NULL) || (strstr(line,"Crouch = ")!=NULL) || (strstr(line,"Flashlight = ")!=NULL) || (strstr(line,"Reload = ")!=NULL) || (strstr(line,"Equipment = ")!=NULL))
      {
       totalInputs++;
      }
    }
    //after counting the inputs, create a list of that many elements
    struct Input* inputList = malloc(totalInputs * sizeof(struct Input));
    //restart reading file
    fseek(DEMInputs, 0, SEEK_SET);
    //Generate the inputs 
    GenerateInputs_DEM(DEMInputs, inputList);
    // Close the DEMInputs
    fclose(DEMInputs);
    
    //return the inputlist
    return inputList;
  }
}