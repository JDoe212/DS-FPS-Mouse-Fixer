/*
purpose: This file containts the file handler and Input Generator for Metroid Prime Hunters games.
*/

extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern int totalInputs;
extern int gameSelected;

//Generate the inputstruct list for the mainloop
void GenerateInputs_MPH(FILE *inputFile, struct Input* inputList)
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
      else if (strstr(line,"Swap To Main Weapon = ")!=NULL)
      {
        removeSubstring(line, "Swap To Main Weapon = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = AmmoTypeOne_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Swap To Missiles = ")!=NULL)
      {
        removeSubstring(line, "Swap To Missiles = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = AmmoTypeTwo_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Swap To Third Weapon = ")!=NULL)
      {
        removeSubstring(line, "Swap To Third Weapon = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = AmmoTypeThree_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Zoom = ")!=NULL)
      {
        removeSubstring(line, "Zoom = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Zoom_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if ( strstr(line,"Special Weapon 1 = ")!=NULL)
      {
        removeSubstring(line, "Special Weapon 1 = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = WeaponOne_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Special Weapon 2 = ")!=NULL)
      {
        removeSubstring(line, "Special Weapon 2 = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = WeaponTwo_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Special Weapon 3 = ")!=NULL)
      {
        removeSubstring(line, "Special Weapon 3 = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = WeaponThree_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Special Weapon 4 = ")!=NULL)
      {
        removeSubstring(line, "Special Weapon 4 = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = WeaponFour_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Special Weapon 5 = ")!=NULL)
      {
        removeSubstring(line, "Special Weapon 5 = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = WeaponFive_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Special Weapon 6 = ")!=NULL)
      {
        removeSubstring(line, "Special Weapon 6 = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = WeaponSix_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Scan Vision = ")!=NULL)
      {
        removeSubstring(line, "Scan Vision = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = ScanVision_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Ball = ")!=NULL)
      {
        removeSubstring(line, "Ball = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Ball_MPH; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Screen Tap Jump = ")!=NULL)
      {
        removeSubstring(line, "Screen Tap Jump = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = ADS_COD4; inputList[i].inpNum = hexVal;
        i++;
      }
    }
}

//Read/Create the COD input file
struct Input* MPH_Input_Reader()
{
  totalInputs = 0;

  FILE* MPHInputs = fopen("DS_MPH_Controls.txt", "r");
  if (MPHInputs == NULL) 
  {
    // File not found, create a new MPHInputs
    MPHInputs = fopen("DS_MPH_Controls.txt", "w");

    if (MPHInputs != NULL) 
    {
      // Write data to the MPHInputs if needed
      fprintf(MPHInputs, "Edit Controls for Metroid Prime Hunters in this file.\nInputs must be denoted by their corresponding hex values as denoted here: \nhttps://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes \n\n");
      
      fprintf(MPHInputs, "Shoot = 0x01\n");
      fprintf(MPHInputs, "Swap To Main Weapon = 0x51\n");
      fprintf(MPHInputs, "Swap To Missiles = 0x45\n");
      fprintf(MPHInputs, "Swap To Third Weapon = 0x52\n");
      fprintf(MPHInputs, "Special Weapon 1 = 0x31\n");
      fprintf(MPHInputs, "Special Weapon 2 = 0x32\n");
      fprintf(MPHInputs, "Special Weapon 3 = 0x33\n");
      fprintf(MPHInputs, "Special Weapon 4 = 0x34\n");
      fprintf(MPHInputs, "Special Weapon 5 = 0x35\n");
      fprintf(MPHInputs, "Special Weapon 6 = 0x36\n");
      fprintf(MPHInputs, "Scan Vision = 0x56\n");
      fprintf(MPHInputs, "Ball = 0xA2\n");
      fprintf(MPHInputs, "Screen Tap Jump = 0xA3\n");
      fprintf(MPHInputs, "Zoom = 0x02");
      
      // Close the MPHInputs
      fclose(MPHInputs);

      totalInputs = 14;

      //open the recently created input file
      FILE* MPHInputs = fopen("DS_MPH_Controls.txt", "r");

      //create the inputstruct list, the length set to the default number of inputs from the generic inputs.txt
      struct Input* inputList = malloc(14 * sizeof(struct Input));
      
      //Generate the inputs
      GenerateInputs_MPH(MPHInputs, inputList);


      fclose(MPHInputs);
      
      //return the inputlist
      return inputList;
    } 
    else
    {
      //printf("Error creating MPHInputs");

    }
  } 
  else 
  {
    //printf("File opened successfully\n");
    // Read data from the MPHInputs if needed
    char line[100];
    //Read the text file line by line, and count the number of inputs that need to be in the inputstruct list
    while (fgets(line, sizeof(line), MPHInputs) != NULL) 
    {
      //printf("%s", line);
      line[strcspn(line, "\n")] = '\0';
      if ((strstr(line,"Shoot = ")!=NULL) || (strstr(line,"Swap To Main Weapon = ")!=NULL) || strstr(line,"Swap To Missiles = ")!=NULL || strstr(line,"Swap To Third Weapon = ")!=NULL || strstr(line,"Special Weapon 1 = ")!=NULL || strstr(line,"Special Weapon 2 = ")!=NULL || strstr(line,"Special Weapon 3 = ")!=NULL || strstr(line,"Special Weapon 4 = ")!=NULL || strstr(line,"Special Weapon 5 = ")!=NULL || strstr(line,"Special Weapon 6 = ")!=NULL || strstr(line,"Scan Vision = ")!=NULL || strstr(line,"Ball = ")!=NULL || strstr(line,"Screen Tap Jump = ")!=NULL || strstr(line,"Zoom = ")!=NULL)
      {
       totalInputs++;
      }
    }
    //after counting the inputs, create a list of that many elements
    struct Input* inputList = malloc(totalInputs * sizeof(struct Input));

    //restart reading file
    fseek(MPHInputs, 0, SEEK_SET);

    //Generate the inputs 
    GenerateInputs_MPH(MPHInputs, inputList);

    // Close the MPHInputs
    fclose(MPHInputs);
    
    //return the inputlist
    return inputList;
  }
}