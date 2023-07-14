
import Build.CToolKit as ct
from Build.exemple_build import create_exemples
from Build.full_folder_zip import zip_folder


STARTER = 'CTextEngine/CTextEngineMain.h'
TEST_NAME  = 'CTextEngine_test.h'

OUTPUT_TEST = 'tests/CTextEngine_test.h'
OUTPUT = 'CTextEngine.h'
ZIP_NAME ='CTextEngine'


ct.generate_amalgamated_code(STARTER,OUTPUT_TEST)
test = ct.FolderTestPreset(folder='tests',side_effect_folder='tests/side_effect')
create_exemples(TEST_NAME,OUTPUT)
'''
test.generate_ouptut()

test.start_test()
ct.include_code_in_markdown('README.md',save_file=True)
ct.generate_amalgamated_code(STARTER,OUTPUT)

create_exemples(TEST_NAME,OUTPUT)

zip_folder(ZIP_NAME)
'''