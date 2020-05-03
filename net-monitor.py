import os
import subprocess

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
    return stats

net_stats = get_network_stats()

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
