
from CToolKit import *
from os import listdir,remove


def execute_test_for_file(file:str):
    result = copile_project(
        'gcc',
        file,
        raise_errors=True,
        raise_warnings=False
    )    
    try:
        test_binary_with_valgrind(result)
        remove(result)
    except Exception as e:
        remove(result)
        raise e


def test_exemple_folder():
    files = listdir('exemples')
    
    for file in files:
        if not file.endswith('.c'):
            continue
        try:
            execute_test_for_file(f'exemples/{file}')
            print(f'passed: {file}')
        except Exception as e:
            print(f'fail with file: {file}')
            print(e)
            exit(1)
def main():

    STARTER  = f'CTextEngine/CTextEngineMain.h'
    amalgamated_code = generate_amalgamated_code(STARTER)

    with open('exemples/CTextEngine.h','w') as f:
        f.write(amalgamated_code)


    test_exemple_folder()
    print('all test passed')
    include_code_in_markdown('README.md')
    
    with open('CTextEngine.h','w') as f:
        f.write(amalgamated_code)
if __name__ == '__main__':
    main()

