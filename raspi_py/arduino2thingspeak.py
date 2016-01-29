import httplib, urllib
import serial
import time


ser = serial.Serial('/dev/ttyACM0', 9600)
currTime = int(time.time())
data = []

def sendToThingspeak(f1val):
    print f1val
    params = urllib.urlencode({'field3': f1val, 'api_key':'YOURAPIKEY'})
    headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
    conn = httplib.HTTPConnection("api.thingspeak.com")
    conn.request("POST", "/update", params, headers)
    response = conn.getresponse()
    print response.status, response.reason
    data = response.read()
    conn.close()
 
if __name__ == "__main__":
    print("Ctrl+c terminates programm")
    print "Start reading ..."
    try:
        while True:
            while (int(time.time()) - currTime  < 60):
                try:
                    data.append(int(ser.readline()))
                except ValueError:
                    print "ValueError: I try again ..."
            brightnessVal = sum(data) / len(data)
            data = []
            currTime = int(time.time())
            sendToThingspeak(brightnessVal)
    except KeyboardInterrupt:
        ser.close
