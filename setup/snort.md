This file will provide the steps for installing snort.
Note** If installation doesn't work with normal commands put "sudo" before them, this will run the commands as a root user.

Snort does come with all its rules, however, you can make an account with snort and get rule sets. to do this go to https://www.snort.org/ and register for a free account. Once registered, you will need to generate an “OinkCode”, that will enable you to download the last free ruleset. To do so, then you receive the activation email, go to the website loggin, click on “Get Rule”, “Command Line”, “Get an Oinkcode”, then click “Generate code”. Depending on what Rule set was downloaded you will need to modify your .conf to read that rule set.

Run the command sudo apt-get install snort, if the command doesn't work for you look below to install from the source
then go to "etc/snort/snort.conf" and input the snort.conf file we have into yours. You will have to modify 


https://www.thegeekstuff.com/2010/08/snort-tutorial/
The link above is a bit outdated, 

Setp 1: Download and extract Snort. In the terminal input these commands:
As of writing this, the latest version is 2.9.16.

cd /usr/src
wget -O snort-2.9.16.tar.gz http://www.snort.org/downloads/116 
tar xvzf snort-2.8.6.1.tar.gz

Step 2: Make sure you have these packages installed, run the following commands:

apt-cache policy libpcap0.8-dev
apt-cache policy libpcre3-dev

Step 3: Run the following commands to install Snort
Note that this process will take some time 

cd snort-2.9.16
./configure
make
make install

Lastly check that Snort is installed by running: "snort --version"

Next we will take all the files in the snort folder and place them in "/etc/snort"

Lastly we will put in a .service file to make snort run on startup. In the terminal execute: "/etc/systemd/system" once you are in this folder create a new file names "snort.service". Now copy and paste the following into your new snort.service:

[Unit]
Description=Snort

[Service]
User=pi
TimeoutStartSec=0
WorkingDirectory=/usr/sbin
ExecStart=sudo snort  -v -c /etc/snort/snort.conf -l /var/log/snort/
StandardError=syslog
SyslogIdentifier=snort
restart=always

[Install]
WantedBy=Multi-user.target

-We are working on a set upscript that will do this automatically. It is still a work in progress.
