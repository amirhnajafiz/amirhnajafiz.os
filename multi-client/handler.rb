#!/usr/bin/env ruby

# Handling clients in this method
def client_handler (client = nil, id)
    puts "Client AASS#{id} accepted"
    client.puts(Time.now.ctime)
    client.puts("Closing the connection by server!")
    client.close
    puts "Client AASS#{id} disconncted !"
end