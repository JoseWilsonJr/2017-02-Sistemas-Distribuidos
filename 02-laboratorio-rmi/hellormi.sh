#!/bin/bash
killall rmiregistry
javac hellormi/Server.java
javac hellormi/Client.java
rmiregistry &

java -Djava.rmi.server.codebase=file:hellormi/ -Djava.rmi.server.hostname="127.0.0.1" hellormi.Server &
