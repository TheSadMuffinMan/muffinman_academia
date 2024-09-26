import pyautogui
import time
import math

def drawCircle():
    R = 50
    (x,y) = pyautogui.size()
    (X, Y) = pyautogui.position((x / 2), (y / 2))

    pyautogui.moveTo((X + R), Y)
    pyautogui.mouseDown()

    for i in range(361):
        if ((i % 6) == 0):
            pyautogui.moveTo((X + (R * math.cos(math.radians(i)))), (Y + (R * math.sin(math.radians(i)))))
        
    pyautogui.mouseUp()


def drawSemiCircleSlow(r):
    centerX = (1920 / 2)
    centerY = (1080 / 2)

    y = (centerY - r)
    x = math.sqrt((r ** 2) - ((y - centerY) ** 2)) + centerX

    oldX = x
    oldY = y

    for i in range(r):
        pyautogui.moveTo(x, y)
        x = math.sqrt((r ** 2) - ((y - centerY) ** 2)) + centerX
        pyautogui.dragTo(x, y)
        tempX = centerX - math.sqrt((r ** 2) - ((y - centerY) ** 2))
        tempOldX = centerX - math.sqrt((r ** 2) - ((oldY - centerY) ** 2))
        pyautogui.moveTo(tempOldX, oldY)
        pyautogui.dragTo(tempX, y)

        oldX = x
        oldY = y

        y = (y + 1)


def main():
    timeDelay = 3 # How long you want the program paused for.
    print("Program paused for", timeDelay, "seconds...")
    time.sleep(timeDelay)

    drawCircle()


main()