import os, pty, serial

master = 3
s_name = '/dev/ttys002'
ser = serial.Serial(s_name)


while True:
    data = ser.write(input().encode())
    print('> ', os.read(master, 1000))
