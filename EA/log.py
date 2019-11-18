import serial
from datetime import datetime

sensor = "DH11"
serial_port = '/dev/cu.wchusbserialfa130'
baud_rate = 9600
today = datetime.now()
today = today.strftime("%d_%m_%Y")
log_file = "log_"+today+".txt"
ser = serial.Serial(serial_port, baud_rate)
output_file = open(log_file, "w+")
logs = 0
while True:
    line = ser.readline()
    line = line.decode("utf-8")
    logs+=1
    if "Write logs down" in line or logs == 10:
        print("Oh, write that down")
        logs = 0
        output_file.close()
        output_file = open(log_file, "w+")
    else:
        output_file.write(line + str(datetime.now()))
        print(line)
