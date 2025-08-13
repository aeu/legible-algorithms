
# Multi-Threaded Client Server Demo

Implementation of a client and server.  The server listens on port 51000, to all
possible addresses.  The client program spawns two thread that connect to the
server and send a message to it which is echoed to the console.  The server
spawns a worker thread per client.  Additionally the client keeps track of the
count of messages sent.  Both client threads update the count, which is
protected by a mutex.

# Reminder:

## Client

socket()
connect()
read()/write()
close()

## Server

socket()
bind()
listen()
accept()
read()/write()
close()
