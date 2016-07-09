#!/usr/bin/python

# Arduino Meets Linux:
# The User's Guide to Arduino Yun Development
# Copyright (c) 2015, Bob Hammell.
#
# Disclaimer:
# This code is provided by ArduinoMeetsLinux.com on an "AS IS"
# basis. ArduinoMeetsLinux.com makes no warranties, express or
# implied, regarding use of the code alone or in combination with
# your projects.
#
# In no event shall ArduinoMeetsLinux.com be liable for any special,
# indirect, incidental, or consequential damages (including, but not
# limited to, loss of data and damage to systems) arising in any way
# out of the use, reproduction, modification and/or distribution of
# this code.

import sys, time, os
sys.path.insert(0, "/usr/lib/python2.7/bridge/")
from bridgeclient import BridgeClient

client = BridgeClient()
#client.put("MCP9808_Temperature",54)
#temp = float(client.get("MCP9808_Temperature"))
temp1 = client.get("temp")
temp = temp1[0]
unit = os.environ["QUERY_STRING"]
if unit == "":
   unit = "C"

print "Content-type: text/html"
print
print """
<!DOCTYPE html>
<html>
<head>
    <title>Project 1 - Building a Web-Based Temperature Monitor</title>
    <link rel="stylesheet" href="/css/normal.css" type="text/css" />
    <meta http-equiv="refresh" content="10">
    <meta charset="UTF-8">
</head>
<body>
    <div id="panel">
        <p id="temperature" class="lcd">
"""

if unit == "F":
    temp = (temp * (9/5)) + 32
print ("%.1f" % temp)

print """
        </p>
        <p id="unit" class="lcd">
"""

print unit

print """
        </p>
        <p id="date" class="lcd">
"""

print time.strftime("%m/%d/%Y")

print """
        </p>
        <p id="time" class="lcd">
"""

print time.strftime("%H:%M")

print """
        </p>
        <input type="button" id="btnUnit" 
"""

if unit == "F":
        print "onclick=\"javascript:location.href='/?C'\""
else:
        print "onclick=\"javascript:location.href='/?F'\""

print """
        value="Unit" />
        <input type="button" id="btnRefresh" onclick="location.reload();" value="Refresh" />
    </div>
</body>
</html>
"""
