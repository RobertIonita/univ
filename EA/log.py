import requests
import serial
from datetime import datetime

API = "http://192.168.1.100:3000"
sensor = "DH11"
serial_port = '/dev/cu.wchusbserialfa130'
baud_rate = 9600
today = datetime.now()
today = today.strftime("%d_%m_%Y")
log_file = "Logs/log_"+today+".txt"
ser = serial.Serial(serial_port, baud_rate)
data = []
log = {}
while True:
    line = ser.readline()
    line = line.decode("utf-8")
    if "Write logs down" in line or len(data) == 5:
        print("Oh, write that down")
        output_file = open(log_file, "a")
        for record in data:
            output_file.write(record)
        data = []
        output_file.close()
    else:
        time_stamp = datetime.now().strftime("%H:%M:%S")
        data.append(today+"/"+time_stamp+"-"+line.strip()+"\n")
        line = line.split("-")
        log_light = {
            "date": today,
            "time": time_stamp,
            "value": line[0],
            "set": line[1]
        }
        log_temperature = {
            "date": today,
            "time": time_stamp,
            "value": line[2],
            "set": line[3]
        }
        log_water = {
            "date": today,
            "time": time_stamp,
            "value": line[4],
            "set": line[5]
        }
        response_light = requests.post(url=API+"/light", data=log_light)
        response_temperature = requests.post(url=API+"/temperature", data=log_light)
        response_water = requests.post(url=API+"/water", data=log_light)
        print(line)

output_file.close()
