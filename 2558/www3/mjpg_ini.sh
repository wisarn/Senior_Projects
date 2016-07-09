#!/bin/sh

mjpg_streamer -i "./input_uvc.so -d /dev/video0 -n -f 30" -o "./output_http.so -p 8090" &
