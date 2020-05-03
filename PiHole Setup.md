This guide is to help setup Pi-hole. We do not own Pi-hole. Under the guide lines provided by the creators of Pi-hole we are allowed to promote the software as long as it does not cause unnexessary consumer or public confusion. We are including Pi-hole setup in here so its a all around guide.


Official Pi-hole website: https://pi-hole.net/
Pi-hole documentation: https://docs.pi-hole.net/

Pre Reqs - Pi-Setup.md (Please read the Setup file before setting up Pi-hole)

Step 1:
Find the IP address of your Pi. to do this open a terminal and type "ifconfig" this will bring up your Pi's IP. Keep note of the IP because this is going to be used when you set up the DNS on your router later on.
Also if you have not done so, run the commands "sudo apt-get update -y && apt-get upgrade -y". this will make your Raspberry Pi uptodate.

Step 2:
Now is the itme to run the Pi-hole install command, in the terminal write "curl -sSL https://install.pi-hole.net | bash" this will run the Pi-hole installation. It will ask you what provider you want for your DNS. Pick which one you want, we went with Cloudfare. the next part will ask if you want your current network settings as static. You can change this if you want, I kept mine as the default IP and set it as a reserved IP in the router so it wouldn't change. It will then ask you if you want to install the web admin interface and to log queries, select yes, (You can turn off logging queries later). The web interface is nice and clean so you will want this. When the installation is complete it will display a password for your webpage interface, make sure to write it down. You can change the password via the terminal with "pihole -a -p". For other commands you can view the documentation at: https://docs.pi-hole.net/

Step 3:
This step will differ based on your router. The router we used is the Arris provided by Spectrum. You need to find your routers default login credentials, a quick Google search of your router will help provide this information. Once inside your router, naviage to your client list and add your Pi's IP to the reserved IP list. this will keep the DHCP from changing it. Head over to the DNS settings, and check the box for DNS Override. For the primary DNS server IP, put your Pi's IP into that field. Then click apply, your router will now use your Pi as its Primary DNS server.