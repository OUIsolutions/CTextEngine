
from CTolkit import *


def execute_tests():
    copile_project_by_comand('gcc exemples/basic_template.c',True,True,True)    



def main():

    STARTER  =f'CTextEngine/CTextEngineMain.h'
    amalgamated_code = get_amalgamated_code(STARTER)

    with open('exemples/CTextEngine.h','w') as f:
        f.write(amalgamated_code)

  


    execute_tests()

    with open('CTextEngine.h','w') as f:
        f.write(amalgamated_code)
if __name__ == '__main__':
    main()

