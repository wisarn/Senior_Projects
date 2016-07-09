#!/usr/bin/python

import sys,time,socket

sys.path.insert(0,"/usr/lib/python2.7/bridge/")
from bridgeclient import BridgeClient
client = BridgeClient()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.settimeout(5)
while 1:
	ttt = client.get("temp")
	dur = client.get("water_duration_min")
	print ttt[0]
	print dur
	if float(ttt[0]) > 35.0:
		print "turn on valve\n"
		try:
			s.connect(("192.168.240.146",8081))
		except:
			print "Unable to connect"
			exit()
		s.send("GET /a0 /HTTP1.1 \r\n")
		time.sleep(int(dur))
		print "turn off valve\n"
		s.send("GET /a1 HTTP/1.1\r\n")
		s.close()
		time.sleep(5)
	
	time.sleep(5)

