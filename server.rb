#!/usr/bin/env ruby

# Implementing a server in ruby programming language.
require 'socket'

server = TCPServer.open(2000)  # Opening the server socket
puts "Listening on port 2000 ...."

loop {
    client = server.accept  # Waiting for client to join
    puts "Client #{client} accepted"
    client.puts(Time.now.ctime)
    client.puts("Closing the connection by server!")
    client.close
    puts "Client #{client} disconncted !"
}

puts "Server terminated !"