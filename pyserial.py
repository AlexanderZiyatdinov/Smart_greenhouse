import os, pty, serial

master, slave = pty.openpty()
s_name = os.ttyname(slave)
print(master, slave, s_name)

s_name = '/dev/ttys002'
ser = serial.Serial(s_name)

# To Write to the device
ser.write(b'Your text')

# To read from the device
while True:
    data = os.read(master, 1000)
    print(data)

