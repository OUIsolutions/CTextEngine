

from shutil import copytree
from shutil import rmtree
from os import remove,makedirs
from os import listdir
from os.path import isdir,dirname




def create_exemples(test_name:str,output:str):
    rmtree('exemples',ignore_errors=True)
    makedirs('exemples')
    elements = listdir('tests/')
    for e in elements:
        path = f'tests/{e}'

        if e == 'side_effect':
            continue

        with open(f'{path}/exec.c','r') as arq:
            content = arq.read()
        
        with open(f'exemples/{e.replace("T_","")}.c','w') as arq2:
            arq2.write(content)
