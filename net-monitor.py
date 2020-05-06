import os
import psutil
import socket
import subprocess
import sys

# Python v3.6.9
# Basic network monitor for use on a local machine or local area network
# Provides ease of access to network statistics during configuration of a home network

def get_network_stats():
    stats = {}

    # Get CPU count
    cpu_count = os.cpu_count()
    stats['cpu_count'] = cpu_count

    # Get load average
    cpu_load = [i / os.cpu_count() * 100 for i in os.getloadavg()][-1]
    stats['cpu_load'] = round(cpu_load)

    # Network latency 
    net_lat = subprocess.run(['ping', '-i 3', '-c 3', 'fit.edu'],
                            stdout=subprocess.PIPE).stdout.decode('utf-8').split('\n')
    min_val, max_val, avg = net_lat[-2].split('=')[-1].split('/')[:3]
    stats['net_lat'] = dict(
        {
            'min': min_val.strip(),
            'max': max_val.strip(),
            'avg': avg.strip(),
        }
    )

    # Memory
    mem = psutil.virtual_memory()
    stats['memory'] = mem
    
    # Network I/O
    input_output = psutil.net_io_counters()
    stats['io'] = input_output

    # Open ports
    conn = psutil.net_connections()
    ports = []
    services = []
    ps_list = []
    count = 0
    for i in conn:
        if i.status == 'LISTEN':
            try:
                ports.append(i.laddr[1])
                services.append(socket.getservbyport(ports[count]))
                count += 1
            except:
                continue
    ps_list = [str(i) + ": " + j for i, j in zip(ports, services)]
    stats['ports'] = ps_list
    return stats

def main():
    net_stats = get_network_stats()

    print("**Network Statistics for Local Machine**")

    print("Number of CPUs: ", end = "")
    print(net_stats['cpu_count'])

    print("CPU Load Average: ", end = "")
    print(net_stats['cpu_load'], end = "")
    print("%")

    print("Minimum Latency: ", end = "")
    print(net_stats['net_lat']['min'])

    print("Maximum Latency: ", end = "")
    print(net_stats['net_lat']['max'])

    print("Average Latency: ", end = "")
    print(net_stats['net_lat']['avg'])

    print(net_stats['memory'])

    print(net_stats['io'])

    print("Open ports: ", end = "")
    print(net_stats['ports'])    
    
    sys.exit(0)

if __name__ == '__main__':
        main()
    
