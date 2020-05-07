import os
import subprocess
import sys

# Python v3.6.9
# Setup script to check if Snort and Pi-hole are installed
# If not installed, asks user if they want them installed and starts the download

# Dependencies for Snort: daq v2.0.7
# cd /usr/local/src
# sudo wget https://www.snort.org/downloads/snort/daq-2.0.7.tar.gz
# sudo tar xvzf daq-2.0.7.tar.gz
# cd /usr/local/src/daq-2.0.7
# nano /home/your-user-name/.bashrc
# export PATH="/usr/local/src/daq-2.0.7/:$PATH" added to the last line of the file
# export PATH="/daq/install/prefix:$PATH" added to the last line of the file
# Save .bashrc file
# Restart terminal
# cd into Net-Pi repository
# sudo python3 setup.py

def check_install():
    snort_path = '/etc/snort-2.9.16'
    pi_hole_path = '/etc/pihole'
    result = []
    result.append(os.path.isdir(snort_path))
    result.append(os.path.isdir(pi_hole_path))
    return result

def download_snort():
    # Download and extract Snort
    os.chdir(os.path.abspath('/etc'))
    subprocess.run(['wget', 'https://www.snort.org/downloads/snort/snort-2.9.16.tar.gz'])
    subprocess.run(['tar', 'xvzf', 'snort-2.9.16.tar.gz'])

def install_snort():
    # Install dev packages of libpcap and libpcre
    subprocess.run(['sudo', 'apt-get', 'update', '-y'])
    subprocess.run(['sudo', 'apt-get', 'install', '-y', 'libpcap-dev'])
    subprocess.run(['sudo', 'apt-get', 'update', '-y'])
    subprocess.run(['sudo', 'apt-get', 'install', '-y', 'libpcre3-dev'])
    subprocess.run(['sudo', 'apt-get', 'update', '-y'])
    subprocess.run(['sudo', 'apt-get', 'install', '-y', 'libdumbnet-dev'])

    # Install Snort
    os.chdir(os.path.abspath('/etc/snort-2.9.16'))
    subprocess.run(['./configure', '', ''])
    subprocess.run(['make'])
    subprocess.run(['make', 'install'])

def install_pi_hole():
    os.chdir(os.path.abspath('/etc'))
    subprocess.run(['git', 'clone', 'https://github.com/pi-hole/pi-hole.git', 'Pi-hole'])
    os.chdir(os.path.abspath('Pi-hole/automated install'))
    subprocess.run(['sudo', 'bash', 'basic-install.sh'])

def main():
    ci_result = check_install()
    if ci_result[0] == False:
        answer = input("Would you like to install Snort? [y/n]: ")
        if answer == 'y':
            download_snort()
            install_snort()
            print("Snort successfully installed")
    if ci_result[1] == False:
        answer = input("Would you like to install Pi-hole? [y/n]: ")
        if answer == 'y':
            install_pi_hole()
    if ci_result[0] == True and ci_result[1] == True:
        print("Snort and Pi-hole already installed")
    sys.exit(0)

if __name__ == '__main__':
        main()
