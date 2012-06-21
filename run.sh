#!/bin/sh
cd testing
ant -Dcount=100 -Ddescription=HelloCocoaHTTPServer run-test convert import clean
