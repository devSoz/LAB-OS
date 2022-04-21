#!/bin/sh
echo "Enter username to be checked: "
read userName
usr="$(id -u -n)"   #usr holds the current user id
if [[ $usr == $userName ]]; then
    echo "Yes user exist"
else
    echo "No user does not exist"
fi
