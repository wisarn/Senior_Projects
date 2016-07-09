#!/usr/bin/python

import sys

sys.path.insert(0,"/usr/lib/python2.7/bridge/")
from bridgeclient import BridgeClient
client = BridgeClient()
client.put("temp", 20.0)
client.put("humid",60.0)
client.put("water_duration_min", 10)
client.put("food_duration_hr",5)
client.put("ctempp",35.0)
client.put("chumit",60.0)
