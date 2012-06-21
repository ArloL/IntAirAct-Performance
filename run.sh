#!/bin/sh
cd testing
ant -Dcount=1000 -DlogPrefix=HelloCocoaHTTPServer run-test convert import clean
