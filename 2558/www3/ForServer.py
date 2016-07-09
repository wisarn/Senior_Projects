import sys, time, os
sys.path.insert(0, "/usr/lib/python2.7/bridge/")
from bridgeclient import BridgeClient

client = BridgeClient()

#ctempp = form.getvalue("tempp")
#chumit = form.getvalue("Humit")

client.put("ctempp",ctempp)
client.put("chumit",chumit)

print "Content-type: text/plain"
print
try:
        print "TEST !!!"
except:
        print "Error"
