#!/bin/bash
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
#sleep 4
$SCRIPT_DIR/RoudedScreenCorners 0 &
$SCRIPT_DIR//RoudedScreenCorners 1 &
$SCRIPT_DIR//RoudedScreenCorners 2 &
$SCRIPT_DIR//RoudedScreenCorners 3 &
