from cv2.cv import *

img = LoadImage("/home/USER/Pictures/python.jpg")
NamedWindow("opencv")
ShowImage("opencv",img)
WaitKey(0)
