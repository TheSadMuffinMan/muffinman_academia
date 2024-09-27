# Program draws a stick man named Murphy!
# CHALLENGE: Babe-tastic wants Murphy to have curly hair.

import pyautogui
import time
import math

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

    (x,y) = pyautogui.position()

    drawMurphy(x,y)

main()