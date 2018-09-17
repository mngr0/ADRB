import bluetooth
import RPi.GPIO as GPIO        #calling for header file which helps in using GPIOs of PI
LED=21
 
GPIO.setmode(GPIO.BCM)     #programming the GPIO by BCM pin numbers. (like PIN40 as GPIO21)
GPIO.setwarnings(False)
GPIO.setup(LED,GPIO.OUT)  #initialize GPIO21 (LED) as an output Pin
GPIO.output(LED,0)
 
server_socket=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
 
port = 1
server_socket.bind(("",port))
server_socket.listen(1)
while 1:
 client_socket,address = server_socket.accept()
 store = open("store.txt","r")
 state = store.read()
 store.close()
 print state
 print "Accepted connection from ",address
 while 1:
  state = client_socket.recv(1024)
  if (state == "q"):
   print ("Quit")
   break
  elif(state == "reqinit"):
   print "req init recv"
   storer = open("store.txt","r")
   state = storer.read()
   storer.close()
   client_socket.send(bytes("ini:"+state))
  elif(state== "logrequest"):
   client_socket.send(bytes("log:"+"log example"))
  else:
   storew = open("store.txt","w") 
   storew.write(state)
   storew.close()
   print "wrote: %s" % state
 client_socket.close()
 print "connection lost, return to listen"
server_socket.close()
