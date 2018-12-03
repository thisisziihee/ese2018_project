# -*- coding: utf-8 -*-
import argparse
import json
from collections import OrderedDict



# Ready for data
def make_json_file(name, time):

    name = str(name)
    time = str(time)

    group_data = OrderedDict()
    
    group_data[name] = time;


    # write JSON
    with open('test.json','w') as make_file:
	json.dump(group_data, make_file,indent="\t")
 
parser = argparse.ArgumentParser(description='save lab time to json file')
parser.add_argument('--name',dest='name', required=True, help='name of save file')
parser.add_argument('--time',dest='time', required=True, help='time of save file')
args = parser.parse_args()

if __name__ == "__main__":
    make_json_file(args.name, args.time)
