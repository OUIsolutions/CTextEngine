
from CToolKit import *



def execute_tests():
    copile_project(
        'gcc',
        'exemples/basic_template.c',
        raise_errors=True,
        raise_warnings=False
    )    
    test_binary_with_valgrind('exemples/basic_template.out')



def main():

    STARTER  = f'CTextEngine/CTextEngineMain.h'
    amalgamated_code = generate_amalgamated_code(STARTER)

    with open('exemples/CTextEngine.h','w') as f:
        f.write(amalgamated_code)

  


    execute_tests()

    with open('CTextEngine.h','w') as f:
        f.write(amalgamated_code)
if __name__ == '__main__':
    main()

