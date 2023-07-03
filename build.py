
import CToolKit as ct
from os import listdir,remove



STARTER  = f'CTextEngine/CTextEngineMain.h'
ct.generate_amalgamated_code(STARTER,'CTextEngine.h')


ct.execute_test_for_folder('gcc','exemples')
print('all test passed')
'''

ct.include_code_in_markdown('README.md')

with open('CTextEngine.h','w') as f:
    f.write(amalgamated_code)
'''
