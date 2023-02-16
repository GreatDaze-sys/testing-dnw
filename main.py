import os
import sys
import time

def main():
    ip = input('Enter an IP or website address to DDoS: ')
    os.system('ping ' + ip) #ping the ip
    print('\n')
    print('IP booted')
    for i in range(10):
        print(f'\033[{i*3+31}mDDoS attack\033[0m')
        time.sleep(1)

if name == 'main':
    main()
