#!/bin/sh
cd testing
#ant clean
ant -Druntime=100 -DlogPrefix=HelloServer run-test