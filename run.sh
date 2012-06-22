#!/bin/sh
cd testing
ant -Dcount=100000 -Ddescription=HelloCocoaHTTPServer run-test
#convert import clean
