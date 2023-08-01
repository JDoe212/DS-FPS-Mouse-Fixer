/*
purpose: This file containts the config reader for this script as a whole. It reads the wait times that the game functions operate on. 
*/

extern float mouseResetWait, buttonWait, swapWait, keyWait;

extern int totalInputs;
extern int gameSelected;

//Take two strings, whole string, substring to be removed, and return the string - substring
void removeSubstring(char *string, const char *substring) 
{
    char *match = strstr(string, substring);
    size_t subLen = strlen(substring);

    if (match != NULL) {
        memmove(match, match + subLen, strlen(match + subLen) + 1);
    }
}

//Create/Read the config file as well as give instructions on how it is used
void ConfigReader()
{
  FILE* ConFile = fopen("DS_Config.txt", "r");

  if (ConFile == NULL) 
  {
    // File not found, create a new ConFile
    ConFile = fopen("DS_Config.txt", "w");

    if (ConFile != NULL) 
    {
      // Write data to the ConFile if needed
      fprintf(ConFile, "VALUES\n\n");
      fprintf(ConFile, "mouseResetWait = 35\nbuttonWait = 120\nswapWait = 220\nkeyWait = 50\n\n");
      
      // Close the ConFile
      fclose(ConFile);
    } 
    else
    {
      //printf("Error creating ConFile");
    }
  } 
  else 
  {
    // Read data from the ConFile if needed
    char line[100];
    //read the config file line by line for specific keywords
    /*
    for each line:
    search for a keyword
    remove the keyword from the line
    use the remainder of the line as an int value
    use this int value to set that specific wait time
    */
    while (fgets(line, sizeof(line), ConFile) != NULL) 
    {
      //printf("%s", line);
      line[strcspn(line, "\n")] = '\0';
      if (strstr(line,"mouseResetWait = ")!=NULL)
      {
        removeSubstring(line, "mouseResetWait = ");
        mouseResetWait = atof(line);
        //printf("%s", line);
      }
      else if (strstr(line,"buttonWait = ")!=NULL)
      {
        removeSubstring(line, "buttonWait = ");
        buttonWait = atof(line);
      }
      else if (strstr(line,"swapWait = ")!=NULL)
      {
        removeSubstring(line, "swapWait = ");
        swapWait = atof(line);
      }
      else if (strstr(line,"keyWait = ")!=NULL)
      {
        removeSubstring(line, "keyWait = ");
        keyWait = atof(line);
      }
    }
    // Close the ConFile
    fclose(ConFile);
  }
}
