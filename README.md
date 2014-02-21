Server
========

This project is a base for what we can call a scalable server
using windows async sockets, and message driven IO it can handle
huge amount of connections at once. at threshhold CPU usage will
rise periodically, but most of it will be dependent on server specs.
capable of holding huge number of clients.
programmed on codeblocks template for GUI with Dialog Boxes.
executed with -lws2_32 switch for linking winsock 2.0
tested against a DOS program with max connections on a i5 1st gen machine
didn't crash.
didn't test against DDOS.
will have far worse results obviously.
Feel free to point out bugs or optimizations 
shoot message @ kaelsusntrider.raghav@gmail.com

[*]can be modified to work as a reverse proxy on a windows server.