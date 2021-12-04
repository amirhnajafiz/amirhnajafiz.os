#!/usr/bin/env ruby

# Implementing a server in ruby programming language.
require 'socket'

def client_handler (client = nil, id)
    puts "Client AASS#{id} accepted"
    client.puts(Time.now.ctime)
    client.puts("Closing the connection by server!")
    client.close
    puts "Client AASS#{id} disconncted !"
end

port = ARGV[0].to_i

server = TCPServer.open(port)  # Opening the server socket
puts "Listening on port #{port} ...."

i = 0

loop {
    Thread.start(server.accept) do |client| # Waiting for client to join
        i += 1
        client_handler client, i
    end
}

puts "Server terminated !"