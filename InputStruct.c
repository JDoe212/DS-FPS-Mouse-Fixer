/*
purpose: This file contains a struct used to listen for user inputs and perform actions accordingly. 
The struct contains: 
  an int to determine if the button is down or not
  a pointer to a game function
  an int to determine what key this input listens for
*/

struct Input {
  int isDown;
  void (*gameFunction)();
  int inpNum;
};