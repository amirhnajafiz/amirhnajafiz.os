#!/usr/bin/env ruby

# Implementing a server in ruby programming language.
require 'socket'
require './handler'

port = ARGV[0].to_i

server = TCPServer.open(port)  # Opening the server socket
puts "Listening on port #{port} ...."

i = 0

loop {
    Thread.start(server.accept) do |client| # Waiting for client to join
        i += 1
        client_handler client, i  # Calling client handler method
    end
}

puts "Server terminated !"