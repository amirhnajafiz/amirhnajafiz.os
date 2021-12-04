#!/usr/bin/env ruby

# Implementing the user client in ruby programming language
require 'socket'

host = 'localhost'
port = 2000 

s = TCPSocket.open(host, port)  # Opening client socket
puts "Connected to #{host}:#{port}"

while line = s.gets
    puts line.chop
end

s.close

puts "Disconnected sucessfully !"