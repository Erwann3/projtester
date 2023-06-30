#!/bin/bash

gcc ./requirement.c -o requirement

output=$(./requirement)

parent_pid=$(echo "$output" | grep "Parent process ID" | awk '{print $4}')
child_pid=$(echo "$output" | grep "Child process ID" | awk '{print $4}')

echo "Parent PID: $parent_pid"
echo "Child PID: $child_pid"

parent_status=$(ps -o pid,ppid,stat,cmd -ax | grep $parent_pid | awk '{print $3}')
echo "Parent process status: $parent_status"