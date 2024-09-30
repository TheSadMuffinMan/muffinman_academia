# Program draws a stick man named Murphy!
# CHALLENGE: Babe-tastic wants Murphy to have curly hair.

import pyautogui
import time
import math

# Function changes the color and moves the cursor back to where it began.
# Color 0: Black
# Color 1: Grey
# Color 2: Red
# Color 3: Orange
# Color 4: Yellow
# Color 5: Lime Green
# Color 6: Cyan
# Color 7: Blue
# Color 8: Pink
# Color 9: Tan-ish Pink
# Color 10: Neon Green
# Color 11: White
# Color 12: Lighter Grey
# Color 13: Sienna
# Color 14: Dark Brown
# Color 15: Dark Green
# Color 16: Blue-Green
# Color 17: Dark Blue
# Color 18: Darker Purple
# Color 19: Lighter Purple
# Color 20: Lighter Yellow
def changeColor(colorNum):
    currentPosition = pyautogui.position()
    if (colorNum == 0): # Black
        pyautogui.moveTo(215, 940)
        pyautogui.click()
    elif (colorNum == 1): # Grey
        pyautogui.moveTo(230, 940)
        pyautogui.click()
    elif (colorNum == 2): # Red
        pyautogui.moveTo(255, 940)
        pyautogui.click()
    elif (colorNum == 3): # Orange
        pyautogui.moveTo(285, 940)
        pyautogui.click()
    elif (colorNum == 4): # Yellow
        pyautogui.moveTo(315, 940)
        pyautogui.click()
    elif (colorNum == 5): # Lime Green
        pyautogui.moveTo(340, 940)
        pyautogui.click()
    elif (colorNum == 6): # Cyan
        pyautogui.moveTo(365, 940)
        pyautogui.click()
    elif (colorNum == 7): # Blue
        pyautogui.moveTo(390, 940)
        pyautogui.click()
    elif (colorNum == 8): # Pink
        pyautogui.moveTo(415, 940)
        pyautogui.click()
    elif (colorNum == 9): # Tan-ish Pink
        pyautogui.moveTo(440, 940)
        pyautogui.click()
    elif (colorNum == 10): # Neon Green
        pyautogui.moveTo(470, 940)
        pyautogui.click()

    # Wait a minute... There's a much easier way to do this T_T......
    # Calculate (x,y) based off of input rather than utilizing (essentially) switch cases.
    pyautogui.moveTo(currentPosition)



# Function draws a top hat.
def drawTopHat(x,y, width, height):
    pyautogui.mouseDown()
    pyautogui.moveTo((x - (width / 2)), y)
    pyautogui.moveTo((x - (width / 2)), (y - (height / 3)))
    pyautogui.moveTo((x - (width / 4)), (y - (height / 3)))
    pyautogui.moveTo((x - (width / 4)), (y - height))
    pyautogui.moveTo((x + (width / 4)), (y - height))
    pyautogui.moveTo((x + (width / 4)), (y - (height / 3)))
    pyautogui.moveTo((x + (width / 2)), (y - (height / 3)))
    pyautogui.moveTo((x + (width / 2)), y)
    pyautogui.moveTo(x,y)
    pyautogui.mouseUp()

# Function draws a circle around coordinates (x,y).
def drawCircle(x,y,r):
    pyautogui.moveTo((x + r), y)
    pyautogui.mouseDown()

    for i in range(361):
        if ((i % 6) == 0):
            pyautogui.moveTo((x + (r * math.cos(math.radians(i)))), (y + (r * math.sin(math.radians(i)))))
        
    pyautogui.mouseUp()

# Pass this function the bottom coordinates of where you'd like to draw Murphy.
# Function draws Murphy directly above your passed coordinates.
def drawMurphy(x,y):
    murphy_pelvis = (x, (y - 75))
    pyautogui.moveTo(murphy_pelvis)

    # Drawing left leg.
    murphy_Lfoot = ((x - 25), y)
    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_Lfoot, duration = 0.25)
    pyautogui.mouseUp()

    # Drawing right leg.
    pyautogui.moveTo(murphy_pelvis)
    murphy_Rfoot = ((x + 25), y)

    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_Rfoot, duration = 0.25)
    pyautogui.mouseUp()

    pyautogui.moveTo(murphy_pelvis) # Moving back to pelvis.

    # Drawing Murphy's body.
    murphy_base_head = (x, (y - 175))
    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_base_head, duration = 0.25)
    pyautogui.mouseDown()

    murphy_shoulder = (x, (y - 150)) # Declaring where Murphy's shoulder is.
    pyautogui.moveTo(murphy_shoulder)

    # Drawing left arm.
    murphy_Larm = ((x - 25), (y - 120))
    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_Larm)
    pyautogui.mouseUp()

    # Drawing right arm.
    pyautogui.moveTo(murphy_shoulder)
    murphy_Rarm = ((x + 25), (y - 120))
    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_Rarm)
    pyautogui.mouseUp()

    # Drawing head.
    murphy_head_radius = 30
    pyautogui.moveTo(murphy_base_head)
    drawCircle(x, (y - 175 - murphy_head_radius), murphy_head_radius)

    # Drawing Top Hat.
    murphy_top_head = (x, (y - 175 - (murphy_head_radius * 2)))
    pyautogui.moveTo(murphy_top_head)
    drawTopHat(x, (y - 175 - (murphy_head_radius * 2)), murphy_head_radius, murphy_head_radius)

def main():
    timeDelay = 3 # How long you want the program paused for.
    print("Program paused for", timeDelay, "seconds...")
    time.sleep(timeDelay)

    changeColor(10)

    # drawMurphy(x,y)

main()