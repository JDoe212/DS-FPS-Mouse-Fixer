/*
purpose: This file containts the file handler and Input Generator for the COD games.
*/

extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern int totalInputs;
extern int gameSelected;

//Generate the inputstruct list for the mainloop
void GenerateInputs_COD(FILE *inputFile, struct Input* inputList) 
{   
    //initialize lists of functions, such that this script will support functionality for each COD game, (using indexing, change the function that each button does.)
    void (*ADS_FUNCTIONS[5])() = {ADS_WaW,ADS_COD4,ADS,ADS_MW3,ADS_MW3};
    void (*SwapWeapon_FUNCTIONS[5])() = {SwapWeapon,SwapWeapon,SwapWeapon,SwapWeapon_MW3,SwapWeapon_MW3};
    void (*SwapToGrenade_FUNCTIONS[5])() = {GrenadeWeaponToggle,GrenadeWeaponToggle,GrenadeWeaponToggle,GrenadeWeaponToggle_MW3,GrenadeWeaponToggle_MW3};
    void (*SwapGrenadeType_FUNCTIONS[5])() = {SwapGrenade,SwapGrenade,SwapGrenade,DoNothing,DoNothing};
    void (*SwapMelee_FUNCTIONS[5])() = {DoNothing,DoNothing,DoNothing,MeleeWeapon_MW3,MeleeWeapon_MW3};
    void (*Interact_FUNCTIONS[5])() = {Interact,Interact,Interact,Interact_MW3,Interact_MW3,};

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
      else if (strstr(line,"ADS = ")!=NULL)
      {
        removeSubstring(line, "ADS = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = ADS_FUNCTIONS[gameSelected]; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Swap Weapon = ")!=NULL)
      {
        removeSubstring(line, "Swap Weapon = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = SwapWeapon_FUNCTIONS[gameSelected]; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Swap To Grenade = ")!=NULL)
      {
        removeSubstring(line, "Swap To Grenade = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = SwapToGrenade_FUNCTIONS[gameSelected]; inputList[i].inpNum = hexVal;
        i++;
      }
      else if ( strstr(line,"Swap Grenade Type = ")!=NULL)
      {
        removeSubstring(line, "Swap Grenade Type = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = SwapGrenadeType_FUNCTIONS[gameSelected]; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Swap To Melee = ")!=NULL)
      {
        removeSubstring(line, "Swap To Melee = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = SwapMelee_FUNCTIONS[gameSelected]; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Reload = ")!=NULL)
      {
        removeSubstring(line, "Reload = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Reload; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Interact = ")!=NULL)
      {
        removeSubstring(line, "Interact = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Interact_FUNCTIONS[gameSelected]; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Crouch = ")!=NULL)
      {
        removeSubstring(line, "Crouch = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Crouch; inputList[i].inpNum = hexVal;
        i++;
      }
      else if (strstr(line,"Sprint = ")!=NULL)
      {
        removeSubstring(line, "Sprint = ");
        sscanf(line, "%x", &hexVal);
        inputList[i].isDown = 0; inputList[i].gameFunction = Sprint; inputList[i].inpNum = hexVal;
        i++;
      }
    }
}

//Read/Create the COD input file
struct Input* COD_Input_Reader()
{
  totalInputs = 0;

  FILE* CODInputs = fopen("DS_COD_Controls.txt", "r");
  if (CODInputs == NULL) 
  {
    // File not found, create a new CODInputs
    CODInputs = fopen("DS_COD_Controls.txt", "w");

    if (CODInputs != NULL) 
    {
      // Write data to the CODInputs if needed
      fprintf(CODInputs, "Edit Controls for COD games in this file.\nInputs must be denoted by their corresponding hex values as denoted here: \nhttps://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes \n\n");
      
      fprintf(CODInputs, "Shoot = 0x01\n");
      fprintf(CODInputs, "ADS = 0x02\n");
      fprintf(CODInputs, "Mouse Manual Reset = 0x04\n");
      fprintf(CODInputs, "Swap Weapon = 0x31\n");
      fprintf(CODInputs, "Swap To Grenade = 0x32\n");
      fprintf(CODInputs, "Swap Grenade Type = 0x51\n");
      fprintf(CODInputs, "Reload = 0x52\n");
      fprintf(CODInputs, "Interact = 0x45\n");
      fprintf(CODInputs, "Crouch = 0xA2\n");
      fprintf(CODInputs, "Sprint = 0xA0\n");
      
      fprintf(CODInputs, "\nInputs below only work in MW3 and Black Ops\n\n");
      fprintf(CODInputs, "Swap To Melee = 0x46\n");

      // Close the CODInputs
      fclose(CODInputs);
      
      totalInputs = 11;
      
      //open the recently created input file
      FILE* CODInputs = fopen("DS_COD_Controls.txt", "r");

      //create the inputstruct list, the length set to the default number of inputs from the generic inputs.txt
      struct Input* inputList = malloc(totalInputs * sizeof(struct Input));
      
      //Generate the inputs
      GenerateInputs_COD(CODInputs, inputList);


      fclose(CODInputs);

      //return the inputlist
      return inputList;
    } 
    else
    {
      printf("Error creating CODInputs");
    }
  } 
  else 
  {
    // Read data from the CODInputs if needed
    char line[100];
    //Read the text file line by line, and count the number of inputs that need to be in the inputstruct list
    while (fgets(line, sizeof(line), CODInputs) != NULL) 
    {
      //printf("%s", line);
      line[strcspn(line, "\n")] = '\0';
      if ((strstr(line,"Shoot = ")!=NULL) || (strstr(line,"ADS = ")!=NULL) || (strstr(line,"Mouse Manual Reset = ")!=NULL) || strstr(line,"Swap Weapon = ")!=NULL || strstr(line,"Swap To Grenade = ")!=NULL || strstr(line,"Swap Grenade Type = ")!=NULL || strstr(line,"Swap To Melee = ")!=NULL || strstr(line,"Reload = ")!=NULL || strstr(line,"Interact = ")!=NULL || strstr(line,"Crouch = ")!=NULL || strstr(line,"Sprint = ")!=NULL/* || strstr(line,"Pause = ")!=NULL || strstr(line,"Kill = ")!=NULL*/)
      {
       totalInputs++;
      }
    }
    //after counting the inputs, create a list of that many elements
    struct Input* inputList = malloc(totalInputs * sizeof(struct Input));
    //restart reading file
    fseek(CODInputs, 0, SEEK_SET);
    //Generate the inputs 
    GenerateInputs_COD(CODInputs, inputList);
    
    // Close the CODInputs
    fclose(CODInputs);
    
    //return the inputlist
    return inputList;
  }
}