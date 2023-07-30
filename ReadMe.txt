DS Mouse Input Fix V 1.0

This tool aims to make DS FPS games more enjoyable by adding custom inputs that map to mouse inputs and keyboard macros, so that the player can simply focus on the game.

IMPORTANT: IF THE SCRIPT CRASHES AND YOUR MOUSE 1 AND MOUS 2 INPUTS ARE STILL REVERSED, RUN "Fix Mouse.exe" THIS SHOULD FIX THE ISSUE

HOW TO USE

First we must make sure that your melon DS inputs match the scripts requirements,
those should look like this:

up, down, left, right = can be whatever buttons you see fit, as long as they are not listed below
Y, A, B = can be whatever buttons you see fit, as long as they are not listed below
Select, Start = can be whatever buttons you see fit, as long as they are not listed below

X = Space key

L = N key

R = M key

You do not need to create any config files ahead of time in fact I recommend you dont and let the script write them for you

Before getting started REMEMBER, Kill the program at any time with BACKSPACE and Pause it at any time with RIGHT_SHIFT

steps to get started:

1)  Run the "DS Mouse Input Fix.exe" 

2)  Read the information presented in the window

3)  Select the game you wish to play from the drop down menu

REMINDER: After pressing start you have 2 seconds before the window screen turns red. Once the screen has turned red, the script is active.

4)  Press Start when ready

5)  Once the script is active DO NOT CLICK, align your mouse loosly with the bottom left corner of your stylus play space, and click once, next align it with the top right corner and click again.

6)  At this point you should be good to go. Your cursor should automatically center and your inputs should be heard. Depending on what game you chose the script will have generated some input config files, and you can adjust them as you please.

AGAIN ALWAYS REMEMBER: BACKSPACE TO KILL, RIGHT_SHIFT TO Pause

======================================================================================================================================================

CHANGING WAIT TIMES

This script uses wait times within its inputs in order to make sure the DS emulator actually catches the desired input. Sometimes however these waits are too short, and can result in ghost inputs and camera stealing.
To remedy this, there is a DS_Config.txt that this script will generate.

Within that file there are 4 values that can be changed:

mouseResetWait pertains to the time before the mouse moves again, adjust this if your camera keeps jerking when your cursor is reset to center.
buttonWait pertains to the time before the mouse moves after pressing a button, adjust this if you get ghost inputs (buttons not properly pressed).
swapWait is COD specific, pertains to the time wait between swapping weapons in the COD games, adjust accordingly.
keyWait pertains to the time between key inputs, this is used for some macros such as sprinting and crouching in the COD Games, adjust this if those inputs are not caught.

Please note that the times MUST be written in milliseconds. ie: 1000 = 1 second of wait time.

These are the defaults: mouseResetWait = 35, buttonWait = 100, swapWait = 220, keyWait = 50.

DO NOT define more than one of these values on the same line.
DO NOT include any other text on a line in which these values are defined.

If you mess up this file too much and start getting crashes, just delete this txt, and the script will fix it for you.

======================================================================================================================================================

CHANGING INPUTS

Each game that this script covers has unique inputs, some of them are shared if the games are similar enough (COD series, Dementium 1 and 2)

The script will generate these files if it does not detect them, then you can edit them.

Note the Input keys must be denoted by their corresponding hex values as denoted here: 
https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes 

DO NOT define more than one of these inputs on the same line.
DO NOT include any other text on a line in which these inputs are defined.

If you would like to customize your keybinds you can do so in any of the Controls text files.

If you mess up these files too much and start getting crashes, just delete them, and the script will fix it for you.
