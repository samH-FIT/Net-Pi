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

Pi-hole works by adding blocklists to generate the pi-holes features. Below are the current block list that are implimented with the Pi:
https://raw.githubusercontent.com/StevenBlack/hosts/master/hosts	
	https://mirror1.malwaredomains.com/files/justdomains	
	http://sysctl.org/cameleon/hosts	
	https://s3.amazonaws.com/lists.disconnect.me/simple_tracking.txt	
	https://s3.amazonaws.com/lists.disconnect.me/simple_ad.txt	
	https://hosts-file.net/ad_servers.txt	
	https://dbl.oisd.nl/	
	https://phishing.army/download/phishing_army_blocklist_extended.txt	
	https://tspprs.com/dl/crypto	
	https://tspprs.com/dl/tracking	
	https://tspprs.com/dl/spotify	
	https://raw.githubusercontent.com/CHEF-KOCH/Audio-fingerprint-pages/master/AudioFp.txt	
	https://raw.githubusercontent.com/CHEF-KOCH/Canvas-fingerprinting-pages/master/Canvas.txt	
	https://raw.githubusercontent.com/CHEF-KOCH/WebRTC-tracking/master/WebRTC.txt	
	https://raw.githubusercontent.com/CHEF-KOCH/CKs-FilterList/master/HOSTS/Game.txt	
	https://raw.githubusercontent.com/CHEF-KOCH/NSABlocklist/master/HOSTS	
	https://raw.githubusercontent.com/deathbybandaid/piholeparser/master/Subscribable-Lists/ParsedBlacklists/AakList.txt	
	https://raw.githubusercontent.com/deathbybandaid/piholeparser/master/Subscribable-Lists/ParsedBlacklists/Prebake-Obtrusive.txt	
	https://jasonhill.co.uk/pfsense/ytadblock.txt	
	https://hosts-file.net/grm.txt	
	https://raw.githubusercontent.com/PolishFiltersTeam/KADhosts/master/KADhosts_without_controversies.txt	
	https://raw.githubusercontent.com/FadeMind/hosts.extras/master/add.Spam/hosts	
	https://v.firebog.net/hosts/static/w3kbl.txt	
	https://adaway.org/hosts.txt	
	https://v.firebog.net/hosts/AdguardDNS.txt	
	https://raw.githubusercontent.com/anudeepND/blacklist/master/adservers.txt	
	https://s3.amazonaws.com/lists.disconnect.me/simple_ad.txt	
	https://hosts-file.net/ad_servers.txt	
	https://v.firebog.net/hosts/Easylist.txt	
	https://pgl.yoyo.org/adservers/serverlist.php?hostformat=hosts&showintro=0&mimetype=plaintext	
	https://raw.githubusercontent.com/FadeMind/hosts.extras/master/UncheckyAds/hosts	
	https://raw.githubusercontent.com/bigdargon/hostsVN/master/hosts	
	https://v.firebog.net/hosts/Easyprivacy.txt	
	https://v.firebog.net/hosts/Prigent-Ads.txt	
	https://gitlab.com/quidsup/notrack-blocklists/raw/master/notrack-blocklist.txt	
	https://raw.githubusercontent.com/FadeMind/hosts.extras/master/add.2o7Net/hosts	
	https://raw.githubusercontent.com/crazy-max/WindowsSpyBlocker/master/data/hosts/spy.txt	
	https://www.github.developerdan.com/hosts/lists/ads-and-tracking-extended.txt	
	https://hostfiles.frogeye.fr/firstparty-trackers-hosts.txt	
	https://raw.githubusercontent.com/DandelionSprout/adfilt/master/Alternate%20versions%20Anti-Malware%20List/AntiMalwareHosts.txt	
	https://osint.digitalside.it/Threat-Intel/lists/latestdomains.txt	
	https://s3.amazonaws.com/lists.disconnect.me/simple_malvertising.txt	
	https://mirror1.malwaredomains.com/files/justdomains	
	https://v.firebog.net/hosts/Prigent-Malware.txt	
	https://hosts-file.net/exp.txt	
	https://hosts-file.net/emd.txt	
	https://hosts-file.net/psh.txt	
	https://mirror.cedia.org.ec/malwaredomains/immortal_domains.txt	
	https://www.malwaredomainlist.com/hostslist/hosts.txt	
	https://bitbucket.org/ethanr/dns-blacklists/raw/8575c9f96e5b4a1308f2f12394abd86d0927a4a0/bad_lists/Mandiant_APT1_Report_Appendix_D.txt	
	https://phishing.army/download/phishing_army_blocklist_extended.txt	
	https://gitlab.com/quidsup/notrack-blocklists/raw/master/notrack-malware.txt	
	https://v.firebog.net/hosts/Shalla-mal.txt	
	https://raw.githubusercontent.com/FadeMind/hosts.extras/master/add.Risk/hosts	
	https://urlhaus.abuse.ch/downloads/hostfile/	
	https://zerodot1.gitlab.io/CoinBlockerLists/hosts_browser	
	https://raw.githubusercontent.com/DandelionSprout/adfilt/master/Alternate%20versions%20Anti-Malware%20List/AntiMalwareHosts.txt	
	https://osint.digitalside.it/Threat-Intel/lists/latestdomains.txt	
	https://s3.amazonaws.com/lists.disconnect.me/simple_malvertising.txt	
	https://mirror1.malwaredomains.com/files/justdomains	
	https://v.firebog.net/hosts/Prigent-Malware.txt	
	https://hosts-file.net/exp.txt	
	https://hosts-file.net/emd.txt	
	https://hosts-file.net/psh.txt	
	https://mirror.cedia.org.ec/malwaredomains/immortal_domains.txt	
	https://www.malwaredomainlist.com/hostslist/hosts.txt	
	https://bitbucket.org/ethanr/dns-blacklists/raw/8575c9f96e5b4a1308f2f12394abd86d0927a4a0/bad_lists/Mandiant_APT1_Report_Appendix_D.txt	
	https://phishing.army/download/phishing_army_blocklist_extended.txt	
	https://gitlab.com/quidsup/notrack-blocklists/raw/master/notrack-malware.txt	
	https://v.firebog.net/hosts/Shalla-mal.txt	
	https://raw.githubusercontent.com/FadeMind/hosts.extras/master/add.Risk/hosts	
	https://urlhaus.abuse.ch/downloads/hostfile/	
	https://raw.githubusercontent.com/HorusTeknoloji/TR-PhishingList/master/url-lists.txt	
	https://blocklist.cyberthreatcoalition.org/vetted/domain.txt	
	https://blocklist.cyberthreatcoalition.org/vetted/url.txt