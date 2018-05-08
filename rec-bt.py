#!/usr/bin/env python

from bluetooth import *

hostMACAddress = 'B8:27:EB:8C:D0:6B' # The MAC address of a Bluetooth adapter on the server. The server might have multiple Bluetooth adapters.
port = PORT_ANY
backlog = 1
size = 1024
s = BluetoothSocket(RFCOMM)
s.bind((hostMACAddress, port))
s.listen(backlog)
client = "init"
#print bluetooth.
#import subprocess
#cmd = 'sudo hciconfig hci0 piscan'
#subprocess.check_output(cmd, shell = True )

def getConf(index):
    pass

def getActive():
    pass


def setConf(index, conf):
    pass

def setActive(newactive):
    pass

def setMachineconf():
    pass


def getMachineconf():
    pass



try:
    print("accepting")
    client, clientInfo = s.accept()
    print ("accepted")
    while 1:
        data = client.recv(size)
        if data:
            print(data)
            client.send(data) # Echo back to client
except:	
    print("Closing socket")
    client.close()
    s.close()
