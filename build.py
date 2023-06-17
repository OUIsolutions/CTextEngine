
from CToolKit import *



def execute_tests():
    compile_project('gcc','exemples/basic_template.c')    



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

