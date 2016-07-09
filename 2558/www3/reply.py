#!/usr/bin/python

import cgi,sys,os

form = cgi.FieldStorage()
sys.path.insert(0,"/usr/lib/python2.7/bridge/")
from bridgeclient import BridgeClient

temps = float(form.getvalue("tempp"))
client = BridgeClient()
client.put("temp", 25)

print "Content-type: text/plain"
print
try:
	print "TEST !!!"
except:
        print "Error"
