import requests, serial, time
from datetime import datetime

API = "http://192.168.0.45:3000"
sensor = "DH11"
serial_port = '/dev/cu.wchusbserialfa130'
baud_rate = 115200
today = datetime.now()
today = today.strftime("%d_%m_%Y")
log_file = "Logs/log_"+today+".txt"
ser = serial.Serial(serial_port, baud_rate, timeout=.1)
time.sleep(1)  # give the connection a second to settle)
data = []
log = {}
while True:
    ser.write("123e234e345ef".encode())
    line = ser.readline().strip()
    line = line.decode("utf-8")
    if line:
        if len(data) == 10:
            output_file = open(log_file, "a+")
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
            rsp_light = requests.post(url=API+"/light", data=log_light)
            rsp_temperature = requests.post(url=API+"/temperature", data=log_temperature)
            rsp_water = requests.post(url=API+"/water", data=log_water)
            print(line, rsp_light.text, rsp_temperature.text, rsp_water.text)
