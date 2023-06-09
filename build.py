
import CToolKit as ct
from os import listdir,remove



STARTER  = f'CTextEngine/CTextEngineMain.h'
amalgamated_code = ct.generate_amalgamated_code(STARTER)

with open('exemples/CTextEngine.h','w') as f:
    f.write(amalgamated_code)


ct.execute_test_for_folder('clang','exemples')
print('all test passed')

ct.include_code_in_markdown('README.md')

with open('CTextEngine.h','w') as f:
    f.write(amalgamated_code)
