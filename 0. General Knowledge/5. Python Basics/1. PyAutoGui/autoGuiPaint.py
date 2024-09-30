import pyautogui
import time

# Function changes the color and moves the cursor back to where it began.
def changeColor(colorNum):
    # Validating input.
    while ((colorNum < 0) or (colorNum > 21)):
        colorNum = input("Invalid color selection. Please input color number: ")

    currentPosition = pyautogui.position()

    if ((colorNum >= 0) & (colorNum <= 10)): # If we want the top row...
        y = 940
        x = (215 + (colorNum * 25))
        pyautogui.moveTo(x,y)

    if ((colorNum > 10) & (colorNum <= 21)): # If we want the bottom row...
        colorNum = (colorNum - 11) # Getting rid of first char for easier calculations later.
        y = 965
        x = (215 + (colorNum * 25))
        pyautogui.moveTo(x,y)

    pyautogui.click()
    pyautogui.moveTo(currentPosition)

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