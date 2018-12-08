#!/bin/bash

echo 21 > /sys/class/gpio/export
sleep 1
echo out > /sys/class/gpio/gpio21/direction
sleep 1
echo 1 > /sys/class/gpio/gpio21/value
sleep 1
echo 0 > /sys/class/gpio/gpio21/value
sleep 1
echo 1 > /sys/class/gpio/gpio21/value

exit 0

