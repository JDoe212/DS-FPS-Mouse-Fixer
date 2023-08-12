DS Mouse Input Fix V 1.4

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

CHANGING WAIT TIMES AND OTHER SETTINGS

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

Another Setting that can be changed in this config file is whether or not you want the program to automatically recenter and drag your mouse across your screen for you.
This is done by changing the "autoMouseDrag" value. Set this equal to 0, to turn off auto mouse drag, or 1 to turn it on.
By default, it is set to 1. 

IMPORTANT:
If you choose to play with this setting off, be warned you will have to drag your mouse with RIGHT CLICK, unless you bind a key to do it with external software, in which case, you will have to bind it to right click.
You should also make sure that the keybinds config file does not have any function bound to RIGHT CLICK either if you choose to play with this setting off.

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

Here is a list of the default controls.

Multiple games:
Shoot/attack = left mouse
ADS/Zoom = right mouse
Reload = R key
Interact = E key
Crouch = Left Control
Sprint = Right Shift
Manual Mouse Reset = Middle Mouse

COD:
Swap weapon (COD) = 1 key
Swap to grenade (COD) = 2 key
Swap Grenade Type (COD) = q key
Swap To Melee (COD) = f key

DEM:
Next Weapon (DEM) = Mouse side button M5
Items (DEM) = G
Resume (DEM) = 2 key
Map (DEM) = M key
Jump (DEM2) = space bar
Flashlight (DEM2) = f key
Equipment (DEM2) = 1 key
Notepad (DEM1) = Q key
Hotbar 1 - Hotbar 8 (DEM1) = 1 key through 8 key 

MPH:
Screen Tap Jump (MPH) = RIGHT CONTROL
Jump (MPH) = Space bar
Ball (MPH) = LEFT CONTROL
Scan vision (MPH) = V key
Special Weapon (MPH) 1 - 6 = 1 - 6 keys
Swap to main weapon (MPH) = Q key
Swap to missiles (MPH) = E key
Swap to third weapon = R key
Select "Yes" in menu = Mouse Back button
Select "No" in menu = Mouse Forward button
Select Left Arrow in menu = Z key
Select Right Arrow in menu = C key