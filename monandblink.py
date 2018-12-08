#!/usr/bin/python
import os  
import time  
import RPi.GPIO as GPIO
led = 16
GPIO.setmode(GPIO.BCM)  
GPIO.setup(led, GPIO.OUT)  
GPIO.setup(18, GPIO.IN, pull_up_down=GPIO.PUD_UP)
state = False

def Shutdown(channel):  
  print('button pressed the RULES! 2018')
  GPIO.output(led, True)
  time.sleep(0.2)
  GPIO.output(led, False)
  time.sleep(0.2)
  GPIO.output(led, True)
  time.sleep(0.2)
  GPIO.output(led, False)
  os.system("sudo shutdown -h now")

GPIO.add_event_detect(18, GPIO.FALLING, callback = Shutdown, bouncetime = 2000)

while True:  
  found = False
  time.sleep(5)
  pids = [pid for pid in os.listdir('/proc') if pid.isdigit()]
  for pid in pids:
    try:
      cmd = open(os.path.join('/proc', pid, 'cmdline'), 'rb').read()
      if "gimx" in cmd:
        found = True
    except IOError: # proc has already terminated
      continue
  if found == True:
    GPIO.output(led, True)
  else:
    GPIO.output(led, False)

