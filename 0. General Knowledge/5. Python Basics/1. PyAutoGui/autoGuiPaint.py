import pyautogui
import time

def drawSquare():
    pyautogui.drag(None, 100, 1, button = 'left') # Drag left mouse relative x, y + 10 over 1 second.
    pyautogui.drag(100, None, 1, button = 'left',)
    pyautogui.drag(None, -100, 1, button = 'left',)
    pyautogui.drag(-100, None, 1, button = 'left',)

def main():
    screenWidth, screenHeight = pyautogui.size() # Sets the screen width and height of primary monitor.
    print("Width: ", screenWidth)
    print("Height: ", screenHeight)
    time.sleep(5) # Pauses the program for 5 seconds so you can switch to kolourpaint.

    screenWidthMiddle = (screenWidth / 2)
    screenHeightMiddle = (screenHeight / 2)

    pyautogui.moveTo(screenWidthMiddle, screenHeightMiddle) # Moves cursor to middle of screen.

    drawSquare()

main()