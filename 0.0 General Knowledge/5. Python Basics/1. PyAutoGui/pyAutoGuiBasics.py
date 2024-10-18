# Documentation located at:
# https://github.com/asweigart/pyautogui/blob/master/README.md

import pyautogui

screenWidth, screenHeight = pyautogui.size() # Sets the screen width and height of primary monitor.
currentMouseX, currentMouseY = pyautogui.position() # Returns current position of mouse.

pyautogui.click() # Clicks the mouse at it's current location.
pyautogui.doubleClick() # Double clicks the mouse.
pyautogui.click(currentMouseX, currentMouseY) # Clicks at X,Y.

pyautogui.move(None, 10) # Moves the mouse 10 pixels down from it's current position.
pyautogui.drag(None, -10) # Clicks and drags from relative position.

pyautogui.write("Hello world!", interval = 0.25) # Types message with quarter second pause between each input.
# pyautogui.press('esc') # Simulates pressing the "ESC" key.

# Need to install pyMsgBox library to use the following code...
# pyautogui.alert("This is an alert box.")
# pyautogui.confirm("Shall the program proceed?")
# pyautogui.prompt("What is your name?")
# pyautogui.password("Enter PW (text will be hidden): ")
