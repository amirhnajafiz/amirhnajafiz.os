#!/usr/bin/env ruby

# Implementing a server in ruby programming language.
require 'socket'

port = ARGV[0].to_i

server = TCPServer.open(port)  # Opening the server socket
puts "Listening on port #{port} ...."

i = 0

loop {
    client = server.accept  # Waiting for client to join
    i += 1
    puts "Client AASS#{i} accepted"
    client.puts(Time.now.ctime)
    client.puts("Closing the connection by server!")
    client.close
    puts "Client AASS#{i} disconncted !"
}

puts "Server terminated !"