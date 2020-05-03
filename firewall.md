This file will provide steps to set up the fire wall along with snort and IP tables.
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

Open the firewall.flows file with an editor and motify for you system as needed. 
IE We have $pi as our device name. This will need to be changed to your device. You will also need to modify the first few lines in firewall.advance to fir your network settings.