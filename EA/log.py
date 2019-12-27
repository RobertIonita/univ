import serial
from datetime import datetime

sensor = "DH11"
serial_port = '/dev/cu.wchusbserialfa130'
baud_rate = 9600
today = datetime.now()
today = today.strftime("%d_%m_%Y")
log_file = "Logs/log_"+today+".txt"
ser = serial.Serial(serial_port, baud_rate)
data = []
while True:
    line = ser.readline()
    line = line.decode("utf-8")
    if "Write logs down" in line or len(data) == 5:
        print("Oh, write that down")
        output_file = open(log_file, "a")
        for record in data:
            output_file.write(record)
        data=[]
        output_file.close()
    else:
        time_stamp = datetime.now().strftime("%H:%M:%S")
        data.append(time_stamp+line.strip()+"\n")
        print(line)

output_file.close()
