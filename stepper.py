import serial
import tkinter

arduinoData = serial.Serial('com8', 9600)


def positiveDirection():
    arduinoData.write(b'b')

def negativeDirection():
    arduinoData.write(b'a')


motor_control_window = tkinter.Tk()
motor_control_window.geometry("1000x1000")

Button = tkinter.Button

btn = Button(motor_control_window, text="ClockWise",height=20,width=20, command=positiveDirection)
btn1 = Button(motor_control_window, text="Anti-ClockWise",height=20,width=20, command=negativeDirection)

btn.config(font=("ClockWise",20))
btn1.config(font=("Anti-ClockWise",20))

btn.grid(row=40,column=50)
btn1.grid(row=40,column=100)
motor_control_window.mainloop()


