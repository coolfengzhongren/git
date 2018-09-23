#!/usr/bin/env python3
# encoding: utf-8
import os

#create in current directory
root_path = os.getcwd()

#directory list
directory_list =[
	'dbconnector',
	'exceptions',
	'helper',
	'route',
	'session',
	'template_engine',
	'view',
	'wsgi_adapter'
]
#children file
children ={'name':'__init__.py','children':None,'type':'file'}

#directory structure ，是一个字典类型的数据
dir_map =[{
	'name':'sylfk',
	'children':[{
		'name':directory,
		'type':'dir',
		'children':[children]
		}for directory in directory_list] + [children],
		'type':'dir'
}]
# create file or folder
def create(path, kind):
    if kind == 'dir':
        os.mkdir(path)
    else:
        open(path, 'w').close()


# Recursively create directories
def gen_project(parent_path, map_obj):
    for line in map_obj:
        path = os.path.join(parent_path, line['name'])
        create(path, line['type'])
        if line['children']:
            gen_project(path, line['children'])


# script entrance
def main():
    gen_project(root_path, dir_map)


if __name__ == '__main__':
    main()