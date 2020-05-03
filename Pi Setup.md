This page will include how to setup Pi-hole and the network modifications that we implimented for this project. 

Step 1, Equipment:
The Raspberry Pi that was used for this projecst was the Raspberry Pi model 4B. A kit with everything that you need runs for 114.99 on Amazon. The 4B model is the latest model and can handle everything with ease for this project.
The Kit Includes:
Raspberry Pi 4 4GB Model B with 1.5GHz 64-bit quad-core ARMv8 CPU (4GB RAM)
64GB Samsung EVO+ Micro SD Card (Class 10) Pre-loaded with NOOBS (New out of the box) software, USB MicroSD Card Reader
CanaKit Premium High-Gloss Raspberry Pi 4 Case with Integrated Fan Mount, CanaKit Low Noise Bearing System Fan
CanaKit 3.5A USB-C Raspberry Pi 4 Power Supply with Noise Filter, Set of Heat Sinks, Set of 2 Micro HDMI to HDMI Cables - 6 foot (Supports up to 4K 60p)
CanaKit USB-C PiSwitch (On/Off Power Switch for Raspberry Pi 4)

https://www.amazon.com/CanaKit-Raspberry-4GB-Starter-MAX/dp/B07XPHWPRB/ref=sr_1_4?dchild=1&keywords=raspberry+pi+4&qid=1588357586&sr=8-4

You will also need a stable internet connection, keyboard, monitor(If you want a graphical user interface) and mouse.

Setp 2, Setting up the Raspberry Pi:
The benefit of the above package is it comes with everything you need, cables to connect to your moitors, a micro SD card with NOOBS a fan for colling and heat syncs. 
To set up the Pi you need to plug in ur keyboard, mouse, micro SD card and power supply. The initial set up is pretty straight foward. With the SD card with NOOBS already, turn on your Pi and check the Raspbian box and the initial set up will start. You will be presented with a welcome screen. Follow the initial set up process.

Optional:
Once initial set up is completed head to the task bar->Preferences->Interfaces. From here click the enable for SSH and VNC, this will allow you to access your Pi from a remote location as well as view your desktop from a different computer.
To connect via SSH, you may use an external application like Putty, or Bitvise. For this project we used the windows commmand prompt to SSH in. 
SSH into the pi by "ssh your_pi_name@IP_ADDRESS
If you did this correctly you will now be SSH into your pi. The next step is to set up the VNC desktop. We used Real VNC to accomplish this, the link is below:
https://www.realvnc.com/en/connect/download/viewer/
Follow the steps for setup. Once the application is installed go to file->new connection. The VNC server field is the IP of your Pi, and the name is what you named your Pi. Double click the new sever and you will be prompted for another login. For username put your Pis name, and for password, the password you assigned to the pi during setup.

