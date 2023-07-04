
import CToolKit as ct
from os import listdir,remove



STARTER  = f'CTextEngine/CTextEngineMain.h'
ct.generate_amalgamated_code(STARTER,'CTextEngine.h')


#ct.execute_test_for_folder('gcc','exemples',use_valgrind=True)
#print('all test passed')

def modifier(text:str):
    formated = text
    targets = [
        '../../../CTextEngine.h',
        '../../CTextEngine.h',
        '../CTextEngine.h'
    ]
    for t in targets:
        formated  = formated.replace(t,'CTextEngine.h')
    return  formated


ct.include_code_in_markdown('README.md',save_file=True, modifier=modifier)

