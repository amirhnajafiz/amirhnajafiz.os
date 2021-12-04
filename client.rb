#!/usr/bin/env ruby

# Implementing the user client in ruby programming language
require 'socket'

host = ARGV[0]       # Domain name
port = ARGV[1].to_i  # Port number

s = TCPSocket.open(host, port)  # Opening client socket
puts "Connected to #{host}:#{port}"

while line = s.gets
    puts line.chop
end

s.close

puts "Disconnected sucessfully !"