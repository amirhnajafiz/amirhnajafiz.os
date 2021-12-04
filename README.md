# Ruby Connection

Creating a server-client application with Ruby programming language.

<p align="center">
    <img src="https://christianmuellerdesign.files.wordpress.com/2014/06/drawing.jpg" width="600" />
</p>

## What are sockets ?
Sockets are the **endpoints** of a bidirectional communications channel. Sockets may communicate within a process, between processes on the same machine, or between processes on different continents.

Sockets may be implemented over a number of different channel types: Unix domain sockets, TCP, UDP, and so on. The socket provides specific classes for handling the common transports as well as a generic interface for handling the rest.

## TCPSocket in Ruby
Ruby class **TCPSocket** provides open function to open such a socket.

The **TCPSocket.open(hosname, port )** opens a TCP connection to hostname on the port.

Once you have a socket open, you can read from it like any IO object. When done, remember to close it, as you would close a file.

Ex:
```ruby
s = TCPSocket.open("127.0.0.1", 8080)
```

## TCPServer in Ruby
A **TCPServer** object is a factory for TCPSocket objects.
 
Now call **TCPServer.open(hostname, port )** function to specify a port for your service and create a TCPServer object.

Ex:
```ruby
server = TCPServer.open(8080)
```

## How to run ?
Use the following command for starting the server on a port:
```shell
ruby ./server.rb [port]
```

Response should be like this:
```shell
Listening on port 8080 ....
```

And after that you can run clients by the following command:
```shell
ruby ./client.rb [domain] [port]
```
