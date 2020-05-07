This file will provide steps to set up the fire wall/IP tables.
Credit to firewall.advanced, firewall.flows to Guillaume Kaddouch

The firewall.advance script basically does the following:
– Blocks inbound/outbound invalid TCP flags (even from established flows)
– Optimises DNS queries (IP TOS field)
– Identifies traffic by flow type, and then match it against a ruleset
– Adds randomness to the NAT process
– Only allow few outbound standard ports (http, https, ftp)
– Logs accurately what is dropped and avoid log flood
– Drops inbound packets with low TTL (could mean a ttl expiry attack or a traceroute)
– Detect & block outbound malware connections

Run these commands in the terminal before applying the rules within firewall.flows and firewall.advanced
$ sudo touch /etc/firewall.advanced
$ sudo touch /etc/firewall.flows
$ sudo chmod u+x /etc/firewall.*

Open the firewall.flows file with an editor and copy and paste the firewall.flows file we have into it. Make sure you modify for you system as needed. 
IE We have $pi as our device name. This will need to be changed to your device. You will also need to modify the first few lines in firewall.advance to fir your network settings.

Follow the same processes for the firewall.advnaced file. 

The next thing we will do is custimize the network parameters, to do this all you need to do is open "/etc/sysctl.conf" and take our sysctl.conf file and paste the contents into yours.