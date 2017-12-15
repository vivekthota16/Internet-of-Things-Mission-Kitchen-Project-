import serial
import time
import requests
import json

firebase_url = 'https://kitchen-b616e.firebaseio.com/(your firebase url)'
#Connect to Serial Port for communication
ser = serial.Serial('COM13', 9600, timeout=0)
#Setup a loop to send Temperature values at fixed intervals
#in seconds
fixed_interval = 1
while 1:
  try:
#temperature value obtained from Arduino      
    temperaturec = ser.readline()
    
    #current time and date
    timehhmmss = time.strftime('%H:%M:%S')
    datemmddyyyy = time.strftime('%d/%m/%Y')
    
    #current location name
    #temperature_location = 'Flour';
    
    print (temperaturec + ',' + timehhmmss + ',' + datemmddyyyy)
    
    #insert record
    data = {'value':temperaturec}
    result = requests.post(firebase_url + '/' + '/Flour.json', data=json.dumps(data))
    
    print ('Record inserted. Result Code = ' + str(result.status_code) + ',' + result.text)
    time.sleep(fixed_interval)
  except IOError:
   print('Error! Something went wrong.')
  time.sleep(fixed_interval)
