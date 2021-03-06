#!/usr/bin/env python
import Tkinter as tk
from Tkinter import *
import roslib
import rospy
from telebot.msg import Coord



class Application(tk.Frame):
    def __init__(self, master=None):
        frame = tk.Frame.__init__(self, master)
        self.createWidgets(frame)

    #def talker(ID, GOAL_POS, SPEED):
	#msg = Coord()
	#msg.ID = ID
	#msg.GOAL_POS = GOAL_POS
	#msg.SPEED = SPEED
	#rospy.loginfo(msg)
	#rospy.publish(msg)
	     
	     

    def createWidgets(self, frame):

        master = frame

        def show_values(ID, GOAL_POS, SPEED):
	    msg = Coord()
	    msg.ID = ID
	    msg.GOAL_POS = GOAL_POS
	    msg.SPEED = SPEED
	    rospy.loginfo(msg)
	    pub.publish(msg)
            #talker(ID, GOAL_POS, SPEED)
	#def show_fingers(ID, GOAL_POS, SPEED):
	#    msg = Coord()
	#    msg.ID = ID
	#    msg.F1 = GOAL_POS
	#    msg.F2 = GOAL_POS
	#    msg.F3 = GOAL_POS
	#    msg.F4 = GOAL_POS
	#    msg.F5 = GOAL_POS
	#    msg.SPEED = SPEED
	#    rospy.loginfo(msg)
	#    pub.publish(msg)
	    


        w1 = Scale(master, from_=1050, to=3050, length=1400, tickinterval=0, orient=HORIZONTAL, showvalue = 2055)
        w1.pack()
        Button(master, text='Left Wrist(ID 25)', command=lambda: show_values(25, w1.get(), 100)).pack()				#ID 25

        w2 = Scale(master, from_=2000, to=4000, length=1400, tickinterval=0, orient=HORIZONTAL, showvalue = 3015)
        w2.pack()
        Button(master, text='Left Forearm Rotation(ID 24)', command=lambda: show_values(24, w2.get(), 100)).pack()		#ID 24

        w3 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w3.pack()
        Button(master, text='Left Elbow Open/Close(ID 23)', command=lambda: show_values(23, w3.get(), 100)).pack()		#ID 23

        w4 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w4.pack()
        Button(master, text='Left Full Arm Rotation(ID 22)', command=lambda: show_values(22, w4.get(), 100)).pack()		#ID 22

        w5 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w5.pack()
        Button(master, text='Left Shoulder Up/Down(ID 21)', command=lambda: show_values(21, w5.get(), 100)).pack()		#ID 21

        w6 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w6.pack()
        Button(master, text='Left Shoulder Forward/Back(ID 20)', command=lambda: show_values(20, w6.get(), 100)).pack()		#ID 20

	w12 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w12.pack()
        Button(master, text='Right Wrist(ID 35)', command=lambda: show_values(35, w12.get(), 100)).pack()			#ID 35

	w11 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w11.pack()
        Button(master, text='Right Forearm Rotation(ID 34)', command=lambda: show_values(34, w11.get(), 100)).pack()		#ID 34

	w10 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w10.pack()
        Button(master, text='Right Elbow Open/Close(ID 33)', command=lambda: show_values(33, w10.get(), 100)).pack()		#ID 33

	w9 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w9.pack()
        Button(master, text='Right Arm Rotation(ID 32)', command=lambda: show_values(32, w9.get(), 100)).pack()			#ID 32

	w8 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        w8.pack()
        Button(master, text='Right Shoulder Up/Down(ID 31)', command=lambda: show_values(31, w8.get(), 100)).pack()		#ID 31

        #w7 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        #w7.pack()
        #Button(master, text='Right Shoulder Forward/Back(ID 30)', command=lambda: show_values(30, w7.get(), 100)).pack()	#ID 30

	#w15 = Scale(master, from_=0, to=4095, length=1400, tickinterval=1000, orient=HORIZONTAL)
        #w15.pack()
        #Button(master, text='Head Up/Down(ID 20)', command=lambda: show_values(20, w7.get(), 100)).pack()			#ID 20

	#w13 = Scale(master, from_=800, to=1800, length=1400, tickinterval=0, orient=HORIZONTAL, showvalue = 800)
        #w7.pack()
        #Button(master, text='Right Hand(ID ?)', command=lambda: show_fingers(1, w13.get(), 100)).pack()			#ID ?

	#w14 = Scale(master, from_=800, to=1800, length=1400, tickinterval=0, orient=HORIZONTAL, showvalue = 800)
        #w7.pack()
        #Button(master, text='Left Hand(ID ?)', command=lambda: show_fingers(2, w14.get(), 100)).pack()			        #ID ?




pub = rospy.Publisher('motor_coord', Coord, queue_size = 1000)
rospy.init_node('telebot_pub')
app = Application()
app.master.title('Telebot Controller')
app.mainloop()
