
from CToolKit import *
from os import listdir,remove



STARTER  = f'CTextEngine/CTextEngineMain.h'
amalgamated_code = generate_amalgamated_code(STARTER)

with open('exemples/CTextEngine.h','w') as f:
    f.write(amalgamated_code)


execute_test_for_folder('exemples')
print('all test passed')
include_code_in_markdown('README.md')

with open('CTextEngine.h','w') as f:
    f.write(amalgamated_code)
