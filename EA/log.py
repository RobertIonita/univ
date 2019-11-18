import serial
from datetime import datetime

sensor = "DH11"
serial_port = '/dev/cu.wchusbserialfa130'
baud_rate = 9600
today = datetime.now()
today = today.strftime("%d_%m_%Y")
log_file = "log_"+today+".txt"
ser = serial.Serial(serial_port, baud_rate)
data = []
while True:
    line = ser.readline()
    line = line.decode("utf-8")
    if "Write logs down" in line or len(data) == 10:
        print("Oh, write that down")
        output_file = open(log_file, "w+")
        for record in data:
            output_file.write(record + datetime.now().strftime("%h_%m_%s"))
        data=[]
        output_file.close()
    else:
        data.append(line)
        print(line)
