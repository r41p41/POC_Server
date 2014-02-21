Server
========
<br>This project is a base for what we can call a scalable server
<br>using windows async sockets, and message driven IO it can handle
<br>huge amount of connections at once. at threshhold CPU usage will
<br>rise periodically, but most of it will be dependent on server specs.
<br>capable of holding huge number of clients.
<br>programmed on codeblocks template for GUI with Dialog Boxes.
<br>executed with -lws2_32 switch for linking winsock 2.0
<br>tested against a DOS program with max connections on a i5 1st gen machine
<br>didn't crash.
<br>didn't test against DDOS.
<br>will have far worse results obviously.
<br>Feel free to point out bugs or optimizations 
<br>shoot message @ kaelsusntrider.raghav@gmail.com
<br>
[*]can be modified to work as a reverse proxy on a windows server.
