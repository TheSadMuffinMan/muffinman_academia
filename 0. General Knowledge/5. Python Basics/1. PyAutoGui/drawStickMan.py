# Program draws a stick man named Murphy!

import pyautogui
import time
import math

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
def drawStickMan(x,y):
    absoluteBottomCenterCoords = (x,y) # DO NOT CHANGE!!

    murphy_Pelvis = (x, (y - 75))

    pyautogui.click()
    pyautogui.moveTo(murphy_Pelvis)
    pyautogui.click()

    murphy_LFoot = ((x - 25), y)
    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_LFoot, duration = 0.25)
    pyautogui.mouseUp()

    murphy_RFoot = ((x + 25), y)
    pyautogui.moveTo(murphy_Pelvis)
    pyautogui.mouseDown()
    pyautogui.moveTo(murphy_RFoot, duration = 0.25)
    pyautogui.mouseUp()



def main():
    timeDelay = 3 # How long you want the program paused for.
    print("Program paused for", timeDelay, "seconds...")
    time.sleep(timeDelay)

    (x,y) = pyautogui.position()

    drawStickMan(x,y)    


main()